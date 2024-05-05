function expect(val) {
    return {
        toBe: function(expectedValue) {
            if (val !== expectedValue) {
                throw new Error("Not Equal");
            }
            return true;
        },
        notToBe: function(expectedValue) {
            if (val === expectedValue) {
                throw new Error("Equal");
            }
            return true;
        }
    };
}