var TimeLimitedCache = function() {
   this.cache = new Map(); 
};

/** 
 * @param {number} key
 * @param {number} value
 * @param {number} duration time until expiration in ms
 * @return {boolean} if un-expired key already existed
 */
TimeLimitedCache.prototype.set = function(key, value, duration) {
    const currentTime = Date.now();
    const expirationTime = currentTime + duration;

    const existing = this.cache.get(key);
    
    if (existing && existing.expiration > currentTime) {
        clearTimeout(existing.timeoutId); 
        existing.timeoutId = this._setExpiration(key, duration); 
        this.cache.set(key, { value, expiration: expirationTime, timeoutId: existing.timeoutId });
        return true;  
    } else {
        const timeoutId = this._setExpiration(key, duration);
        this.cache.set(key, { value, expiration: expirationTime, timeoutId });
        return false;  
    }
};

/** 
 * @param {number} key
 * @return {number} value associated with key
 */
TimeLimitedCache.prototype.get = function(key) {
    const currentTime = Date.now();
    const entry = this.cache.get(key);

    if (entry && entry.expiration > currentTime) {
        return entry.value;  
    } else {
        return -1;  
    } 
};

/** 
 * @return {number} count of non-expired keys
 */
TimeLimitedCache.prototype.count = function() {
    const currentTime = Date.now();
    let count = 0;

    for (let [key, entry] of this.cache) {
        if (entry.expiration > currentTime) {
            count++;
        }
    }

    return count;   
};

TimeLimitedCache.prototype._setExpiration = function(key, duration) {
    return setTimeout(() => {
        this.cache.delete(key);  
    }, duration);
};

/**
 * const timeLimitedCache = new TimeLimitedCache()
 * timeLimitedCache.set(1, 42, 1000); // false
 * timeLimitedCache.get(1) // 42
 * timeLimitedCache.count() // 1
 */