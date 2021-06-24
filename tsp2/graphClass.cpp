#include <iostream>
#include "graphClass.h"
#include <fstream>

using namespace std;

void graphClass::copy(const graphClass& other)
{
    this->size = other.size;
    for (size_t i = 0; i < V; i++)
    {
        for (size_t j = 0; j < V; j++)
        {
            this->graph[i][j] = other.graph[i][j];
        }
    }
  
}

graphClass::graphClass()
{ 
    this->size = 0;
    for (size_t i = 0; i < V; i++)
    {
        for (size_t j = 0; j < V; j++)
        {
            graph[i][j] = 0;
        }
    }
    
}

graphClass::graphClass(int const newSize, int newGraph[V][V])
{
    size = newSize;
    createGraph();

}

graphClass::graphClass(const graphClass& other)
{
    this->copy(other);
}


graphClass& graphClass::operator=(const graphClass& other)
{
    if (this != &other)
    {
        this->copy(other);
    }
    return *this;
}

int graphClass::getSize() const
{
    return this->size;
}

int** graphClass::getGraph() const
{
    int** newGraph = new int* [V];
    for (int i = 0; i < V; ++i)
        newGraph[i] = new int[V];

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            newGraph[i][j] = graph[i][j];
        }
    }
    return newGraph;
}

void graphClass::createGraph()
{
    ifstream imputFile;
    imputFile.open("matrix.txt");
    if (!imputFile)
    {
        cout << "cant find file!!";
        return ;
    }

    while (!imputFile.eof())
    {
        for (size_t i = 0; i < V; i++)
        {
            for (size_t j = 0; j < V; j++)
            {
                imputFile >> this->graph[i][j];
            }
        }
    }
}