#include<iostream>
using namespace std;

class packet
{
	int source_mac;
	int source_ip;
	int destination_mac;
	int destination_ip;

	void change_source()
	{
		source_mac = mac_address; // mac_address of router
	}
	void change_destination()
	{
		destination_mac = nextRoutermac();
	}
	
}