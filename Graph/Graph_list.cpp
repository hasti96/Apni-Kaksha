#include <bits/stdc++.h>
#define MAX 1000

using namespace std;

class Edgenode
{
public:
	int y; // adjacency info
	int weight;
	Edgenode* next;

	Edgenode(): y(0), weight(0), next(nullptr) {};
	Edgenode(int y, int weight, Edgenode* node): y(y), weight(weight), next(node) {} ;

};

class Graph
{
public:
	
	int nVertices;
	int nEdges;
	bool directed;

	Edgenode* edges[MAX+1];
	int degree[MAX+1];

	Graph(): nVertices(0), nEdges(0), directed(false) {};

	static void initialize_graph(Graph*& g, bool directed)
	{
		int i;

		g->nVertices = 0;
		g->nEdges = 0;
		g->directed = directed;

		for(int i=0; i <= MAX; i++)
			g->edges[i] = nullptr;

		for(int j=0; j <= MAX; j++)
			g->degree[j] = 0;
	}

	static void insert_edge(Graph*& g, int x, int y, bool directed)
	{	
		Edgenode* edgenode = new Edgenode(y, 0, g->edges[x]);

		g->edges[x] = edgenode;
		g->degree[x]++;

		if(directed)
			g->nEdges++;
		else
			insert_edge(g, y, x, true);
	}

	static void read_graph(Graph*& g, bool directed)
	{
		int m; // -> number of Edges
		int x,y; // -> vertices in edge(x, y)

		initialize_graph(g, directed);

		cin >> g->nVertices;
		cin >> m;
		
		for(int i=1; i <= m; i++)
		{	
			
			cin >> x;
			cin >> y;
			insert_edge(g, x, y, directed);
		}
	}

	static void print_graph(Graph*& g)
	{
		Edgenode* p = nullptr;

		for(int i=0; i <= g->nVertices; i++)
		{
			printf("%d : ", i);
			p = g->edges[i];
			while(p != nullptr) 
			{
				printf("%d ", p->y);
				p = p->next;
			}
			printf("\n");
		}
	}

	static bool isVerticePresent(Graph* g, int inVertice)
	{
		return g->edges[inVertice] == nullptr ? false : true; 
	}
};


int main()
{
	Graph* g = new Graph();

	Graph::read_graph(g, false);
	Graph::print_graph(g);
	int verticeToFind = 0;
	printf("Vertice : [%d] is %d", verticeToFind, Graph::isVerticePresent(g, verticeToFind));

	return 0;
}