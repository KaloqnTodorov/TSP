#pragma once
#include "graphClass.h"

class nearestNeighbour
{
private:
	int time;
	graphClass graph;
	int completed[V];
	void copy(const nearestNeighbour& other);
public:
	nearestNeighbour();
	nearestNeighbour(graphClass newGraph);
	nearestNeighbour& operator = (const nearestNeighbour& other);
	nearestNeighbour(const nearestNeighbour& other);

	int getTime() const;
	graphClass getGraph() const;
	int* getCompleted() const;
	void displayGraph();
	void mincost(int city, graphClass newGraph);
	int least(int c, graphClass newGraph);
};