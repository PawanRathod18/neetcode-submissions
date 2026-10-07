

class Solution {
public:
    bool checkInclusion(std::string s1, std::string s2) {
        int n1 = s1.length();
        int n2 = s2.length();

        if (n1 > n2) return false;

        std::vector<int> s1_count(26, 0);
        std::vector<int> s2_count(26, 0);

        // Populate initial counts for s1 and the first window of s2
        for (int i = 0; i < n1; i++) {
            s1_count[s1[i] - 'a']++;
            s2_count[s2[i] - 'a']++;
        }

        // Slide the window across s2
        for (int i = 0; i < n2 - n1; i++) {
            if (s1_count == s2_count) return true;

            // Slide window: include new character, exclude old character
            s2_count[s2[i + n1] - 'a']++;
            s2_count[s2[i] - 'a']--;
        }

        // Check the last window
        return s1_count == s2_count;
    }
};