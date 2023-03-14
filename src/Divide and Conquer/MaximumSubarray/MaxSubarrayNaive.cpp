#include "iostream"
/*
 * Naive approach to the Maximum Subarray problems presented in "MaxSubarray.cpp"
 * This is not a divide and conquer algorithm, however I added it in this directory as it's related to the
 * maximum subarray problem solved via divide and conquer.
 * The naive approach tries all possible combinations of subarray index pairs and returns the greatest sum.
 * Since the number of pairs is [n(n-1)]/2, the time complexity of this algorithm is Θ(n^2).
 */
int findMaximumSubarray(int *array, int size);

int main()
{
    int array[] = {13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};
    int size = 16;
    std::cout << "Maximum sum is: " << findMaximumSubarray(array, size) << std::endl;

    return 0;
}

int findMaximumSubarray(int *array, int size)
{
    int maxSum = INT_MIN;
    int sum = 0;
    for(int i = 0; i < size; i++) {
        for(int j = i; j < size; j++) {
                sum += array[j];
            if(sum > maxSum) {
                maxSum = sum;
            }
        }
        sum = 0;
    }
    return maxSum;
}
