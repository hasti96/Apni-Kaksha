#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
	int data;
	Node* left;
	Node* right;

	Node(int data): data(data), left(nullptr), right(nullptr) {}
	Node(int data, Node* left, Node* right): data(data), left(left), right(right) {}
};

void heapify(int arr[], int n, int i)
{
	int largest = i;
	int left = 2*i + 1;
	int right = 2*i + 2;

	if(left < n and arr[largest] < arr[left])
		largest = left;

	if(right < n and arr[largest] < arr[right])
		largest = right;

	if(largest != i)
	{
		swap(arr[largest], arr[i]);
		heapify(arr, n, largest);
	}
}

void heapSort(int arr[], int n)
{
	//build Heap
	for(int i = n/2 - 1; i >= 0; i--)
		heapify(arr, n , i);

	//do heap sort
	for(int i = n - 1; i >= 0; i--)
	{
		swap(arr[0], arr[i]);
		heapify(arr, i, 0);
	}

}

int main()
{
	int arr1[] = {10,56,78,4,1,3,65,78,19}; int n1= 9;

	heapSort(arr1, n1);

	for(auto i: arr1)
		printf("%d ", i);

	return 0;
}