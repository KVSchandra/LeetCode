class Solution {
public:
    bool reorderedPowerOf2(int n) {
       string s = to_string(n);
       if(n == 1 || n == 2 || n == 4 || n == 8) return true;
       sort(s.begin(), s.end());
       if((stoi(s) & (stoi(s)-1)) == 0 && s[0] != '0') return true;
       while(next_permutation(s.begin(), s.end())){
            if(s[0] == '0') continue;
            if((stoi(s) & (stoi(s) - 1)) == 0) return true;
       } 
       return false;
    }
};