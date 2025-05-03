// Constant window (Two pointer / Sliding Window)
// Maximum sum for window size k=4 consecutively 

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int k=4, sum =0, maxSum =0;
    int l=0/*left*/, r =0 /*right*/;
    int lmax=0, rmax=0;
    vector<int> arr = {-1, 2, 3, 3, 4, 5, -1};

  int vecSiz =0;
  //input vector size vz, cin
  //for loop with vz, push_back into arr.
      //For expanding array size / testing
    cin >> vecSiz;
    for (int i=0; i<vecSiz; i++) {
        int x =0;
        cin>>x;
        arr.push_back(x);
    }
    //print complete vector
    for (int j=0; j<arr.size(); j++) {
        cout <<" "<<arr.at(j);
    }
    
    cout<<endl << " arr.size() "<<arr.size()<<endl;

    //getting size upto size k    
    for (r=0; r<k; r++) {
        sum = sum + arr[r];
    }
    cout << " sum: "<<sum<<endl;
    
    //traverse through constant k size window
    while (r < arr.size()) {
        cout<< "l:"<<l<<" r:"<<r<<" sum:"<<sum<<" maxSum:"<<maxSum<<endl;
        sum = sum - arr.at(l);
        sum = sum + arr.at(r);
        if (sum > maxSum) {
            lmax = l;
            rmax = r;
            maxSum = sum;
        }
        // maxSum = max(maxSum, sum); //here we cant get lmax & rmax indexes.
        l++;
        r++;
    }
    cout<<"maxSum : "<<maxSum <<" lmax:"<<lmax <<" rmax:"<<rmax<<endl;
    return 0;
}
