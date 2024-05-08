class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<int>v = score;
        vector<string>ans;
        sort(v.begin(), v.end(), greater<int>());
        for(int i = 0; i<score.size(); i++) {
            int idx = find(v.begin(), v.end(), score[i]) - v.begin();
            if(idx + 1 >= 4) ans.push_back(to_string(idx+1));
            else if(idx + 1 >= 3) ans.push_back("Bronze Medal");
            else if(idx + 1 >= 2) ans.push_back("Silver Medal");
            else if(idx + 1 >= 1) ans.push_back("Gold Medal");
        }
        return ans;
    }
};