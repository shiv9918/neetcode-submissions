class Solution {
    public String minWindow(String s, String t) {

        if (t.length() > s.length()) {
            return "";
        }

        // map stores the frequency of each character required from t
        HashMap<Character, Integer> hashmap = new HashMap<>();

        for (int i = 0; i < t.length(); i++) {
            char ch = t.charAt(i);
            hashmap.put(ch, hashmap.getOrDefault(ch, 0) + 1);
        }

        int left = 0;

        // window stores the frequency of characters
        // present in the current sliding window
        HashMap<Character, Integer> window = new HashMap<>();

        // Store length of the smallest valid window
        int mini = Integer.MAX_VALUE;

        // Number of required characters currently satisfied
        int count = 0;

        // Starting index of answer
        int start = 0;

        // Expand the window using right pointer
        for (int i = 0; i < s.length(); i++) {

            char ch = s.charAt(i);

            // Add current character to window
            window.put(ch, window.getOrDefault(ch, 0) + 1);

            /*
             * If character is required by t
             * and we have not taken more than required,
             * increase count.
             */
            if (hashmap.containsKey(ch)
                    && window.get(ch) <= hashmap.get(ch)) {

                count++;
            }

            /*
             * When count == t.length(),
             * the current window contains all required characters.
             *
             * Now try to shrink the window from left.
             */
            while (count == t.length()) {

                // Update smallest window
                if (i - left + 1 < mini) {
                    mini = i - left + 1;
                    start = left;
                }

                // Character that we are removing
                char leftChar = s.charAt(left);

                // Remove it from window
                window.put(leftChar, window.get(leftChar) - 1);

                /*
                 * If leftChar is required and
                 * we no longer have enough of it,
                 * the window becomes invalid.
                 */
                if (hashmap.containsKey(leftChar)
                        && window.get(leftChar) < hashmap.get(leftChar)) {

                    count--;
                }

                // Move left pointer
                left++;
            }
        }

        // No valid window found
        if (mini == Integer.MAX_VALUE) {
            return "";
        }

        // Return smallest window
        return s.substring(start, start + mini);
    }
}