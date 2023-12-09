#include "BinarySegmentation.h"
#include <Rcpp.h>
using namespace Rcpp;

// Function to perform binary segmentation
// Input: NumericVector data - the time series data
// Output: List containing segment indices and means
// Note: This is a simple example; you may need to modify it based on your specific requirements.

List binarySegmentation(const NumericVector& data) {
  int n = data.size();
  
  // Initialize variables
  int bestSplitIndex = 0;
  double bestSplitValue = 0.0;
  double bestError = R_PosInf;  // Positive infinity as the initial value
  
  // Iterate through the time series data to find the best split
  for (int splitIndex = 1; splitIndex < n; ++splitIndex) {
    // Calculate means of the two segments
    NumericVector subset1(data.begin(), data.begin() + splitIndex);
    NumericVector subset2(data.begin() + splitIndex, data.end());
    
    double mean1 = mean(subset1);
    double mean2 = mean(subset2);
    
    // Calculate the squared error
    double error = sum(pow(subset1 - mean1, 2.0)) + sum(pow(subset2 - mean2, 2.0));
    
    // Update the best split if the error is smaller
    if (error < bestError) {
      bestSplitIndex = splitIndex;
      bestSplitValue = (data[splitIndex - 1] + data[splitIndex]) / 2.0;
      bestError = error;
    }
  }
  
  // Create the result as a list
  return List::create(Named("split_index") = bestSplitIndex + 1,  // 1-based index in R
                      Named("split_value") = bestSplitValue);
}