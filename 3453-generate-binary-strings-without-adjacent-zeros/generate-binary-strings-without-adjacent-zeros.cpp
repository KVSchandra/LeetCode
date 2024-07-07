class Solution {
public:
    void solve(int i, int count, int n, string &temp, vector<string>&ans) {
        if(i == n) {
            ans.push_back(temp);
            return;
        }
        if(count < 1) {
            temp.push_back('0');
            solve(i+1, count+1, n, temp, ans);
            temp.pop_back();
        }
        temp.push_back('1');
        solve(i+1, 0, n, temp, ans);
        temp.pop_back();
    }
    
    vector<string> validStrings(int n) {
        vector<string> ans;
        string temp = "";
        solve(0, 0, n, temp, ans);
        return ans;
    }
};