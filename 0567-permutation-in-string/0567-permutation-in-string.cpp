
#include <string>
#include <vector>

class Solution {
public:
    bool checkInclusion(std::string s1, std::string s2) {
        int n1 = s1.length(), n2 = s2.length();
        if (n1 > n2) return false;

        std::vector<int> s1Count(26, 0);
        std::vector<int> s2Count(26, 0);

        for (int i = 0; i < n1; i++) {
            s1Count[s1[i] - 'a']++;
            s2Count[s2[i] - 'a']++;
        }

        int matches = 0;
        for (int i = 0; i < 26; i++) {
            if (s1Count[i] == s2Count[i]) matches++;
        }

        for (int i = 0; i < n2 - n1; i++) {
            if (matches == 26) return true;

            // Character entering the window
            int r = s2[i + n1] - 'a';
            s2Count[r]++;
            if (s2Count[r] == s1Count[r]) {
                matches++;
            } else if (s2Count[r] == s1Count[r] + 1) {
                matches--;
            }

            // Character leaving the window
            int l = s2[i] - 'a';
            s2Count[l]--;
            if (s2Count[l] == s1Count[l]) {
                matches++;
            } else if (s2Count[l] == s1Count[l] - 1) {
                matches--;
            }
        }

        return matches == 26;
    }
};