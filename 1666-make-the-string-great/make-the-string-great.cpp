class Solution {
public:
    string makeGood(string s) {
        stack<char>st;
        st.push('1');
        for(int i = 0; i<s.size(); i++){
            if(st.top() != '1' && ((st.top() - 'a' == s[i] - 'A') || (s[i] - 'a' == st.top() - 'A')) ){
                st.pop();
            }
            else st.push(s[i]);
        }
        string ans = "";
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        ans.pop_back();
        reverse(ans.begin(), ans.end());
        return ans;
    }
};