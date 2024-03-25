class Solution {
public:
    int maximumGroups(vector<int>& grades) {
        sort(grades.begin(), grades.end());
        int n = grades.size();
        int low = 0, high = 1000;
        while(low <= high) {
            int mid = low + (high - low)/2;
            if(mid*(mid+1)/2 == n) return mid;
            else if(mid*(mid+1)/2 > n) high = mid-1;
            else low = mid+1;
        }
        return low-1;
    }
};