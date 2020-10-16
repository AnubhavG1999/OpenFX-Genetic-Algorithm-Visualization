#pragma once

#include "ofMain.h"
#include "ofxPlotter.h"
#include "Individual.h"
#include "Genetics.h"
#include "ofxDatGui.h"


class ofApp : public ofBaseApp{

public:
	int generation;
	bool found;
	bool creator;
	vector<Individual> population;
	void setup();
	void update();
	void draw();
	int average;

	ofxPlotter fitness_plotter;


};
