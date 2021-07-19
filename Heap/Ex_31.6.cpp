/*
	Heap -Smallest Sequence with sum K | C++ Placement Course | Lecture 31.6
*/
#include <bits/stdc++.h>

using namespace std;

int findSmallestSubSeq(vector<int> arr, int sum)
{
	int count = 0;
	int m_sum = 0;

	priority_queue<int> pqmax = {};

	for(auto i: arr)
		pqmax.push(i);

	while(m_sum < sum and !pqmax.empty())
	{
		m_sum += pqmax.top();
		count++;
		pqmax.pop();
	}
	return count;
}

int main()
{

	vector<int> arr = {8,3,0,1,1};
	cout << findSmallestSubSeq(arr, 12) << endl;

	return 0; 
}