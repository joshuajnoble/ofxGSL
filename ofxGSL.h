//
//  ofxGSL.h
//  emptyExample
//
//  Created by base on 30/12/11.
//  Copyright (c) 2011 __MyCompanyName__. All rights reserved.
//

#pragma once


#include "ofMain.h"
#include <gsl_matrix.h>

class ofxGSL {

template <typename T>
static T toGSL(float* data) {
    return static_cast<T>(data);
};
    
    
static gsl_matrix* toGSL(ofMatrix4x4 mat) {
    gsl_matrix *m = gsl_matrix_alloc(4,4); /* create a matrix */
    
    int i,j;
    for (i=0;i<4;i++)
    {
        for (j=0;j<4;j++)
        {
            gsl_matrix_set(m,i,j,mat(i,j));
        }
    }
    
    return m;
    
};
    
};
