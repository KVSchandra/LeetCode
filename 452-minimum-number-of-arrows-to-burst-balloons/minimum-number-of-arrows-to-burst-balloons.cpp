class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        int count = 0;
        int prev = points[0][1];
        for(int i = 0; i<points.size(); i++){
            if(points[i][0] > prev){
                prev = points[i][1];
                count++;
            }
            else prev = min(prev, points[i][1]);
        }
        return count + 1;
    }
};