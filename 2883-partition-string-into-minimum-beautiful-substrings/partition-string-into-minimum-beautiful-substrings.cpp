class Solution {
public:
    bool check(string s) {
        reverse(s.begin(), s.end());
        int num = 0;
        for(int i = 0; i<s.size(); i++) {
            if(s[i] == '1') num += (1 << i);
        }
        // cout << num << endl;
        while(num) {
            if(num%5 == 0 || num == 1) num/=5;
            else return false;
        }
        return true;
    }

    int solve(int idx, string &s) {
        if(idx == s.size()) return 0;
        int mini = INT_MAX;
        int count = 0;
        string temp = "";
        for(int i = idx; i<s.size(); i++) {
            temp += s[i];
            if(temp[0] == '0') break;
            if(check(temp)) {
                mini = min((long long)mini, (long long)1 + solve(i+1, s));
            }
        }
        return mini;
    }

    int minimumBeautifulSubstrings(string s) {
        // cout << check("101") << endl;
        int a = solve(0, s);
        if(a >= INT_MAX) return -1;
        return a;
    }
};