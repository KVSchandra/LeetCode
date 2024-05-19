/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLastWord = function(s) {
    let str = s.trim();
    let i = str.length-1;
    while(i >= 0 && str[i] != ' ') {
        i--;
    }
    // console.log(str);
    return str.length-1-i;
};