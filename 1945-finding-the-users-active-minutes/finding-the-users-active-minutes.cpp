class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        vector<int>ans(k);
        set<vector<int>>st;
        for(auto val : logs){
            st.insert(val);
        }
        logs.clear();
        int count = 0;
        if(st.size() == 1){
            ans[0]++;
            return ans;
        }
        for(auto val : st) logs.push_back(val);
        for(int i = 0; i<st.size()-1; i++){
            if(logs[i][0] == logs[i+1][0]){
                count++;
            }
            else{
                ans[count]++;
                count = 0;
            }
        }
        if(logs[st.size()-1][0] != logs[st.size()-2][0]) ans[0]++;
        if(count != 0) ans[count]++;
        return ans;
    }
};