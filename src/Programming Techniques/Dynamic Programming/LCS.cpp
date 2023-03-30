#include "iostream"
#include "algorithm"
#include "vector"
/*
 * Implementation of the LCS algorithm to find the longest common subsequence of two sequences X and Y.
 * A brute force solution to the LCS problem would be to check all possible subsequences of X,
 * evaluate whether they are also subsequences of Y, and keep track of the longest one.
 * Because X has 2^m subsequences, this approach would take exponential time.
 * With dynamic programming, we can solve the problem in O(n*m).
 * The implementation below uses recursion with memoization, but it can also be done iteratively.
 */
using std::string;
using std::max;
using std::cout;
using vec2D = std::vector<std::vector<int>>;

int LCS(vec2D &vec, const string& X, const string& Y, unsigned int m, unsigned int n)
{
    if(m == 0 || n == 0) return 0;
    if(vec[m - 1][n - 1] != -1) return vec[m - 1][n - 1];

    if(X[m - 1] == Y[n - 1]) {
        vec[m - 1][n - 1] = LCS(vec, X, Y, m - 1, n - 1) + 1;
    } else {
        vec[m - 1][n - 1] = max(LCS(vec, X, Y, m - 1, n), LCS(vec, X, Y, m, n - 1));
    }

    return vec[m - 1][n - 1];
}

int main()
{
    string X = "ABCABCBABCBABCBCBCBABA";
    string Y = "CBABABABCBABCACBABCBABCABCBABCCBABCBABCBABCBABCBABCC";
    vec2D vec(X.size(), std::vector<int>(Y.size(), -1));
    cout << "LCS(X, Y) = " << LCS(vec, X, Y, X.size(), Y.size());
}
