class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int>st;
        vector<int>ple(n), nle(n);
        for(int i = 0; i<n; i++) {
            while(!st.empty() && heights[i] <= heights[st.top()]) {
                st.pop();
            }
            if(st.empty()) ple[i] = i;
            else ple[i] = i-st.top()-1;
            st.push(i);
        }
        while(!st.empty()) st.pop();
        for(int i = n-1; i>=0; i--) {
            while(!st.empty() && heights[i] < heights[st.top()]) {
                st.pop();
            }
            if(st.empty()) nle[i] = n-i-1;
            else nle[i] = st.top()-i-1;
            st.push(i);
        }
        long long maxi = INT_MIN;
        // for(auto val : ple) cout << val << " ";
        // cout << endl;
        // for(auto val : nle) cout << val << " ";
        // cout << endl;
        for(int i = 0; i<n; i++) {
            long long left = (ple[i]+1)*heights[i];
            long long right = (nle[i]+1)*heights[i];
            maxi = max(maxi, (long long)left + right - heights[i]);
        }
        return maxi;
    }
};