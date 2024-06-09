var reverseWords = function(s) {
    return s.trim().split(/\s+/).reverse().join(' ');
};

// test case
let s = "hello world";
console.log(reverseWords(s));