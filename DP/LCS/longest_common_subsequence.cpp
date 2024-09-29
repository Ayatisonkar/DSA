//Recursion
int longest_common_subsequence(int i, int j, string s, string t)
{
	if(i<0 || j<0) return 0;
	int len=0;
	if(s[i]==t[j]) len=1 + longest_common_subsequence(i-1, j-1, s, t);
	else
		len=0+max(longest_common_subsequence(i, j-1, s, t), longest_common_subsequence(i-1, j, s, t));
	return len;
}
int lcs(string s, string t)
{
	return longest_common_subsequence(s.size()-1,t.size()-1,s,t);
}
//Memoisation
int longest_common_subsequence(int i, int j, string s, string t,vector<vector<int>>& dp)
{
	if(i<0 || j<0) return 0;
	int len=0;
  if(dp[i][j] != -1)
    return dp[i][j];
	if(s[i]==t[j]) dp[i][j]=1 + longest_common_subsequence(i-1, j-1, s, t);
	else
		dp[i][j]=0+max(longest_common_subsequence(i, j-1, s, t), longest_common_subsequence(i-1, j, s, t));
	return dp[i][j];
}
int lcs(string s, string t)
{
  int n=s.size();
  int m=t.size();
  vector<vector<int>> dp(n,vector<int>(m,-1));
	return longest_common_subsequence(s.size()-1,t.size()-1,s,t);
}
//Tabulation
int lcs(string s, string t)
{
  int n=s.size();
  int m=t.size();
  vector<vector<int>> dp(n+1,vector<int>(m+1,0));
  dp[0][0]=0;
   for (int i = 0; i <= n; i++) {
        dp[i][0] = 0;
    }
    for (int i = 0; i <= m; i++) {
        dp[0][i] = 0;
    }
   for (int ind1 = 1; ind1 <= n; ind1++) {
        for (int ind2 = 1; ind2 <= m; ind2++) {
            if (s1[ind1 - 1] == s2[ind2 - 1])
                dp[ind1][ind2] = 1 + dp[ind1 - 1][ind2 - 1]; // Characters match, increment LCS length
            else
                dp[ind1][ind2] = max(dp[ind1 - 1][ind2], dp[ind1][ind2 - 1]); // Characters don't match, consider the maximum from left or above
        }
    }

    return dp[n][m];
	
}
