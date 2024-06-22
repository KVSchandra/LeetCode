#define ll long long
class Solution {
public:
    int minOperations(vector<int>& nums) {
        ll i = 0;
        ll j = 2;
        ll count = 0;
        while(j < nums.size()) {
            if(nums[i] == 0) {
                count++;
                for(ll k = i; k <= j; k++) {
                    nums[k] = !nums[k];
                }
            }
            i++;
            j++;
        }
        if(nums.back() == 0 || nums[nums.size()-2] == 0) {
            return -1;
        }
        return count;
    }
};