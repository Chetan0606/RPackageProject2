#include "DynamicSegmentation.h"

#include <Rcpp.h>
using namespace Rcpp;

List dynamicSegmentation(const NumericVector& data, double threshold) {
  int n = data.size();
  
  // Initialize variables
  int currentSegment = 0;
  double currentSum = 0.0;
  int segmentStart = 0;
  
  // Vectors to store segment indices and means
  std::vector<int> segmentIndices;
  std::vector<double> segmentMeans;
  
  // Iterate through the time series data
  for (int i = 0; i < n; ++i) {
    currentSum += data[i];
    
    // Check if a new segment should be created
    if (currentSum > threshold) {
      // Calculate segment mean
      double segmentMean = currentSum / (i - segmentStart + 1);
      
      // Store segment information
      segmentIndices.push_back(segmentStart + 1);  // Segment indices are 1-based in R
      segmentMeans.push_back(segmentMean);
      
      // Update variables for the next segment
      currentSegment++;
      currentSum = 0.0;
      segmentStart = i + 1;
    }
  }
  
  // Create the final segment if needed
  if (segmentStart < n) {
    double segmentMean = currentSum / (n - segmentStart);
    segmentIndices.push_back(segmentStart + 1);
    segmentMeans.push_back(segmentMean);
  }
  
  // Return the result as a list
  return List::create(Named("segment_indices") = segmentIndices,
                      Named("segment_means") = segmentMeans);
}