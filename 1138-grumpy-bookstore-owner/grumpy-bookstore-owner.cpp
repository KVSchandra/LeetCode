class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int i = 0, j = 0;
        int sum = 0;
        int a = 0;
        while(j < minutes) {
            if (grumpy[j] == 1) sum += customers[j];
            else a += customers[j];
            j++;
        }
        int maxi = sum; 

        while(j < customers.size()) {
            if (grumpy[j] == 1) sum += customers[j];
            else a += customers[j];
            if (grumpy[i] == 1) sum -= customers[i];
            maxi = max(maxi, sum);
            i++;
            j++;
        }
        return a + maxi;
    }
};
