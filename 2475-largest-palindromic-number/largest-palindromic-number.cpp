class Solution {
public:
    string largestPalindromic(string num) {
        map<char, int>mp;
        for(auto &val : num) mp[val]++;
        // for(auto val : mp) cout<<val.first<<" "<<val.second<<endl;
        string ans = "";
        for(auto &val : mp) {
            if(val.second >= 2) {
                bool flag = false;
                if(val.second%2 == 1) flag = true;
                val.second /= 2;
        
                while(val.second--) {
                    ans.push_back(val.first);
                }
                if(flag) val.second = 1;
                else val.second = -1;
            }
        }
        string a = ans;
        reverse(ans.begin(), ans.end());
        int maxi = INT_MIN;
        for(auto val : mp) {
            if(val.second >= 1) {
                maxi = max((long long)maxi, (long long)val.first);
            }
        }
        // for(auto val : mp) cout<<val.first<<" "<<val.second<<endl;
        if(maxi != INT_MIN)
        ans.push_back(maxi);
        ans += a;
        if(ans[0] == '0') {
            int i = 0, j = ans.size()-1;
            while(ans[i] == '0' && ans[j] == '0') {
                i++;
                j--;
            }
            string b = ans.substr(i, j-i+1);
            if(i > j) return "0"; 
            return b;
        }
        return ans;
    }
};