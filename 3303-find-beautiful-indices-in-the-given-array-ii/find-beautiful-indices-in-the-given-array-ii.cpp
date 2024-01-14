class Solution {
public:
    vector<int> buildLPS(const string& p){int m=p.length();vector<int> l(m,0);int len=0;for(int i=1;i<m;){if(p[i]==p[len]){len++;l[i]=len;i++;}else{if(len!=0)len=l[len-1];else{l[i]=0;i++;}}}return l;}
vector<int> KMP(const string& t,const string& p){int n=t.length(),m=p.length();vector<int> a,lps=buildLPS(p);int i=0,j=0;while(i<n){if(p[j]==t[i]){j++;i++;}if(j==m){a.push_back(i-j);j=lps[j-1];}
else if(i<n&&p[j]!=t[i]){if(j!=0)j=lps[j-1];else i++;}}return a;}
    
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        vector<int> v1 = KMP(s, a);
        vector<int> v2 = KMP(s, b);
        vector<int>ans;
        int j = 0;
        for(long long i = 0; i<v1.size(); i++){
            while(j < v2.size() && v1[i] > v2[j] && abs(v1[i] - v2[j]) > k) j++;
            if(j < v2.size() && abs(v1[i] - v2[j]) <= k) ans.push_back(v1[i]);
        }
        return ans;
    }
};