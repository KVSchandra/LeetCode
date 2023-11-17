class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int i = 0;
        int j = nums.size() - 1;
        int max = INT_MIN;
        while(i<j){
            int sum = nums[i] + nums[j];
            if(max < sum) max = sum;
            i++;j--;
        }
        return max;
    }
};