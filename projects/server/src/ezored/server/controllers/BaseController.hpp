#pragma once

#include "Poco/Net/HTTPServerRequest.h"
#include "Poco/Net/HTTPServerResponse.h"

namespace ezored
{
namespace server
{
namespace controllers
{

class BaseController
{
public:
    BaseController();
    virtual ~BaseController() {}
};

} // namespace controllers
} // namespace server
} // namespace ezored
