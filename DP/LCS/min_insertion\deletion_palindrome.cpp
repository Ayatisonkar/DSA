
int canYouMake(string &s1, string &s2){
    // Write your code here.
    int n = s1.size();
    int m = s2.size();
    // Create a 2D DP table with dimensions (n+1) x (m+1)
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    int ans = 0; // Initialize the answer variable

    for (int ind1 = 1; ind1 <= n; ind1++) {
        for (int ind2 = 1; ind2 <= m; ind2++) {
            if (s1[ind1 - 1] == s2[ind2 - 1])
                dp[ind1][ind2] = 1 + dp[ind1 - 1][ind2 - 1]; // Characters match, increment LCS length
            else
                dp[ind1][ind2] = max(dp[ind1 - 1][ind2], dp[ind1][ind2 - 1]); // Characters don't match, consider the maximum from left or above
        }
    }

    return (n+m)-2*dp[n][m];
    
}
