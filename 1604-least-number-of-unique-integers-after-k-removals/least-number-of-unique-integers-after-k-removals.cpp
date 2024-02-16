class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int>mp;
        for(auto val : arr){
            mp[val]++;
        }
        priority_queue<int, vector<int>, greater<int>>pq;
        for(auto val : mp){
            pq.push(val.second);
        }
        while(k >= pq.top()){
            k -= pq.top();
            pq.pop();
        }
        return pq.size();
    }
};