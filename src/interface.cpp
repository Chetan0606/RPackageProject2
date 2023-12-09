#include "BinarySegmentation.h"
#include "DynamicSegmentation.h"
#include <R_ext/Rdynload.h>
#include <Rcpp.h>

using namespace Rcpp;

#ifdef RCPP_USE_GLOBAL_ROSTREAM
Rcpp::Rostream<true>&  Rcpp::Rcout = Rcpp::Rcpp_cout_get();
Rcpp::Rostream<false>& Rcpp::Rcerr = Rcpp::Rcpp_cerr_get();
#endif

// RcppExport SEXP dynamicSegmentation_interface(SEXP xSEXP) {
//   
//   NumericVector x(xSEXP);
//   IntegerVector result = dynamicSegmentation(x);
//   
//   return result;
// }


RcppExport SEXP dynamicSegmentation_interface(SEXP xSEXP, double threshold) {
  NumericVector x(xSEXP);
  List result = dynamicSegmentation(x, threshold);
  return wrap(result);
}

RcppExport SEXP binarySegmentation_interface(SEXP xSEXP) {
  NumericVector x(xSEXP);
  List result = binarySegmentation(x);
  return wrap(result);
}

static const R_CallMethodDef CallEntries[] = {
  {"dynamicSegmentation_interface", (DL_FUNC) &dynamicSegmentation_interface, 2},
  {"binarySegmentation_interface", (DL_FUNC) &binarySegmentation_interface, 1},
  {NULL, NULL, 0}
};

RcppExport void R_init_RPackageCreationProject(DllInfo *dll) {
  R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
  R_useDynamicSymbols(dll, FALSE);
}