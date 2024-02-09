class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        vector<int>ans;
        priority_queue<pair<double, pair<int, int>>>pq;
        for(int i = 0; i<arr.size()-1; i++){
            for(int j = i+1; j<arr.size(); j++){
                double a = arr[j]*1.0/arr[i];
                pq.push({a, {arr[i], arr[j]}});
            }
        }
        k--;
        // while(!pq.empty()){
        //     cout<<pq.top().first<<" "<<pq.top().second.first<<" "<<pq.top().second.second<<endl;
        //     pq.pop();
        // }
        while(k--){
            pq.pop();
        }
        ans.push_back(pq.top().second.first);
        ans.push_back(pq.top().second.second);
        return ans;
    }
};