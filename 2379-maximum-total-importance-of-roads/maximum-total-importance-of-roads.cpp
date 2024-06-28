#define ll long long
class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<ll> inDegree(n);
        for(auto val : roads) {
            inDegree[val[0]]++;
            inDegree[val[1]]++;
        }
        sort(inDegree.begin(), inDegree.end(), greater<ll>());
        long long ans = 0;
        for(ll i = 0; i < n; i++) {
            ans += ((long long)inDegree[i] * (n-i));
        }
        return ans;
    }
};