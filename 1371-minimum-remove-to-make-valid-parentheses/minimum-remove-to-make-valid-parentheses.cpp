class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<char>st;
        vector<int>v;
        st.push('a');
        for(int i = 0; i<s.size(); i++){
            if(s[i] != '(' && s[i] != ')') continue;
            else{
                if(s[i] == '('){
                    st.push(s[i]);
                }
                else{
                    if(st.top() == '('){
                        st.pop();
                    }
                    else{
                        v.push_back(i);
                    }
                }
            }
        }
        if(st.size() > 1){
            for(int i = s.size()-1; i>=0; i--){
                if(s[i] == '('){
                    v.push_back(i);
                    st.pop();
                    if(st.size() == 1) break;
                }
            }
        }
        string ans = "";
        for(int i = 0; i<s.size(); i++){
            if(find(v.begin(), v.end(), i) != v.end()) continue;
            ans += s[i];
        }
        return ans;
    }
};