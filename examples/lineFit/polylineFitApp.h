#pragma once

#include "ofMain.h"
#include "gsl_multifit.h"
#include "gsl_cblas.h"
#include "ofxGSL.h"

#define DEGREE 3


class polylineFitApp : public ofBaseApp{

	public:
    
    void setup();
    void update();
    void draw();

    void keyPressed  (int key);
    
    double coeff[DEGREE];
    bool polynomialfit(int obs, int degree, double *dx, double *dy, double *store);

		
};
