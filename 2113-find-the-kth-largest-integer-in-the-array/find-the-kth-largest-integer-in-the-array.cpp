class Solution {
public:
    static bool comp(string &s1, string &s2){
        if(s1.size() > s2.size()) return true;
        else if(s1.size() < s2.size()) return false;
        else {
            for(int i = 0; i<s1.size(); i++){
                if(s1[i] > s2[i]) return true;
                else if(s1[i] < s2[i]) return false;
            }
            return false;
        }
    }

    string kthLargestNumber(vector<string>& nums, int k) {
        sort(nums.begin(), nums.end(), comp);
        int n = nums.size();
        for(auto val : nums) cout<<val<<" ";
        return nums[k-1];
    }
};