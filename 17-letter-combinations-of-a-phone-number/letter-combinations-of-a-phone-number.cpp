class Solution {
public:
    void solve(int i, string temp, string digits, vector<string>&v, vector<string> &ans) {
        if(i == digits.size()) {
            ans.push_back(temp);
            return;
        }
        string s = v[digits[i]-'0'];
        for(int j = 0; j<s.size(); j++) {
            temp.push_back(s[j]);
            solve(i+1, temp, digits, v, ans);
            temp.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0) return {};
        vector<string>v = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string>ans;
        solve(0, "", digits, v, ans);
        return ans;
    }
};