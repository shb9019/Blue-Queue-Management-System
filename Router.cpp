#include <bits/stdc++.h>
#include <mutex>
#include <unistd.h>
#include "Node.cpp"
#include "CentralRouter.cpp"
using namespace std;

class Router
{
	long long mac_address;
	long long ip_address;
    long long packets_received, packets_processed, packets_dropped;
    vector<Node*> nodes;
	queue<Packet*> q;
    mutex mtx;
	int queue_length;

    Router (long long _mac_address, long long _ip_address) {
        mac_address = _mac_address;
        ip_address = _ip_address;
        packets_received = 0;
        packets_dropped = 0;
        packets_processed = 0;
        queue_length = 10;
    }

    void add_node (Node* node) {
        mtx.lock();
        nodes.push_back(node);
        mtx.unlock();
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

    void sendPacket (Packet* packet) {
        auto same_network_index = find(nodes.begin(), nodes.end(), packet->dest);
        
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
