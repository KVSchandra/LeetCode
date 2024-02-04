class Solution {
public:
    int longestBeautifulSubstring(string word) {
        int n = word.size();
        int maxi = 0;
        int count = 1;
        int vowels = 1;
        for(int i = 0; i<n-1; i++){
            if(word[i] == word[i+1]){
                count++;
            }
            else if(word[i] < word[i+1]){
                vowels++;
                count++;
            }
            else {
                count = 1;
                vowels = 1;
            }
            if(vowels == 5){
                maxi = max(maxi, count);
            }
        }
        return maxi;
    }
};