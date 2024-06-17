#include <string>
#include <chrono>
#include <thread>
#include <cstdlib>
#include <time.h>
#include "requestqueue.h"
#include "loadbalancer.h"
#include "server.h"
#include "request.h"

using namespace std;

request::request() {
    ip_in = make_ip();
    ip_out = make_ip();
    time = make_time();
}

string request::make_ip() {
    string create_ip_address = "";
    int add_octects[4]= {0, 0, 0, 0};
    int rand_seed = (rand()%1000);
    int min = 0;
    int max = 256;


    srand(rand_seed);
    
    for(int i = 0; i < 4; i++) {
        if(i == 0) {
            min = 1;
            max = 127;
        } 

        else if (i == 3) {
            min = 1;
            max = 255;
        }

        add_octects[i] = min + (rand() % max);
        create_ip_address += to_string(add_octects[i]);
        if(i != 3) {
            create_ip_address += ".";
        }
    }
    return create_ip_address;
}

int request::make_time() {
    int rand_seed = (rand() % 1000);
    srand(rand_seed);
    int time = rand() % 3;
    return time;
}