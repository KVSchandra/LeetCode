class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<int>pq;
        for(int i = 0; i<n; i++){
            pq.push(nums[i]);
        }
        long long sum = 0;
        while(k--){
            sum += pq.top();
            int a = pq.top()/3;
            if(pq.top() % 3) a++;
            pq.push(a);
            // cout<<pq.top()<<endl;
            pq.pop();
        }
        return sum;
    }
};