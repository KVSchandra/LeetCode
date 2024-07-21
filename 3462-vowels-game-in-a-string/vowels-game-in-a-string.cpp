class Solution {
public:
    bool doesAliceWin(string s) {
        int count = 0;
        for(auto val : s) {
            if(val == 'a' || val == 'e' || val == 'i' || val == 'o' || val == 'u') {
                count++;
            }
        }
        if(count == 0) return false;
        return true;
    }
};