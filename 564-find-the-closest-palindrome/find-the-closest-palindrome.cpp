#define ll long long

class Solution {
public:
    string smaller(string s) {
        ll i = 0, j = s.size()-1;
        bool flag = false;

        while(i < j) {
            if(s[i] < s[j]) {
                flag = true;
            }
            else if(s[i] > s[j]) flag = false;
            s[j] = s[i];
            i++; j--;
        } 

        if(flag) return s;

        ll n = s.size();
        if(n%2 == 1) {
            i = n/2;
            j = n/2;
        }
        else {
            i = (n-1)/2;
            j = n/2;
        }

        while(i >= 0) {
            if(s[i] == '0') {
                s[i] = '9';
                s[j] = '9';
            }
            else {
                s[i] -= 1;
                s[j] = s[i];
                break;
            }
            i--; j++;
        }
        if(s[0] == '0') {
            s[n-1] = '9';
            reverse(s.begin(), s.end());
            s.pop_back();
            reverse(s.begin(), s.end());
        }
        return s;
    }

    string larger(string s) {
        ll i = 0, j = s.size()-1;
        bool flag = false;

        while(i < j) {
            if(s[i] > s[j]) {
                flag = true;
            }
            else if(s[i] < s[j]) flag = false;
            s[j] = s[i];
            i++; j--;
        } 

        if(flag) return s;

        ll n = s.size();
        if(n%2 == 1) {
            i = n/2;
            j = n/2;
        }
        else {
            i = (n-1)/2;
            j = n/2;
        }

        while(i >= 0) {
            if(s[i] == '9') {
                s[i] = '0';
                s[j] = '0';
            }
            else {
                s[i] += 1;
                s[j] = s[i];
                break;
            }
            i--; j++;
        }
        return s;
    }

    bool isPalindrome(string s) {
        ll i = 0, j = s.size()-1;
        while(i <= j) {
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }

    string nearestPalindromic(string n) {
        if(n.size() == 1) {
            n[0] -= 1;
            return n;
        }
        ll N, A, B;
        string a, b;
        if(isPalindrome(n)) {
            N = stoll(n);
            N--;
            a = smaller(to_string(N));
            N+=2;
            b = larger(to_string(N));
            N--;
        }
        else {
            N = stoll(n);
            a = smaller(n);
            b = larger(n);
        }
        cout<<a<<" "<<b<<endl;
        // cout<<A<<" "<<B<<" "<<N<<endl;
        
        if(abs(N - stoll(a)) <= abs(N-stoll(b))) return a;
        return b;
    }
};