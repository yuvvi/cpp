//  (Two pointer / Sliding Window)
//5. Longest sub string without repeating characters


#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// String s = cadbzabcd
//list of substring
//c, ca, cad, cadb, cadbz, cadbza, cadbzab, cadbzabc, cadbzabcd
//a, ad, adb, adbz, adbza, adbzab, adbzabc, adbzabcd
//d, db, dbz, dbza, dbzab, dbzabc, dbzabcd
//b, bz, bza, bzab, bzabc, bzabcd
//z, za, zab, zabc, zabcd
//a, ab, abc, abcd
//etc ...

// As requirement is longest sub string without repeating characters
//c
//c a
//c a d
//c a d b
//c a d b z --> valid
//c a d b z a ---> not valid as 'a' is repeated


//Time complexity = O (n x n) = O(n^2)
//Space complexity = O (256)
int getLongestSubString_bruteForce() {
    string str = "cadbzabcd";
    // string str = "cadbzabcdef";
    int maxLen = 0;
    cout <<"str :"<<str<<endl;
    
    for (int i=0; i< str.size(); i++) {
        int hash[256] = {0}; //for each iteration array is created & default initialized to zero
        for (int j=i; j< str.size(); j++) {
            if (hash[str[j]] == 1) {
                cout <<"Loop break J :"<<j<<endl;
                break;
            }
            int len = j-i+1;
            maxLen = max(len, maxLen);
            hash[str[j]] =1;
        }
    }
        
    cout <<"------maxLen :"<<maxLen<<endl;    
    return maxLen;
}

int main() {
    getLongestSubString_bruteForce();
    cout <<"-----END------"<<endl;    
    return 0;
}
