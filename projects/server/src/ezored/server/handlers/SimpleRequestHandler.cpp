#include "SimpleRequestHandler.hpp"
#include "ezored/server/controllers/PingController.hpp"
#include "ezored/server/helpers/WebHelper.hpp"

#include "Poco/Path.h"
#include "Poco/URI.h"

#include <iostream>
#include <regex>

namespace ezored
{
namespace server
{
namespace handlers
{

using namespace ezored::server::helpers;
using namespace ezored::server::controllers;

SimpleRequestHandler::SimpleRequestHandler()
{
    mimeTypeMap = WebHelper::getMimeMap();
    regexStaticFiles = std::regex("\\.(?:htm|html|bmp|gif|jpg|jpeg|log|txt|png|ico|svg|xml|css|pdf)");
}

void SimpleRequestHandler::handleRequest(Poco::Net::HTTPServerRequest &req, Poco::Net::HTTPServerResponse &resp)
{
    if (isStaticFileRequest(req, resp))
    {
        sendStaticFile(req, resp);
    }
    else if (WebHelper::matchRoute(req, "/ping"))
    {
        PingController::process(req, resp);
    }
    else if (isDefaultRequest(req, resp))
    {
        sendDefaultResponse(req, resp);
    }
    else
    {
        resp.setStatus(Poco::Net::HTTPResponse::HTTP_NOT_FOUND);
        resp.setContentType("text/html");

        std::ostream &out = resp.send();
        out << "<h1>Not found</h1>";
        out.flush();
    }
}

bool SimpleRequestHandler::isStaticFileRequest(Poco::Net::HTTPServerRequest &req, Poco::Net::HTTPServerResponse &resp)
{
    if (req.getMethod() == "GET")
    {
        if (std::regex_search(req.getURI(), regexStaticFiles))
        {
            return true;
        }
    }

    return false;
}

bool SimpleRequestHandler::isDefaultRequest(Poco::Net::HTTPServerRequest &req, Poco::Net::HTTPServerResponse &resp)
{
    if (req.getMethod() == "GET")
    {
        if (req.getURI() == "/")
        {
            return true;
        }
    }

    return false;
}

void SimpleRequestHandler::sendStaticFile(Poco::Net::HTTPServerRequest &req, Poco::Net::HTTPServerResponse &resp)
{
    Poco::URI fileURI = Poco::URI(req.getURI());
    Poco::Path filePath = Poco::Path("assets", fileURI.getPath());
    std::string fileExtension = filePath.getExtension();

    resp.sendFile(filePath.makeAbsolute().toString(), mimeTypeMap[fileExtension]);
}

void SimpleRequestHandler::sendDefaultResponse(Poco::Net::HTTPServerRequest &req, Poco::Net::HTTPServerResponse &resp)
{
    std::string mimeType = mimeTypeMap["html"];
    resp.sendFile("assets/index.html", mimeType);
}

} // namespace handlers
} // namespace server
} // namespace ezored
