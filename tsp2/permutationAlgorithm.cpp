#include "permutationAlgorithm.h"
#include <iostream>
#include <chrono> 
#include <algorithm>
#include <vector>

//#include <windows.h>
//#include <Psapi.h>

using namespace std;
using namespace std::chrono;


void permutationAlgorithm::copy(const permutationAlgorithm& other)
{
	this->graph = other.graph;
	this->time = other.time;
}

permutationAlgorithm::permutationAlgorithm()
{
	graphClass newGraph;
	this->graph = newGraph;
	this->time = 0;
}

permutationAlgorithm::permutationAlgorithm(graphClass newGraph)
{
	this->graph = newGraph;
	this->time = 0;
}

permutationAlgorithm& permutationAlgorithm::operator=(const permutationAlgorithm& other)
{
	if (this != &other)
	{
		this->copy(other);
	}
	return *this;
}

permutationAlgorithm::permutationAlgorithm(const permutationAlgorithm& other)
{
	this->copy(other);
}

graphClass permutationAlgorithm::getGraph() const
{
	return this->graph;
}

int permutationAlgorithm::getTime() const
{
	return this->time;
}

void permutationAlgorithm::displayGraph()
{
	for (int i = 0;i < this->graph.getSize();i++)
	{
		cout << "\n";

		for (int j = 0;j < this->graph.getSize();j++)
			if (this->graph.getGraph()[i][j] > 9)
				cout << " " << this->graph.getGraph()[i][j];
			else
				cout << "  " << this->graph.getGraph()[i][j];
	}

	cout << "\n";
	auto start = high_resolution_clock::now();
	cout<<algorithm(this->graph.getGraph(),graph.getSize());
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<milliseconds>(stop - start);
	cout << " \nTime taken: " << duration.count() << " milliseconds" << endl;
	this->time = duration.count();

	//PROCESS_MEMORY_COUNTERS memCounter;
	//BOOL result = K32GetProcessMemoryInfo(GetCurrentProcess(), &memCounter, sizeof(memCounter));
	//std::cout << "WorkingSetSize: " << memCounter.WorkingSetSize << std::endl;

}

int permutationAlgorithm::algorithm(int** graph, int size)
{
	vector<int> vertex;
	vector<int> temp;
	vector<int> min;

	int s = 0;

	for (int i = 0; i < size; i++)
	{

		if (i != s)
			vertex.push_back(i);
	}
	
	int min_path = INT_MAX;
	do {

		
		int current_pathweight = 0;
		temp.clear();
		
		int k = s;
		for (int i = 0; i < vertex.size(); i++) {
			current_pathweight += graph[k][vertex[i]];
			k = vertex[i];
			temp.push_back(k);
		}
		current_pathweight += graph[k][s];
		



		if (min_path > current_pathweight)
		{
			min_path = current_pathweight;
			min.clear();
			for (size_t i = 0; i < temp.size(); i++)
			{
				min.push_back(temp[i]);
			}
		}


	} while (next_permutation(vertex.begin(), vertex.end()));
	cout << "\nThe path is (permutation algorithm):\n" << s + 1 << "--->";
	for (size_t i = 0; i < min.size(); i++)
	{
		cout << min[i] + 1 << "--->";
	}
	cout << s + 1;
	cout << endl;
	cout << "Minimum cost is: ";
	return min_path;
}