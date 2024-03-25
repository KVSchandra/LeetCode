class Solution {
public:
    bool solve(string s, vector<long double>&v) {
        if(s.empty()) return v.size() >= 2;
        for(long double i = 0; i<s.size(); i++) {
            long double num = stold(s.substr(0, i+1));
            if(v.size() == 0 || v.back()-num == 1) {
                v.push_back(num);
                if(solve(s.substr(i+1), v)) {
                    return true;
                }
                v.pop_back();
            }
        }
        return false;
    }

    bool splitString(string s) {
        vector<long double>v;
        bool flag = solve(s, v);
        // for(auto val : v) cout<<val<<" ";
        return flag;
    }
};