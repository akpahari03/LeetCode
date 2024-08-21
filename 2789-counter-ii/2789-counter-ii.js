/**
 * @param {integer} init
 * @return { increment: Function, decrement: Function, reset: Function }
 */
var createCounter = function(init) {
    let presentCount=init
    return {
        increment() {
            return ++presentCount
        },
        decrement() {
            return --presentCount
        },
        reset() {
            presentCount=init
            return presentCount
        }
    }
};

/**
 * const counter = createCounter(5)
 * counter.increment(); // 6
 * counter.reset(); // 5
 * counter.decrement(); // 4
 */