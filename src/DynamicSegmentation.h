#include <Rcpp.h>
using namespace Rcpp;

List dynamicSegmentation(const NumericVector& data, double threshold);