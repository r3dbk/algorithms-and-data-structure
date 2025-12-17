#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> intersect(const vector<int>& a,const vector<int>& b){
    unordered_map<int,bool> m;
    vector<int> res;
    for(int x:a){
        m[x]=true;
    }
    for(int x:b){
        if(m.find(x)!=m.end()&&m[x]){
            res.push_back(x);
            m[x]=false;
        }
    }
    return res;
}

int main(){
    int n1,n2;
    cout<<"enter size of first array: ";
    cin>>n1;
    vector<int> a(n1);
    cout<<"enter "<<n1<<" numbers for first array: ";
    for(int i=0;i<n1;i++) cin>>a[i];

    cout<<"enter size of second array: ";
    cin>>n2;
    vector<int> b(n2);
    cout<<"enter "<<n2<<" numbers for second array: ";
    for(int i=0;i<n2;i++) cin>>b[i];

    vector<int> res=intersect(a,b);
    if(res.empty()){
        cout<<"no intersection"<<endl;
    }else{
        cout<<"intersection: ";
        for(int x:res) cout<<x<<" ";
        cout<<endl;
    }
    return 0;
}
