#include <bits/stdc++.h>

using namespace std;

class MedianStream
{
public:
	priority_queue<int , vector<int>, greater<int>> pqmin;
	priority_queue<int , vector<int>> pqmax;

	MedianStream() {
		pqmax = {};
		pqmin = {};
	}

	void insert(int data)
	{
		if(pqmax.size() == pqmax.size())
		{
			if(pqmax.size() == 0)
			{
				pqmax.push(data);
				return;
			}

			if(data < pqmax.top())
				pqmax.push(data);
			else
				pqmin.push(data);
		}
		else
		{
			if(pqmax.size() > pqmin.size())
			{
				if(data > pqmax.top())
					pqmin.push(data);
				else
				{
					int tmp = pqmax.top();
					pqmax.pop();
					pqmax.push(data);
					pqmin.push(tmp);
				}
			}
			else
			{
				if(data > pqmin.top())
				{
					pqmax.push(pqmin.top()); pqmin.pop();
					pqmin.push(data);
				}
				else
				{
					pqmax.push(data);
				}
			}
		}
	}

	double findMedian()
	{
		if(pqmax.size() == pqmin.size())
			return (pqmax.top() + pqmin.top()) / 2.0;
		else
			return pqmax.size() > pqmin.size() ? pqmax.top() : pqmin.top();
	}
};

int main()
{
	MedianStream obj;
	obj.insert(1);obj.insert(5);obj.insert(10);
	cout<< obj.findMedian() << endl;
	return 0;
}