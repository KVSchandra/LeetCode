#define ll long long
class Solution {
public:
    int numTriplets(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<ll, ll> mp1, mp2;
        for(ll i = 0; i < nums1.size(); i++) {
            for(ll j = i+1; j < nums1.size(); j++) {
                mp1[(ll)nums1[i] * nums1[j]]++;
            }   
        }
        for(ll i = 0; i < nums2.size(); i++) {
            for(ll j = i+1; j < nums2.size(); j++) {
                mp2[(ll)nums2[i] * nums2[j]]++;
            }   
        }
        ll count = 0;
        for(auto val : nums1) {
            if(mp2.find((ll)val*val) != mp2.end()) {
                count += mp2[(ll)val*val];
            }
        }
        for(auto val : nums2) {
            if(mp1.find((ll)val*val) != mp1.end()) {
                count += mp1[(ll)val*val];
            }
        }
        return count;
    }
};