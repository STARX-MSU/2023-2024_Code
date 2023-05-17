/**
 * \file ZeroCrossing.cpp
 *
 * \author Jordan Hybki (@jh9587)
 * 
 * Pseudocode referenced from MATLAB EMG Feature Extraction Toolbox:
 * https://www.mathworks.com/matlabcentral/fileexchange/71514-emg-feature-extraction-toolbox
 * 
 */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "emgToolbox.h"

double emgToolbox::ZC()
{
    double sum = 0;
    for (int a = 0; a < mSize-1; a++)
    {
        // Counter for each time the singal passes the zero threshold on Y axis.
        if ( ((mArr[a] > 0 && mArr[a+1] < 0) || (mArr[a] < 0 && mArr[a+1] > 0)) && (fabs(mArr[a] - mArr[a+1]) >= mOpts) )
        {
            sum += 1;
        }
    }
    return sum;
}
