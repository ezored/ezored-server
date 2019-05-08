#pragma once

#include "Poco/Net/HTTPRequestHandler.h"
#include "Poco/Net/HTTPServerRequest.h"
#include "Poco/Net/HTTPServerResponse.h"

#include <map>
#include <memory>
#include <regex>

namespace ezored
{
namespace server
{
namespace handlers
{

class SimpleRequestHandler : public Poco::Net::HTTPRequestHandler
{
public:
    SimpleRequestHandler();
    void handleRequest(Poco::Net::HTTPServerRequest &req, Poco::Net::HTTPServerResponse &resp);
    bool isStaticFileRequest(Poco::Net::HTTPServerRequest &req, Poco::Net::HTTPServerResponse &resp);
    bool isDefaultRequest(Poco::Net::HTTPServerRequest &req, Poco::Net::HTTPServerResponse &resp);
    void sendStaticFile(Poco::Net::HTTPServerRequest &req, Poco::Net::HTTPServerResponse &resp);
    void sendDefaultResponse(Poco::Net::HTTPServerRequest &req, Poco::Net::HTTPServerResponse &resp);
    bool matchRoute(Poco::Net::HTTPServerRequest &req, std::string route);

private:
    static int count;
    std::map<std::string, std::string> mimeTypeMap;
    std::regex regexStaticFiles;
};

} // namespace handlers
} // namespace server
} // namespace ezored
