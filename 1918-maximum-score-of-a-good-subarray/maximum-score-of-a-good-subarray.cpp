class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int maxi = nums[k];
        int mini = nums[k];
        int i = k, j = k;
        while(i > 0 || j < nums.size()-1) {
            int a = -1, b = -1;
            if(i-1 >= 0) a = nums[i-1];
            if(j+1 < nums.size()) b = nums[j+1];
            if(a == -1 && b == -1) break;
            if(a > b) {
                mini = min(mini, a);
                i--;
            }
            else if(a < b) {
                mini = min(mini, b);
                j++;
            }
            else {
                mini = min(mini, a);
                i--;
                j++;
            }
            maxi = max(maxi, (j-i+1)*mini);
        }
        return maxi;
    }
};