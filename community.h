//declare a community class
#ifndef __COMMUNITY_H
#define __COMMUNITY_H
#include <set>
#include "node.h"
//a class of a community
class Community
{
	public:
		//constructor
		Community();
		Community(int maxNode,int minNeighbors,int maxNeighbors);
		//init community
		void initCommunity(void);
		//set a number of active node
		void activeNodes(int numNode);
		//start diffusion
		void startDiffusion(void);
		//active Node
		void displayActiveNode(void);
		//display inactive Node
		void displayInactiveNode(void);
		
	private:
		int m_maxNode;
		int m_minNeighbors;
		int m_maxNeighbors;
		set<Node> m_inactiveNodes; 
		set<Node> m_activeNodes;
};
#endif //__COMMUNITY_H
