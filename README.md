# IntroPP2182041

Postman Sort Algorithm
The Postman Sort algorithm implemented in this C++ code is designed to efficiently sort a large set of numbers by their most significant digits. This algorithm is particularly useful for situations where numbers are distributed across a wide range and need to be sorted quickly.

How it Works
Input: The algorithm takes an unsorted array of integers as input.

Initialization: It determines the maximum number of digits present in the array elements.

Sorting by Most Significant Digit (MSD): The array is sorted based on the MSD, dividing the work among multiple threads to exploit parallelism.

Continued Sorting: After sorting by the MSD, the algorithm continues to sort elements with the same MSD.

Benefits
Efficiency: By utilizing OpenMP for parallel execution, the algorithm achieves faster sorting times, especially on multi-core systems.
Scalability: The algorithm's parallel nature allows it to scale effectively with increasing workload sizes.
Ease of Use: The code is written in C++, making it easy to understand and integrate into existing projects.
