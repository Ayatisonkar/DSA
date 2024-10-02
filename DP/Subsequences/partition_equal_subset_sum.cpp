#include <bits/stdc++.h> 

bool subsetSumToK(int n, int k, vector<int> &arr,vector<vector<bool>>& dp) {
    for(int i=0;i<n-1;i++){
        dp[i][0]=true;
    }
    dp[0][arr[0]]=true;
    for(int i=1;i<n;i++){
        for(int j=1;j<=k;j++){
           bool notake=dp[i-1][j];
           bool take=false;
           if(j>=arr[i])
           take=dp[i-1][j-arr[i]];
           dp[i][j]=notake || take;
        }
    }
    return dp[n-1][k];
}
bool canPartition(vector<int> &arr, int n)
{
	int totSum = 0;

    // Calculate the total sum of the array
    for (int i = 0; i < n; i++) {
        totSum += arr[i];
    }
	if(totSum%2) return false;
	int target=totSum/2;
	vector<vector<bool>> dp(n, vector<bool>(target + 1, 0));
	return subsetSumToK(n,target,arr,dp);
}
