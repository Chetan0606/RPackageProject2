#' Dynamic Segmentation Algorithm
#'
#' This function performs dynamic segmentation on the input data.
#' @name dynamicSegmentation_interface
#' @param data The input numeric vector.
#' @param threshold The threshold value.
#'
#' @return An integer vector of changepoint indices.
#'
#' @export
#'
#' @examples
#' set.seed(123)
#' data <- rnorm(100)
#' threshold = 0.5
#' dynamicSegmentation_algo(data, threshold)
dynamicSegmentation_algo <- function(data, threshold) {
  result.vec <- .Call("dynamicSegmentation_interface", data, threshold)
  result.vec
}