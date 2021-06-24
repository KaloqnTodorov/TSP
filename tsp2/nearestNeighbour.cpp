#include "nearestNeighbour.h"
#include <iostream>
#include <chrono> 
//#include <windows.h>
//#include <Psapi.h>

using namespace std;
using namespace std::chrono;

int cost = 0;


void nearestNeighbour::copy(const nearestNeighbour& other)
{
	this->graph = other.graph;
	this->time = other.time;
	for (size_t i = 0; i < V; i++)
	{
		this->completed[i] = other.completed[i];
	}
}

nearestNeighbour::nearestNeighbour()
{
	graphClass newGraph;
	this->graph = newGraph;
	this->time = 0;
	for (size_t i = 0; i < V; i++)
	{
		this->completed[i] = 0;
	}
}

nearestNeighbour::nearestNeighbour(graphClass newGraph)
{
	this->graph = newGraph;
	this->time = 0;
	for (size_t i = 0; i < V; i++)
	{
		this->completed[i] = 0;
	}
}

nearestNeighbour& nearestNeighbour::operator=(const nearestNeighbour& other)
{
	if (this != &other)
	{
		this->copy(other);
	}
	return *this;
}

nearestNeighbour::nearestNeighbour(const nearestNeighbour& other)
{
	this->copy(other);
}

int nearestNeighbour::getTime() const
{
	return this->time;
}

graphClass nearestNeighbour::getGraph() const
{
	return this->graph;
}

int* nearestNeighbour::getCompleted() const
{
	int* newGraph = new int [V];
	for (size_t i = 0; i < V; i++)
	{
		newGraph[i] = this->completed[i];
	}
	return newGraph;
}

void nearestNeighbour::displayGraph()
{
	for (int i = 0;i <this->graph.getSize();i++)
	{
		cout << "\n";

		for (int j = 0;j < this->graph.getSize();j++)
			if (this->graph.getGraph()[i][j] > 9)
				cout << " " << this->graph.getGraph()[i][j];
			else
				cout << "  " << this->graph.getGraph()[i][j];
	}
	
	cout << "\n\nThe path is (nearest neighbour algorithm):\n";
	auto start = high_resolution_clock::now();
	mincost(0, this->graph);
	auto stop = high_resolution_clock::now();
	cout << "\nMinimum cost is " << cost;
	auto duration = duration_cast<milliseconds>(stop - start);
	cout << " \nTime taken: " << duration.count() << " milliseconds" << endl;
	this->time = duration.count();
	cost = 0;
	

	//PROCESS_MEMORY_COUNTERS memCounter;
	//BOOL result = K32GetProcessMemoryInfo(GetCurrentProcess(), &memCounter, sizeof(memCounter));
	//std::cout << "WorkingSetSize: " << memCounter.WorkingSetSize << std::endl;

}

void nearestNeighbour::mincost(int city, graphClass newGraph)
{
	int i, ncity;
	
	completed[city] = 1;

	std::cout << city + 1 << "--->";
	ncity = least(city, newGraph);

	if (ncity == 999)
	{
		ncity = 0;
		std::cout << ncity + 1;
		cost += newGraph.getGraph()[city][ncity];

		return;
	}

	mincost(ncity, newGraph);
	
}

int nearestNeighbour::least(int c, graphClass newGraph)
{
	int i, nc = 999;
	int min = 999, kmin;
	

	for (i = 0;i < newGraph.getSize();i++)
	{
		if ((newGraph.getGraph()[c][i] != 0) && (completed[i] == 0))
			if (newGraph.getGraph()[c][i] + newGraph.getGraph()[i][c] < min)
			{
				min = newGraph.getGraph()[i][0] + newGraph.getGraph()[c][i];
				kmin = newGraph.getGraph()[c][i];
				nc = i;
			}
	}

	if (min != 999)
		cost += kmin;

	return nc;
}