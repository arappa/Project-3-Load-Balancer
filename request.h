#ifndef REQUEST_H
#define REQUEST_H

#include <string>

/**
 * @class request
 * @brief A class representing a network request.
 */
class request {
    public:
        /**
         * @brief Constructs a request object.
         */
        request();

        /**
         * @brief The incoming IP address for the request.
         */
        std::string ip_in;

        /**
         * @brief The outgoing IP address for the request.
         */
        std::string ip_out;

        /**
         * @brief The time associated with the request.
         */
        int time;

        /**
         * @brief Generates and returns the IP address for the request.
         * @return The IP address as a string.
         */
        std::string make_ip();

        /**
         * @brief Generates and returns the time for the request.
         * @return The time as an integer.
         */
        int make_time();
};

#endif // REQUEST_H
