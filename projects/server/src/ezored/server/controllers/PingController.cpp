#include "PingController.hpp"
#include <iostream>
#include <string>

namespace ezored
{
namespace server
{
namespace controllers
{

int PingController::count = 0;

PingController::PingController()
{
}

void PingController::process(Poco::Net::HTTPServerRequest &req, Poco::Net::HTTPServerResponse &resp)
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

} // namespace controllers
} // namespace server
} // namespace ezored
