/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @return {ListNode}
 */
function ListNode(val, next = null) {
    this.val = val;
    this.next = next;
}

function gcd(a, b) {
    return b === 0 ? a : gcd(b, a % b);
}

var insertGreatestCommonDivisors = function(head) {
    let curr = head;
    while (curr !== null && curr.next !== null) {
        const gcdValue = gcd(curr.val, curr.next.val);
        const gcdNode = new ListNode(gcdValue);
        
        gcdNode.next = curr.next;
        curr.next = gcdNode;
        
        curr = gcdNode.next;
    }
    return head;
};