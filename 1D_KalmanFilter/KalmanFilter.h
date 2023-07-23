#pragma once
#include <iostream>

void calculateKalmanGain(float Eest, float Emea, float& KG);

void calculateCurrentEstimate(float previousEst, float Measurement,float KG, float& currentEstimate);

void calculateNewEstimateError(float previousErrEst, float KG, float& currErrEst);
