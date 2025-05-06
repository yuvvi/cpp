//  (Two pointer / Sliding Window)
//4. Maximum points you can obtain from cards k=4,
//Only need to pick from front or back sequentially. Not from middle

#include <iostream>
#include <vector>
using namespace std;

void getMaximumPoints(int k) {
    vector<int> arr {6,2,3,4,7,2,1,7,1};
    int leftSum=0, rightSum=0, maxSum =0;
    
    //print vector data
    for (int x=0;x<arr.size(); x++) {
        cout<<" "<<arr.at(x);
    }
    cout<<endl;
    
    //calculate maximum value from left side - 6,2,3,4
    for (int i=0; i<k;i++) {
        leftSum = leftSum + arr.at(i);
    }
    cout<<" Maximum value of left side :"<<leftSum<<endl;
    maxSum = leftSum;
    int rightIndex = arr.size() - 1;
    
    //Now we can calculate leftSide 3 indexes (6,2,3) & right side 1 (1)
    // we can shift left by 1, leftSide 2 indexes (6,2) & rightSide 2 (7,1)
    // we can shift left by 1, leftSide 1 indexes (6) & rightSide3 (1,7,1)
    // we can shift left by 1, leftSide 0 indexes     & rightSide3 (2,1,7,1)
    //for each iteration, need to check for maximum value
    
    for (int j=k-1; j>=0;j--) {
        leftSum = leftSum - arr.at(j);
        rightSum = rightSum + arr.at(rightIndex);
        rightIndex = rightIndex - 1;
        maxSum = max(maxSum, (leftSum + rightSum));
        cout<<" leftSum :"<<leftSum<< " rightSum:"<<rightSum <<" maxSum:"<<maxSum<<endl;
    }
//    return maxSum;
    
}

int main() {
    getMaximumPoints(4);
    return 0;
}
