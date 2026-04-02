class MedianFinder {
priority_queue<int> q;
public:
    MedianFinder() {
    }
    void addNum(int num) {
        q.push(num);
    }
    
    double findMedian() {
        int n = q.size();
        deque<int> tmp;
        double ans;
        if(n&1){
            for(int i = 0; i < n/2; i++) tmp.push_back(q.top()), q.pop();
            ans = (double)q.top();
        }
        else{
            for(int i = 0; i < n/2-1; i++) tmp.push_back(q.top()), q.pop();
            double x, y;
            x = (double)q.top();
            tmp.push_back(q.top());
            q.pop();
            y = (double)q.top();
            ans = (x+y)/2;
        }
        while(!tmp.empty()) q.push(tmp.back()), tmp.pop_back();
        return ans;
    }
};
