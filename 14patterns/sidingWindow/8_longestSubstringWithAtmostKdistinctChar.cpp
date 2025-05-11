//  (Two pointer / Sliding Window)
//8. Longest substring with atmost K distinct characters

#include <iostream>
#include <vector>
#include <set>
#include <map>
using namespace std;

//---------BRUTE FORCE---------
//Time complexity : O(N^2)
//Space complexity: O(3)

int getLongestSubStringWithKdistinctChar(const string &str, const int k) {
    int maxLen = 0;
    for (int i=0; i< str.length();i++) {
        set<char> list;
        for (int j=i; j< str.length(); j++) {
            list.insert(str[j]);
            if (list.size() <= k) {
                maxLen = max(maxLen, (j-i+1));
            }
            else
            break;
        }
    }
    return maxLen;
}

//--------------------OPTIMIZED----------
//Time complexity : O(N) + O log(256)
//Space complexity: O (256)

int getLongestSubStringWithKdistinctCharOpt(const string &str, const int k) {
    int left=0, right=0, maxLen =0;
    map<char, int> mpp;
    while (right < str.size()) {
        mpp[str[right]]++;
        if (mpp.size() > k) {
            mpp[str[left]]--;
            if (mpp[str[left]] == 0) {
                mpp.erase(str[left]);
            }
            left++;
        }
        if (mpp.size() <= k) {
            maxLen = max(maxLen, (right - left + 1));
        }
        right++;
    }
    return maxLen;
}


int main() {
    string str = "aaabbccd";
    int max = getLongestSubStringWithKdistinctChar(str, 2);
    cout <<" maxLen "<< max <<endl;
    int max2 = getLongestSubStringWithKdistinctCharOpt(str, 2);
    cout <<" maxLen "<< max2 <<endl;
    
    return 0;
}
