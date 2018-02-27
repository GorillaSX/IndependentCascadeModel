//declare a neighbor
#ifndef _NEIGHBOR_H
#define _NEIGHBOR_H
//Neighbor class
class Neighbor
{
	public:
		//constructor
		Neighbor(int name,double weight = 0.0); 
		//get neighbor name
		int getName(void)const;
		//get neighbor weight
		double getWeight(void)const;
		//set neightbor weight
		void setWeight(double weight);
		//overload operator <
		bool operator<(const Neighbor& r)const;
	private:
		int m_name;
		double m_weight;
};
#endif //_NEIGHBOR_H
