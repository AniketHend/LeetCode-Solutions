class Solution {
    private static int calc(int opnd1, int opnd2, char oper) {
        if (oper == '+') {
            return opnd1 + opnd2;
        } else if (oper == '-') {
            return opnd1 - opnd2;
        } else if (oper == '*') {
            return opnd1 * opnd2;
        } else if (oper == '/') {
            return opnd1 / opnd2;
        } else {
            return 0;
        }
    }

    private static int priority(char oper) {
        if (oper == '+') {
            return 1;
        } else if (oper == '-') {
            return 1;
        } else if (oper == '*') {
            return 2;
        } else if (oper == '/') {
            return 2;
        } else {
            return 0;
        }
    }

    public int calculate(String s) {
        Stack<Integer> opnd = new Stack<>();
        Stack<Character> oper = new Stack<>();
        for (int i = 0; i < s.length(); i++) {
            if (Character.isDigit(s.charAt(i))) {
                int num = 0;
                while (i < s.length() && Character.isDigit(s.charAt(i))) {
                    num = num * 10 + (s.charAt(i) - '0');
                    i++;
                }
                i--;
                opnd.push(num);
            } else if (s.charAt(i) == '+' || s.charAt(i) == '-' || s.charAt(i) == '*' || s.charAt(i) == '/') {
                while (!oper.isEmpty() && priority(oper.peek()) >= priority(s.charAt(i))) {
                    int opnd2 = opnd.pop();
                    int opnd1 = opnd.pop();
                    int res = calc(opnd1, opnd2, oper.pop());
                    opnd.push(res);
                }
                oper.push(s.charAt(i));
            }
        }
        while (oper.size() > 0) {
            int opnd2 = opnd.pop();
            int opnd1 = opnd.pop();
            int res = calc(opnd1, opnd2, oper.pop());
            opnd.push(res);
        }
        return opnd.peek();
    }
}
