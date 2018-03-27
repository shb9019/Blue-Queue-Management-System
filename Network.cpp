#include <bits/stdc++.h>
#include <mutex>
#include "Node.cpp"
#include "Router.cpp"
#include "Packet.cpp"
using namespace std;

class Network {
public:
    Router* router;
    CentralRouter* centralRouter;
    vector<Node*> nodes;
    mutex mtx;
    long long transmission_time;

    Network(Router* _router, CentralROuter* _centralRouter, long long _transmission_time) {
        router = _router;
        transmission_time = _transmission_time;
        centralRouter = _centralRouter;
    }

	void add_node (Node* node) {
        mtx.lock();
        nodes.push_back(node);
        mtx.unlock();
    }

    void sendPacket (Packet* packet) {
        auto same_network_index = find(nodes.begin(), nodes.end(), packet.dest);
        
        if (same_network_index == nodes.end()) {
            usleep(transmission_time);
            centralRouter->sendPacket(packet, router->ip_address);
        }
        
        else {
            long long index = same_network_index - nodes.begin();
            usleep(nodes[index]->transmission_time);
            nodes[index]->sendPacket(packet);
        }
    }
};