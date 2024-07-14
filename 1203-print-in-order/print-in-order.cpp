class Foo {
    std::mutex m;
    std::condition_variable cv;
    int cnt = 0;

public:
    Foo() { cnt = 0; }

    void first(function<void()> printFirst) {
        std::unique_lock<std::mutex> lock(m);
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        cnt = 1;
        cv.notify_all();
    }

    void second(function<void()> printSecond) {
        std::unique_lock<std::mutex> lock(m);
        while (cnt != 1) {
            cv.wait(lock);
        }
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        cnt = 2;
        cv.notify_all();
    }

    void third(function<void()> printThird) {
        std::unique_lock<std::mutex> lock(m);
        while (cnt != 2) {
            cv.wait(lock);
        }
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
        cnt = 0;
        cv.notify_all();
    }
};