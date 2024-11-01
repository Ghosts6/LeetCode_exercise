var findMedianSortedArrays = function(nums1, nums2) {
    if (nums1.length > nums2.length) {
        return findMedianSortedArrays(nums2, nums1);
    }

    let m = nums1.length;
    let n = nums2.length;
    let halfLen = Math.floor((m + n + 1) / 2);
    let left = 0, right = m;

    while (left <= right) {
        let i = Math.floor((left + right) / 2);
        let j = halfLen - i;

        let nums1LeftMax = (i === 0) ? -Infinity : nums1[i - 1];
        let nums1RightMin = (i === m) ? Infinity : nums1[i];
        let nums2LeftMax = (j === 0) ? -Infinity : nums2[j - 1];
        let nums2RightMin = (j === n) ? Infinity : nums2[j];

        if (nums1LeftMax <= nums2RightMin && nums2LeftMax <= nums1RightMin) {
            if ((m + n) % 2 === 1) {
                return Math.max(nums1LeftMax, nums2LeftMax);
            }
            return (Math.max(nums1LeftMax, nums2LeftMax) + Math.min(nums1RightMin, nums2RightMin)) / 2;
        } else if (nums1LeftMax > nums2RightMin) {
            right = i - 1;
        } else {
            left = i + 1;
        }
    }

    throw new Error("The arrays are not sorted or input is invalid.");
};

// Test cases
console.log(findMedianSortedArrays([1, 3], [2])); // Expected output: 2.0
console.log(findMedianSortedArrays([1, 2], [3, 4])); // Expected output: 2.5
console.log(findMedianSortedArrays([0, 0], [0, 0])); // Expected output: 0.0

