class Solution {
private:
    bool isAlphaNum(char ch) {
        return (ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9');
    }
public:
    bool isPalindrome(string s) {
        int left = 0, right = s.size() - 1;
        while(left < right) {
            if(!isAlphaNum(s[left])) {
                left++;
                continue;
            }
            if(!isAlphaNum(s[right])) {
                right--;
                continue;
            }
            if(s[left] >= 'A' && s[left] <= 'Z') s[left] += 32;
            if(s[right] >= 'A' && s[right] <= 'Z') s[right] += 32;
            if(s[left++] != s[right--]) return false;
        }
        return true;
    }
};
