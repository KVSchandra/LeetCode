class Solution {
public:
    bool solve(int i, int sum, string &s, int n) {
        if(i == s.size() && sum == n) return true;
        if(sum > stoi(s) || i > s.size()) return false;
        int temp = 0;
        for(int j = i; j<s.size(); j++) {
            temp = temp*10 + (s[j]-'0');
            if(solve(j+1, sum+temp, s, n)) return true;            
        }
        return false;
    }

    int punishmentNumber(int n) {
        int sum = 0;
        for(int i = 1; i<=n; i++) {
            string temp = to_string(i*i);
            if(solve(0, 0, temp, i)) sum += i*i;
        }
        return sum;
    }
};