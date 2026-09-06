class Solution {
   public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> hashmap1;
        unordered_map<char, int> hashmap2;

        for (int i = 0; i < s1.length(); i++) {
            hashmap1[s1[i]]++;
        }

        if (s1.length() > s2.length()) {
            return false;
        }

        int left = 0;
        for (int i = 0; i < s2.length(); i++) {
            hashmap2[s2[i]]++;

            if (i - left + 1 > s1.length()) {
                hashmap2[s2[left]]--;
                if (hashmap2[s2[left]] == 0) {
                    hashmap2.erase(s2[left]);
                }
                left++;
            }
            if (hashmap1 == hashmap2) {
                return true;
            }
        }
        return false;
    }
};
