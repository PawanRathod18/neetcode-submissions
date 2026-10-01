class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        std::unordered_set<char> charSet;
        int left = 0;
        int maxLength = 0;

        for (int right = 0; right < s.length(); right++) {
            // If character already exists in window, shrink window from the left
            while (charSet.count(s[right])) {
                charSet.erase(s[left]);
                left++;
            }
            // Add current character and update max length
            charSet.insert(s[right]);
            maxLength = std::max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};
