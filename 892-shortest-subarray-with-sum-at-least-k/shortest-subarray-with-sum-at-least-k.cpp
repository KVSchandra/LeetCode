#define ll long long
class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        ll sum = 0;
        ll mini = INT_MAX;
        priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
        for(ll i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if(sum >= k)
                mini = min(mini, i+1);
            while(!pq.empty() && (sum - pq.top().first >= k)) {
                mini = min(mini, i - pq.top().second);
                pq.pop();
            }
            pq.push({sum, i});
        }
        if(sum >= k) mini = min(mini, (ll)nums.size());
        if(mini == INT_MAX) return -1;
        return mini;
    }
};