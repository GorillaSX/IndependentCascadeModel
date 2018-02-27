//declare a node class
#ifndef _NODE_H
#define _NODE_H
#include <iostream>
#include <set>
using namespace std;
#include "neighbor.h"
//Node class
class Node
{
	public:
		//constructor
		Node(int name,int min,int max);
		Node(int name);
		//get node name
		int getName(void)const;
		//get node threshold
		double getThreshold(void)const;
		//get the number of the node
		int getNumOfNeighbor(void)const;
		//get the node tendency
		double getTendency(void)const;
		//get the node status
		bool isActive(void)const;
		//active node
		void activeNode(void);
		//inactive node
		void inActiveNode(void);
		//get the probability the node not been active by the active node
		double getNotActiveProb(void)const;
		//set the probability, the node tried but failed 
		void setNotActiveProb(double prob);
		//update node tendency
		void updateTendency(double weight);
		//add a neightbor
		void addNeighbor(Neighbor& neighbor);
		//get a neighbor weight
		double getNeighborWeight(Neighbor& neighbor)const;
		//get neighbor current size
		int getNeighborsSize(void)const;
		//print Node information
		void print(void)const;	
		//initializing node neighbors
		void initNeighbor(set<Node>& nodes);
		//set neighbors weight
		void setNeighborsWeight(void);
		//when node active affect node neighbor
		void affectNeighbor(set<Node>& nodes);
		//overload operator < 
		bool operator < (const Node& r)const;

	private:
		int m_name;
		double m_threshold;
		int m_numOfNeighbor;
		set<Neighbor> m_neighbors;
		double m_tendency;
		bool m_active;
		double m_notActiveProb;
};
#endif //_NODE_H
