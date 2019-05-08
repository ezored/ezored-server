#pragma once

#include "Poco/Util/ServerApplication.h"

#include <string>
#include <vector>

namespace ezored
{
namespace server
{
namespace apps
{

using Poco::Util::OptionSet;
using Poco::Util::ServerApplication;

class SimpleServer : public ServerApplication
{
public:
    SimpleServer();
    virtual ~SimpleServer();

protected:
    void initialize(Application &self);
    void uninitialize();
    void defineOptions(OptionSet &options);
    void handleOption(const std::string &name, const std::string &value);
    void displayHelp();
    int main(const std::vector<std::string> &args);

private:
    bool helpRequested;
};

} // namespace apps
} // namespace server
} // namespace ezored
