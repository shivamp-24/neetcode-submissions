class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(char ch: s) {
            if(ch == '(' || ch == '{' || ch == '[') st.push(ch);
            else {
                if(st.empty()) return false;
                if((ch == ')' && st.top() != '(') || (ch == '}' && st.top() != '{') || (ch == ']' && st.top() != '[')) {
                    return false;
                } else st.pop();
            }
        }

        return st.empty();

        // instead of so many if-else, we can create a mapping of {close, non-close} brackets
    }
};
