class Solution {
public:
    string customSortString(string order, string s) {
        string ans = "";
        unordered_map<char, int>mp;
        for(auto val : s) mp[val]++;
        for(int i = 0; i<order.size(); i++){
            if(mp.find(order[i]) != mp.end()){
                while(mp[order[i]]--){
                    ans += order[i];
                }
            }
        }
        // for(auto val : mp) cout<<val.first<<" "<<val.second<<endl;
        // cout<<ans<<endl;
        for(auto val : mp){
            if(val.second >= 1){
                int a = val.second;
                while(a--){
                    ans += val.first;
                }
            }
        }
        
        return ans;
    }
};