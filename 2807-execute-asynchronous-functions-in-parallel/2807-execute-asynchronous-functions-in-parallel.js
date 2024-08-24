/**
 * @param {Array<Function>} functions
 * @return {Promise<any>}
 */
var promiseAll = function(functions) {
    return new Promise((resolve,reject) => {
        let res = Array(functions.length)
        let waitingTime = functions.length
        for(let i=0;i<functions.length;i++) {
            functions[i]().then((result)=> {
                res[i]=result
                waitingTime--;
                if(waitingTime==0) resolve(res)
            }).catch(reject)
        }
    })
};

/**
 * const promise = promiseAll([() => new Promise(res => res(42))])
 * promise.then(console.log); // [42]
 */