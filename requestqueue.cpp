#include <queue>
#include "requestqueue.h"
#include "loadbalancer.h"
#include "server.h"
#include "request.h"

using namespace std;

requestqueue::requestqueue() {}

void requestqueue::push_request(request req){
    requests.push(req);
}

request requestqueue::pop_request() {
    request req = requests.front();
    requests.pop();
    return req;
}

bool requestqueue::is_empty(){
    bool empty = requests.empty();
    return empty;
}
