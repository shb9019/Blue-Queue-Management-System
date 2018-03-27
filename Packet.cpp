#include <bits/stdc++.h>
using namespace std;

class Packet {
public:
	long long src, dest;
	long long src_mac, dest_mac;
	long long size;

	Packet(long long _src,long long _dest, long long _src_mac, long long _dest_mac, long long _size = 1024) {
		src = _src;
		dest = _dest;
        src_mac = _src_mac;
        dest_mac = _dest_mac;
        size = _size;
	}

	void change_src_mac(long long _src_mac) {
		src_mac = _src_mac;
	}

	void change_dest_mac(long long _dest_mac) {
		dest_mac = _dest_mac;
	}
};
