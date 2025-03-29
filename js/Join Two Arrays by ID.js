var join = function(arr1, arr2) {
    const map = new Map();

    [...arr1, ...arr2].forEach(obj => {
        if (map.has(obj.id)) {
            Object.assign(map.get(obj.id), obj);
        } else {
            map.set(obj.id, { ...obj });
        }
    });

    return [...map.values()].sort((a, b) => a.id - b.id);
};

// Test cases

// Case 1
const arr1_1 = [
    { "id": 1, "x": 2, "y": 3 },
    { "id": 2, "x": 3, "y": 6 }
];

const arr1_2 = [
    { "id": 2, "x": 10, "y": 20 },
    { "id": 3, "x": 0, "y": 0 }
];

console.log(join(arr1_1, arr1_2)); 

// Case 2
const arr2_1 = [
    { "id": 1, "b": { "b": 94 }, "v": [4, 3], "y": 48 }
];

const arr2_2 = [
    { "id": 1, "b": { "c": 84 }, "v": [1, 3] }
];

console.log(join(arr2_1, arr2_2)); 

// Case 3
const arr3_1 = [
    { "id": 1, "x": 2, "y": 3 },
    { "id": 2, "x": 3, "y": 6 }
];

const arr3_2 = [
    { "id": 2, "x": 10, "y": 20 },
    { "id": 3, "x": 0, "y": 0 }
];

console.log(join(arr3_1, arr3_2)); 
