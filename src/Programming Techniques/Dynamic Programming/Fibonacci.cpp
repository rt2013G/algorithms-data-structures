#include "iostream"
#include "vector"
/*
 * Implementation of two algorithms for calculating the nth Fibonacci number.
 * The first one is the simple naive approach that runs in Θ(1.6^n)
 * The second one uses dynamic programming with memoization and has a time complexity of Θ(n)
 */
using intVec = std::vector<long long int>;

int fibonacci(int n)
{
    if(n <= 0) return 0;
    if(n == 1) return 1;
    return fibonacci(n - 2) + fibonacci(n - 1);
}

long long int memoizedFibonacci(intVec &vec, int n)
{
    if(n < vec.size()) return vec[n];
    long long int fibValue = memoizedFibonacci(vec, n - 1) + memoizedFibonacci(vec, n - 2);
    vec.push_back(fibValue);
    return fibValue;
}

int main()
{
    intVec vec = {0, 1};
    for(int i = 0; i <= 50; i++) {
        std::cout << i << "th Fibonacci number: " << memoizedFibonacci(vec, i) << std::endl;
    }
    return 0;
}
