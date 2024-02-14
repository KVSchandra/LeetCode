class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>>ans;
        priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>>pq;
        for(int i = 0; i<points.size(); i++){
            double a = sqrt(pow(points[i][0], 2) + pow(points[i][1], 2))*1.0;
            pq.push({a, i});
        }
        while(k--){
            ans.push_back(points[pq.top().second]);
            pq.pop();
        }
        return ans;
    }
};