class TimeLimitedCache {
    constructor() {
        this.cache =  new Map()
    }
    set(key,value,duration) {
        const alreadyExists = this.cache.get(key)
        if(alreadyExists) {
            clearTimeout(alreadyExists.timeOutId)
        }
        const timeOutId = setTimeout(() => {
            this.cache.delete(key)
        },duration)

        this.cache.set(key,{value,timeOutId})
        return Boolean(alreadyExists)
    }
    get(key) {
        if(this.cache.has(key)) {
            return this.cache.get(key).value
        }
        return -1;
    }
    count() {
        return this.cache.size
    }

}