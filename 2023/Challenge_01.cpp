#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n1=0;
    string l1,l2="";
    getline(cin,l1);
    vector<string> l3(0,"");
    vector<string> l4(0,"");
    for(int i=0;i<l1.size();i++){
        char a=l1[i]+ 32;
        if(a == 'a' || a == 'b' || a == 'c' || a == 'd' || a == 'e' || a == 'f' || a == 'g' || a == 'h' || a == 'i' || a == 'j' || a == 'k' || a == 'l' || a == 'm' || a == 'n' || a == 'ñ' || a == 'o' || a == 'p' || a == 'q' || a == 'r' || a == 's' || a == 't' || a == 'u' || a == 'v' || a == 'w' || a == 'x' || a == 'y' || a == 'z'){
            l2+=a;
            l1[i]=a;
        }else if(l1[i]==' ' || l1.size()-i==1){
            if(l1.size()-i==1){
                l2+=l1[i];
            }
            for(int j=0;j<l3.size();j++){
                if(l2!=l3[j]){
                    n1++;
                }
            }
            if(n1==l3.size()){
                l3.push_back(l2);
            }
            l4.push_back(l2);
            n1=0;
            l2="";
        }else{
            l2+=l1[i];
        }
    }
    for(int i=0; i<l3.size();i++){
        for(int j=0;j<l4.size();j++){
            if(l3[i]==l4[j]){
                n1++;
            }
        }
        cout<<l3[i]<<n1;
        n1=0;
    }
    
}