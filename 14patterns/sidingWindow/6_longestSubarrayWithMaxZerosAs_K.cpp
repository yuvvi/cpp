//  (Two pointer / Sliding Window)
//6. Maximum consecutive 1's, allowed to flip atmost k zeros.
//Question could also be:
//Finding the longest sub array with maximum zero's as k.
//Finding the longest sub array with atmost k zero's

#include <iostream>
#include <vector>
using namespace std;

//Brute force
//going through each and every sub array & getting maximum 1's
//Time complexity : O(n^2)
//Space complexity: O(1)

int getMaximum1s_BF(vector<int> &vect, int k) {
    // vector<int> vect = {1,1,1,0,0,0,1,1,1,1,0};
    int maxLen=0;
    for (int i=0; i<vect.size(); i++) {
        cout<<" i: "<<i<<" maxLen:"<<maxLen<<endl;
        int zeros = 0;
        for (int j=i; j < vect.size(); j++) {
            if (vect[j] == 0) { zeros ++;}
            cout<<" j: "<<j<<" zero: "<< zeros <<" maxLen:"<<maxLen<<endl;
            if (zeros <= k) {
                int len = j - i +1;
                maxLen = max(len, maxLen);
            }
            else
                break;
        }
    }
    return maxLen;
}

//----------------------Optimized-----------------------
//Time complexity : O(2N)
//Space complexity: O(1)

int getMaximum_1s_optimized(vector<int> &vect, int k) {
    int left=0, right=0, zeros=0, maxLen =0;
    while (right < vect.size()) {
        if (vect[right] == 0) {
            zeros++;
        }
        
        //shifting left until zeros count is <=k
        while (zeros > k) {
            if (vect[left] == 0) {
                zeros--;
            }
            left++;
        }
        
        //maxLen is calculated only if <=k is satified
        if (zeros <= k) {
            int len = right - left + 1;
            maxLen = max(len, maxLen);
        }
        right++;
    }
    return maxLen;
}

//-----------------OPTIMIZED 2--------------------------
//Time complexity: O(N)
//Space complexity: O(1)

int getMaximum1s_optimized2(vector<int> &vect, int k) {
    int left=0, right=0, maxLen=0, zeros=0;
    while (right < vect.size()) {
        if (vect[right] == 0) { zeros++;}
        if (zeros > k) {
            if (vect[left] == 0) {
                zeros--;
            }
            left++;
        }
        if (zeros <= k) {
            int len = right - left + 1;
            maxLen = max(maxLen, len);
        }
        right++;
    }
    return maxLen;
}

int main() {
    vector<int> vect = {1,1,1,0,0,0,1,1,1,1,0};
    cout <<"BruteForce maxLen :" << getMaximum1s_BF(vect, 2) << endl;
    cout <<"Optimised maxLen  :"<< getMaximum_1s_optimized(vect, 2)<<endl;
    cout <<"Optimised 2 maxLen  :"<< getMaximum1s_optimized2(vect, 2)<<endl;
    return 0;
}
