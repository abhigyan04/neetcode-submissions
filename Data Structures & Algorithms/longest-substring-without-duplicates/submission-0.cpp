class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> duplicates;
        int l = 0, r = 0;
        int maxLength = 0;

        while(r < s.length()) {
            while(duplicates.contains(s[r])) {
                duplicates.erase(s[l]);
                l++;
            }
            duplicates.insert(s[r]);
            maxLength = max(maxLength, r - l + 1);
            r++;
        }
        return maxLength;
    }
};
