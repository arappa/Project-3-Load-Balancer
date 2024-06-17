#ifndef REQUESTQUEUE_H
#define REQUESTQUEUE_H
#include <iostream>
#include <string>
#include <queue>
#include "request.h"

class requestqueue {
    public:
        requestqueue();
        std::queue<request> requests;
        void push_request(request req);
        request pop_request();
        bool is_empty();
};

#endif // REQUESTQUEUE_H