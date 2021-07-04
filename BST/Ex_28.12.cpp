/* 
	Set & Multiset | Standard Template Library | C++ Placement Course | Lecture 28.12
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
	set<int, greater<int>> s;
	s.insert(1); s.insert(2);s.insert(3);
	for(auto i: s)
		cout<< i;

	printf("\n--------------\n");
//==================================================
	multiset<int> m_s = {};

	m_s.insert(1); m_s.insert(2);m_s.insert(3);
	m_s.insert(3);m_s.insert(3);m_s.insert(3);

	for(auto i: m_s)
		printf("%d", i);
	printf("\n-----------------\n");

	m_s.erase(m_s.find(3));

	for(auto i: m_s)
		printf("%d", i);
	printf("\n-----------------\n");
//======================================================

	
	return 0;
}