#define ll long long

class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char, ll> mp;
        for(auto val : s) mp[val]++;
        stack<char>st;
        vector<int>vis(26, false);
        for(ll i= 0; i<s.size(); i++) {
            mp[s[i]]--;
            if(vis[s[i]-'a']) continue;
            while(!st.empty() && st.top() > s[i] && mp[st.top()] > 0) {
                vis[st.top() - 'a'] = false; 
                st.pop();
            }
            st.push(s[i]);
            vis[s[i] - 'a']++; 
        }
        string ans = "";
        while(!st.empty()) {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};