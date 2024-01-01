class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int n = s.size();
        int m = g.size();
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int count = 0;
        int i = n-1;
        int j = m-1;
        while(i >= 0 && j >= 0) {
            if(s[i] >= g[j]) {
                count++;
                i--;
                j--;
            }
            else j--;
        }
        return count;
    }
};