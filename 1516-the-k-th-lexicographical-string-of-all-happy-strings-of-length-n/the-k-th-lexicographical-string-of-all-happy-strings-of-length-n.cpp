class Solution {
public:
    void solve(int index, int n, vector<char>&a, string temp, vector<string>&v) {
        if(temp.size() == n) {
            v.push_back(temp);
            return;
        }
        for(auto val : a) {
            if(temp.empty() || temp.back() != val) {
                temp.push_back(val);
                solve(index, n, a, temp, v);
                temp.pop_back();
            }
        }
    }

    string getHappyString(int n, int k) {
        vector<string> v;
        vector<char> a = {'a', 'b', 'c'};
        string temp;
        solve(0, n, a, temp, v);
        if(k > v.size()) {
            return "";
        }
        return v[k - 1];
    }
};
