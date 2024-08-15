class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int count1 = 0, count2 = 0;
        for(auto val : bills) {
            if(val == 5) {
                count1++;
            }
            else if(val == 10) {
                if(count1) {
                    count1--;
                    count2++;
                }
                else {
                    return false;
                }
            }
            else {
                if(count2) {
                    count2--;
                    if(count1) {
                        count1--;
                    }
                    else {
                        return false;
                    }
                }
                else {
                    if(count1 >= 3) {
                        count1 -= 3;
                    }
                    else {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};