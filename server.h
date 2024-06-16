#ifndef SERVER_H
#define SERVER_H

#include <chrono>
#include <string>
#include "request.h"

class Server{
    public:
        Server::server(string serverName);
        request cur_req;
        string ID;
        int wait;

        void handle_req(request request, int time);
}

#endif //SERVER_H