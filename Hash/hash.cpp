#include <bits/stdc++.h>

using namespace std;

int main()
{
	map<int, int> a { {1,2}, {3,4}, {5,6}};
	for(auto i: a)
		printf("%d : %d\n", i.first, i.second);
	return 0;
}