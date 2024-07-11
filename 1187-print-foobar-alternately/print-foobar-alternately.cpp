
static const int _ = []() {ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); return 0;}();

class FooBar {
private:
    int n;
    std::condition_variable turn;
    std::mutex m;
    std::atomic<bool> isFooTurn;

public:
    FooBar(int n) {
        this->n = n;
        isFooTurn.store(true); // Start with foo's turn
    }

    void foo(std::function<void()> printFoo) {
        std::unique_lock<std::mutex> lock(m);
        for (int i = 0; i < n; i++) {
            // Wait until it's foo's turn
            turn.wait(lock, [this]() { return isFooTurn.load(); });
            // Print "foo"
            printFoo();
            // Change the turn to bar
            isFooTurn.store(false);
            // Notify one waiting thread (bar) to proceed
            turn.notify_one();
        }
    }

    void bar(std::function<void()> printBar) {
        std::unique_lock<std::mutex> lock(m);
        for (int i = 0; i < n; i++) {
            // Wait until it's bar's turn
            turn.wait(lock, [this]() { return !isFooTurn.load(); });
            // Print "bar"
            printBar();
            // Change the turn to foo
            isFooTurn.store(true);
            // Notify one waiting thread (foo) to proceed
            turn.notify_one();
        }
    }
};