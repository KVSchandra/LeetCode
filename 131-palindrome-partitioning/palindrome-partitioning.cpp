class Solution {
public:
    bool isPalindrome(int i, int j, string &s) {
        while(i < j) {
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }

    void solve(int i, vector<string> &temp, string &s, vector<vector<string>>&ans) {
        if(i == s.size()) {
            ans.push_back(temp);
            return;
        }
        for(int j = i; j<s.size(); j++) {
            if(isPalindrome(i, j, s)) {
                temp.push_back(s.substr(i, j-i+1));
                solve(j+1, temp, s, ans);
                temp.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>temp;
        solve(0, temp, s, ans);
        return ans;
    }
};