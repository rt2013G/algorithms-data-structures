#include "iostream"
/*
 * Given an array of n elements, the maximum subarray problems searches for the maximum contiguous subarray of A.
 * If all the elements of the array are positive, then the maximum subarray is the entire subarray.
 * If all the elements are negative, then the problem becomes searching for the maximum element of the array.
 * A divide and conquer solution to the problem might work as follows:
 * After splitting the array in two halves, a maximum subarray must lie entirely in one of two parts,
 * or crossing the mid-point. We can therefore find recursively a maximum subarray of the two halves,
 * because these two problems are smaller instances of the original problem,
 * then find a maximum subarray crossing the mid-point, compare the three and return the largest.
 * The time complexity of this algorithm is characterized by the recursion: T(n) = 2T(n/2) + Θ(n), because the
 * problems is split into two problems half the size of the original one, while the function that finds
 * a maximum subarray crossing the mid-point runs in Θ(n) time.
 * By case two of the master theorem, this recursion yields the result Θ(n log n);
 */
// todo brute force approach that runs in Θ(n^2) time
// todo 4.1-5 exercise that solves the problem in Θ(n) time
int max(int a, int b);
int maxOfThree(int a, int b, int c);
int findCrossingSubarray(int *array, int left, int mid, int right);
int findMaximumSubarray(int *array, int left, int right);

int main()
{
    int array[] = {13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};
    int size = 16;
    std::cout << "Maximum sum is: " << findMaximumSubarray(array, 0, size - 1) << std::endl;

    return 0;
}

int max(int a, int b)
{
    if(a > b)
        return a;
    else return b;
}

int maxOfThree(int a, int b, int c)
{
    if(max(a, b) > c)
        return max(a, b);
    else return c;
}

int findCrossingSubarray(int *array, int left, int mid, int right)
{
    int leftSum = INT_MIN;
    int sum = 0;
    for(int i = mid; i >= left; i--) {
        sum += array[i];
        if(sum > leftSum) {
            leftSum = sum;
        }
    }
    int rightSum = INT_MIN;
    sum = 0;
    for(int j = mid + 1; j <= right; j++) {
        sum += array[j];
        if(sum > rightSum) {
            rightSum = sum;
        }
    }
    return maxOfThree(leftSum + rightSum, leftSum, rightSum);
}

int findMaximumSubarray(int *array, int left, int right)
{
    if(left == right) {
        return array[right];
    }
    if(left > right) {
        return INT_MIN;
    }
    int mid = (left + right) / 2;
    int leftSum = findMaximumSubarray(array, left, mid - 1);
    int rightSum = findMaximumSubarray(array, mid + 1, right);
    int crossingSum = findCrossingSubarray(array, left, mid, right);
    return maxOfThree(leftSum, rightSum, crossingSum);
}
