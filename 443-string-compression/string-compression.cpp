class Solution {
public:
    int compress(vector<char>& chars) {
        string ans = "";
        int count = 0;
        for(int i = 0; i<chars.size()-1; i++) {
            if(chars[i] == chars[i+1]) {
                count++;
            }
            else {
                if(count == 0) {
                    ans.push_back(chars[i]);
                    continue;
                }
                ans.push_back(chars[i]);
                ans += to_string(count+1);
                count = 0;
            }
        }
        ans.push_back(chars.back());
        if(count > 0) ans += to_string(count+1);
        chars.clear();
        for(auto val : ans) {
            chars.push_back(val);
        }
        cout<<ans<<endl;
        return ans.size();
    }
};