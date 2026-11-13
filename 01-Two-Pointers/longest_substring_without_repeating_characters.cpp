class Solution {
      public:
          int lengthOfLongestSubstring(string s) {
              unordered_map<char,int>lastSeen;
              int j=0; int n=s.size();
              int mx=0;//Fix 1:Handle Empty String properly
              for(int i=0;i<n;i++){
                  //Fix 2&3: Only shrink the window if duplicate is inside [i,j]
                  if(lastSeen.find(s[i])!=lastSeen.end() && lastSeen[s[i]]>=j){
                      j=lastSeen[s[i]]+1;
                  }
                  lastSeen[s[i]]=i;//Record the latest index of s[i]
                  mx = max(mx,i-j+1); //Fix 4: Always update max length or current window 
              }
              return mx;
          }
      };