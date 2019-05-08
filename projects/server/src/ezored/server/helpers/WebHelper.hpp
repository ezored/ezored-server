#pragma once

#include "Poco/Net/HTTPServerRequest.h"
#include "Poco/Net/HTTPServerResponse.h"

#include <map>
#include <string>

namespace ezored
{
namespace server
{
namespace helpers
{

class WebHelper
{
public:
    static const std::map<std::string, std::string> getMimeMap();
    static bool matchRoute(Poco::Net::HTTPServerRequest &req, std::string route);
};

} // namespace helpers
} // namespace server
} // namespace ezored
