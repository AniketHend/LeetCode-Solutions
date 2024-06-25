#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

template <typename T>
using oset =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using omset = tree<T, null_type, less_equal<T>, rb_tree_tag,
                   tree_order_statistics_node_update>;

class MedianFinder {
    omset<int> v;
    int n;

public:
    MedianFinder() { n = 0; }

    void addNum(int num) {
        v.insert(num);
        n++;
    }

    double findMedian() {
        if (n % 2 == 1) {
            return *(v.find_by_order(n/2));
        } else {
            int ans = 0;
            ans += *(v.find_by_order(n/2));
            ans += *(v.find_by_order(n/2-1));
            return (double)(ans) / 2;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */