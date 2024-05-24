/**
 * @param {number[]} queries
 * @param {number} m
 * @return {number[]}
 */
var processQueries = function(queries, m) {
    let arr = [];
    let ans = [];
    for(let i = 1; i<=m; i++) arr.push(i);
    for(let val of queries) {
        let idx = arr.indexOf(val);
        ans.push(idx);
        arr.splice(idx, 1);
        arr.splice(0, 0, val);
    }   
    return ans;
};