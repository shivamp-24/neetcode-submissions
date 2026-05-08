class Solution {
// private:
//     long long findHash(string &str) {
//         int hashValue = 0;
//         //estimate max value of hashValue
//         // all z -> 100 * 26^26
//         // 100 * 2^26 * 13^26 -> large int value
//         // it will be grater than long long range
//         // need to use some other way of hashing
//     }
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // we can use hashing
        // custom hashing -> convert string into integers using some formula
        // abc -> 26 + 26^2 + 26^3
        // string -> integer => sum(26^(str[i] - 'a' + 1))
        // but in this technique, the max value of hash can be very large
        // hence will sort each string for uniqueness
        // unordered_map<string, vector<string>> mp;
        // for(auto str: strs) {
        //     // find hash of str
        //     string temp = str;
        //     sort(str.begin(), str.end());
        //     mp[str].push_back(temp);
        // }

        // vector<vector<string>> res;
        // for(auto it: mp) {
        //     res.push_back(it.second);
        // }
        // return res;

        //complexity of above is m*n*logn, m-> total number of strings, n -> average length of strings

        //need to find a algo to solve it in m*n
        // we know only 26 characters are there
        // use a hashmap as key of mapping
        map<vector<int>, vector<string>> mp;
        for(auto str: strs) {
            vector<int> hsh(26, 0);
            for(auto ch: str) hsh[ch - 'a']++;

            mp[hsh].push_back(str);
        }
        vector<vector<string>> res;
        for(auto it: mp) res.push_back(it.second);
        return res;
    }
};
