/*
 * Given a string s, find the length of the longest substring without repeating characters.
 */

int lengthOfLongestSubstring(string s) {
        int n = s.length();
        std::unordered_map<char, int> dic;
        int cur_max = 0;
        int start = 0;
        for (int i = 0; i < n; ++i) {
            char c = s[i];
            if (dic[c] == 0 || dic[c]-1 < start) {
                dic[c] = i+1;
            } else {
                cur_max = max(cur_max, i-start);
                start = dic[c];
                dic[c] = i+1;
            }
        }
        return max(cur_max, n-start);
    }

