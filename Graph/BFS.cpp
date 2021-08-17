#include <bits/stdc++.h>
#define MAX 1000

using namespace std;

class EdgeNode
{
public:

	int y;
	int weight;
	EdgeNode* next;

	EdgeNode(): y(0), weight(0), next(nullptr) {};
	EdgeNode(int vertice, int wt, EdgeNode* node): y(vertice), weight(wt), next(node) {} 
};

class Graph
{
public:
	EdgeNode* edges[MAX];
	int degree[MAX];

	int nEdges;
	int nVertices;
	bool directed;

	Graph(){};
	Graph(int vertices, int edges): nVertices(vertices), nEdges(edges) {};

	static void initialize_graph(Graph*& g, bool directed)
	{
		g->nEdges = 0;
		g->nVertices = 0;
		g->directed = false;

		for(int i=0; i <= MAX; i++)
			g->edges[i] = nullptr;

		for(int i=0; i <= MAX; i++)
			g->degree[i] = 0;
	}

	static void insert_edge(Graph*& g, int x, int y, bool directed)
	{
		g->degree[x]++;

		EdgeNode* node = new EdgeNode(y, 0, g->edges[x]);

		g->edges[x] = node;

		if(directed)
			g->nEdges++;
		else
			insert_edge(g, y, x, true);
	}

	static void read_graph(Graph*& g, bool directed)
	{
		int m;
		int x,y;

		initialize_graph(g, directed);

		cin>> g->nVertices;
		cin>> m;

		for(int i=0; i < m; i++)
		{
			cin >> x;
			cin >> y;

			insert_edge(g, x, y, directed);
		}
	}

	static void print_graph(Graph* g)
	{
		EdgeNode* node = nullptr;
		for(int i=0; i <= g->nVertices; i++)
		{
			node = g->edges[i];
			printf("%d : ", i);
			while(node != nullptr)
			{
				printf("%d ", node->y);
				node = node->next;
			}
			printf("\n");
		}
	}

	static void bfs(Graph* g, int vertex, bool visited[])
	{
		visited[vertex] = true;
		printf("%d ", vertex);

		queue<EdgeNode*> node_q = {};
		EdgeNode* node_1 = g->edges[vertex];

		node_q.push(node_1);

		while(!node_q.empty())
		{
			EdgeNode* node = node_q.front();
			node_q.pop();
			
			while (node != nullptr)
			{	
				if(!visited[node->y])
				{	
					printf("%d ", node->y);
					visited[node->y] = true;
					node_q.push(g->edges[node->y]);
				}
				node = node->next;
			}
		}
	}
};

int main()
{	
	bool visited[] = {};
	Graph* g = new Graph();

	Graph::read_graph(g, false);
	Graph::print_graph(g);

	Graph::bfs(g, 1, visited);

	return 0;
}