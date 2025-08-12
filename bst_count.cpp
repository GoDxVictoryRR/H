#include <bits/stdc++.h>
using namespace std;

// Function to compute the number of unique Binary Search Trees (BSTs) 
// possible with 'n' distinct keys.
// This is essentially computing the nth Catalan number using DP.
long long numBST(int n) {
    // dp[i] will store the number of BSTs possible with i nodes.
    vector<long long> dp(n+1, 0);

    // Base cases:
    // dp[0] = 1 → empty tree
    // dp[1] = 1 → single node tree
    dp[0] = dp[1] = 1;

    // Fill dp[] for all sizes from 2 to n
    for(int i = 2; i <= n; i++) {
        // Choose each node as root (1 to i)
        for(int root = 1; root <= i; root++) {
            // Number of nodes in left subtree = root - 1
            // Number of nodes in right subtree = i - root
            // Total BSTs for this root = BST(left) * BST(right)
            dp[i] += dp[root - 1] * dp[i - root];
        }
    }

    // The result for n nodes is stored in dp[n]
    return dp[n];
}

int main() {
    int n = 5; // Example: Number of distinct nodes
    cout << "Number of BSTs with " << n 
         << " nodes: " << numBST(n) << endl;
    return 0;
}

