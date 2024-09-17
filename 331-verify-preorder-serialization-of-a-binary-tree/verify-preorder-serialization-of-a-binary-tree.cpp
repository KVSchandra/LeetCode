class Solution {
public:
    bool isValidSerialization(string s) {
        int count = 0;
        bool f = false;
        string temp = "";
        if(s == "#") return true;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == ',') {
                if(temp.size() != 0) {
                    if(f == false) {
                        count += 2;
                        f = true;
                    }
                    else if(f && count != 0) {
                        count++;
                    }
                    else {
                        return false;
                    }
                    temp.clear();
                }
                else if(count == 0) return false;
                else {
                    count--;
                }
                temp.clear();
            }
            else {
                if(s[i] != '#') {
                    temp.push_back(s[i]);
                }
            }  
        }
        if(temp.size()) count++;
        else count--;
        if(count != 0) return false;
        return true;   
    }
};