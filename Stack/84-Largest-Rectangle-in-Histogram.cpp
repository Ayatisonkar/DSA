class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int area=0;
        int n= heights.size();
        vector<int> left(n); vector<int> right(n);
        stack<int> st;
        for(int i=0; i<n; i++){
            while(!st.empty() && heights[st.top()]> heights[i]){
                st.pop();
            }
            left[i]=st.empty()? -1 : st.top();
            st.push(i);
        }
        while(!st.empty()){
            st.pop();
        }
        for(int i=n-1; i>=0; i--){
             while(!st.empty() && heights[st.top()]>= heights[i])
                st.pop();
            right[i]=st.empty()? n : st.top();
            st.push(i);
        }
        for(int i=0; i<n; i++){
            area = max( area, heights[i]*(right[i]-left[i]-1));

        }
        return area;

    }
};