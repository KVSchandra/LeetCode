class Solution {
public:
    int myAtoi(string s) {
        int n=s.size();
        double num=0;
        int i=0,plus=0,minus=0;
        int sign;
        int max=INT_MAX,min=INT_MIN;
        while(s[i]==' ') ++i;
        if(s[i]=='+'){sign=1;++i;plus++;}
        if(s[i]=='-'){sign=-1;++i;minus++;}

        while(s[i]>='0' && s[i]<='9' && i<n){
            if(num<=min || num>=max) {break;}
            num=(num*10)+(s[i]-'0');
            if(num<=min || num>=max) {break;}
            i++;
        }
        num=sign*num;
        if(num>=max)num=max;
        else if(num<=min) num=min;
        if(plus && minus) return 0;
        return num;
    }
};