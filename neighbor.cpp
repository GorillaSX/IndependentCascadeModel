//implement a neighbor
//Neighbor class
//constructor
#include "neighbor.h"
Neighbor::Neighbor(int name,double weight/* = 0.0*/):m_name(name),m_weight(weight){}
//get neighbor name
int Neighbor::getName(void)const
{
	return m_name;
}
//get neighbor weight
double Neighbor::getWeight(void)const
{
	return m_weight;
}
//set neightbor weight
void Neighbor::setWeight(double weight)
{
	m_weight = weight;
}
//overload operator <
bool Neighbor::operator<(const Neighbor& r)const
{
	return this->m_name < r.m_name;
}
