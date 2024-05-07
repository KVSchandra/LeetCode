class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        long long count = 0;
        long long sum = 0;
        for(long long i = 0; i<capacity.size(); i++) {
            capacity[i] = (capacity[i] - rocks[i]);
            sum += capacity[i];
        }
        if(sum <= additionalRocks) return capacity.size();
        sort(capacity.begin(), capacity.end());
        for(long long i = 0; i<capacity.size(); i++) {
            if(additionalRocks >= capacity[i]) additionalRocks -= capacity[i];
            else break;
            count++;
        }
        return count;
    }
};