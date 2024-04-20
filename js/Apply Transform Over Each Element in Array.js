var map = function(arr, fn) {
    const mappedArr = [];
    for (let i = 0; i < arr.length; i++) {
        mappedArr.push(fn(arr[i], i));
    }
    return mappedArr;
};