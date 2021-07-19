#include <bits/stdc++.h>

using namespace std;

class Pair
{
public:
	int data;
	int arrayNo;
	int index;

	Pair(): data(0), arrayNo(0), index(0) {}
	Pair(int data, int arrayNo, int index): data(data), arrayNo(arrayNo), index(index) {}

	constexpr bool operator > (const Pair &inputPair) const 
	{
	    return data > inputPair.data; // assumes that the implementation uses a flat address space
	}

	constexpr bool operator < (const Pair &inputPair) const 
	{
	    return data < inputPair.data; // assumes that the implementation uses a flat address space
	}
};

vector<int> MergeKSortedArray(const vector<vector<int>>& input)
{
	vector<int> ans = {};
	priority_queue<Pair, vector<Pair> ,greater<vector<Pair>::value_type>> pqmin;

	vector<int> idxArray(input.size());
	
	for(int i = 0; i < input.size(); i++)
	{
		pqmin.push(Pair(input[i][0], i, 1));
		idxArray[i]++;
	}

	while(!pqmin.empty()) 
	{
		Pair pair = pqmin.top(); 
		
		ans.push_back(pair.data);
		pqmin.pop();
		
		if(pair.index < input[pair.arrayNo].size())
		{
			pqmin.push(Pair(input[pair.arrayNo][pair.index], pair.arrayNo, pair.index+1));
		}
	}

	return ans;
}

int main(int argc, char const *argv[])
{
	vector<vector<int>> v = {{1,5,8,9,20}, {3,4,5,6,12,18,19}, {6,9,13,16,29,47,69,99}};

	printf("[");
	for(auto i:MergeKSortedArray(v))
		printf("%d ", i);

	printf("]\n");

	return 0;
}