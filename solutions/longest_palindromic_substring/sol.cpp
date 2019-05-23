class Solution {
public:
    int memo[1010][1010];
    bool isPalindrome(const string &s, int start, int end) {
        if (start >= end) return 1;
        if (memo[start][end] != -1) return memo[start][end];
        if (s[start] == s[end]) {
            return memo[start][end] = isPalindrome(s, start+1, end-1);
        }   
        return memo[start][end] = 0;
    }

    string longestPalindrome(string s) {
        int sz = s.size();
        if (sz <= 1) return s;
        memset(memo, -1, sizeof(int) * 1010 * 1010);
        string out = ""; 
        for (int i = 0; i < sz-1; i++) {
            for (int j = i; j < sz; j++) {
                if (isPalindrome(s,i,j) && j-i+1 > out.size()) out = s.substr(i,j-i+1);
            }   
        }   
        return out;
    }
};
