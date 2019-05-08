#include "ezored/server/apps/SimpleServer.hpp"

using namespace ezored::server::apps;

int main(int argc, char **argv)
{
    SimpleServer app;
    return app.run(argc, argv);
}
