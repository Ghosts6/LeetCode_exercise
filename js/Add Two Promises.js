/**
 * @param {Promise} promise1
 * @param {Promise} promise2
 * @return {Promise}
 */
var addTwoPromises = async function(promise1, promise2) {
    try {
        const [result1, result2] = await Promise.all([promise1, promise2]);
        return result1 + result2;
    } catch (error) {
        throw error;
    }
};
/**
 * addTwoPromises(Promise.resolve(2), Promise.resolve(2))
 *   .then(console.log); // 4
 */