class KthLargest {
public:
    priority_queue<int, vector<int>, greater<>> pq;
    int k;
    KthLargest(int k, vector<int>& nums) {
        // goal will be to keep k largest elements
        // but should we able to get the smallest one from top
        // hence use min-heap
        for(int x: nums) {
            pq.push(x);
            if(pq.size() > k) pq.pop();
        }
        this->k = k;
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size() > k) pq.pop();
        return pq.top();
    }
};
