class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(int x: stones) pq.push(x);

        while(pq.size() > 1) {
            int x = pq.top();
            pq.pop();
            int y = pq.top();
            pq.pop();

            int newWt = abs(x - y);
            if(newWt) pq.push(newWt);
        }
        return pq.empty() ? 0 : pq.top();
    }
};
