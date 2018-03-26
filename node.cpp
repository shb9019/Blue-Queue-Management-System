#include<iostream>
using namespace std;

class Node
{
	int mac_address;
	int ip_address;
	int router_address;

	 int sendcount = 0;
	 int receivecount = 0;



	void sendpacket(int des_mac , int des_ip)
	{
		packet p = new packet();
		p.source_mac = this->mac_address;
		p.source_ip  = this->ip_address;
		p.destination_mac = des_mac;      //include router / final  destination mac??
		p.destination_ip  = des_ip;

		delay();
		//now add the packet to the router queue which is of packets type
		//we maintain a circular queue for router
        sendcount++;
		cout<<"packet with source address "<<source_ip<<" is sent to "<<destination_ip<<endl;

		//now check whether queue is full or not
		if ( queue is full )
		{
			cout<<"this packet is dropped"<<endl;
		}
		else
		{
			add this packet to the queue;
            cout<<"packet successfully reached the router"<<endl;
		}
	}


    //now packets need to be reached to this node
}