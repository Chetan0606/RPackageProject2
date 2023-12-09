library(RPackage2)
library(testthat)
context("binarySegmentation")

test_that("dynamicSegmentation_algo computes the same answer as R", {
  set.seed(123)
  data <- c(rnorm(50, mean = 2), rnorm(50, mean = 8))
  binarySegmentation <- binarySegmentation_algo(data)
  
  expect_equal(binarySegmentation$split_index, 51)
  expect_equal(binarySegmentation$split_value, 5.084975)
  
})