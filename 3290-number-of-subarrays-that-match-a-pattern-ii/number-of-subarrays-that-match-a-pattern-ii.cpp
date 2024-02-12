class Solution {
public:
    // KMP ALGORITHM :- vector<int> V = KMP (string s1, string s2).
    vector<int> buildLPS(const string& p) {
        int m = p.length();
        vector<int> l(m, 0);
        int len = 0;
        for (int i = 1; i < m;) {
            if (p[i] == p[len]) {
                len++;
                l[i] = len;
                i++;
            } else {
                if (len != 0)
                    len = l[len - 1];
                else {
                    l[i] = 0;
                    i++;
                }
            }
        }
        return l;
    }
    vector<int> KMP(const string& t, const string& p) {
        int n = t.length();
        int m = p.length();
        vector<int> a, lps = buildLPS(p);
        int i = 0, j = 0;
        while (i < n) {
            if (p[j] == t[i]) {
                j++; i++;    
            }
            if (j == m) {
                a.push_back(i - j);
                j = lps[j - 1];
            } else if (i < n && p[j] != t[i]) {
                if (j != 0) j = lps[j - 1];    
                else i++;    
            }
        }
        return a;
    }

    int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
        string text = "";
        for(int i = 0; i<nums.size()-1; i++){
            if(nums[i] == nums[i+1]) text += 'a';
            if(nums[i] > nums[i+1]) text += 'b';
            if(nums[i] < nums[i+1]) text += 'c';
        }
        string pat = "";
        for(int i = 0; i<pattern.size(); i++){
            if(pattern[i] == 0) pat += 'a';
            if(pattern[i] == -1) pat += 'b';
            if(pattern[i] == 1) pat += 'c';
        }
        vector<int>ans = KMP(text, pat);
        return ans.size();
    }
};