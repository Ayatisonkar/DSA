class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> arr= height;
        int n=height.size();
        int leftMax=0,rightMax=0,l=0,r=n-1;
        int sum=0;
        while( l<r ){
            if(arr[l]<=arr[r]){
                if( arr[l] < leftMax ){
                    sum += leftMax - arr[l];
                   
                }
                else 
                    leftMax = arr[l];
                
                l++;
            }
            else{
                if(  arr[r] < rightMax ){
                    sum += rightMax - arr[r];
                    
                }
                else 
                    rightMax=arr[r];
                
                r--;
            }
        }
        return sum;
    }
};