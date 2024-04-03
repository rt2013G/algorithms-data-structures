#include "iostream"
/*
 * Algorithm that solves the maximum subarray problem presented in "MaxSubarray.cpp" in Θ(n) time.
 * This is not a divide and conquer algorithm, however I added it in this directory as it's related to the
 * maximum subarray problem solved via divide and conquer.
 */
int max(int a, int b);
int findMaximumSubarray(int *array, int size);

int main()
{
    int array[] = {13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};
    int size = 16;
    std::cout << "Maximum sum is: " << findMaximumSubarray(array, size) << std::endl;

    return 0;
}

int max(int a, int b)
{
    if(a > b)
        return a;
    else return b;
}

int findMaximumSubarray(int *array, int size)
{
    int maxSum = INT_MIN;
    int sum = 0;
    for(int i = 0; i < size - 1; i++) {
        sum += array[i];
        if(sum > maxSum) {
            maxSum = sum;
        }
        if(sum < 0) {
            sum = 0;
        }
    }
    return maxSum;
}
