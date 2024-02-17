class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int>v = nums;
        sort(v.begin(), v.end());
        int a = -1, b = -1;
        for(int i = 0; i<v.size(); i++){
            if(v[i] != nums[i]){
                a = i;
                break;
            }
        }
        for(int i = nums.size()-1; i>=0; i--){
            if(v[i] != nums[i]){
                b = i;
                break;
            }
        }
        if(a == -1 && b == -1) return 0;
        return abs(b-a) + 1;
    }
};