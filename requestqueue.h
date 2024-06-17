#ifndef REQUESTQUEUE_H
#define REQUESTQUEUE_H

#include <iostream>
#include <string>
#include <queue>
#include "request.h"

/**
 * @class requestqueue
 * @brief A class representing a queue of requests.
 */
class requestqueue {
    public:
        /**
         * @brief Constructs an empty request queue.
         */
        requestqueue();

        /**
         * @brief A queue storing requests.
         */
        std::queue<request> requests;

        /**
         * @brief Adds a request to the queue.
         * @param req The request to be added.
         */
        void push_request(request req);

        /**
         * @brief Removes and returns the next request from the queue.
         * @return The next request in the queue.
         */
        request pop_request();

        /**
         * @brief Checks if the queue is empty.
         * @return True if the queue is empty, false otherwise.
         */
        bool is_empty();
};

#endif // REQUESTQUEUE_H
