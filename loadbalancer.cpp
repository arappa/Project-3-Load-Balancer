#include <ostream>
#include <iostream>
#include <vector> 
#include <chrono>
#include <ctime>
#include "loadbalancer.h"
#include "requestqueue.h"
#include "server.h"
#include "request.h"

using namespace std;

Loadbalancer::Loadbalancer(int running_time, int servers, int init_req) : runtime(running_time), servers(servers), init_req(init_req){}

std::vector<server> Loadbalancer::start_webservers(){
    std::vector<server> webserver_list;

    cout << "New servers created: ";
    for(int i = 0; i < servers; i++) {
        server new_server("Server " + to_string(i));
        cout << "Server " << to_string(i);
        if(i != servers-1) 
            cout << ", ";

        webserver_list.push_back(new_server);
        empty_servers.push(new_server);
    }

    cout << "\n";
    return webserver_list;
}

requestqueue Loadbalancer::fill_requests() {
    requestqueue req;

    for(int i = 0; i < init_req; i++) 
    {
        request new_request;
        cout << "New Request from " << new_request.ip_in << " to " << new_request.ip_out << " in " << new_request.time << "Clock Cycles" << endl;
        req.push_request(new_request);
    }
    cout << "Queue has been filled with " << to_string(init_req) << " requests." << endl;
    return req;
}

void Loadbalancer::assign_request() {
        server current_server = empty_servers.front();
        empty_servers.pop();
        request current_request = requests.pop_request();
        int current_timestamp = cycle;
        current_server.handle_req(current_request, current_timestamp);
}

void Loadbalancer::server_sweep() {
    int request_time;
    int request_duration;

    for(int i = 0; i < servers; i++) 
    {
        server current_server = web_servers[i];
        request_time = current_server.curr_req.time;
        request_duration = cycle - current_server.curr_wait;

        if(request_duration >= request_time)
        {
            handled_req.push_back(current_server.curr_req);
            std::string handled_time = to_string(request_duration);
            handled_times.push_back(handled_time);
            empty_servers.push(current_server);
        }
    }
}

void Loadbalancer::initialize(){
    web_servers = start_webservers();
    requests = fill_requests();
}

void Loadbalancer::run() {
    cycle= 0;
    while(cycle < runtime && !requests.is_empty()) {
        cycle += 1;
        if(!requests.is_empty() && empty_servers.empty()) 
            server_sweep();
        while(!empty_servers.empty() && !requests.is_empty())
            assign_request();
    }
}