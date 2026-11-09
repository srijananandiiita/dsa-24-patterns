/*
leetcode 125. Valid Palindrome
Given a string s, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

*/

//Method 1: Using extra space
class Solution {
      public:
          bool isPalindrome(string s) {
              string q;
              for(int i=0;i<s.size();i++){
                  if((s[i]>='a' && s[i]<='z')||(s[i]>='0' && s[i]<='9')){
                      q.push_back(s[i]);
                  }
                  if(s[i]>='A' && s[i]<='Z'){
                      q.push_back(char(s[i]+32));
                  }
              }
              int i=0; int j=q.size()-1;
              while(i<=j){
                  if(q[i]!=q[j])
                  return false;
                  i++; j--;
              }
              return true;
          }
      };

//Method 2: Two Pointer Approach without using inbuilt functions
class Solution {
      public:
          bool comparable(char c){
              return (c>='a' && c<='z')|| (c>='A' && c<='Z')||(c>='0'&&c<='9');
          }
      
          char lcase(char c){
              if(c>='A' && c<='Z'){
                  c=char(c+32);
              }
              return c;
          }
      
          bool isPalindrome(string s) {
              if(s.empty()) return true;
              int i=0; int j=s.size()-1;
              while(i<j){
                  while(!comparable(s[i]) && i<j){
                      i++;
                  }
                  while(!comparable(s[j]) && i<j){
                      j--;
                  }
                  if(i>=j) break;
                  if(comparable(s[i])&&comparable(s[j])){
                      if(lcase(s[i])!=lcase(s[j])){
                          return false;
                      }
                  }    
                  i++;j--;
              }
              return true;
          }
      };

//Method 3: Two Pointer Approach using inbuilt functions
class Solution {
      public:
          bool isPalindrome(string s) {
              int left = 0;
              int right = s.size() - 1;
      
              while (left < right) {
                  while (left < right && !isalnum(s[left])) {
                      left++;
                  }
                  while (left < right && !isalnum(s[right])) {
                      right--;
                  }
      
                  if (tolower(s[left]) != tolower(s[right])) {
                      return false;
                  }
      
                  left++;
                  right--;
              }
      
              return true;
          }
      };