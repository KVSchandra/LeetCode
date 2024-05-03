class Solution {
public:
    int solve(int i, int j, string &s1, string &s2) {
        int I, J;
        bool f1 = 0, f2 = 1;
        if(i >= s1.size() && j >= s2.size()) return 0;
        if(i < s1.size()) for(I = i; I < s1.size(); I++) {
            if(s1[I] == '.') {
                f1 = 1;
                break;
            }
        }
        if(j < s2.size()) for(J = j; J < s2.size(); J++) {
            if(s2[J] == '.') {
                f2 = 1;
                break;
            }
        }
        string a = "", b = "";
        
        if(i < s1.size()){ a = (s1.substr(i, I-i)); cout << a << "s1"<<endl;}
        if(j < s2.size()){ b = (s2.substr(j, J-j)); cout << b << "s2"<<endl;}
        int A, B;
        if(f1 == 0) I = s1.size();
        if(f2 == 0) J = s2.size();
        if(a == "" && b == "") {return 0;}
        if(a == "") A = 0;
        else A = stoi(a);
        if(b == "") B = 0;
        else B = stoi(b);
        if(A > B) return 1; 
        else if(B > A) return -1;
        return solve(I+1, J+1, s1, s2);
    }

    int compareVersion(string version1, string version2) {
        int i = 0, j = 0;
        return solve(0, 0, version1, version2);
    }
};