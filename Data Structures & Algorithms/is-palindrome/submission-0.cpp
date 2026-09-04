class Solution {
   public:
    bool isPalindrome(string s) {
        string res = "";
        for (char c : s) {
            if (c == ' ') {
                continue;
            }
            if (isalnum(c)) {
                res += c;
            }
        }
        int n = res.length();
        int left = 0;
        int right = n - 1;

        while (left <= right) {
            char ch1 = tolower(res[left]);
            char ch2 = tolower(res[right]);
            if (ch1 != ch2) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};
