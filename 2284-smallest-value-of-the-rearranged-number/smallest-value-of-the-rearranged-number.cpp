class Solution {
public:
    void getDigits(long long n, vector<long long>&v){
        if(n < 0) n*=(-1);
        while(n){
            v.push_back(n%10);
            n/=10;
        }
    }

    long long getInteger(vector<long long>&v){
        long long ans = 0;
        for(long long i = 0; i<v.size(); i++){
            ans = ans*10 + v[i];
        }
        return ans;
    }

    long long smallestNumber(long long num) {
        vector<long long>v;
        getDigits(num, v);
        sort(v.begin(), v.end());
        long long c = 0;
        for(auto val : v){
            if(val == 0) c++;
            else break;
        }
        vector<long long>ans;
        long long a = c;
        if(num > 0){
            ans.push_back(v[c]);
            while(a--) ans.push_back(0);
            for(int i = c+1; i<v.size(); i++) ans.push_back(v[i]);
        }
        else {
            reverse(v.begin(), v.end());
            for(auto val : v) ans.push_back(val);
        }
        for(auto val : ans) cout<<val<<" ";
        long long res = getInteger(ans);
        if(num < 0) res *= (-1);
        return res;
    }
};