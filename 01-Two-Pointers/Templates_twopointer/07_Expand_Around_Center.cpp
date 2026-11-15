// ============================================================================
// Template 7: Expand Around Center
// When to Use:
//   - Finding or counting palindromic substrings in a string
// Classic Problems: Longest Palindromic Substring (LC 5), Palindromic Substrings (LC 647)
// Time Complexity: O(n^2)
// Space Complexity: O(1)
// ============================================================================

#include <iostream>
#include <string>
using namespace std;

// Helper that expands outward from [left, right] while characters match
int expandFromCenter(const string& s, int left, int right) {
    while (left >= 0 && right < s.length() && s[left] == s[right]) {
        left--;  // Move left pointer outward
        right++; // Move right pointer outward
    }
    // Note: When the loop ends, left and right have gone 1 step too far,
    // so length is (right - 1) - (left + 1) + 1 = right - left - 1
    return right - left - 1;
}

string longestPalindrome(const string& s) {
    if (s.empty()) return "";
    int start = 0, maxLen = 1;

    for (int i = 0; i < s.length(); i++) {
        // Case 1: Odd-length palindrome centered at i (e.g., "aba")
        int len1 = expandFromCenter(s, i, i);
        // Case 2: Even-length palindrome centered between i and i+1 (e.g., "abba")
        int len2 = expandFromCenter(s, i, i + 1);

        int len = max(len1, len2);
        if (len > maxLen) {
            maxLen = len;
            // Calculate starting index of this palindrome
            start = i - (len - 1) / 2;
        }
    }
    return s.substr(start, maxLen);
}

int main() {
    string s = "babad";
    cout << "Longest Palindromic Substring in '" << s << "': " 
         << longestPalindrome(s) << endl;
    return 0;
}
