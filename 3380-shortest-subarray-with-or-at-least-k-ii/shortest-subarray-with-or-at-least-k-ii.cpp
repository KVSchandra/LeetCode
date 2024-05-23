class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int i = 0, j = 0;
        int x = 0;
        int mini = INT_MAX;
        vector<int>v(32, 0);
        while(j < nums.size()) {
            for(int b = 0; b < 32; b++) {
                if(nums[j] & (1 << b)) {
                    if(v[b] == 0) x += (1 << b);
                    v[b]++;
                }
            }
            if(x < k) {
                j++;
            }
            else {
                while(x >= k && i <= j) {
                    cout << x << " ";
                    mini = min(mini, j-i+1);
                    for(int b = 0; b<32; b++) {
                        if(nums[i] & (1 << b)) {
                            v[b]--;
                            if(v[b] == 0) {
                                x -= (1 << b);
                            }
                        }
                    }
                    i++;
                }
                j++;
            }
        }
        if(mini == INT_MAX) return -1;
        return mini;
    }
};