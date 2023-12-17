#include <iostream>
#include <vector>
using namespace std;
int main(){
  unsigned int cantidad=0,verdaderos=0,buscado;
  cin>>cantidad>>buscado;
  vector<string> p(cantidad,"");
  for(int i=0;i<p.size();i++){
    cin>>p[i];
  }
  for(int i=0;i<p.size();i++){
    vector<char> l(0);
    vector<int> nl(0,0);
    int guion=0,incongruente=0;
    for(int j=0;j<p[i].size();j++){
      int encontrado=0;
      for(int k=0;k<l.size();k++){
        if(p[i][j]=='-'){
          guion=1;
          break;
        }else if(p[i][j]==l[k]){
          nl[k]++;
          encontrado=1;
          break;
        }
      }
      if(guion==1){
        guion=j;
        break;
      }else if(encontrado==0){
        l.push_back(p[i][j]);
        nl.push_back(1);
      }
    }
    for(int j=guion+1;j<p[i].size();j++){
      for(int k=0;k<l.size();k++){
        if(p[i][j]==l[k] && nl[k]!=1){
          incongruente=1;
          break;
        }
      }
      if(incongruente==1){
        break;
      }
    }
    if(incongruente==0){
      verdaderos++;
      if(verdaderos==buscado){
        cout<<p[i];
      }
    }
  }
}
