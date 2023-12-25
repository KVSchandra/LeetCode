class Solution {
public:
    int minimumDeletions(string s) {
        stack<char>st;
        int count = 0;
        st.push(-1);
        st.push(s[0]);
        for(int i = 1; i<s.size(); i++){
            if(st.top() == 'b' && s[i] == 'a'){
                st.pop();
                count++;
            }
            else st.push(s[i]);
        }
        return count;
    }
};