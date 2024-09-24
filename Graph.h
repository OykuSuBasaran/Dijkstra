#pragma once
#include <vector>

#ifndef GRAPH_H
#define GRAPH_H

class Graph {
private:
	int V;
	std::vector<std::vector<int>> adjacencyList;
	std::vector<std::vector<int>> edgeList;
public:
	Graph(int V);
	void link_vertices(int a, int edge1, int b);
	void printGraph();
	void printGraphedge(); 
friend void dijkstra(Graph g);
};


#endif
