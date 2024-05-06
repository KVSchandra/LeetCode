class Solution {
public:
    // only +- collides....not -+
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>st;
        for(auto val : asteroids) {
            if(!st.empty() && st.top() > 0 && val < 0) {
                bool flag = false;
                while(!st.empty() && st.top() > 0 && val < 0) {
                    if(st.top() < abs(val)) {
                        st.pop();
                    }
                    else if(st.top() > abs(val)) {
                        break;
                    }
                    else {
                        st.pop();
                        flag = true;
                        break;
                    }
                }
                if(!st.empty() && st.top() < 0 && flag == false) st.push(val);
                else if(st.empty() && flag == false) st.push(val);
            }
            else st.push(val);
        }
        vector<int>ans;
        while(!st.empty()) {ans.push_back(st.top()); st.pop();}
        reverse(ans.begin(), ans.end());
        return ans;
    }
};