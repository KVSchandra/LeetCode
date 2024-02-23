class Solution {
public:
    int solve(int i){
        if(i == 1) return 0;
        if((i & 1) == 0){
           return 1 + solve(i/2);
        }
        if(i & 1) return 1 + solve(3*i + 1);
        return 0;
    }

    int getKth(int lo, int hi, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
        for(int i = lo; i<=hi; i++){
            pq.push({solve(i), i});
           
        }
        k--;
        while(!pq.empty() && k--){
            // cout<<pq.top().second<<','<<pq.top().first<<" ";
            pq.pop();
        }

        return pq.top().second;
    }
};