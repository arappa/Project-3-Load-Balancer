#ifndef SERVER_H
#define SERVER_H

#include <chrono>
#include <string>
#include "request.h"

class server {
    public:
        server(std::string server_name);
        std::string ID;
        request curr_req;
        int curr_wait;
        void handle_req(request request, int ts);
};

#endif //SERVER_H