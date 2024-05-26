var removeNodes = function(head) {
    const stack = [];
    while (head) {
        while (stack.length && stack[stack.length - 1].val < head.val) {
            stack.pop();
        }
        stack.push(head);
        head = head.next;
    }
    let nxt = null;
    while (stack.length) {
        const cur = stack.pop();
        cur.next = nxt;
        nxt = cur;
    }
    return nxt;
};