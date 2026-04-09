/*
Given a string s, find the length of the longest substring without duplicate characters.

 

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3. Note that "bca" and "cab" are also correct answers.
Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
 

Constraints:

0 <= s.length <= 5 * 104
s consists of English letters, digits, symbols and spaces.
*/

#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
//OPTIMIZED SOLUTION
        int lengthOfLongestSubstring(string s) {
                unordered_map<char, int> hash_char_index;
                int maxLength = 0;
                int left = 0;

                for (int right =0; right < s.size(); ++right) {
                    //element found - move the left pointer index
                if (hash_char_index.find(s[right]) != hash_char_index.end()) {
                    left = max(left, hash_char_index[s[right]]+1);
                }
                    hash_char_index[s[right]] = right; //index is added
                    maxLength = max(maxLength, right - left +1);

                }
                return maxLength;
        }


//LONG THINKING SOLUTION
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> hash_char_freq; //frequency is calculated
        int maxLength = 0;
        
        for (int left=0, right =0; right < s.size(); ++right) {
            cout<<"left :"<<left<<" right:"<<right<<endl;
            
            auto it = hash_char_freq.find(s[right]);
            
            if (it != hash_char_freq.end()) { //element found
                for (;left < right; ++left) {
                    cout<<"-----left :"<<left<<" right:"<<right<<endl;
                    if (s[left] == s[right]) {
                        ++left;
                        break;
                    }
                    else {
                        hash_char_freq[s[left]]--;
                        auto it1 = hash_char_freq.find(s[left]);
                        hash_char_freq.erase(it1);
                        
                    }
                }
                
            }
            else { //element not found
                hash_char_freq[s[right]]++;
                maxLength = std::max(right - left + 1, maxLength);
            }
            
        }
        return maxLength;
    }
};

int main()
{
    Solution s;
    // int len = s.lengthOfLongestSubstring("abcabcbb");
    int len = s.lengthOfLongestSubstring("bbbb");
    std::cout<<" Len :"<<len<<endl;

    return 0;
}
