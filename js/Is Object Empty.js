/**
 * @param {Object|Array} obj
 * @return {boolean}
 */
var isEmpty = function(obj) {
    if(Object.entries(obj).length===0){
        return true;
    }else{
        return false;
    }
};