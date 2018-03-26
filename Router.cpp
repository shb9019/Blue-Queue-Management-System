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

    		if ( ip1 == this->ip_address)        // this case implies we need to send to one of the nodes in this network only
    		{
    			
    		}
    		else                                 //this case implies send to central router
    		{

    		}
    	}
    }
}