#include <bits/stdc++.h> 

void subsetSumToK(int n, int k, vector<int> &arr,vector<vector<bool>>& dp) {
    for(int i=0;i<n-1;i++){
        dp[i][0]=true;
    }
	if(arr[0]==k)
    dp[0][arr[0]]=true;
	for(int i=1;i<k+1;i++)
    for(int i=1;i<n;i++){
        for(int j=1;j<=k;j++){
           bool notake=dp[i-1][j];
           bool take=false;
           if(j>=arr[i])
           take=dp[i-1][j-arr[i]];
           dp[i][j]=notake || take;
        }
    }
    
}
int minSubsetSumDifference(vector<int>& arr, int n)
{
	int totSum = 0;

    // Calculate the total sum of the array
    for (int i = 0; i < n; i++) {
        totSum += arr[i];
    }
	vector<vector<bool>> dp(n, vector<bool>(totSum+1, 0));
	int mini = 1e9;
	subsetSumToK(n,totSum,arr,dp);
    for (int i = 0; i <= totSum; i++) {
        if (dp[n - 1][i] == true) {
            // Calculate the absolute difference between two subset sums
            int diff = abs(i - (totSum - i));
            mini = min(mini, diff);
        }
}
return mini;
}
