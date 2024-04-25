class Solution {
public:
    int minimumDistance(vector<vector<int>>& points) {
        multiset<int>st1, st2;
        for(auto val : points) {
            st1.insert(val[0] + val[1]);
            st2.insert(val[0] - val[1]);
        }
        int mini = INT_MAX;
        for(auto val : points) {
            st1.erase(st1.find(val[0]+val[1]));
            st2.erase(st2.find(val[0]-val[1]));

            mini = min(mini, max(*st1.rbegin()-*st1.begin(), *st2.rbegin()-*st2.begin()));

            st1.insert(val[0]+val[1]);
            st2.insert(val[0]-val[1]);
        }
        return mini;
    }
};