#include <iostream>
using namespace std;
int main(){
    string l1;
    cin>>l1;
    int n1=0;
    for(int i=0;i<l1.size();i++){
        if(l1[i]=='#'){
            n1++;
        }else if(l1[i]=='@'){
            n1--;
        }else if(l1[i]=='*'){
            n1*=n1;
        }else{
            cout<<n1;
        }
    }
}
