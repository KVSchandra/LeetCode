static bool cmp(string& s1, string& s2) {
    return (s1 + s2) > (s2 + s1);
}

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> temp;
        for(auto val : nums) {
            temp.push_back(to_string(val));
        }
        sort(temp.begin(), temp.end(), cmp);
        string ans = "";
        for(auto val : temp) {
            ans += val;
        }
        if(ans[0] == '0') return "0";
        return ans;
    }
};