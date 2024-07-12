class Solution {
public:
    int solve(string&str, char a, char b){
        int count = 0;
        stack<char>st;
        for(int i = 0; i<str.length(); i++) {
            if(!st.empty() && str[i]==b && st.top()==a) {
                st.pop();
                count++;
            }
            else {
                st.push(str[i]);
            }
        }
        str = "";
        while(!st.empty()) {
            str += st.top();
              st.pop();
            }
        reverse(str.begin(),str.end());
        return count;
    }
    
    int maximumGain(string s, int x, int y) {
        int ca = 0, cb =  0;
        if(x > y) {
            ca = solve(s, 'a', 'b');
            cb = solve(s, 'b', 'a');
        }
        else {
            cb = solve(s, 'b', 'a');
            ca = solve(s, 'a', 'b');
        }
        return ca*x + cb*y;
    }
};