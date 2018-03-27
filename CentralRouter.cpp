#include <bits/stdc++.h>
using namespace std;

class CentralRouter {
public:
	Router* routerA, routerB;

	CentralRouter (Router* _routerA, router* _routerB) {
		routerA = _routerA;
		routerB = _routerB;
	}

	void sendPacket(Packet* packet, long long dest_ip_address) {
        if (routerA->ip_adress == dest_ip_address) {
            usleep(routerA->transmission_time);
            routerA->sendPacket(packet);
        }
        else {
            usleep(routerB->transmission_time);
            routerB->sendPacket(packet);
        }
    }	
};