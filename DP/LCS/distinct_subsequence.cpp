int mod = 1000000007;
int distinctSubsequences(string &str, string &sub)
{
	string s1=str;
	string s2=sub;
	int n=s1.size();
	int m=s2.size();
	  vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    for(int i=0 ; i<=n ; i++){

        for(int j=0  ; j<=m ; j++){

            if(i==0) dp[i][j]=0;

            if(j==0) dp[i][j]=1;

            

        }

    }
	

    for (int ind1 = 1; ind1 <= n; ind1++) {
        for (int ind2 = 1; ind2 <= m; ind2++) {
            if (s1[ind1 - 1] == s2[ind2 - 1])
                dp[ind1][ind2] = (dp[ind1 - 1][ind2 - 1]+dp[ind1-1][ind2])% mod; // Characters match, increment LCS length
            else
                dp[ind1][ind2] =  dp[ind1 - 1][ind2]%mod; // Characters don't match, consider the maximum from left or above
        }
    }

    //int len= (n+m)-dp[n][m];
	return dp[n][m];
}

