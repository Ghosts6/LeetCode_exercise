var distributeCoins = function(root) {
    let moves = 0;

    function postorder(node) {
        if (!node) return 0;
        const leftBalance = postorder(node.left);
        const rightBalance = postorder(node.right);
        const balance = node.val + leftBalance + rightBalance - 1;
        moves += Math.abs(balance);
        return balance;
    }

    postorder(root);
    return moves;
};