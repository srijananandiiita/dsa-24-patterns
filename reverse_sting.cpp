/*
 * Problem: Reverse String
 * Link: https://leetcode.com/problems/reverse-string/description/
 * Pattern: 01 - Two Pointers
 * Problem Number: Leetcode 344
 * Time Complexity: O(N)
 * Space Complexity: O(1)
 * Key Note: Use two pointers to swap characters from both ends of the string.
 */
class Solution {
      public:
          void reverseString(vector<char>& s) {
              int i=0; int j=s.size()-1;
              while(i<=j){
                  swap(s[i],s[j]);
                  i++,j--;
              }
          }
      };