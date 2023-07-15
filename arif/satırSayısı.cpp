#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>

using namespace std;

int satirSayisi(string dosyaOku, int dosyaSatirSayisi){
  int satirSayisi
  int numLines = 0;
  ifstream in(dosyaOku);
  string unused;
  while (getline(in, unused))
  ++numLines;
  cout<<numLines;
}


int main() {

satirSayisi("sample1.inp");


  return 0;
}
