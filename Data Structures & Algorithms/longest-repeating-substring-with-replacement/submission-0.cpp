class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int>hashmap;
        int left = 0;
        int maxfreq = 0;
        int res = 0;
        int count = 0;
        for(int i = 0;i<s.length();i++)
        {
            hashmap[s[i]]++;

            maxfreq = max(maxfreq,hashmap[s[i]]);

            while((i-left+1) - maxfreq > k)
            {
                hashmap[s[left]]--;
                if(hashmap[s[left]] == 0)
                {
                    hashmap.erase(s[left]);
                }
                left++;
            }

            res = max(res,i-left+1);
        }
        return res;
    }
};
