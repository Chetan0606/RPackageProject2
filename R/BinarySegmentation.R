#' Binary Segmentation
#'
#' This function calls a C++ function to perform Binary Segmentation on the input data.
#' @name binarySegmentation_interface
#' @param data The input numeric matrix.
#'
#' @return A list containing eigenvalues, eigenvectors, and principal components.
#'
#' @export
#'
#' @examples
#' set.seed(123)
#' data <- c(rnorm(50, mean = 2), rnorm(50, mean = 8))
#' binarySegmentation_algo(data)
binarySegmentation_algo <- function(data) {
  result.list <- .Call("binarySegmentation_interface", data)
  result.list
}
