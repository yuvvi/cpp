#include <iostream>

using namespace std;

void selectionSort(){
    cout << "Selection Sort - 1st iteration minimum at 1st position" << endl;
    cout<<"Time complexity : O(n*n)"<<endl;
    int arr[]={64,25,12,22,11};
    int arrlen = sizeof(arr)/sizeof(arr[0]);

    cout<<"Array :";
    for(int i=0;i<arrlen;++i){
        cout<<" "<<arr[i];
    }
    cout<<endl;

    for(int i=0;i<arrlen;++i){
        int min_indx = i;
        for(int j=i+1;j<arrlen;++j){
            if(arr[min_indx] > arr[j]){
                min_indx = j;
            }
        }
        if(i != min_indx){
            int temp = arr[i];
            arr[i] = arr[min_indx];
            arr[min_indx] = temp;
        }
    }
    cout<<"Sorted array :";
    for(int i=0;i<arrlen;++i){
        cout<<" "<<arr[i];
    }
    cout<<endl;
}

void bubbleSort(){
    cout << "Bubble Sort - 1st iteration max at the end position, swap happens for every comparison" << endl;
    cout<<"Time complexity : O(n*n)"<<endl;
    int arr[]={64,34,25,12,27,11,90,8};
    int arrlen = sizeof(arr)/sizeof(arr[0]);
    cout<<"Array :";
    for(int i=0;i<arrlen;++i){
        cout<<" "<<arr[i];
    }
    cout<<endl;
    for(int i=0;i<arrlen;++i){
        for(int j=0;j<arrlen-1;++j){
            if(arr[j] > arr[j+1]){
                int tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
            }
        }
    }
    cout<<"Sorted Array :";
    for(int i=0;i<arrlen;++i){
        cout<<" "<<arr[i];
    }
    cout<<endl;

}


void insertionSort(){
    cout << "Insertion Sort " << endl;
    cout<<"Time complexity : O(n*n)"<<endl;
    int arr[]={64,34,25,12,27,11,90,8};
    int arrlen = sizeof(arr)/sizeof(arr[0]);
    cout<<"Array :";
    for(int i=0;i<arrlen;++i){
        cout<<" "<<arr[i];
    }
    cout<<endl;

    for(int i=1;i<arrlen;++i){
        int key = arr[i];
        int j = i - 1;
        while(j >= 0 && arr[j] > key){
            arr[j+1] = arr[j];
            j = j -1;
        }
        arr[j+1] = key;
        for(int x=0;x<arrlen;++x){
            cout<<" "<<arr[x];
        }
        cout<<endl;

    }

    cout<<"Sorted Array :";
    for(int x=0;x<arrlen;++x){
        cout<<" "<<arr[x];
    }
    cout<<endl;
}

int main()
{
//    selectionSort();
//    bubbleSort();
    insertionSort();
    return 0;
}
