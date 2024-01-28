class Solution {
public:
    bool canMeasureWater(int n1, int n2, int t) {
        if(n1 + n2 == t || n1 == t || n2 == t) return true;
        if(n1 + n2 < t) return false;
        vector<int>dir = {n1, -n1, n2, -n2};
        queue<int>q;
        q.push(0);
        vector<int>vis(n1+n2+1, 0);
        vis[0] = 1;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            if(node == t) return true;
            for(int i = 0; i<4; i++){
                int j = node + dir[i];
                if(j>=0 && j<=(n1+n2) && !vis[j]){
                    q.push(j);
                    vis[j] = 1;
                }
            }
        }
        return false;
    }
};