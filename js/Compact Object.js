var compactObject = function(obj){
    if (Array.isArray(obj)) {
        return obj.map(compactObject).filter(Boolean);
    } else if (obj && typeof obj === "object") {
        return Object.fromEntries(
            Object.entries(obj)
                .map(([k, v]) => [k, compactObject(v)])
                .filter(([_, v]) => Boolean(v))
        );
    }
    return obj;
};

// Test cases
console.log(compactObject([null, 0, false, 1])); // Expected output: [0, false, 1]
console.log(compactObject({"a": null, "b": [false, 1]})); // Expected output: {"b": [false, 1]}
console.log(compactObject([null, 0, 5, [0], [false, 16]])); // Expected output: [0, 5, [0], [false, 16]]
