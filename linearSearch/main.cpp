#include <iostream>
#include <vector>
using namespace std;

int search_linear(int *arr, int arrlen, int s_num){
    for(int i=0;i<arrlen;++i){
       if(arr[i] == s_num){
           return i;
       }
    }
    return -1;
}

void linearSearch1(){
    cout << "--Linear search--";
    int arr[]={1,2,3,4,5,6,7};
    int arrlen = sizeof(arr)/sizeof(arr[0]);
    int search_element = -1;
    cout<<"Please enter search element :";
    cin>>search_element;
    int index = search_linear(arr,arrlen,search_element);

    if(index != -1){
        cout<<"Element found at index: "<<index<<endl;
    }else{
        cout<<"Element is not found ";
    }
}

int linearSearch_vect(vector<int> &vec,int s_num){

    for(int i=0;i<vec.size();++i){
        if(vec[i] == s_num){
            return i;
        }
    }
    return -1;
}

void linearSearch2(){
    //Vector
    cout << "--Linear search--";
    vector<int> vec_arr;
    int arrayLen =0;
    cout<<"Enter array size :"<<endl;
    cin>>arrayLen;
    for(int i=0;i<arrayLen;++i){
        cout << "--1";
        int val = 0;
        cin>>val;
        vec_arr.push_back(val);
    }
    for(int j=0;j<vec_arr.size();++j){
        cout<<" "<<vec_arr[j];
    }

    int search_num=0;
    cout<<"Enter search element :";
    cin>>search_num;
    int index = linearSearch_vect(vec_arr,search_num);
    if(index != -1){
        cout<<"Num found at index: "<<index<<endl;
    }else{
        cout<<"Num not found"<<endl;
    }
}

int main()
{
//    linearSearch1();
    linearSearch2();

    return 0;
}
