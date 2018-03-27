#include <bits/stdc++.h>
#include <mutex>
#include <unistd.h>
#include "Packet.cpp"
using namespace std;

class CentralRouter;
class Router;

class Node {
public:
    long long mac_address;
    long long ip_address;
    Router* router;
    long long transmission_time;

    int send_count    = 0;
    int receive_count = 0;

    Node(long long _mac_address, long long _ip_address, Router* _router, long long _transmission_time) {
        mac_address = _mac_address;
        ip_address = _ip_address;
        router = _router;
        transmission_time = _transmission_time;
    }

    void sendPacket(Packet* packet);

    void receivePacket(Packet* p) {
        receive_count++;
        cout<<"Packet Received from "<<p->src<<" to "<<p->dest;
    }
};

class Router
{
public:
	long long mac_address;
	long long ip_address;
    long long packets_received, packets_processed, packets_dropped;
    CentralRouter* central_router;
    vector<Node*> nodes;
	queue<Packet*> q;
    mutex mtx;
	int queue_length;
    long long transmission_time;

    Router (long long _mac_address, long long _ip_address, long long _transmission_time, CentralRouter* _central_router) {
        mac_address = _mac_address;
        ip_address = _ip_address;
        packets_received = 0;
        packets_dropped = 0;
        packets_processed = 0;
        queue_length = 10;
        transmission_time = _transmission_time;
        central_router = _central_router;
    }

    void add_node (Node* node) {
        mtx.lock();
        nodes.push_back(node);
        mtx.unlock();
    }

    void processQueue() {
    	while(true) {
            usleep(20);
            if (q.size() != 0) {
                mtx.lock();
                Packet* packet = q.front();
                q.pop();
                mtx.unlock();
                async(&Router::sendPacket, this, packet);
            }
        }
    }

    void receivePacket(Packet* packet) {
        mtx.lock();
        packets_received++;
        if (q.size() >= queue_length) {
            cout<<"Packet Tail Dropped due to full queue length"<<endl;
            packets_dropped++;
            return;
        }
        else {
            packets_processed++;
            cout<<"Packet received at "<<packet->dest<<" from "<<packet->src<<endl;
            q.push(packet);
        }
        mtx.unlock();
    }

    void sendPacket (Packet* packet);
};

class CentralRouter {
public:
    Router *routerA, *routerB;

    CentralRouter (Router *_routerA, Router *_routerB) {
        routerA = _routerA;
        routerB = _routerB;
    }

    void sendPacket(Packet* packet, long long dest_ip_address);
};

void CentralRouter::sendPacket(Packet* packet, long long dest_ip_address) {
    if (routerA->ip_address == dest_ip_address) {
        usleep(routerA->transmission_time);
        routerA->sendPacket(packet);
    }
    else {
        usleep(routerB->transmission_time);
        routerB->sendPacket(packet);
    }
}


void Node::sendPacket(Packet* packet) {
    cout<<"Packet sent from "<<packet->src<<" to "<<packet->dest;
    usleep((__useconds_t)transmission_time);

    send_count++;
    router->receivePacket(packet);
}

void Router::sendPacket (Packet* packet) {
    long long same_network_index = -1;
    for (auto i=0; i<nodes.size(); i++) {
        if (nodes[i]->ip_address == packet->dest) {
            same_network_index = i;
            break;
        }
    }
    if (same_network_index == -1) {
        usleep(transmission_time);
        central_router->sendPacket(packet, packet->dest);
    }   
        
    else {
        long long index = same_network_index;
        usleep(nodes[index]->transmission_time);
        nodes[index]->sendPacket(packet);
    }
}
