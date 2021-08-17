#include <bits/stdc++.h>
#define MAX 100

using namespace std;


class EdgeNode
{
public:
	int y;
	int weight;
	EdgeNode* next;

	EdgeNode(): y(0), weight(0), next(nullptr) {};
	EdgeNode(int data, int weight, EdgeNode* next): y(data), weight(weight), next(next) {};
};

class Graph
{
public:
	EdgeNode* edges[MAX];
	int degree[MAX];
	bool directed;

	int nVertices;
	int nEdges;

	Graph(): nEdges(0), nVertices(0), directed(false) {};

	Graph(int vertices, int edges): nVertices(nVertices), nEdges(edges) {};

	static void initialize_graph(Graph*& g, bool directed) 
	{	
		g->nEdges = 0;
		g->nVertices = 0;
		g->directed = directed;

		for(int i=0; i<=MAX; i++)
			g->edges[i] = nullptr;

		for(int i=0; i<= MAX; i++)
			g->degree[i] = 0;
	}

	static void insert_edge(Graph*& g, int x, int y, bool directed)
	{
		g->degree[x]++;

		EdgeNode* edge = new EdgeNode(y, 0, g->edges[x]);

		g->edges[x] = edge;

		if(directed)
			g->nEdges++;
		else
			insert_edge(g, y, x, true);

	}

	static void read_graph(Graph*& g, bool directed)
	{
		int m = 0;
		int x, y;

		initialize_graph(g, directed);

		cin>> g->nVertices;
		cin>> m;

		for(int i = 0; i<m; i++)
		{
			cin >> x;
			cin >> y;
			insert_edge(g, x, y, directed); 
		}
	}

	static void print_graph(Graph*& g)
	{
		EdgeNode* node = nullptr;

		for(int i=1; i <= g->nVertices; i++)
		{
			printf("%d : ", i);
			node = g->edges[i];

			while(node != nullptr)
			{
				printf("%d ", node->y);
				node = node->next;
			}
			printf("\n");
		}
	}

	static void dfs(Graph* g, int vertice, bool visited[])
	{
		visited[vertice] = true;
		EdgeNode* node = g->edges[vertice];

		printf("%d ", vertice);

		while(node != nullptr)
		{
			if(!visited[node->y])
				dfs(g, node->y, visited);
			node = node->next;
		}
	}
};

int main()
{
	bool visited[MAX] = {};
	Graph* g = new Graph(4, 4);

	Graph::read_graph(g, false);
	Graph::print_graph(g);
	printf("DFS : ");
	Graph::dfs(g, 0, visited);

	return 0;
}