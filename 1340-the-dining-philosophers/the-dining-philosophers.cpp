class DiningPhilosophers {
    mutex m;
    condition_variable cv;
    int busy[5];

public:
    DiningPhilosophers() {
        for (int i = 0; i < 5; ++i)
            busy[i] = 0;
    }

    void wantsToEat(int i, function<void()> pickLeftFork,
                    function<void()> pickRightFork, function<void()> eat,
                    function<void()> putLeftFork,
                    function<void()> putRightFork) {
        unique_lock<mutex> lock(m);
        while (busy[(i - 1 + 5) % 5] == 1 || busy[(i + 1) % 5] == 1) {
            cv.wait(lock);
        }
        pickLeftFork();
        pickRightFork();
        eat();
        putLeftFork();
        putRightFork();
        cv.notify_all();
    }
};