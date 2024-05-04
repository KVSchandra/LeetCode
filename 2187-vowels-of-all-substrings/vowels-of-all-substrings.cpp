class Solution {
public:
    long long countVowels(string word) {
        long long count = 0;
        vector<char>v = {'a', 'e', 'i', 'o', 'u'};
        for(long long i = 0; i<word.size(); i++) {
            if(find(v.begin(), v.end(), word[i]) != v.end()) {
                count += i + word.size()-i-1 + (i)*(word.size()-i-1) + 1;
            }
        }
        return count;
    }
};