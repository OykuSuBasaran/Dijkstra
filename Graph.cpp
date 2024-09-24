#include "Graph.h"
#include <iostream>

#ifndef COMP_GRAPH
#define COMP_GRAPH


Graph::Graph(int V) { //constructor
	this->V = V;
	adjacencyList.resize(V);
	edgeList.resize(V);
}

void Graph::link_vertices(int a, int edge1, int b) { //will link two vertices, a and b
	//two vectors will always have the same size
	adjacencyList[a].push_back(b); //link between vertices
	edgeList[a].push_back(edge1); //distance between both according to index number
}

void Graph::printGraph() {
	for (int i = 0; i < V; ++i) {
		std::cout << i << ": ";
		for (int j : adjacencyList[i]) {
			std::cout << j << " ";
		}
		std::cout << std::endl;
	}
}

void Graph::printGraphedge() {
	for (int i = 0; i < V; ++i) {
		std::cout << i << ": ";
		for (int j : edgeList[i]) {
			std::cout << j << " ";
		}
		std::cout << std::endl;
	}
}
#endif