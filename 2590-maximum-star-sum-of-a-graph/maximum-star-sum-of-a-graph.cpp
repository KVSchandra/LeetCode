class Solution {
public:
    int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) {
        int n = vals.size();
        vector<int>adj[n];
        for(auto val : edges){
            adj[val[0]].push_back(val[1]);
            adj[val[1]].push_back(val[0]);
        }
        int maxi = INT_MIN;
        for(int i = 0; i<n; i++){
            priority_queue<pair<int, int>>pq;
            for(auto val : adj[i]){
                pq.push({vals[val], val});
            }
            int sum = 0;
            int c = k;
            
            while(c-- && !pq.empty()){
                if(pq.top().first < 0) { break;}
                sum += pq.top().first;
                // c++;
                pq.pop();
            }
            maxi = max(maxi, sum + vals[i]);
        }
        // for(int i = 0; i<n; i++){
        //     for(auto val : adj[i]){
        //         cout<<val<<" ";
        //     }
        //     cout<<endl;
        // }
        return maxi;
    }
};