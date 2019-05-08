#pragma once

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
};

} // namespace helpers
} // namespace server
} // namespace ezored
