void longestIncreasingSubsequence(int arr[], int n)
{
    vector<int> dp(n,1);
    vector<int> hash(n);
    for(int i=0;i<n;i++)
    {
        hash[i]=i;
    }
    for(int i=0;i<n;i++)
    {
      
      for(int j=0;j<i;j++)
      {
          if(arr[j]<arr[i] && dp[j]+1>dp[i])
            dp[i]=max(dp[j]+1,dp[i]);
      }
        
    }
    int maxi=INT_MIN;int ind;
    for(int i=0;i<n;i++){
      if(maxi<dp[i]){
        maxi=max(maxi,dp[i]);
        ind=i;
      }
    }
    vector<int> temp;
    while(hash[ind]!=ind)
    {
        temp.push_back(arr[ind]);
        ind=hash[ind];
    }
    reverse(temp.begin(),temp.end());
    return temp;
}
