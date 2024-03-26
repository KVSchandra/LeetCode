class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(int i = 0; i<s.size(); i++) {
            if(st.empty()) {
                st.push(s[i]);
            }
            else {
                if(st.size() >= 2 && st.top() == 'a' && s[i] == 'b' && s[i+1] == 'c') {
                    st.pop();
                    i++;
                }
                else if(st.size() >= 2 && st.top() == 'b' && s[i] == 'c') {
                    char c = st.top();
                    st.pop();
                    if(st.top() == 'a') {
                        st.pop();
                    }
                    else {
                        st.push(c);
                        st.push(s[i]);
                    }
                }
                else st.push(s[i]);
            }
            // else st.push(s[i]);
        }
        return st.empty();
    }
};