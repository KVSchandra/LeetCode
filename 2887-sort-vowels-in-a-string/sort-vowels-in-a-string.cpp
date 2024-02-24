class Solution {
public:
    string sortVowels(string s) {
        priority_queue<pair<int, char>, vector<pair<int, char>>, greater<pair<int, char>>>pq;
        for(auto val : s){
            if(val == 'a' || val == 'e' || val == 'i' || val == 'o' || val == 'u' || val == 'A' || val == 'E' || val == 'I' || val == 'O' || val == 'U'){
                pq.push({int(val), val});
            }
        }
        // while(!pq.empty()){
        //     cout<<pq.top().second<<" ";
        //     pq.pop();
        // }
        string ans = "";
        for(auto val : s){
            if(val == 'a' || val == 'e' || val == 'i' || val == 'o' || val == 'u' || val == 'A' || val == 'E' || val == 'I' || val == 'O' || val == 'U'){
                ans += pq.top().second;
                pq.pop();
            }
            else ans += val;
        }
        return ans;
    }
};