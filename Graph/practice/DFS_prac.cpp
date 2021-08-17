#include <bits/stdc++.h>
#define MAX 100

using namespace std;

class EdgeNode
{
public:
	int y;
	int weight;
	EdgeNode* next;

	EdgeNode(int data, int wt, EdgeNode* next): y(data), weight(wt), next(next) {}
};

class Graph
{
public:
	int nVertice;
	int nEdges;

	EdgeNode* edges[MAX];
	int vertice[MAX];

	bool directed;

	static void initialize_graph(Graph*& g)
	{
		g->nVertice = 0;
		g->nEdges = 0;
		g->directed = false;

		for(auto& i: g->edges)
			i = nullptr;

		for(auto& j: g->vertice)
			j = 0;
	}

	static void insert_edge(Graph*& g, int x, int y, bool directed)
	{
		EdgeNode* edgeNode = new EdgeNode(y, 0, g->edges[x]);

		g->edges[x] = edgeNode;
		g->vertice[x]++;

		if(directed)
			g->nEdges++;
		else
			insert_edge(g, y, x, true);
	}

	static void read_graph(Graph*& g, bool directed)
	{
		int V, E;
		int x, y;
		initialize_graph(g);

		cin >> V >> E;

		g->nVertice = V;
		g->nEdges = E;
		g->directed = directed;

		for(int i = 0; i < E; i++)
		{
			cin >> x >> y;
			insert_edge(g, x, y, directed);
		}
	}

	static void print_graph(Graph*& g)
	{
		for(int i=0; i <= g->nVertice; i++)
		{
			EdgeNode* edgeNode = g->edges[i];
			printf("%d :", i);
			while(edgeNode != nullptr) 
			{
				printf(" %d", edgeNode->y);
				edgeNode = edgeNode->next;
			}
			printf("\n");
		}
	}

	static void dfs(Graph*& g, int vertex, bool visited[])
	{
		EdgeNode* edgeNode = g->edges[vertex];

		visited[vertex] = true;
		printf("%d ", vertex);
		
		while(edgeNode != nullptr) 
		{
			if(!visited[edgeNode->y]) 
				dfs(g, edgeNode->y, visited);
			edgeNode = edgeNode->next;
		}
	}
};

int main()
{
	bool visited[] = {};
	Graph* g = new Graph();

	Graph::read_graph(g, false);
	Graph::print_graph(g);
	printf("DFS : ");
	Graph::dfs(g, 1, visited);

	return 0;
}