#include <bits/stdc++.h> 
int solve(vector<int> &weight,vector<int> &value,int n,int maxWeight)
{
	/*Recursion
	if(n==0)
	{
		if(weight[0]<=maxWeight)
		return value[0];
		else
		return 0;
	}
	int inc=value[n]+solve(weight,value,n-1,maxWeight-weight[n]);
	int exc=solve(weight,value,n-1,maxWeight);
	return max(inc,exc);*/
	//memoisation
	/*if(n==0)
	{
		if(weight[0]<=maxWeight)
		return value[0];
		else
		return 0;
	}
	if(dp[n][maxWeight]!=-1)
	return dp[n][maxWeight];
	int inc=0;
	if(weight[n]<=maxWeight)
	inc=value[n]+solve(weight,value,n-1,maxWeight-weight[n],dp);
	int exc=solve(weight,value,n-1,maxWeight,dp)+0;
	dp[n][maxWeight]=max(inc,exc);
	return dp[n][maxWeight];*/
	//tabulation
	vector<vector<int>> dp(n,vector<int>(maxWeight+1,0));
	if(n==0)
	{
		if(weight[0]<=maxWeight)
		return value[0];
		else
		return 0;
	}
	
	for(int w=weight[0];w<=maxWeight;w++)
	{
		if(weight[0]<=maxWeight)
		dp[0][w]=value[0];
		else
		dp[0][w]=0;
	}
	for(int index=1;index<n;index++)
	{
		for(int w=0;w<=maxWeight;w++)
		{
			int include=0;
			if(weight[index]<=w)
			include=value[index]+dp[index-1][w-weight[index]];
			int exclude=0+dp[index-1][w];
			dp[index][w]=max(exclude,include);
		}
	}
	return dp[n-1][maxWeight];
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	//vector<vector<int>> dp(n,vector<int>(maxWeight+1,-1));
     return solve(weight,value,n-1,maxWeight);
   //return solve(weight,value,n-1,maxWeight);
}
