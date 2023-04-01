#pragma once

#include <drogon/exports.h>
#include <trantor/net/TcpConnection.h>
#include <drogon/HttpRequest.h>
#include <drogon/drogon_callbacks.h>

/**
 * NOTE: This class now works only as a sub-handler of HttpClient. It's intended to be changed later. Just some quick and dirty code to get myself started.
*/

namespace drogon
{
class DROGON_EXPORT Http2Client
{
public:
    void onConnected(const trantor::TcpConnectionPtr &conn);
    void onMessage(const trantor::TcpConnectionPtr &conn, trantor::MsgBuffer *buf);
    void sendRequest(const trantor::TcpConnectionPtr &conn, const HttpRequestPtr &req, const HttpReqCallback &callback, double timeout);
};
}