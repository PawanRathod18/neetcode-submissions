class Solution {
public:
    int characterReplacement(std::string s, int k) {
        std::vector<int> count(26, 0);
        int maxFreq = 0;
        int maxLength = 0;
        int L = 0;

        for (int R = 0; R < s.length(); ++R) {
            // Expand the window and update character frequency
            count[s[R] - 'A']++;
            maxFreq = std::max(maxFreq, count[s[R] - 'A']);

            // If replacements needed exceed k, shrink the window from the left
            while ((R - L + 1) - maxFreq > k) {
                count[s[L] - 'A']--;
                L++;
            }

            // Update maximum valid window length found
            maxLength = std::max(maxLength, R - L + 1);
        }

        return maxLength;
    }
};
