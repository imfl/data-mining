![demo](image/demo.gif)

#### Introducing Dynamic Time Warping Distance into Matrix Profile

*an academic project on time series data mining*

Matrix Profile (MP) has emerged as a new concept in the data mining community since 2016. It is a framework to extract information from time series, which can be later applied in similarity research. Two steps are involved:

1. construct a matrix profile
2. use the matrix profile

In step 1, the current setting uses traditional Euclidean distance to measure how similar two subsequences are. However, a better approach would be using Dynamic Time Warping (DTW) distance. See the graph below for intuition.

![dtw](image/dtw.png)

As an initial attempt in the academic community, I introduced DTW into MP.

The main challenge is -- the time complexity for computing DTW is high even for a single pair of points. It is infeasible to compute all the pairs in a matrix.

My originalities are

1. compute lower bounds to skip unnecessary computation
2. use randomized local search within each column of the matrix

An abstract of this project is [here](summary/abstract.pdf).

The results of this project are [here](summary/results.pdf).
