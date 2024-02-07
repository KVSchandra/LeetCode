class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>mp;
        for(int i = 0;i<s.size();i++){
            mp[s[i]]++;
        }
        priority_queue<pair<int, char>>pq;
        for(auto val : mp){
            pq.push({val.second, val.first});
        }
        string ans = "";
        while(!pq.empty()){
            int a = pq.top().first;
            while((a)--) ans += pq.top().second;
            pq.pop();
        }
        return ans;
    }
};