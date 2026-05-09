class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        // find the next greater element
        // int n = temperatures.size();
        // stack<int> st;
        // vector<int> res(n);
        // for(int i=n-1; i>=0; i--) {
        //     while(!st.empty() && temperatures[st.top()] <= temperatures[i]) {
        //         st.pop();
        //     }

        //     if(!st.empty())  res[i] = st.top() - i;

        //     st.push(i);
        // }
        // return res;

        // do it without stack
        int n = temperatures.size();
        vector<int> res(n, 0);
        // we will utilise the results that we have already calculated

        // for each i, we will look for the day on right with greater temperature
        // instead of moving one step at a time, we will utilise results already calculated

        for(int i=n-2; i>=0; i--) {
            int j = i + 1;
            while(j < n && temperatures[i] >= temperatures[j]) {
                // we will move j to res[j]
                if(res[j] == 0) {
                    j = n;
                    break;
                }
                j += res[j];
            }

            if(j < n) res[i] = j - i;
        }
        return res;
    }
};
