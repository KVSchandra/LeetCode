class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int>pq;
        for(int i = 0; i<heights.size()-1; i++){
            if(heights[i+1] > heights[i]){
                pq.push(heights[i+1] - heights[i]);
                bricks -= heights[i+1] - heights[i];
                if(bricks < 0){
                    bricks += pq.top();
                    pq.pop();
                    ladders--;
                }
                if(ladders < 0 || bricks < 0){
                    return i;
                }
            }
        }
        return heights.size() - 1;
    }
};