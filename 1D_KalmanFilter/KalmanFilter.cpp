#include "KalmanFilter.h"

void calculateKalmanGain(float Eest, float Emea, float& KG)
{
	KG = Eest / (Eest + Emea);
}

void calculateCurrentEstimate(float previousEstimate, float Measurement, float KG, float& currentEstimate)
{
	currentEstimate = previousEstimate + KG * (Measurement - previousEstimate);
}

void calculateNewEstimateError(float previousErrorEstimate, float KG, float& currentErrorEstimate)
{
	currentErrorEstimate = (1 - KG) * previousErrorEstimate;
}