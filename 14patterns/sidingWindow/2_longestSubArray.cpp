//  (Two pointer / Sliding Window)
//2. Longest sub array / sub string with sum <= k

#include <iostream>
#include <vector>
using namespace std;

void bruteForceAlgo_longestSubArrayWithSizeLessThanEqualK(int k) {\
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

int main() {
    //sum <= k
    int k=14;
    cout<<" K size to check (sum <= k) :" << k<<endl;
    bruteForceAlgo_longestSubArrayWithSizeLessThanEqualK(k);
    return 0;
}
