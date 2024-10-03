
class MyCalendarTwo {
public:
  set<vector<int>> st;
  set<vector<int>> dou;
  int now = 1;
  MyCalendarTwo() {}
  bool intersect(int a, int b, int c, int d) {
    return max(a,c) < min(b,d);
  }
  bool book(int s, int e) {
    for (auto it : dou) {
      if (intersect(it[0], it[1], s, e)) return 0;
    }
    for (auto it : st) {
      if (intersect(it[0], it[1], s, e)) {
        dou.insert({max(it[0], s), min(it[1], e)});
      }
    }
    st.insert({s, e});
    return 1;
  }
};