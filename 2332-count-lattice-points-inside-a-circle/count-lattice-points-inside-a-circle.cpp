class Solution {
public:
    int countLatticePoints(vector<vector<int>>& circles) {
        map<pair<int, int>, int> mp;
        for(auto val : circles) {
            for(int i = 0; i <= 200; i++) {
                for(int j = 0; j <= 200; j++) {
                    if(((val[0] - i)*(val[0]-i)) + ((val[1] - j)*(val[1]-j)) <= val[2]*val[2]) {
                        mp[{i, j}]++;
                    }
                }
            }
        }
        return mp.size();
    }
};