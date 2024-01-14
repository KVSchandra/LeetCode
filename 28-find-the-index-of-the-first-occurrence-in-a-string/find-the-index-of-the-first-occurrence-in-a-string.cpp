class Solution {
public:
vector<int> buildLPS(const string& p){int m=p.length();vector<int> l(m,0);int len=0;for(int i=1;i<m;){if(p[i]==p[len]){len++;l[i]=len;i++;}else{if(len!=0)len=l[len-1];else{l[i]=0;i++;}}}return l;}
int KMP(const string& t,const string& p){int n=t.length(),m=p.length();vector<int> a,lps=buildLPS(p);int i=0,j=0;while(i<n){if(p[j]==t[i]){j++;i++;}if(j==m){return (i-j);j=lps[j-1];}
else if(i<n&&p[j]!=t[i]){if(j!=0)j=lps[j-1];else i++;}}return -1;}

    int strStr(string haystack, string needle) {
        int ans = KMP(haystack, needle);
        return ans;
    }
};