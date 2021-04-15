#include <iostream>
#include <string>
#include <algorithm> 

using namespace std;

string interpretador(string msg, int nFragmentos);
int encontraNumeroFragmentos(string msg);

int main() {
  string msg = "90c87esd67uj,./';*&^120lin87uj101gu87km102a77jh150gem..&";

  // string msg = "*(12*23qualquer130i120n87j102t87ejh104er*&^_)(105n7k122e33kw140t**";

  cout << msg << endl;
  
  int n = encontraNumeroFragmentos(msg);
  string mm = interpretador(msg, n);
  // cout << "n = " << n << endl;
  cout << "Mensagem decodificada = " << mm << endl;

}

string interpretador(string msg, int nFragmentos)
{
  string fq;
  string submsg, msgDecodificada = "";
  int idx, caracter; 

  int vet[nFragmentos];
  int qnt = 0;
  for(int i = 100; i <= 200; i++){
      idx = msg.find(to_string(i));

    if(idx > 0)
    {
      vet[qnt] = idx;
      qnt ++;
    }
  }

  sort(vet, vet + nFragmentos);

  for(int k = 0; k < qnt; k++)
  {
    submsg = msg.substr(vet[k]+3);
    
    int j;
    for(j = 0; j < submsg.size(); j++)
    {
      caracter = submsg[j];
      // cout << "caracter = " << submsg[j] << endl;
      if(!((caracter >= 97) && (caracter <= 122)))
      {
        break;
      }
    }
    
    msgDecodificada += submsg.substr(0, j);
  }
  return msgDecodificada;
}

int encontraNumeroFragmentos(string msg)
{
  int qnt = 0;
  int idx;

  for(int i = 100; i <= 200; i++){
      idx = msg.find(to_string(i));

    if(idx > 0)
      qnt ++;
  }

  

  return qnt;
}