#ifndef LOADBALANCER_H
#define LOADBALANCER_H
#include <queue>
#include <vector>
#include <chrono>
#include "requestqueue.h"
#include "server.h"


class Loadbalancer{

public:
    Loadbalancer(int running_time, int servers, int init_req);
    int runtime;
    int servers;
    int init_req;
    int cycle;

    requestqueue requests;

    std::queue<server> empty_servers;
    std::vector<server> web_servers;
    std::vector<server> handled_ser;
    std::vector<request> handled_req;
    std::vector<std::string> handled_times; 
    std::vector<server> start_webservers();
    requestqueue fill_requests();

    void initialize();
    void run();

    void assign_request();
    void server_sweep();
    bool is_ip_blocked(const std::string& ip);
};
#endif // LOADBALANCER_H