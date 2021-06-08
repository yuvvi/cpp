#include <iostream>

using namespace std;


int binarySearch_array(int *arr,int left, int right, int searchNum){
    while(left <= right){
        int mid = left + (right-left)/2;
        if(arr[mid] == searchNum){
            return mid;
        }

        if(arr[mid] < searchNum){
            left = mid +1;
        }
        else{
            right = mid -1;
        }

    }
    return -1;
}

void binarySearch(){
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    int search_num = 0;
    cout<<"Enter search element : ";
    cin>>search_num;

    int arrLen = sizeof(arr)/sizeof (arr[0]);

    int left = 0;
    int right =  arrLen -1;
    int index = binarySearch_array(arr,left,right,search_num);
    if(index != -1){
        cout<<"Num found at index: "<<index<<endl;
    }else{
        cout<<"Num not found"<<endl;
    }
}

void binarySearch_Matrix(){
    cout << "Binary search - matrix" << endl;
    int searchEle = 0;
    cout<<"Please enter search element :"<<endl;
    cin>>searchEle;
    bool isElementFound = false;

    int arr[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    int row = 3;
    int col = 3;

    int start =0;
    int end = row * col -1;

    while(start <= end){
        int mid = start + (end - start)/2;
        int midx = mid/col;
        int midy = mid%col;
        cout<<"midx: "<<midx<<" midy: "<<midy<<endl;
        if(arr[midx][midy] == searchEle){
            cout<<"Element is found at ("<<midx<<", "<<midy<<")"<<endl;
            isElementFound = true;
            break;
        }
        else if(arr[midx][midy] < searchEle){
            start = mid +1;
        }else{
            end = mid - 1;
        }
    }

    if(isElementFound){

    }else{
        cout<<" Element is not found"<<endl;
    }

}

int main()
{
    cout << "Binary search" << endl;
//    binarySearch();
    binarySearch_Matrix();
    return 0;
}
