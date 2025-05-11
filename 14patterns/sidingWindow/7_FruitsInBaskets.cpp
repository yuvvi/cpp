//  (Two pointer / Sliding Window)
//7. Fruits into baskets
//Maximum length of sub array with atmost 2 (k) types of fruits / numbers.

#include <iostream>
#include <vector>
#include <set>
using namespace std;
//-------------BRUTE FORCE-------------
//Time complexity  = O(N^2)
//Space complexity = O (3)
int getMaxSubArrayLenAtmost2types(vector<int> &arr, int k) {
    cout<<"getMaxSubArrayLenAtmost2types"<<endl;
    int maxLen = 0;
    for (int i=0; i< arr.size(); i++) {
        set<int> bucket;
        for (int j=i; j < arr.size(); j++) {
            bucket.insert(arr[j]);
            cout<<"i:"<<i<<" j:"<<j<<" bucket.size():"<<bucket.size()<<" maxLen:"<<maxLen<<endl;
            if (bucket.size() <= k) {
                maxLen = max(maxLen, (j-i+1));
            }
            else
            break;
        }
    }
    return maxLen;
}

//-----------------OPTIMIZED-----------------
//Time complexity : O (2N)
//Space complexity: O (3)
int getMaxSubArrayLenOptimized(vector<int> &arr, int k) {
    cout <<"getMaxSubArrayLenOptimized"<<endl;
    int left=0, right=0, maxLen =0;
    map<int, int> mpp; //fruit, freq
    while (right < arr.size()) {
        mpp[arr[right]]++;
        if (mpp.size() > k) {
            while (mpp.size() > k) {
                mpp[arr[left]]--;
                if (mpp[arr[left]] == 0) {
                    mpp.erase(arr[left]);
                }
                left++;
            }
        }
        if (mpp.size() <= k) {
            maxLen = max(maxLen, (right - left + 1));
        }
        right++;
    }
    return maxLen;
}
//----------OPTIMIZED2----------
//Time complexity : O (N)
//Space complexity: O (3)

int getMaxLenSubArrayOpt2(vector<int> &arr, int k) {
    int left=0, right=0, maxLen =0;
    map<int,int> mpp;
    
    while (right < arr.size()) {
        mpp[arr[right]]++;
        if (mpp.size() > k) {
            mpp[arr[left]]--;
            if (mpp[arr[left]] == 0) {
                mpp.erase(arr[left]);
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
    vector<int> arr1 = {3,3,3,1,2,1,1,2,3,3,4}; 
    int max = getMaxSubArrayLenAtmost2types(arr1, 2);
    cout<<"Brute force maxlen:"<< max<<endl;
    int maxOpt = getMaxSubArrayLenOptimized(arr1,2);
    cout<<"Optimized maxlen:"<<maxOpt<<endl;
    int maxOpt2 = getMaxLenSubArrayOpt2(arr1, 2);
    cout<<"Optimized2 maxlen:"<<maxOpt2<<endl;
    return 0;
}
