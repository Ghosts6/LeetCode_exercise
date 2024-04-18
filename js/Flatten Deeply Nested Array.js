/**
 * @param {Array} arr
 * @param {number} depth
 * @return {Array}
 */
var flat = function(arr, n) {
    const result = [];
    
    const flatten = (arr, depth, currentDepth) => {
        for (let i = 0; i < arr.length; i++) {
            if (Array.isArray(arr[i]) && currentDepth < depth) {
                flatten(arr[i], depth, currentDepth + 1);
            } else {
                result.push(arr[i]);
            }
        }
    };
    
    flatten(arr, n, 0);
    return result;
};
