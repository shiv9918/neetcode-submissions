class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        int maxi  = 0;
        unordered_map<char, int> hashmap;
        for (int i = 0; i < s.length(); i++) {
            while (hashmap[s[i]]>0) {
                hashmap[s[left]]--;
                if(hashmap[s[left]] == 0)
                {
                    hashmap.erase(s[left]);
                }
                left++;
            }

            hashmap[s[i]]++;
            maxi = max(maxi, i-left+1);
        }
        return maxi;
    }
};
