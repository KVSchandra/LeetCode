#define ll long long
class Solution {
public: 
    bool isPalindrome(ll n) {
        string s = to_string(n);
        ll i = 0, j = s.size()-1;
        while(i <= j) {
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }

    ll smaller(ll n) {
        while(isPalindrome(n) == 0) {
            n--;
        }
        return n;
    }

    ll larger(ll n) {
        while(isPalindrome(n) == 0) {
            n++;
        }
        return n;
    }

    long long minimumCost(vector<int>& nums) {
        ll ans = 0;
        sort(nums.begin(), nums.end());
        ll m = nums.size()/2;
        ll num = nums[m];
        ll x1 = smaller(num);
        ll x2 = larger(num);
        ll sum1 = 0, sum2 = 0;
        for(ll i = 0; i < nums.size(); i++) {
            sum1 += abs(nums[i] - x1);
            sum2 += abs(nums[i] - x2);
        }
        return min(sum1, sum2);
    }
};