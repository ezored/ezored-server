#include "SimpleRequestHandlerFactory.hpp"
#include "ezored/server/handlers/SimpleRequestHandler.hpp"

namespace ezored
{
namespace server
{
namespace factories
{

using namespace ezored::server::handlers;

Poco::Net::HTTPRequestHandler *SimpleRequestHandlerFactory::createRequestHandler(const Poco::Net::HTTPServerRequest &)
{
    return new SimpleRequestHandler;
}

} // namespace factories
} // namespace server
} // namespace ezored
