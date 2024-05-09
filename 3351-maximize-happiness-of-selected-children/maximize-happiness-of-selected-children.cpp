class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(), happiness.end(), greater<int>());
        int j = 0;
        long long sum = 0;
        for(int i = 0; i < happiness.size(); i++){
            k--;
            if(happiness[i] >= j) happiness[i] -= j;
            else happiness[i] = 0;
            sum += (happiness[i]);
            if(k == 0) return sum;
          
            j++;
        }
        return sum;
    }   
};