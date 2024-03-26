class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        map<pair<int, int>, vector<int>> mp;
        for(int i = 0; i<points.size()-1; i++) {
            for(int j = i+1; j<points.size(); j++) {
                if(points[i][0] == points[j][0]) {
                    mp[{points[i][1], points[j][1]}].push_back(points[i][0]);
                }
                else break;
            }
        }
        int mini = INT_MAX;
        for(auto val : mp) {
            if(val.second.size() >= 2) {
                int m = INT_MAX;
                for(int i = 0; i<val.second.size()-1; i++){
                    if(val.second[i+1] - val.second[i] < m) {
                        m = val.second[i+1] - val.second[i];
                    }
                }
                int a = val.first.second - val.first.first;
                mini = min(mini, a*m);
            }
        }
        if(mini == INT_MAX) mini = 0;
        return mini;
    }
};
