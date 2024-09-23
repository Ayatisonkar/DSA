//Recursion
#include <bits/stdc++.h> 
int coins_earned(vector<int>& a,int i,int j)
{
	if(i>j) return 0;
	int maxi=INT_MIN;
	for(int k=i;k<=j;k++)
	{
	
		int coins=a[i-1]*a[k]*a[j+1]+coins_earned(a,i,k-1)+coins_earned(a,k+1,j);
		maxi=max(maxi,coins);
	}
	return maxi;
}
int maxCoins(vector<int>& a)
{
	int n=a.size();
	int j=n;
	a.insert(a.begin(),1);
	a.push_back(1);
	int maxi=INT_MIN;
	return coins_earned(a,1,n);

}
/********************************************************************************************************************/
//Memoization
#include <bits/stdc++.h> 
int coins_earned(vector<int>& a,int i,int j,vector<vector<int>>& dp)
{
	if(i>j) return dp[i][j]=0;
	int maxi=INT_MIN;
	if(dp[i][j]!=-1)
	return dp[i][j];
	for(int k=i;k<=j;k++)
	{
	
		int coins=a[i-1]*a[k]*a[j+1]+coins_earned(a,i,k-1,dp)+coins_earned(a,k+1,j,dp);
		maxi=max(maxi,coins);
	}
	return dp[i][j]=maxi;
}
int maxCoins(vector<int>& a)
{
	int n=a.size();
	vector<vector<int>> dp(n+2,vector<int>(n+2,-1));
	
	int j=n;
	a.insert(a.begin(),1);
	a.push_back(1);
	int maxi=INT_MIN;
	return coins_earned(a,1,n,dp);

}
/*******************************************************************************************************************/
//Tabulation
#include <bits/stdc++.h> 
int maxCoins(vector<int>& a)
{
	int n=a.size();
	vector<vector<int>> dp(n+2,vector<int>(n+2,0));
	a.insert(a.begin(),1);
	a.push_back(1);
	for(int i=n;i>=1;i--)
	{
		for(int j=i;j<=n;j++){
			int maxi=INT_MIN;
			for(int k=i;k<=j;k++)
			{
				int coins=a[i-1]*a[k]*a[j+1]+dp[i][k-1]+dp[k+1][j];
				maxi=max(maxi,coins);
			}
			dp[i][j]=maxi;
		}
	}
	return dp[1][n];

}
