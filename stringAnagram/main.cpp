#include <iostream>
#include <unordered_map>
#include <map>

using namespace std;

void isAnagram(char *arr1,int a1Len, char *arr2, int a2len){

    cout<<"arr1Len: "<<a1Len<<" arr2Len: "<<a2len<<endl;
    if(a1Len != a2len){
        cout<<"Strings are not anagrams"<<endl;
        return;
    }
    unordered_map<char,int> m;
    bool isAnagram = false;

    for(int i=0;i< a1Len;++i){
        m[arr1[i]]++;
        m[arr2[i]]--;
        cout<<"m[arr1["<<i<<"]] :"<<m[arr1[i]]<<"m[arr12["<<i<<"]] :"<<m[arr2[i]]<<endl;
    }
    cout<<"map.size() :"<<m.size()<<endl;

    for(auto it=m.begin(); it!=m.end();it++){
        if(it->second!=0){
            isAnagram = false;
        }else{
            isAnagram = true;
        }
    }
    if(isAnagram){
        cout<<"Anagram "<<endl;
    }else{
        cout<<"NOT Anagram "<<endl;

    }
}

void Anagram1(){
    char arr1[] ="abcde";
    char arr2[] ="bcaed";

    int arr1Len = sizeof (arr1)/sizeof (arr1[0]);
    int arr2Len = sizeof (arr2)/sizeof (arr2[0]);

    isAnagram(arr1,arr1Len,arr2,arr2Len);
}

bool validateAnagram(string s, string word){

    unordered_map<char,int> m;
    for(int i=0; i < s.length();++i){
        m[s[i]]++;
        m[word[i]]--;
    }

    for(auto it=m.begin();it != m.end();++it){
        if(it->second != 0){
            return false;
        }
    }
    return true;
}

void anagram2(){
    string sentence, word;
    cout<<"please enter anagram word :"<<endl;
    cin>>word;
    cout<<"Please enter sentence with anagrams"<<endl;
    cin>>sentence;

    int anagramCount =0;
    for(int i=0;i<sentence.length() - word.length()+1 ;++i){
        if(validateAnagram(sentence.substr(i,word.length()),word)){
            anagramCount++;
        }
    }
    cout<<"anagram count :"<<anagramCount<<endl;
}

int main()
{
    cout << "String anagram : An anagram of a string is another string that contains the same characters,\n"
    "only the order of characters can be different. Ex: abcd == dabc" << endl;

//    Anagram1();
    anagram2();

    return 0;
}
