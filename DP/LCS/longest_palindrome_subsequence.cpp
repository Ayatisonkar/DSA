#include <bits/stdc++.h>
int longest_common_subsequence(int i, int j, string s, string t,vector<vector<int>>& dp)
{
	if(i<0 || j<0) return 0;
	int len=0;
  if(dp[i][j] != -1)
    return dp[i][j];
	if(s[i]==t[j]) dp[i][j]=1 + longest_common_subsequence(i-1, j-1, s, t,dp);
	else
		dp[i][j]=0+max(longest_common_subsequence(i, j-1, s, t,dp), longest_common_subsequence(i-1, j, s, t,dp));
	return dp[i][j];
}
int lcs(string s)
{
  string t=s;
  reverse(s.begin(),s.end());
  int n=s.size();
  int m=t.size();
  vector<vector<int>> dp(n,vector<int>(m,-1));
	return longest_common_subsequence(s.size()-1,t.size()-1,s,t,dp);
}
//Tabulation
same as LCS tabulation.
//Space optimization
same as LCS space optimization  
