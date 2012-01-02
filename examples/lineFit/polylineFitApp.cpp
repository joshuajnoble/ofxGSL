#include "polylineFitApp.h"


void polylineFitApp::setup(){
    
    const int NP = 11;
    double x[] = {0,  1,  2,  3,  4,  5,  6,   7,   8,   9,   10};
    double y[] = {1,  6,  17, 34, 57, 86, 121, 162, 209, 262, 321};
    
    polynomialfit(NP, DEGREE, x, y, coeff);
    
}

void polylineFitApp::update(){
}

void polylineFitApp::draw(){
    
    stringstream s;
    s << coeff[0] << " " << coeff[1] << " " << coeff[2] << " ";
    
    ofDrawBitmapString(s.str(), ofPoint(100, 100));

}

void polylineFitApp::keyPressed(int key){
    
}


void polylineFitApp::polynomialfit(int obs, int degree, double *dx, double *dy, double *store)
{
    gsl_multifit_linear_workspace *ws;
    gsl_matrix *cov, *X;
    gsl_vector *y, *c;
    double chisq;
    
    int i, j;
    
    X = gsl_matrix_alloc(obs, degree);
    y = gsl_vector_alloc(obs);
    c = gsl_vector_alloc(degree);
    cov = gsl_matrix_alloc(degree, degree);
    
    for(i=0; i < obs; i++) {
        gsl_matrix_set(X, i, 0, 1.0);
        for(j=0; j < degree; j++) {
            gsl_matrix_set(X, i, j, pow(dx[i], j));
        }
        gsl_vector_set(y, i, dy[i]);
    }
    
    ws = gsl_multifit_linear_alloc(obs, degree);
    gsl_multifit_linear(X, y, c, cov, &chisq, ws);
    
    /* store result ... */
    for(i=0; i < degree; i++)
    {
        store[i] = gsl_vector_get(c, i);
    }
    
    gsl_multifit_linear_free(ws);
    gsl_matrix_free(X);
    gsl_matrix_free(cov);
    gsl_vector_free(y);
    gsl_vector_free(c);
    
}
