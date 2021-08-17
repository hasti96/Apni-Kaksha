#include <bits/stdc++.h>

using namespace std;

int main()
{
	int V;
	int E;
	int x, y;

	cin >> V >> E;

	int row = V+1;
	int col = V+1;

	int arr[row][col];

	for(int i = 0; i < row; i++)
	{
		for(int j=0; j < col; j++)
		{
			arr[i][j] = 0;
		}
	}
	
	for(int i=0; i < E; i++)
	{
		cin >> x >> y;
		arr[x][y] = 1;
		arr[y][x] = 1;
	}

	for(int i = 0; i < row; i++)
	{
		for(int j=0; j < col; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}

	return 0;
}