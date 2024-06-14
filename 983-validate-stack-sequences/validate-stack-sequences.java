class Solution {
    public boolean validateStackSequences(int[] pushed, int[] popped) {
        int j = 0;
        Stack<Integer> st = new Stack<>();
        for (int i = 0; i < pushed.length; i++) {
            st.push(pushed[i]);
            while (j < popped.length && st.size() > 0 && st.peek() == popped[j]) {
                st.pop();
                j++;
            }
            // if (pushed[i] == popped[j]) {
            // // i++;
            // j++;
            // } else if (st.size() > 0 && popped[j] == st.peek()) {
            // st.pop();
            // j++;
            // } else {
            // // i++;
            // }
        }
        while (j < popped.length) {
            if (popped[j] != st.peek()) {
                return false;
            }
            st.pop();
            j++;
        }
        return true;
    }
}