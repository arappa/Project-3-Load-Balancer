#ifndef LOADBALANCER_H
#define LOADBALANCER_H

#include <queue>
#include <vector>
#include <chrono>
#include "requestqueue.h"
#include "server.h"

/**
 * @class Loadbalancer
 * @brief A class representing a load balancer for managing server requests.
 */
class Loadbalancer {
public:
    /**
     * @brief Constructs a Loadbalancer object.
     * @param running_time The running time for the load balancer.
     * @param servers The number of servers managed by the load balancer.
     * @param init_req The initial number of requests.
     */
    Loadbalancer(int running_time, int servers, int init_req);

    /**
     * @brief The runtime for the load balancer.
     */
    int runtime;

    /**
     * @brief The number of servers managed by the load balancer.
     */
    int servers;

    /**
     * @brief The initial number of requests.
     */
    int init_req;

    /**
     * @brief The current cycle of the load balancer.
     */
    int cycle;

    /**
     * @brief The queue of requests to be handled.
     */
    requestqueue requests;

    /**
     * @brief A queue of empty servers available to handle requests.
     */
    std::queue<server> empty_servers;

    /**
     * @brief A vector of all web servers managed by the load balancer.
     */
    std::vector<server> web_servers;

    /**
     * @brief A vector of servers that have handled requests.
     */
    std::vector<server> handled_ser;

    /**
     * @brief A vector of requests that have been handled.
     */
    std::vector<request> handled_req;

    /**
     * @brief A vector of times when requests were handled.
     */
    std::vector<std::string> handled_times;

    /**
     * @brief Starts the web servers and returns them as a vector.
     * @return A vector of started web servers.
     */
    std::vector<server> start_webservers();

    /**
     * @brief Fills the request queue and returns it.
     * @return A filled request queue.
     */
    requestqueue fill_requests();

    /**
     * @brief Initializes the load balancer.
     */
    void initialize();

    /**
     * @brief Runs the load balancer.
     */
    void run();

    /**
     * @brief Assigns requests to available servers.
     */
    void assign_request();

    /**
     * @brief Performs a sweep of the servers to check their status.
     */
    void server_sweep();

    /**
     * @brief Checks if an IP address is blocked.
     * @param ip The IP address to check.
     * @return True if the IP is blocked, false otherwise.
     */
    bool is_ip_blocked(const std::string& ip);
};

#endif // LOADBALANCER_H
