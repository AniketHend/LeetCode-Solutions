class MedianFinder {
public:
    priority_queue<int> left; // max heap
    priority_queue<int> right; //min heap
    int n = 0;
    MedianFinder() {
        // if(n%2 == 1){
        //     cout << minn.top();
        // }else{
        //     cout << double( minn.top() + maxx.top() ) /2.0;
        // }
    }
    /*
            priority_queue<int> g, s;
   
    for (int i = 0; i < n; i++) {
        s.push(A[i]);
        int temp = s.top();
        s.pop();
       
        // Negation for treating it as min heap
        g.push(-1 * temp);
        if (g.size() > s.size()) {
            temp = g.top();
            g.pop();
            s.push(-1 * temp);
        }
        if (g.size() != s.size())
            cout << (double)s.top() << "\n";
        else
            cout << (double)((s.top() * 1.0 
                              - g.top() * 1.0)
                             / 2)
                 << "\n";
    }

    */
    void addNum(int num) {
        n++;

        // if(left.size() == 0  || left.top() > num){
        //     left.push(num);
        // }else{
        //     right.push(num);
        // }

        // if(left.size() > 1 + right.size() ){
        //     right.push(left.top() );
        //     left.pop();
        // }
        // else if(left.size() < right.size() ){
        //     left.push(right.top() );
        //     right.pop();
        // }

        left.push(num);
        int temp = left.top();
        left.pop();
       
        // Negation for treating it as min heap
        right.push(-1 * temp);
        if (right.size() > left.size()) {
            temp = right.top();
            right.pop();
            left.push(-1 * temp);
        }

    }
    
    double findMedian() {

        // if(left.size() == right.size() ){
        //     double mean = (left.top() + right.top())/2.0;
        //     return mean;
        // }else{
        //     return left.top();
        // }

        if (right.size() != left.size())
            return (double)left.top();
        else
            return (double)(((left.top()) * 1.0 + (-right.top()) * 1.0)/ 2);
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */