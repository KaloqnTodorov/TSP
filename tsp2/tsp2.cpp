#include<iostream>
#include"nearestNeighbour.h"
#include"graphClass.h"
#include"permutationAlgorithm.h"
//#include<conio.h>
#include "pbPlots.hpp"
#include "supportLib.hpp"

using namespace std;

int main() {

	int ary[V][V] = { 0 };
	int  v1 = 15;
	int  v2 = 11;
	int v2_2 = 10;
	int  v3 = 8;
	int  v4 = 5;
	int  v5 = 3;
	vector<double> nnX, nnY, perX, perY;
	int i = 0, j = 0;

	graphClass	firstGraph(v1, ary),
		firstGraph_(v2, ary),
		secondGraph = firstGraph_,
		secondGraph_(v2_2, ary),
		thirdGraph(v3, ary),
		fourthGraph(v4, ary),
		fifthGraph(v5, ary);

	nearestNeighbour firstGraphNearestNeighbour(firstGraph),
		secondGraphNearestNeighbour(secondGraph),
		thirdGraphNearestNeighbour(thirdGraph),
		fourthGraphNearestNeighbour(fourthGraph),
		fifthGraphNearestNeighbour(fifthGraph);

	permutationAlgorithm firstGraphPermutationAlgorithm(firstGraph_),
		secondGraphPermutationAlgorithm(secondGraph_),
		thirdGraphPermutationAlgorithm(thirdGraph),
		fourthGraphPermutationAlgorithm(fourthGraph),
		fifthGraphPermutationAlgorithm(fifthGraph);

	firstGraphNearestNeighbour.displayGraph();			nnX.push_back(firstGraphNearestNeighbour.getGraph().getSize());			nnY.push_back(firstGraphNearestNeighbour.getTime());i++;
	firstGraphPermutationAlgorithm.displayGraph();		perX.push_back(firstGraphPermutationAlgorithm.getGraph().getSize());	perY.push_back(firstGraphPermutationAlgorithm.getTime());j++;
	secondGraphNearestNeighbour.displayGraph();			nnX.push_back(secondGraphNearestNeighbour.getGraph().getSize());		nnY.push_back(secondGraphNearestNeighbour.getTime());i++;
	secondGraphPermutationAlgorithm.displayGraph();		perX.push_back(secondGraphPermutationAlgorithm.getGraph().getSize());	perY.push_back(secondGraphPermutationAlgorithm.getTime());j++;
	thirdGraphNearestNeighbour.displayGraph();			nnX.push_back(thirdGraphNearestNeighbour.getGraph().getSize());			nnY.push_back(thirdGraphNearestNeighbour.getTime());i++;
	thirdGraphPermutationAlgorithm.displayGraph();		perX.push_back(thirdGraphPermutationAlgorithm.getGraph().getSize());	perY.push_back(thirdGraphPermutationAlgorithm.getTime());j++;
	fourthGraphNearestNeighbour.displayGraph();			nnX.push_back(fourthGraphNearestNeighbour.getGraph().getSize());		nnY.push_back(fourthGraphNearestNeighbour.getTime());i++;
	fourthGraphPermutationAlgorithm.displayGraph();		perX.push_back(fourthGraphPermutationAlgorithm.getGraph().getSize());	perY.push_back(fourthGraphPermutationAlgorithm.getTime());j++;
	fifthGraphNearestNeighbour.displayGraph();			nnX.push_back(fifthGraphNearestNeighbour.getGraph().getSize());			nnY.push_back(fifthGraphNearestNeighbour.getTime());i++;
	fifthGraphPermutationAlgorithm.displayGraph();		perX.push_back(fifthGraphPermutationAlgorithm.getGraph().getSize());	perY.push_back(fifthGraphPermutationAlgorithm.getTime());j++;

	cout << "\ntime for execution of nearest neighbour\n";

	for (size_t i = 0; i < 5; i++)
	{
		cout  << "number of cities: " << nnX[i] << " " << "time: " << nnY[i] << " milliseconds"<< endl;
	}
	cout << "\ntime for execution of permutation algorithm\n";
	for (size_t j = 0; j < 5; j++)
	{
		cout << "number of cities: " << perX[j] << " " << "time: " << perY[j] << " milliseconds"<< endl ;
	}

	RGBABitmapImageReference* imageReference = CreateRGBABitmapImageReference();

	ScatterPlotSeries* series = GetDefaultScatterPlotSeriesSettings();
	ScatterPlotSeries* series2 = GetDefaultScatterPlotSeriesSettings();
	series->xs = &nnX;
	series->ys = &nnY;
	series->linearInterpolation = true;
	series->lineType = toVector(L"dashed");
	series->lineThickness = 2;
	series->color = GetBlack();

	series2->xs = &perX;
	series2->ys = &perY;
	series2->linearInterpolation = true;
	series2->lineType = toVector(L"dashed");
	series2->lineThickness = 2;
	series2->color = GetGray(0.3);

	ScatterPlotSettings* settings = GetDefaultScatterPlotSettings();
	settings->width = 900;
	settings->height = 600;
	settings->autoBoundaries = true;
	settings->autoPadding = true;
	settings->xLabel = toVector(L"number of cities");
	settings->yLabel = toVector(L"time in milliseconds");
	settings->scatterPlotSeries->push_back(series);
	settings->scatterPlotSeries->push_back(series2);

	DrawScatterPlotFromSettings(imageReference, settings);

	vector<double>* pngdata = ConvertToPNG(imageReference->image);
	WriteToFile(pngdata, "graphcomparing.png");
	DeleteImage(imageReference->image);

	return 0;
}