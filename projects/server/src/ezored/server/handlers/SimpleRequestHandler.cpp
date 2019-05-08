#include "SimpleRequestHandler.hpp"
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

int SimpleRequestHandler::count = 0;

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
    else if (matchRoute(req, "/ping"))
    {
        resp.setStatus(Poco::Net::HTTPResponse::HTTP_OK);
        resp.setContentType("text/html");

        std::ostream &out = resp.send();

        count = count + 1;

        out << "<h1>Ping</h1>"
            << "<p>Count: " << count << "</p>"
            << "<p>Host: " << req.getHost() << "</p>"
            << "<p>Method: " << req.getMethod() << "</p>"
            << "<p>URI: " << req.getURI() << "</p>";

        out.flush();
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

bool SimpleRequestHandler::matchRoute(Poco::Net::HTTPServerRequest &req, std::string route)
{
    std::string uri = req.getURI();

    if (uri.substr(0, route.size()) == route)
    {
        return true;
    }

    return false;
}

} // namespace handlers
} // namespace server
} // namespace ezored
