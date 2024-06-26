class Solution {
public:
    // OPTIMAL ONE PASS SOLUTION TO FIND MAX AREA OF HISTOGRAM
    //TC : O(N) + O(N), SC : O(N)
    int maxAreaHistogram(vector<int>&heights) {
        int n = heights.size();
        int maxi = INT_MIN;
        stack<int>st;
        for(int i = 0; i<=n; i++) {
            while(!st.empty() && (i == n || heights[i] <= heights[st.top()])) {
                int h = heights[st.top()];
                st.pop();
                int width;
                if(st.empty()) width = i;
                else width = i-st.top()-1;
                maxi = max(maxi, width*h);
            }
            st.push(i);
        }
        return maxi;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<int>heights(m, 0);
        int maxi = INT_MIN;
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<m; j++) {
                if(matrix[i][j] == '1') {
                    heights[j]++;
                }
                else heights[j] = 0;
            }
            maxi = max(maxi, maxAreaHistogram(heights));
        }   
        return maxi;
    }
};