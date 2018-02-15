#include <iostream>
#include "tools.h"

using Eigen::VectorXd;
using Eigen::MatrixXd;
using std::vector;

Tools::Tools() {}

Tools::~Tools() {}

VectorXd Tools::CalculateRMSE(const vector<VectorXd> &estimations,
                              const vector<VectorXd> &ground_truth) {
  /**
  TODO: [Done]
    * Calculate the RMSE here.
  */

  VectorXd rmse(4);
	rmse << 0,0,0,0;

  // Debug:
  // cout << "Tools::CalculateRMSE Starting to calculate rmse" << endl; 
  
  // check the validity of the inputs:
	//  * the estimation vector size should not be zero
	//  * the estimation vector size should equal ground truth vector size
	if(estimations.size() == 0
	  || estimations.size() != ground_truth.size())
	{
    cout << "ERROR!!! Input to CalculateRMSE is malformed!!! Estimations size: " 
      << estimations.size() << ", Ground_truth: " << ground_truth.size() << endl;
    return rmse;
	}
	
	//accumulate squared residuals
	for(int i=0; i < estimations.size(); ++i) {
		VectorXd diff = estimations[i] - ground_truth[i];
		diff = (diff.array() * diff.array());
		rmse += diff;
	}

	//calculate the mean
	rmse /= estimations.size();

	//calculate the squared root
	rmse = rmse.array().sqrt();

	//return the result
	return rmse;
}

