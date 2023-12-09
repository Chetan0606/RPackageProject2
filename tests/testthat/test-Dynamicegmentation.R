library(RPackage2)
library(testthat)
context("dynamicsegmentation")

test_that("dynamicSegmentation_algo computes the same answer as R", {
  set.seed(123)
  data <- rnorm(50)
  threshold = 0.5
  dynamicsegmentation <- dynamicSegmentation_algo(data, threshold)
  
  expect_equal(dynamicsegmentation$segment_indices, 1)
  expect_equal(dynamicsegmentation$segment_means, 0.03440355, tolerance = 1e-6)
  
})
