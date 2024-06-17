#include <string>
#include <chrono>

#include "loadbalancer.h"
#include "requestqueue.h"
#include "server.h"
#include "request.h"
using namespace std;

server::server(std::string server_name) : ID(server_name) {}

void server::handle_req(request request,  int ts) {
    curr_wait = ts;
    curr_req = request;
}