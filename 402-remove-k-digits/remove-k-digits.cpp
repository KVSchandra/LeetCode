class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char>st;
        for(int i = 0; i<num.size(); i++) {
            if(st.empty() || st.top() <= num[i]) {
                st.push(num[i]);
            }
            else {
                while(!st.empty() && st.top() > num[i] && k) {
                    st.pop();
                    k--;
                }
                st.push(num[i]);
            }
        }
        while(!st.empty() && k--) {
            st.pop();
        }
        string ans = "";
        while(!st.empty()) {
            ans += st.top();
            st.pop();
        }
        while(ans.size() > 0 && ans.back() == '0') ans.pop_back();
        if(ans.size() > 0) {reverse(ans.begin(), ans.end());
        return ans;}
        else return "0";
    }
};