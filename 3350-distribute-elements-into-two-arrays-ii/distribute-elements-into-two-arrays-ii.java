class Node {
    int key;
    int size;
    Node left;
    Node right;

    Node(int k, int s, Node l, Node r) {
        key = k;
        size = s;
        left = l;
        right = r;
    }

    Node(int k) {
        this(k, 1, null, null);
    }
}

class BalancedTree {
    private Node root;

    private void updateSize(Node node) {
        if (node != null) {
            node.size = getSize(node.left) + getSize(node.right) + 1;
        }
    }

    private Node leftRotate(Node x) {
        Node y = x.right;
        x.right = y.left;
        y.left = x;
        updateSize(x);
        updateSize(y);
        return y;
    }

    private Node rightRotate(Node y) {
        Node x = y.left;
        y.left = x.right;
        x.right = y;
        updateSize(y);
        updateSize(x);
        return x;
    }

    private Node insert(Node node, int key) {
        if (node == null) {
            return new Node(key);
        }

        if (key < node.key) {
            node.left = insert(node.left, key);
        } else {
            node.right = insert(node.right, key);
        }

        updateSize(node);

        int balance = getSize(node.left) - getSize(node.right);
        if (balance > 1) {
            return rightRotate(node);
        } else if (balance < -1) {
            return leftRotate(node);
        }

        return node;
    }

    private int greaterCount(Node node, int key) {
        if (node == null) {
            return 0;
        }

        if (key < node.key) {
            return getSize(node.right) + 1 + greaterCount(node.left, key);
        } else {
            return greaterCount(node.right, key);
        }
    }

    private int getSize(Node node) {
        return (node != null) ? node.size : 0;
    }

    BalancedTree() {
        root = null;
    }

    void insert(int key) {
        root = insert(root, key);
    }

    int greaterCount(int key) {
        return greaterCount(root, key);
    }

    int getSize() {
        return getSize(root);
    }
}
class Solution {
    public int[] resultArray(int[] nums) {
        int n = nums.length;
        if (n == 1) return nums;
        List<Integer> arr1 = new ArrayList<>();
        List<Integer> arr2 = new ArrayList<>();
        BalancedTree tree1 = new BalancedTree();
        BalancedTree tree2 = new BalancedTree();

        arr1.add(nums[0]);
        arr2.add(nums[1]);
        tree1.insert(nums[0]);
        tree2.insert(nums[1]);

        for (int i = 2; i < n; i++) {
            int cnt1 = tree1.greaterCount(nums[i]);
            int cnt2 = tree2.greaterCount(nums[i]);

            if (cnt1 > cnt2) {
                arr1.add(nums[i]);
                tree1.insert(nums[i]);
            } else if (cnt1 < cnt2) {
                arr2.add(nums[i]);
                tree2.insert(nums[i]);
            } else {
                int size1 = tree1.getSize();
                int size2 = tree2.getSize();

                if (size1 > size2) {
                    arr2.add(nums[i]);
                    tree2.insert(nums[i]);
                } else {
                    arr1.add(nums[i]);
                    tree1.insert(nums[i]);
                }
            }
        }

        arr1.addAll(arr2);
        int[] ans = new int[n];
        int j=0;
        for(int i=0;i<arr1.size();i++) {
            ans[j++]=arr1.get(i);
        }
        return ans;
    }
}