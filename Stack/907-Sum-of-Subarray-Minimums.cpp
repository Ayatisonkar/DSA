class Solution {
public:
    int MOD = 1e9 + 7;
    
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        stack<int> st;
        long long sum = 0;
        
        // Vector to store the distance to the previous smaller element
        vector<int> left(n);
        // Vector to store the distance to the next smaller element
        vector<int> right(n);
        
        // Find previous smaller element distance
        for (int i = 0; i < n; ++i) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            left[i] = st.empty() ? i + 1 : i - st.top();
            st.push(i);
        }
        
        // Clear the stack for the next calculation
        while (!st.empty()) {
            st.pop();
        }
        
        // Find next smaller element distance
        for (int i = n - 1; i >= 0; --i) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            right[i] = st.empty() ? n - i : st.top() - i;
            st.push(i);
        }
        
        // Calculate the sum of the minimums of all subarrays
        for (int i = 0; i < n; ++i) {
            sum = (sum + (long long)arr[i] * left[i] * right[i]) % MOD;
        }
        
        return sum;
    }
};
