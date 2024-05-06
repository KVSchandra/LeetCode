class Solution {
public:
    int trap(vector<int>& height) {
        int i = 0, j = height.size()-1;
        int leftMax = height[i], rightMax = height[j];
        int ans = 0;
        while(i <= j) {
            if(height[i] <= height[j]) {
                if(height[i] >= leftMax) leftMax = height[i];
                else {
                    ans += (leftMax - height[i]);
                }
                i++;
            }
            else {
                if(height[j] >= rightMax) rightMax = height[j];
                else {
                    ans += (rightMax - height[j]);
                }
                j--;
            }
        }
        return ans;
    }
};