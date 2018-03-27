#include <bits/stdc++.h>
#include <mutex>
#include "Network.cpp"
#include "Packet.cpp"
using namespace std;

class Router
{
	long long mac_address;
	long long ip_address;
    long long packets_received, packets_processed, packets_dropped;
	Network* network;
	queue<Packet*> q;
    mutex mtx;
	int queue_length;

    Router(long long _mac_address, long long _ip_address, Network* _network) {
        mac_address = _mac_address;
        ip_address = _ip_address;
        network = _network;
        packets_received = 0;
        packets_dropped = 0;
        packets_processed = 0;
        queue = NULL;
        queue_length = 10;
    }

    void receivePacket(Packet packet) {
        mtx.lock();
        packets_received++;
        if (q.length >= queue_length) {
            cout<<"Packet Tail Dropped due to full queue length"<<endl;
            packets_dropped++;
            return;
        }
        else {
            packets_processed++;
            cout<<"Packet received at "<<packet->dest<<" from "<<packet-<src<<endl;
            queue.push_back(q);
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
                async(network->sendPacket, packet);
            }
        }
    }
}

