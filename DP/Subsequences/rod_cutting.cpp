int max_cost(vector<int> &price,int n, int m,vector<vector<int>>& dp){
	 if (n == 0) return 0;

   
    if (m == 0) return 0;

    if (dp[n][m] != -1) return dp[n][m];

    int notake = max_cost(price, n, m - 1, dp);

    
    int take = INT_MIN;
    if (m <= n) {
        take = price[m - 1] + max_cost(price, n - m, m, dp);
    }


    dp[n][m] = max(take, notake);
    return dp[n][m];
}
int cutRod(vector<int> &price, int n)
{
	int m=price.size();int i=1;
	vector<vector<int>> dp(n+1 ,vector<int>(m+1,-1));
	return max_cost(price,n,m,dp);
}
