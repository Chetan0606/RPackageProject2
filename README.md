# RPackageProject2

This R package provides a demonstration of Binary Segmentation/Dynamic Segmentation algorithm implemented in C++. Users can use this package to perform Binary Segmentation/Dynamic Segmentation on their data.

## Installation

To install this package from CRAN, you can use the following command:

```R
install.packages("RPackageProject2")
##OR:
if (!requireNamespace("remotes")) install.packages("remotes")
remotes::install_github("Chetan0606/RPackageProject2")

Examples:

Dynamic segmentation:

set.seed(123)
data <- rnorm(100)
threshold = 0.5
dynamicsegmentation <- dynamicSegmentation_algo(data, threshold)

Binary Segmentation:

set.seed(123)
data <- c(rnorm(50, mean = 2), rnorm(50, mean = 8))
binarySegmentation <- binarySegmentation_algo(data)
