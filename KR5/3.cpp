#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

pair<int,int> findSumInd(const vector<int>& arr,int target){
    unordered_map<int,int> m;
    for(int i=0;i<arr.size();i++){
        int comp=target-arr[i];
        if(m.find(comp)!=m.end()){
            return {m[comp],i};
        }
        m[arr[i]]=i;
    }
    return {-1,-1};
}

int main(){
    int n,target;
    cout<<"enter arr size: ";
    cin>>n;
    vector<int> arr(n);
    cout<<"enter "<<n<<" numbers: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"enter target: ";
    cin>>target;

    pair<int,int> res=findSumInd(arr,target);
    if(res.first!=-1){
        cout<<res.first<<" and "<<res.second<<endl;
        cout<<arr[res.first]<<" + "<<arr[res.second]<<" = "<<target<<endl;
    }else{
        cout<<"no pair"<<endl;
    }
    return 0;
}
