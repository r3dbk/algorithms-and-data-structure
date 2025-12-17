#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

string firstDuplicate(const vector<string>& arr){
    unordered_map<string,int> m;
    for(const string& s:arr){
        if(m.find(s)!=m.end()){
            return s;
        }
        m[s]=1;
    }
    return "";
}

int main(){
    int n;
    cout<<"enter array size: ";
    cin>>n;
    vector<string> arr(n);
    cout<<"enter "<<n<<" strings: ";
    for(int i=0;i<n;i++) cin>>arr[i];
    
    string res=firstDuplicate(arr);
    if(res.empty()){
        cout<<"no duplicates found"<<endl;
    }else{
        cout<<"first duplicate: "<<res<<endl;
    }
    return 0;
}
