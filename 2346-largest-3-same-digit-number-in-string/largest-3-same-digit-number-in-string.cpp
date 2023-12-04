class Solution {
public:
    string largestGoodInteger(string num) {
        int maxi = INT_MIN;
        string ans;
        for(int i = 0;i<num.size()-2;i++){
            if(num[i] == num[i+1] && num[i+1] == num[i+2]){
                string s;
                s += num[i];
                s += num[i];
                s += num[i];
                int a = stoi(s);
                if(maxi < a) {maxi = a;ans = s;}
            }
            
        }
        if(maxi == INT_MIN) return "";
        
        return ans;
    }
};