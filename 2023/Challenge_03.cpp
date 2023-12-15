#include <iostream>
using namespace std;
int main(){
    int CantidadLista,ClaveIncorrectaMostrar,ContadorIncorrectas=0,ContadorCorrectas=0;
    cin>>CantidadLista;
    cin.ignore();
    cin>>ClaveIncorrectaMostrar;
    cin.ignore();
    string l1[CantidadLista];
    for(int i=0;i<CantidadLista;i++){
      getline(cin,l1[i]);
    }
    for(int i=0; i<CantidadLista;i++){
      int min=0,max=0,espacios=0,ContadorLetra=0;
      char letra;
      string numeros="";
      int guion=0;
      for(int j=0;j<l1[i].size();j++){
        if(l1[i][j]=='-'){
          guion=1;
        }
        if(l1[i][j]==' '){
          espacios++;
        }
        if(espacios==0 && guion==0){
          if(l1[i][1]=='-'){
            min=l1[i][j]-48;
          }else{
            numeros+=l1[i][j];
            if(l1[i][j+1]=='-'){
              min=stoi(numeros);
              numeros="";
            }
          }
        }else if(espacios==0){
          if(l1[i][3]==' '){
            max=l1[i][j]-48;
          }else if(l1[i][4]==' ' && min>9){
            max=l1[i][j]-48;
          }else{
            numeros+=l1[i][j+1];
            if(l1[i][j+1]==' '){
              max=stoi(numeros);
              numeros="";
            }
          }
        }else if(espacios<2 && l1[i][j]!=':'){
          letra=l1[i][j];
        }else if(espacios==2 && l1[i][j]==letra){
          ContadorLetra++;
        }
      }
      if(ContadorLetra<min || max<ContadorLetra){
        ContadorIncorrectas++;
      }
      espacios=0;
      if(ContadorIncorrectas==ClaveIncorrectaMostrar){
        for(int j=0;j<l1[i].size();j++){
          if(l1[i][j]==' '){
            espacios++;
          }else if(espacios==2){
            cout<<l1[i][j];
          }
          CantidadLista=0;
        }
      }
    }
}
