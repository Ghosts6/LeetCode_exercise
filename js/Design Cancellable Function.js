/**
 * @param {Generator} generator
 * @return {[Function, Promise]}
 */
function cancellable(generator) {
    let cancelled = false;
    let done = false;

    const cancel = () => {
        if (!done) cancelled = true;
    };

    const promise = new Promise((resolve, reject) => {
        const step = (fn, arg) => {
            if (done) return;
            try {
                const { value, done: isDone } = fn.call(generator, arg);
                done = isDone;
                if (isDone) return resolve(value);
                if (cancelled) return step(generator.throw, "Cancelled");
                Promise.resolve(value)
                    .then(val => {
                        if (cancelled) step(generator.throw, "Cancelled");
                        else step(generator.next, val);
                    })
                    .catch(err => step(generator.throw, err));
            } catch (err) {
                done = true;
                reject(err);
            }
        };

        step(generator.next);
    });

    return [cancel, promise];
}

/**
 * function* tasks() {
 *   const val = yield new Promise(resolve => resolve(2 + 2));
 *   yield new Promise(resolve => setTimeout(resolve, 100));
 *   return val + 1;
 * }
 * const [cancel, promise] = cancellable(tasks());
 * setTimeout(cancel, 50);
 * promise.catch(console.log); // logs "Cancelled" at t=50ms
 */