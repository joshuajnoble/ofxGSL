#pragma once

#include "ofMain.h"
#include "gsl_monte.h"
#include "gsl_monte_vegas.h"


#include "ofxGSL.h"


class monteCarloApp : public ofBaseApp{

	public:
    
    void setup();
    void update();
    void draw();

    void keyPressed  (int key);
    
    void monteVegasIntegrate(gsl_monte_function * f, double xLower[], double xUpper[], gsl_rng *range, int dimensions, int numCalls);

		
};
