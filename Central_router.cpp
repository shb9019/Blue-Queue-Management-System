#include<iostream>
using namespace std;

class Central_router
{
	int ip_address;
	int mac_address;
	packet queue q;
	int queue_length = 10;
	//sai defines all the built in queues 

	//now check for packets in the queue
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
            //now add this packet to top of the destination router
    	    
    	    if ( ip1 == router[0])
    	    {
    	    	//add this packet to the router[0] queue;
    	    	delay();
                cout<<"the packet is being moved from central router to "<<router[0].ip_address<<endl;
    	    }

    	    if ( ip1 == router[1])
    	    {
    	    	//add this packet to the router[1] queue;
    	    	delay();
                cout<<"the packet is being moved from central router to "<<router[1].ip_address<<endl;
    	    }
    	}
	}
}