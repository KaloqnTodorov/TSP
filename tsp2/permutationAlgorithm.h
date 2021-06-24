#pragma once
#include "graphClass.h"
class permutationAlgorithm
{
private:
	graphClass graph;
	int time;
	void copy(const permutationAlgorithm& other);
public:
	permutationAlgorithm();
	permutationAlgorithm(graphClass newGraph);
	permutationAlgorithm& operator = (const permutationAlgorithm& other);
	permutationAlgorithm(const permutationAlgorithm& other);

	graphClass getGraph() const;
	int getTime() const;
	void displayGraph();
	int algorithm(int** graph, int size);
};