#include <bits/stdc++.h> 
/*int paths(int m,int n,vector<vector<int>> &dp)
{
	if(m==0 && n==0)
	return dp[0][0]=1;
	if(m<0 || n<0)
	return 0;
	if(dp[m][n]!=-1)
	return dp[m][n];
	int up=paths(m-1,n,dp);
	int left=paths(m,n-1,dp);
	return dp[m][n]=up+left;
}*/
int uniquePaths(int m, int n) {
	vector<int> prev(n, 0);
	vector<int> prev2(n, 0);
    for(int i=0;i<n;i++)
	{
		prev[i]=1;
	}
	
	for(int i=1;i<m;i++)
	{
		prev2[0]=1;
		for(int j=1;j<n;j++)
		{
			  prev2[j]=prev[j]+prev2[j-1];
			 
		}
		for(int k=0;k<n;k++)
		{
			prev[k]=prev2[k];
		}
	}
	return prev[n-1];
}
