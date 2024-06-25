class Solution {
    /*
  https://codeforces.com/contest/1778/submission/191586789
  https://codeforces.com/blog/entry/68953
*/
template<class T, int B> struct bit_trie {
  vector<array<long long, 2>> trie = {{0, 0}};
  vector<long long> cnt = {0};

  bit_trie() {}

  bit_trie(int elements) {
    trie.reserve(elements * B);
    cnt.reserve(elements * B);
  }

  void update(T val, int delta) {
    int node = 0;
    for (int i = B - 1; i >= 0; i--) {
      int c = val & (1ll << i) ? 1 : 0;
      if (!trie[node][c]) {
        trie[node][c] = trie.size();
        trie.push_back({0, 0});
        cnt.push_back(0);
      }
      node = trie[node][c];
      cnt[node] += delta;
    }
  }

  void insert(T val) {
    update(val, 1);
  }

  void erase(T val) {
    update(val, -1);
  }

  T max(T val) {
    // Find max of val XOR element
    T res = 0;
    int node = 0;
    for (int i = B - 1; i >= 0; i--) {
      int c = val & (1ll << i) ? 0 : 1;
      if (trie[node][c] && cnt[trie[node][c]]) {
        res ^= 1ll << i;
        node = trie[node][c];
      } else node = trie[node][c ^ 1];
    }
    return res;
  }

  T min(T val) {
    // Find min of val XOR element
    T res = 0;
    int node = 0;
    for (int i = B - 1; i >= 0; i--) {
      int c = val & (1ll << i) ? 1 : 0;
      if (trie[node][c] && cnt[trie[node][c]]) node = trie[node][c];
      else {
        res ^= 1ll << i;
        node = trie[node][c ^ 1];
      }
    }
    return res;
  }

  int less_than(T val, T limit) {
    // How many elements satisfy val XOR element < limit ?
    int res = 0, node = 0;
    for (int i = B - 1; i >= 0; i--) {
      int c = val & (1ll << i) ? 1 : 0;
      if (limit & (1ll << i)) {
        res += cnt[trie[node][c]];
        if (trie[node][c ^ 1] && cnt[trie[node][c ^ 1]]) node = trie[node][c ^ 1];
        else break;
      } else {
        if (trie[node][c] && cnt[trie[node][c]]) node = trie[node][c];
        else break;
      }
    }
    return res;
  }
};
public:
    int findMaximumXOR(vector<int>& nums) {
        bit_trie<long long,31> t(nums.size());
        for (auto i : nums)
            t.insert(i);
        long long a = 0;
        for (auto i : nums) {
            a = max(a, t.max(i));
        }
        return a;
    }
};