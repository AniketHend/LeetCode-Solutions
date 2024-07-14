class FizzBuzz {
private:
    int n;
    mutex m;
    condition_variable cv;
    int num;

public:
    FizzBuzz(int n) {
        this->n = n;
        this->num = 1;
    }

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz) {
        while (num <= n) {
            unique_lock<mutex> lock(m);
            while (num <= n && ((num % 3 == 0 && num % 5 != 0)) == 0) {
                cv.wait(lock);
            }
            if (num <= n) {
                printFizz();
                num++;
            }
            cv.notify_all();
        }
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz) {
        while (num <= n) {
            unique_lock<mutex> lock(m);
            while (num <= n && ((num % 5 == 0 && num % 3 != 0)) == 0) {
                cv.wait(lock);
            }
            if (num <= n) {
                printBuzz();
                num++;
            }
            cv.notify_all();
        }
    }

    // printFizzBuzz() outputs "fizzbuzz".
    void fizzbuzz(function<void()> printFizzBuzz) {
        while (num <= n) {
            unique_lock<mutex> lock(m);
            while (num <= n && ((num % 3 == 0 && num % 5 == 0)) == 0) {
                cv.wait(lock);
            }
            if (num <= n) {
                printFizzBuzz();
                num++;
            }
            cv.notify_all();
        }
    }

    // 1 2 4 6 7 8 11 13 14
    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber) {
        while (num <= n) {
            unique_lock<mutex> lock(m);
            while (num <= n && ((num % 3 != 0 && num % 5 != 0)) == 0) {
                cv.wait(lock);
            }
            if (num <= n) {
                printNumber(num++);
            }
            cv.notify_all();
        }
    }
};