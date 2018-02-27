//implement a community class
//constructor
#include "community.h"
#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "random.h"
using namespace std;
Community::Community(){};
Community::Community(int maxNode,int minNeighbors,int maxNeighbors):m_maxNode(maxNode),m_minNeighbors(minNeighbors),m_maxNeighbors(maxNeighbors)
{
	for(int i = 0;i < maxNode;i++)
	{
		Node node(i,minNeighbors,maxNeighbors);
		m_inactiveNodes.insert(node);
	}
}
//init community connect each nodes
void Community::initCommunity(void)
{
	cout << "finish init Community" << endl;
	for(set<Node>::iterator it = m_inactiveNodes.begin(); 
					it != m_inactiveNodes.end(); ++it)
	{
		const_cast<Node&>(*it).initNeighbor(m_inactiveNodes);
	}
	for(set<Node>::iterator it = m_inactiveNodes.begin(); 
					it != m_inactiveNodes.end(); ++it)
	{
		const_cast<Node&>(*it).setNeighborsWeight();
	}
	cout << "end init Community" << endl;
}
//set a number of active node
void Community::activeNodes(int numNode)
{
	cout << "start active Nodes" << endl;
	for(int i = 0;i < numNode;++i)
	{
		while(1)
		{
				int nodename = random(0,m_maxNode-1);	
				Node activenode(nodename);
				set<Node>::iterator it;
				it = m_inactiveNodes.find(activenode);
				if(it != m_inactiveNodes.end())
				{
					Node n = const_cast<Node&>(*it);
					n.updateTendency(1.00);		
					n.activeNode();
					m_activeNodes.insert(n);
					m_inactiveNodes.erase(it);
					break;
				}
		}
	}
	cout << "finish active nodes" << endl;
}
//start diffusion
void Community::startDiffusion(void)
{
	cout << "start diffusion " << endl;
	for(set<Node>::iterator it = m_activeNodes.begin(); it != m_activeNodes.end();++it)
	{
		const_cast<Node&>(*it).affectNeighbor(m_inactiveNodes);
	}
	int num = 0;
	while(1)
	{
		num++;
		cout << "step " << num << endl;
		vector<Node> activeNodes;
		for(set<Node>::iterator it = m_inactiveNodes.begin();it != m_inactiveNodes.end();)
		{
			if(it->isActive() == true)
			{
				activeNodes.push_back(*it);
				m_inactiveNodes.erase(it++);
			}
			else
				it++;
		}
		if(activeNodes.size() != 0)
		{
			for(vector<Node>::iterator it = activeNodes.begin();it != activeNodes.end();++it)
			{
				it->affectNeighbor(m_inactiveNodes);
				m_activeNodes.insert(*it);
			}
			activeNodes.clear();
		}
		else
		{
			break;
		}	
	}
	cout << "end diffusion" << endl;
}
//active Node
void Community::displayActiveNode(void)
{
	cout << "Total Active Node: " << m_activeNodes.size() << endl;
/*	for(set<Node>::iterator it = m_activeNodes.begin();it!=m_activeNodes.end();++it)
	{
		it->print();
	}*/
}
//display inactive Node
void Community::displayInactiveNode(void)
{		
	cout << "Total Inactive Node: " << m_inactiveNodes.size() << endl;
/*	for(set<Node>::iterator it = m_inactiveNodes.begin();it!=m_inactiveNodes.end();++it)
	{
		it->print();
	}*/
}
		
