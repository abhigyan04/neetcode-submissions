class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> count;
        int result = 0;
        int l = 0, maxF = 0;

        for(int r = 0 ; r < s.size() ; r++) {
            count[s[r]]++;
            maxF = max(maxF, count[s[r]]);

            while((r - l + 1) - maxF > k) {
                count[s[l]]--;
                l++;
            }
            result = max(result, r - l + 1);
        }

        return result;
    }
};
