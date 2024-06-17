#include <iostream>
#include <string>
#include "request.h"
#include "server.h"
#include "loadbalancer.h"
#include "requestqueue.h"

using std::cin, std::cout, std::string, std::endl, std::to_string;

int main() {

    int servers;
    int runtime;
    string input;

    cout << "Enter the number of servers: ";

    getline(cin, input);
    servers = stoi(input);

    cout << "Enter the amount of time to run the load balancer: ";

    getline(cin, input);
    runtime = stoi(input);

    Loadbalancer lb(runtime, servers, servers * 5);

    cout << "Starting queue size: " << to_string(servers * 5) << "\n";
    cout << "Ending queue size: 0" << "\n";
    cout << "Range for request time: 3-16 clock cycles\n";
    cout << "-------- Load Balancer Log ---------\n";

    lb.initialize();
    lb.run();

    cout << "---- FINISHED ----\n" << endl;

    for(int i = 0; i < (int)lb.handled_req.size(); i++) {
        cout << "At " << lb.handled_times[i] << " " << lb.handled_ser[i].ID << " processed request from " << lb.handled_req[i].ip_in << " to " << lb.handled_req[i].ip_out << endl;
    }
}