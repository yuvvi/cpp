//  (Two pointer / Sliding Window)
//2. Longest sub array / sub string with sum <= k

#include <iostream>
#include <vector>
using namespace std;

void bruteForceAlgo_longestSubArrayWithSizeLessThanEqualK(int k) {
    //Time complexity : O (n^2)
    //Space complexity: O (n)
    vector<int> arr {2,5,1,7,10};
    for (auto i: arr) {
        cout <<" "<<i;
    }
    cout<< endl<< " vec size: "<<arr.size()<<endl;
    
    //Generate all sub arrays
    //[2], [2,5], [2,5,1], [2,5,1,7], [2,5,1,7,10]
    //[5], [5,1], [5,1,7], [5,1,7,10]
    //[1], [1,7], [1,7,10]
    //[7], [7,10]
    //above are 14 combinations of sub arrays
    
    int maxLen = 0;

    for (int i=0; i<arr.size(); i++) {
        int sum = 0;
        for (int j=i; j < arr.size(); j++) {
            sum = sum + arr[j];
            if (sum <= k) {
                maxLen = max(maxLen, (j-i+1));
            }
        }
    }
    cout << "Max Len :"<<maxLen;
}

void twoPointer_LongestSubArray(int k) {
    vector<int> arr {15,5,1,7,10};
    int left=0, right =0, sum =0, maxLen=0;
    while (right < arr.size()) {
        sum = sum + arr[right];

        //if sum > k, shrink left side (shrink only condition based)
        if (sum > k) {
            sum = sum - arr[left];
            left = left +1;
        }
        //if sum <=k, get MaxLen
        if (sum <= k) {
            maxLen = max(maxLen, (right -left + 1));
        }

        //expand right side (default)
        right = right + 1;
    }
    
    cout <<" maxLen: "<<maxLen;
}

int main() {
    //sum <= k
    int k=14;
    cout<<" K size to check (sum <= k) :" << k<<endl;
    bruteForceAlgo_longestSubArrayWithSizeLessThanEqualK(k);
    return 0;
}
