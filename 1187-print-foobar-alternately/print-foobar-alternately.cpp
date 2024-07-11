class FooBar {
private:
    int n;
    atomic<bool> y;

public:
    FooBar(int n) {
        this->n = n;
        y = false;
    }

    void foo(function<void()> printFoo) {

        for (int i = 0; i < n; i++) {
            while (y) {
                this_thread::yield();
            }
            // printFoo() outputs "foo". Do not change or remove this line.
            printFoo();
            y = !y;
        }
    }

    void bar(function<void()> printBar) {
        for (int i = 0; i < n; i++) {
            while (!y) {
                this_thread::yield();
            }
            // printBar() outputs "bar". Do not change or remove this line.
            printBar();
            y = !y;
        }
    }
};