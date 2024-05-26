class Solution:
    def removeNodes(self, head: ListNode) -> ListNode:
        stack = []
        while head:
            while stack and stack[-1].val < head.val:
                stack.pop()
            stack.append(head)
            head = head.next
        nxt = None
        while stack:
            cur = stack.pop()
            cur.next = nxt
            nxt = cur
        return nxt