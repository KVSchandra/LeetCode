class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int count = 0;
        int i = 0;
        int j = k;
        int sum = 0;
        for(int a = 0;a<k;a++){
            sum += arr[a];
        }
        if(sum/k >= threshold) count++;

        while(j < arr.size()){
            sum -= arr[i++];
            sum += arr[j++];
            if(sum/k >= threshold) count++;
        }
        return count;
    }
};