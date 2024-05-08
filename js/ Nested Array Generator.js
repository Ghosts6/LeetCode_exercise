var inorderTraversal = function*(arr) {
        for (let item of arr) {
        if (Array.isArray(item)) {
            yield* inorderTraversal(item);
        } else {
            yield item;
        }
    }
};

const arr = [1, [2, 3], 4, [5, [6, 7]]];
const generator = inorderTraversal(arr);
for (let val of generator) {
    console.log(val);
}