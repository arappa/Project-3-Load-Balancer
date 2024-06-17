#ifndef SERVER_H
#define SERVER_H

#include <chrono>
#include <string>
#include "request.h"

/**
 * @class server
 * @brief A class representing a server that handles requests.
 */
class server {
    public:
        /**
         * @brief Constructs a server object with a given name.
         * @param server_name The name of the server.
         */
        server(std::string server_name);

        /**
         * @brief The ID of the server.
         */
        std::string ID;

        /**
         * @brief The current request being handled by the server.
         */
        request curr_req;

        /**
         * @brief The current wait time for the server.
         */
        int curr_wait;

        /**
         * @brief Handles a request at a given timestamp.
         * @param request The request to be handled.
         * @param ts The timestamp at which the request is handled.
         */
        void handle_req(request request, int ts);
};

#endif // SERVER_H
