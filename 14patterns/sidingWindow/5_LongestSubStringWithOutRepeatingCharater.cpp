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

//-------------------------------OPTIMIZED WAY-------------------------------------------------------
//To find sub string need to think of two poiner / sliding window

//initially letss have two pointers left, right
//map <char, index> 
//maxlen =0
//       0 1 2 3 4 5 6 7 8
// str = c a d b z a b c d

//---------------ITERATION 1------------------------
//       0 1 2 3 4 5 6 7 8
// str = c a d b z a b c d
//       l
//       r
//  len = r - l +1; 0-0+1 = 1
//  check for 'c' exist in map or not. Insert char & its index
//  C
//  Update maxLen = 1
//---------------ITERATION 2------------------------
//       0 1 2 3 4 5 6 7 8
// str = c a d b z a b c d
//       l
//         r
//  len = r - l +1; 1-0+1 = 2
//  check for 'a' exist in map or not. Insert char & its index
//  C A
//  Update maxLen = 2
//---------------ITERATION 3------------------------
//       0 1 2 3 4 5 6 7 8
// str = c a d b z a b c d
//       l
//           r
//  len = r - l +1; 2-0+1 = 3
//  check for 'd' exist in map or not. Insert char & its index
//  C A D
//  Update maxLen = 3
//---------------ITERATION 4------------------------
//       0 1 2 3 4 5 6 7 8
// str = c a d b z a b c d
//       l
//             r
//  len = r - l +1; 3-0+1 = 4
//  check for 'b' exist in map or not. Insert char & its index
//  C A D B
//  Update maxLen = 4
//---------------ITERATION 5------------------------
//       0 1 2 3 4 5 6 7 8
// str = c a d b z a b c d
//       l
//               r
//  len = r - l +1; 4-0+1 = 5
//  check for 'b' exist in map or not. Insert char & its index
//  C A D B Z
//  Update maxLen = 5
//---------------ITERATION 6------------------------
//       0 1 2 3 4 5 6 7 8
// str = c a d b z a b c d
//       l
//                 r
//  check for 'a' exist in map. shift 'l' to ('a' index from map + 1).
//          l = 'a'index from map + 1 = 1 + 1 = 2
//          l index wont be updated, if l index > mapIndex. L could be increamented, but not decreamented.
//       0 1 2 3 4 5 6 7 8
// str = c a d b z a b c d
//           l
//                 r
// Update 'a' index in map
//  len = r - l +1; 5-2+1 = 4
//  C A  |  D B Z A
//  Update maxLen = 5
//---------------ITERATION 7------------------------
//       0 1 2 3 4 5 6 7 8
// str = c a d b z a b c d
//           l
//                   r
//  check for 'b' exist in map. shift 'l' to ('b' index from map + 1).i.e., 'b'index in map = 3
//          l_new = 'b'index from map + 1 = 3 + 1 = 4
//          if (l_new > l) { l = l_new; }
//          l index wont be updated, if l index > mapIndex. L could be increamented, but not decreamented.
// str = c a d b z a b c d
//               l
//                   r
// Update 'b' index in map
//  len = r - l +1; 6-4+1 = 3
//  C A D B |  Z A B
//  Update maxLen = 5
//---------------ITERATION 8------------------------
//       0 1 2 3 4 5 6 7 8
// str = c a d b z a b c d
//               l
//                     r
//  check for 'c' exist in map. shift 'l' to ('c' index from map + 1).i.e., 'c'index in map = 0
//          l_new = 'c'index from map + 1 = 0 + 1 = 1 
//          if (l_new > l) { l = l_new; } //this condition is not satisfied l_new = 1, l = 4
//  len = r - l +1; 7-4+1 = 4
//  C A D B |  Z A B C
//  Update maxLen = 5
//---------------ITERATION 9------------------------
//       0 1 2 3 4 5 6 7 8
// str = c a d b z a b c d
//               l
//                       r
//  check for 'd' exist in map. shift 'l' to ('d' index from map + 1).i.e., 'd'index in map = 2
//          l_new = 'd'index from map + 1 = 2 + 1 = 1 
//          if (l_new > l) { l = l_new; } //this condition is not satisfied l_new =3, l = 4
//  len = r - l +1; 8-4+1 = 5
//  C A D B |  Z A B C D
//  Update maxLen = 5

int getLongSubStringOptimized() {
    string str = "cadbzabcd";
    int left=0, right=0, maxLen = 0, len =0;
    int iteration=1;
    // map<char, int> charIndexMap;
    //array<int, 256> charIndex; charIndex.fill(-1);
    int charIndex[256] = {-1};
    fill_n(charIndex, 256, -1);
    cout <<" "<<charIndex[100]<<endl;
        cout <<"------------------------getLongSubStringOptimized -------------------------"<<endl;
        cout <<"str :"<<str<<endl;
    
    while (right < str.size()) {
        cout<<"-----ITERATION "<<iteration<<" -------"<<endl;
        cout <<"left:"<<left<<" right:"<<right<<" str[left]:"<<str[left]<<" str[right]:"<<str[right]<<" len:"<<len<<" maxLen:"<<maxLen<<endl;
        if (charIndex[str[right]] != -1) {
            
            cout<<"statisfied " <<str[right]<<"  "<<charIndex[str[right]]<<endl;
            if (charIndex[str[right]] >= left) {
                left = charIndex[str[right]] + 1;
            }
        }
        len = right - left + 1;
        maxLen = max(len, maxLen);
        charIndex[str[right]] = right;
        right ++;
        iteration++;
        cout <<"left:"<<left<<" right:"<<right<<" str[left]:"<<str[left]<<" str[right]:"<<str[right]<<" len:"<<len<<" maxLen:"<<maxLen<<endl;
    }
    return maxLen;
}

int main() {
    getLongestSubString_bruteForce();
    getLongSubStringOptimized();
    cout <<"-----END------"<<endl;    
    return 0;
}


