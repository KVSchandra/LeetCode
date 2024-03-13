class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int count = 0;
        deque<int>dq;
        sort(people.begin(), people.end());
        for(auto val : people){
            dq.push_back(val);
        }
        while(!dq.empty()){
            if(dq.size() == 1){
                count++;
                break;
            }
            if(dq.front() + dq.back() > limit){
                count++;
                dq.pop_back();
            }
            else if(dq.front() + dq.back() <= limit){
                dq.pop_front();
                dq.pop_back();
                count++;
            }
        }
        return count;
    }
};