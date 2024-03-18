class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int i = 0;
        int j = 1;
        vector<int>v;
        while(j < intervals.size()){
            if(intervals[i][1] >= intervals[j][0]){
                intervals[i][1] = max(intervals[j][1], intervals[i][1]);
                v.push_back(j);
                j++;
            }
            else {
                i++;
                j = i+1;
            }
        }
        vector<vector<int>>ans;
        for(int i = 0; i<intervals.size(); i++){
            if(find(v.begin(), v.end(), i) != v.end()){
                continue;
            }
            ans.push_back(intervals[i]);
        }
        return ans;
    }
};