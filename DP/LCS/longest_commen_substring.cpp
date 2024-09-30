//Recursive
int longest_common_substring(int i, int j, int count, const string &s, const string &t) {
    // Base case: if any index is out of bounds, return the count of common characters
    if (i < 0 || j < 0) return count;

    // If characters match, continue the substring and increase count
    if (s[i] == t[j]) {
        count = longest_common_substring(i - 1, j - 1, count + 1, s, t);
    }

    // Return the max between continuing the substring and resetting the count
    return count;
}

int lcs(string &str1, string &str2) {
    int maxi = 0;  // To keep track of the maximum length of the common substring
   string s=str1;
   string t=str2;
    // Try every combination of substrings in the two strings
    for (int i = 0; i < s.size(); i++) {
        for (int j = 0; j < t.size(); j++) {
            // Call the recursive function and update the maximum length
            maxi = max(maxi, longest_common_substring(i, j, 0, s, t));
        }
    }

    return maxi;
}
//Memoisation
int longest_common_substring(int i, int j, const string &s, const string &t, vector<vector<int>>& dp) {
    // Base case: if any index is out of bounds, return 0
    if (i < 0 || j < 0) return 0;

    // If the subproblem has already been solved, return the stored result
    if (dp[i][j] != -1) return dp[i][j];

    // If characters match, continue expanding the common substring
    if (s[i] == t[j]) {
        dp[i][j] = 1 + longest_common_substring(i - 1, j - 1, s, t, dp);
    } else {
        dp[i][j] = 0;  // Reset the count if characters do not match
    }

    return dp[i][j];
}

int lcs(string &str1, string &str2) {
    int maxi = 0;  // To keep track of the maximum length of the common substring
    int n = str1.size();
    int m = str2.size();

    // Initialize the DP table with -1 (indicating uncalculated states)
    vector<vector<int>> dp(n, vector<int>(m, -1));

    // Try every combination of substrings in the two strings
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            // Call the memoized recursive function and update the maximum length
            maxi = max(maxi, longest_common_substring(i, j, str1, str2, dp));
        }
    }

    return maxi;
//Tabulation
int lcs(string &str1, string &str2) {
    string s1=str1;
    string s2=str2;
    int n = s1.size();
    int m = s2.size();
    
    // Create a 2D DP table with dimensions (n+1) x (m+1)
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    int ans = 0; // Initialize the answer variable

    for(int i = 1; i <=n ; i++){
        for(int j = 1; j <= m; j++){
            if(s1[i-1] == s2[j-1]){
                int val = 1 + dp[i-1][j-1]; // Characters match, increment substring length
                dp[i][j] = val; // Update the DP table
                ans = max(ans, val); // Update the maximum substring length found so far
            }
            else
                dp[i][j] = 0; // Characters don't match, substring length becomes 0
        }
    }
    
    return ans; // Return 
}
//space optimization
int lcs(string &str1, string &str2) {
vector<int> prev(m+1, 0); // Stores values of the previous row
    vector<int> cur(m+1, 0);  // Stores values of the current row

    int ans = 0; // Initialize the answer variable to store the maximum LCS length found
    
    // Loop through both strings
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(s1[i-1] == s2[j-1]){
                int val = 1 + prev[j-1]; // Characters match, increment substring length
                cur[j] = val; // Update the current row with the new value
                ans = max(ans, val); // Update the maximum substring length found so far
            }
            else
                cur[j] = 0; // Characters don't match, substring length becomes 0
        }
        prev = cur; // Update the previous row with the values of the current row
    }
    
    return ans; // Return the length of the Longest Common 
}
