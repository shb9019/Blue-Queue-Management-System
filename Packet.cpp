#include <bits/stdc++.h>
using namespace std;

struct process_address {
	long long port;
	long long ip;
};

class Packet {
	process_address src, dest;
	long long src_mac, dest_mac;
	long long size;

	Packet(process_address _src,process_address _dest) {
		src = _src;
		dest = _dest;
	}

	void change_src_mac(long long _src_mac) {
		src_mac = _src_mac;
	}

	void change_dest_mac(long long _dest_mac) {
		dest_mac = _dest_mac;
	}
};
