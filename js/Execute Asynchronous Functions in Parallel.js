/**
 * @param {Array<Function>} functions
 * @return {Promise<any>}
 */

var promiseAll = function(functions) {
    return new Promise((resolve, reject) => {
        const results = [];
        let count = 0;
        const length = functions.length;
        
        if (length === 0) {
            resolve(results);
            return;
        }
        
        functions.forEach((fn, index) => {
            fn().then(result => {
                results[index] = result;
                count++;
                if (count === length) {
                    resolve(results);
                }
            }).catch(reject);
        });
    });
};

// Test case
const promise = promiseAll([
    () => new Promise(resolve => resolve(42)),
    () => new Promise(resolve => setTimeout(() => resolve(10), 1000)),
    () => new Promise((resolve, reject) => setTimeout(() => reject('Error occurred'), 500)),
    () => new Promise(resolve => setTimeout(() => resolve(99), 1500))
]);
promise.then(console.log).catch(console.error);

