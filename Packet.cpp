#include <bits/stdc++.h>
using namespace std;

struct process_address {
	long long port;
	long long ip;
};

class Packet {
	process_address src, port;
	long long src_mac, dest_mac;

	Packet(process_address _src,process_address _dest) {
		src = _src;
		dest = _dest;
	}

	void remove_packet() {
		
	}
}