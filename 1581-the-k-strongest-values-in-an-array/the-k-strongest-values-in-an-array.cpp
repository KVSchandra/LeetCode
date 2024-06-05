class Solution {
public:
    vector<int> getStrongest(vector<int>& arr, int k) {
        priority_queue<pair<int, int>>pq;
        sort(arr.begin(), arr.end());
        int m = arr[(arr.size()-1)/2];
        for(auto val : arr) {
            pq.push({abs(val-m), val});
        }
        vector<int>ans;
        while(k--) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};