var cancellable = function(fn, args, t) {
    let cancelled = false;
    const result = [];
    const start = performance.now();

    const executeFn = () => {
        if (!cancelled) {
            const time = Math.floor(performance.now() - start);
            const returned = fn(...args);
            result.push({ "time": time, "returned": returned });
        }
    };

    executeFn();

    const intervalId = setInterval(executeFn, t);

    const cancelFn = () => {
        cancelled = true;
        clearInterval(intervalId);
    };

    return cancelFn;
};

// Test cases

const testCancellable = (fn, args, t, cancelTimeMs) => {
    const cancelFn = cancellable(fn, args, t);
    setTimeout(cancelFn, cancelTimeMs);
    setTimeout(() => {
        console.log("Result:", result);
    }, cancelTimeMs + t + 15);
};

const fn1 = (x) => x * 2;
const args1 = [4], t1 = 35, cancelTimeMs1 = 190;
testCancellable(fn1, args1, t1, cancelTimeMs1);

const fn2 = (x1, x2) => x1 * x2;
const args2 = [2, 5], t2 = 30, cancelTimeMs2 = 165;
testCancellable(fn2, args2, t2, cancelTimeMs2);

const fn3 = (x1, x2, x3) => x1 + x2 + x3;
const args3 = [5, 1, 3], t3 = 50, cancelTimeMs3 = 180;
testCancellable(fn3, args3, t3, cancelTimeMs3);

