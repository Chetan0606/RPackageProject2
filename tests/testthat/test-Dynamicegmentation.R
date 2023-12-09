library(RPackage2)
library(testthat)
context("dynamicsegmentation")

test_that("dynamicSegmentation_algo computes the same answer as R", {
  set.seed(123)
  data <- rnorm(100)
  threshold = 0.5
  dynamicsegmentation <- dynamicSegmentation_algo(data, threshold)
  expect_equal(dynamicsegmentation$segment_indices, 1)
  expect_equal(dynamicsegmentation$segment_means, 0.09040591)
  
  # Check if the length is 1 for segment_indices and segment_means
  expect_equal(length(dynamicsegmentation$segment_indices), 1)
  expect_equal(length(dynamicsegmentation$segment_means), 1)
  
  # Check the actual values
  expect_equal(dynamicsegmentation$segment_indices, 1)
  expect_equal(dynamicsegmentation$segment_means, 0.09040591, tolerance = 1e-6)
  
})
