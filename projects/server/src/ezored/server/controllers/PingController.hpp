#pragma once

#include "BaseController.hpp"

namespace ezored
{
namespace server
{
namespace controllers
{

class PingController : public BaseController
{
public:
    PingController();
    virtual ~PingController() {}
    static void process(Poco::Net::HTTPServerRequest &req, Poco::Net::HTTPServerResponse &resp);

private:
    static int count;
};

} // namespace controllers
} // namespace server
} // namespace ezored
