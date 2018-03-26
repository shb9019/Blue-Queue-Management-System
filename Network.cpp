#include <bits/stdc++.h>
#include <mutex>
#include "Node.cpp"
#include "Packet.cpp"
using namespace std;

class Network {
    long long base_ip;
    long long mask;
    mutex mtx;
	vector<Node> nodes;
	vector<Packet> packets;

	void add_node (Node node) {
        mtx.lock();
        nodes.push_back(node);
        mtx.unlock();
    }

    void add_packet (Packet packet) {
        mtx.lock();
        packets.push_back(packet);
        mtx.unlock();
    }

    void remove_packet (Packet packet) {
        mtx.lock();
        packets.erase(remove(packets.begin(), packets.end(), packet), packets.end());
        mtx.unlock();
    }
};