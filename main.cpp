//Dijkstra: Shortest path algoritmasý yani bir minimization problemi. Yani optimizasyon problemi. Ve greedy metod ile 
//çözülüyor. Yönlü ya da yönsüz graflara uygulanabiliyor. Bir drawback'i var. O da negatif aðýrlýklý edge'lere sahip graflarda doðru da çalýþabiliyor 
//yanlýþ da çalýþabiliyor. 

#include <iostream>
#include "Graph.h"
#include <algorithm>
#include <iterator>

void dijkstra(Graph g) {
	std::vector <int> track_{ 0 };
	std::vector <int> totalVertexValue; //needed for comparison and update 
	int index;
	int trackCount = 1;
	//2 for loops since Dijkstra's worst case big-O notation O(n^2). 
	for (int i = 0; i < g.edgeList.size(); i++) { //tüm satýrlar
		auto maks = std::max_element(g.edgeList[track_.back()].begin(), g.edgeList[track_.back()].end());
		index = std::distance(g.edgeList[track_.back()].begin(), maks);
		//edge update must be done
		for (int j = 0; j < g.edgeList[i].size(); j++) {
			if (j != index && totalVertexValue[j] > g.edgeList[track_.back()][j] + totalVertexValue[trackCount-1]) { //?
				totalVertexValue[j] = g.edgeList[track_.back()][j];
			}
		}

		track_.push_back(g.adjacencyList[track_.back()][index]);
		trackCount += 1;
	}
	for (int z = 0; z < track_.size(); z++) {
		std::cout << track_[z];
	}
	
}

int main() {
	// 6 node graph
	Graph g(6);
	
	// Graph's edges

	g.link_vertices(0, 2, 1);
	g.link_vertices(0, 4, 2);
	g.link_vertices(1, 1, 2);
	g.link_vertices(1, 7, 3);
	g.link_vertices(2, 3, 4);
	g.link_vertices(3, 1, 5);
	g.link_vertices(4, 2, 3);
	g.link_vertices(4, 5, 5);

	// Write
	g.printGraph();
	g.printGraphedge();
	dijkstra(g);
	return 0;
}