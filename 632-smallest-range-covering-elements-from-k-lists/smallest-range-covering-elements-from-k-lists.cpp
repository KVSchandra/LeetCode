class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        set<pair<int, int>>st;
        if(nums.size() == 1) return {nums[0][0], nums[0][0]};
        for(int i = 0; i<nums.size(); i++){
            for(int j = 0 ; j<nums[i].size(); j++){
                st.insert({nums[i][j], i});
            }
        }
        // for(auto val : st) cout<<val.first<<" "<<val.second<<endl;
        vector<pair<int, int>>v;
        for(auto val : st) v.push_back(val);
        int a = -1, b = -1;
        deque<int>dq;
        int mini = INT_MAX;
        int i = 0 ,j = 0;
        unordered_map<int, int>mp;
        while(j < v.size()){
            dq.push_back(v[j].second);
            mp[v[j].second]++;
            if(mp.size() < nums.size()){
                j++;
            }
            else {
                while(mp.size() == nums.size() && i < j){
                    mp[dq.front()]--;
                    if(mp[dq.front()] == 0){
                        mp.erase(dq.front());
                    }
                    dq.pop_front();
                    i++;
                }
                if(mini > v[j].first - v[i-1].first){
                    mini = v[j].first - v[i-1].first;
                    a = v[i-1].first;
                    b = v[j].first;
                }
                j++;
            }
        }
        return {a, b};
    }
};