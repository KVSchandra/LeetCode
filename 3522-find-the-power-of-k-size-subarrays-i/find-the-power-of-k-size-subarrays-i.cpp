#define ll long long
class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        ll n = nums.size();
        vector<int> ans(n - k + 1, -1);
        ll i = 0, j = 0;
        while(j < n) {
            if(j+1 < n && nums[j+1] - nums[j] == 1) {
                if(j-i+1 >= k) {
                    ans[i] = nums[j];
                    i++;
                }
                j++;
            }
            else {
                if(j-i+1 >= k) {
                    ans[i] = nums[j];
                }
                else if(j == n-1) {
                    if(nums[j] - nums[j-1] == 1 && j-i+1 >= k) {
                        ans[i] = nums[j];
                    } 
                }
                i = j+1;
                j++;
            }
        }
        return ans;
    }
};