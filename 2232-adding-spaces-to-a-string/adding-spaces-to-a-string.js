/**
 * @param {string} s
 * @param {number[]} spaces
 * @return {string}
 */
var addSpaces = function(s, spaces) {
    let arr = s.split('');
    for(let val of spaces) {
        arr[val] = ` ${arr[val]}`;
    }
    return arr.join('');
};