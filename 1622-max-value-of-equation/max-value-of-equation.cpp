class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, int>> pq;
        int maxi = INT_MIN;
        for(auto val : points) {
            while(!pq.empty() && val[0] - pq.top().second > k) {
                pq.pop();
            }
            if(!pq.empty()) {
                maxi = max(maxi, pq.top().first + val[0] + val[1]);
            }
            pq.push({val[1] - val[0], val[0]});
        }
        return maxi;
    }
};