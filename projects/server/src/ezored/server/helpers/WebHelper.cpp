#include "WebHelper.hpp"

namespace ezored
{
namespace server
{
namespace helpers
{

const std::map<std::string, std::string> WebHelper::getMimeMap()
{
    std::map<std::string, std::string> extMap;

    extMap.insert(std::make_pair("htm", "text/html"));
    extMap.insert(std::make_pair("html", "text/html"));
    extMap.insert(std::make_pair("bmp", "image/bmp"));
    extMap.insert(std::make_pair("gif", "image/gif"));
    extMap.insert(std::make_pair("jpg", "image/jpeg"));
    extMap.insert(std::make_pair("jpeg", "image/jpeg"));
    extMap.insert(std::make_pair("log", "text/plain"));
    extMap.insert(std::make_pair("txt", "text/plain"));
    extMap.insert(std::make_pair("png", "image/png"));
    extMap.insert(std::make_pair("ico", "image/x-icon"));
    extMap.insert(std::make_pair("svg", "image/svg+xml"));
    extMap.insert(std::make_pair("xml", "text/xml"));
    extMap.insert(std::make_pair("css", "text/css"));
    extMap.insert(std::make_pair("rss", "application/rss+xml"));
    extMap.insert(std::make_pair("pdf", "application/pdf"));

    return extMap;
}

} // namespace helpers
} // namespace server
} // namespace ezored
