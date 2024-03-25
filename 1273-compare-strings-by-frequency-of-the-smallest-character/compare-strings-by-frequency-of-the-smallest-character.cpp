class Solution {
public:
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        vector<int>ans;
        vector<int>v;
        vector<int>q;
        for(int i = 0; i<queries.size(); i++) {
            sort(queries[i].begin(), queries[i].end());
            q.push_back(count(queries[i].begin(), queries[i].end(), queries[i][0]));
        }
        for(int i = 0; i<words.size(); i++) {
            sort(words[i].begin(), words[i].end());
            char a = words[i][0];
            v.push_back(count(words[i].begin(), words[i].end(), a)); 
        }
        sort(v.begin(), v.end());
        for(int i = 0; i<q.size(); i++) {
            int a = upper_bound(v.begin(), v.end(), q[i]) - v.begin();
            ans.push_back(v.size() - a);
        }
        return ans;
    }
};