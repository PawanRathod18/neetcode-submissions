class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.length() - 1;

        while (left < right) {

            // Skip non-alphanumeric characters from the left
            if (!isalnum(s[left])) {
                left++;
                continue;
            }

            // Skip non-alphanumeric characters from the right
            if (!isalnum(s[right])) {
                right--;
                continue;
            }

            // If characters don't match, it's not a palindrome
            if (tolower(s[left]) != tolower(s[right])) {
                return false;
            }

            // Characters matched, move both pointers
            left++;
            right--;
        }

        // No mismatch found
        return true;
    }
};