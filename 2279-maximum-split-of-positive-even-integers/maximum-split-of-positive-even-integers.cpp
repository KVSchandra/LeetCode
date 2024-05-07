class Solution {
public:
    vector<long long> maximumEvenSplit(long long finalSum) {
        if(finalSum&1) return {};
        vector<long long>ans;
        for(int i = 2; i<=INT_MAX; i+=2) {
            if(finalSum - i >= 0) {
                finalSum -= i;
                ans.push_back(i);
            }
            else break;
        }
        ans.back() += finalSum; 
        return ans;
    }
};