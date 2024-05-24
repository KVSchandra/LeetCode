class Solution {
public:
    string rev(string &s) {
        string ans = "1";
        for(int i = s.size()-1; i>=0; i--) {
            if(s[i] == '0') ans.push_back('1');
            else ans.push_back('0');
        }
        return ans;
    }

    void solve(string &temp, int n) {
        if(n == 0) return;
        temp = temp + rev(temp);
        solve(temp, n-1);
    }

    char findKthBit(int n, int k) {
        string a = "0";
        solve(a, n-1);
        // cout << a << endl;
        return a[k-1];
    }
};