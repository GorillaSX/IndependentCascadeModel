#include <iostream>
#include "community.h"
#include "neighbor.h"
#include "node.h"
#include <ctime>
#include <cstdlib>
using namespace std;

int main(int argc,char* argv[])
{
	srand(unsigned(time(NULL)));
	Community com;
	if(argc == 1)
		com = Community(1000,10,50);
	else if(argc == 4)
	{
		int maxNode = atoi(argv[1]);
		int minNeig = atoi(argv[2]);
		int maxNeig = atoi(argv[3]);
		com = Community(maxNode,minNeig,maxNeig);
	}
	else
	{
		cout << "Usage: ./diffuse [MaxNode MinNeighbor MaxNeighbor]" << endl;
		return 0;
	}
	com.initCommunity();
	com.activeNodes(5);
	com.startDiffusion();
	com.displayActiveNode();
	com.displayInactiveNode();
	return 0;
}
