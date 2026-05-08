class KthLargest {
public:
    priority_queue<int, vector<int>, greater<>> pq;
    int k;
    KthLargest(int k, vector<int>& nums) {
        // goal will be to keep k largest elements
        // but should we able to get the smallest one from top
        // hence use min-heap
        for(int x: nums) {
            if(pq.size() < k) pq.push(x);
            else {
                if(x > pq.top()) {
                    pq.pop();
                    pq.push(x);
                }
            }
        }
        this->k = k;
    }
    
    int add(int val) {
        if(pq.size() < k) pq.push(val);
        else {
            if(val > pq.top()) {
                pq.pop();
                pq.push(val);
            }
        }
        return pq.top();
    }
};
