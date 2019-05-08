#include "SimpleServer.hpp"

#include "Poco/DateTimeFormatter.h"
#include "Poco/LocalDateTime.h"
#include "Poco/Net/HTTPServer.h"
#include "Poco/Net/ServerSocket.h"
#include "Poco/Util/HelpFormatter.h"
#include "Poco/Util/ServerApplication.h"

#include "ezored/server/factories/SimpleRequestHandlerFactory.hpp"

#include <iostream>

namespace ezored
{
namespace server
{
namespace apps
{

using namespace ezored::server::factories;

SimpleServer::SimpleServer()
{
    helpRequested = false;
}

SimpleServer::~SimpleServer()
{
}

void SimpleServer::initialize(Poco::Util::Application &self)
{
    loadConfiguration();
    ServerApplication::initialize(self);
}

void SimpleServer::uninitialize()
{
    ServerApplication::uninitialize();
}

void SimpleServer::defineOptions(Poco::Util::OptionSet &options)
{
    ServerApplication::defineOptions(options);

    options.addOption(Poco::Util::Option("help", "h", "display help information on command line arguments")
                          .required(false)
                          .repeatable(false));
}

void SimpleServer::handleOption(const std::string &name, const std::string &value)
{
    ServerApplication::handleOption(name, value);

    if (name == "help")
    {
        helpRequested = true;
    }
}

void SimpleServer::displayHelp()
{
    Poco::Util::HelpFormatter helpFormatter(options());
    helpFormatter.setCommand(commandName());
    helpFormatter.setUsage("OPTIONS");
    helpFormatter.setHeader("A simple but powerful web server.");
    helpFormatter.format(std::cout);
}

int SimpleServer::main(const std::vector<std::string> &args)
{
    if (helpRequested)
    {
        displayHelp();
    }
    else
    {
        int port = config().getInt("http_server.port", 8080);
        std::string basePath = config().getString("http_server.base_path", "dumps//");

        Poco::Net::ServerSocket svs(port);
        Poco::Net::HTTPServer srv(new SimpleRequestHandlerFactory, svs, new Poco::Net::HTTPServerParams);

        srv.start();

        this->logger().information(Poco::format("%s: Server startup on port %d", Poco::DateTimeFormatter::format(Poco::LocalDateTime().timestamp(), "%Y-%m-%d %H:%M:%s"), port));

        waitForTerminationRequest();
        srv.stop();
    }

    return Application::EXIT_OK;
}

} // namespace apps
} // namespace server
} // namespace ezored
