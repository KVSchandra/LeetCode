#define ll long long

class Solution {
public:
    ll solve(ll temp, ll next, ll n) {
        ll count = 0;
        while(temp <= n) {
            count += min(n + 1, next) - temp;
            temp *= 10;
            next *= 10;
        }
        return count;
    }

    int findKthNumber(int n, int k) {
        if(n == 1) {
            return 1;
        }
        ll temp = 1;
        k--;
        while(k) {
            ll count = solve(temp, temp + 1, n);
            if(count <= k) {
                temp++;
                k -= count;
            }
            else {
                temp *= 10;
                k--;
            }
        }
        return temp;
    }
};