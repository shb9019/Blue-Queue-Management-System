#include <bits/stdc++.h>
#include <unistd.h>
#include "Packet.cpp"
#include "Router.cpp"
using namespace std;

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

	void sendPacket(int des_mac , int des_ip) {
		auto packet = new Packet(ip_address, des_ip, mac_address, des_mac);

        cout<<"Packet sent from "<<ip_address<<" to "<<des_ip;
        usleep((__useconds_t)transmission_time);

        send_count++;
        router->receive_packet(packet);
	}

	void receivePacket(Packet* p) {
		receive_count++;
		cout<<"Packet Received from "<<p->src<<" to "<<p->dest;
	}
};