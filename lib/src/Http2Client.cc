#include "Http2Client.h"
#include <drogon/utils/string_view.h>
#include <trantor/utils/Logger.h>

using namespace drogon;
static const string_view h2Magic = "PRI * HTTP/2.0\r\n\r\nSM\r\n\r\n";

void Http2Client::onConnected(const trantor::TcpConnectionPtr &conn)
{
    LOG_TRACE << "Sending HTTP2 magic string.";
    conn->send(h2Magic.data(), h2Magic.length());
}

void Http2Client::onMessage(const trantor::TcpConnectionPtr &conn, trantor::MsgBuffer *buf)
{
    LOG_TRACE << "Got http2 message. Size; " << buf->readableBytes();
    buf->retrieveAll();
    // stub!
}

void Http2Client::sendRequest(const trantor::TcpConnectionPtr &conn, const HttpRequestPtr &req, const HttpReqCallback &callback, double timeout)
{
    // stub!
}