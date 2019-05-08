#pragma once

#include "Poco/Net/HTTPRequestHandlerFactory.h"

namespace ezored
{
namespace server
{
namespace factories
{

class SimpleRequestHandlerFactory : public Poco::Net::HTTPRequestHandlerFactory
{
public:
    virtual Poco::Net::HTTPRequestHandler *createRequestHandler(const Poco::Net::HTTPServerRequest &);
};

} // namespace factories
} // namespace server
} // namespace ezored
