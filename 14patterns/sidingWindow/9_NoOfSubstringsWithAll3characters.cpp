//  (Two pointer / Sliding Window)
//9. Number of substrings containing all three characters

//  b b a c b a

#include <iostream>
#include <vector>
#include <set>
#include <map>
using namespace std;

//---------BRUTE FORCE---------
//Time complexity : O(N^2)
//Space complexity: O(1)

int getSubStringWithAllThreeCharacters(const string &str, const int k) {
    int count = 0;
    for (int i=0; i< str.size(); i++) {
        int arr[3]= {0};
        for(int j=i; j < str.size(); j++) {
            arr[str[j] - 'a'] = 1;
            
            if ((arr[0] + arr[1] + arr[2]) == 3) {
                cout<<"increase count"<<endl;
                count = count + 1;
            }
            cout<<"i:"<<i<<" j:"<<j<<" count:"<<count <<" arr[0]:"<<arr[0]<<" arr[1]:"<<arr[1]<<" arr[2]:"<<arr[2]<<endl;
        }
    }
    cout<<" count:"<<count<<endl;
    return count;
}

//--------------------OPTIMIZED----------
int getSubStringWithAllThreeCharactersOpt(const string &str, const int k) {
    int lastSeen[3] = {-1,-1,-1}, count = 0;
    
    for (int i=0; i< str.size(); i++) {
        lastSeen[str[i] - 'a'] = i;
        if ((lastSeen[0]!= -1) && (lastSeen[1]!=-1) && (lastSeen[2]!=-1)) {
            count = count + min(lastSeen[0],lastSeen[1],lastSeen[2]);
        }
        cout<<"i:"<<i<<" lastSeen[str[i]-'a']:"<<lastSeen[str[i]-'a']<<endl;
    }
    
    cout <<" arr[0]:"<<lastSeen[0]<<" arr[1]:"<<lastSeen[1]<<" arr[2]:"<<lastSeen[2]<<k<<endl;
    return count;
}


int main() {
    // string str = "aaabbccd";
    string str = "bbacba";
    // int count = getSubStringWithAllThreeCharacters(str,3);
    // cout<<"no. of Sub strings : "<<count<<endl;
    getSubStringWithAllThreeCharactersOpt(str,3);
    return 0;
}
