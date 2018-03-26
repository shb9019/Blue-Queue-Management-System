#include<iostream>
using namespace std;

class Router
{
	int mac_address;
	int ip_address;

	packet queue q;
	int queue_length = 10;
	// sai defines queue using inbuilt queues only

    //now define functions for checking the packets inside the queue

    void sendpacket_to_centralrouter(packet p, int ip1)
    {
       //add this packet p to central router queue...
       //also check for overflow in queue...
       delay();
       cout<<"the packet is sent from this node"<<p.source_ip<<" to "<<ip1<<"the intremediate path is from"<<p.source_mac<<" to "
       <<"central router"<<endl;

    }

    int search_table(int ip1,int ip)
    {
    	for(int i=0;i<n;i++)
    	{
    		if(node[i].ip_address == ip1 && node[i].router_address == ip )
    		{
    			return i;
    		}
    	}
    	return -1;
    }

    void checkpackets()
    {
    	if ( queue is empty)
    	{
    		do nothing
    	}
    	else
    	{
    		packet p = remove packet from top of the queue;
    		int ip1 = p.destination_ip;

    		
    	    int i = search_table(ip1,ip_address);
    	    if(i==-1) // not there in routing table
    	    {
               sendpacket_to_centralrouter(p,ip1);    
    	    }
    	    else
    	    {
    	    	node[i].receivepacket(p);
    	    }
    	
    	}
    }


}

