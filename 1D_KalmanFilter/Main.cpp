#include "KalmanFilter.h"
#define MEASUREMENTS 7

int main()
{
	float measurements[MEASUREMENTS] = { 75,71,70,74,73,73.5,72 };
	const int measurementError = 4;
	float estimateError = 2.00f;
	float KalmanGain = 0;
	float initialEstimate = 68;
	float estimate = 0;
	float previousEstimate = initialEstimate;
	
	for (int idx = 0; idx < MEASUREMENTS; idx++)
	{
		calculateKalmanGain(estimateError, measurementError, KalmanGain);
		calculateCurrentEstimate(previousEstimate, measurements[idx], KalmanGain, estimate);
		calculateNewEstimateError(estimateError, KalmanGain, estimateError);
		previousEstimate = estimate;
		
		std::cout << "Estimated values : " << estimate << std::endl;
		//std::cout << "Kalman gain : " << KalmanGain << std::endl;
		//std::cout << "Error in estimate" << estimateError << std::endl;
	}

	std::cin.get();

}