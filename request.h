#ifndef REQUEST_H
#define REQUEST_H

#include <string>

class request{

    public:
        request();
        std::string ip_in;
        std::string ip_out;
        int time;

        std::string make_ip();
        int make_time();
};

#endif