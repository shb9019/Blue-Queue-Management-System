#include <iostream>
using namespace std;

// we use red algorithm only for the central router..
// in this red implementation, let us maintain a queue of length (l_max);
// at any time let the size of queue length = (l_curr);
// we maintain a discrete time (t_d) during which all the packets are received and kept in the dynamic buffer, but not in the 
// regular queue used for central_router...
// we also maintain a buffer (Buffer_queue) to take all the packets during the time (t_d)..

// now we calculate (l_max - l_curr);
// only half of that will be used for filling the incoming packets...and other half of the queue is kept empty


// now calculate int x = buffer_size/((l_max - l_curr)/2)
// in the buffer we choose packets with the buffer[i] mod x == 0 and keep them in queue...all other are dropped

// after all this again the timer is set fro t_d...
// but most importantly based on queue length we set the delay in node's timing...



class Red_central_router
{
    public:
    	int mac_address;
    	int ip_address;
        int l_max;              // maximum length of queue
        int l_curr;             // current length of queue 
       	packet queue[l_max];    //instantiate  a inbuilt queue of max size size l_max;
        int t_dis;              // instantiate discrete time for filling the buffer

        Red_central_router(int mac,int ip,int l_size,int t_d )   // constructor
        {
        	mac_address = mac;
        	ip_address = ip;
        	l_max = l_size;
        	l_curr = 0;
        	t_dis = t_d;
        }

        //now implement methods..
        
        
}