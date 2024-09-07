class Solution {
  private boolean test(ListNode lNode, TreeNode tNode) {
    if (lNode == null) return true;
    if (tNode == null) return false;

    return lNode.val == tNode.val && (test(lNode.next, tNode.left) || test(lNode.next, tNode.right));
  }

  public boolean isSubPath(ListNode head, TreeNode node) {
    if (node == null)
      return false;
    
    if (test(head, node))
      return true;

    return isSubPath(head, node.left) || isSubPath(head, node.right);
  }
}