#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>

using namespace std;

string degisken[3][2];
void sifirla(){
  degisken[0][1] = "";
  degisken[1][1] = "";
  degisken[2][1] = "";
}
void remove_all(){
  system("cls");
}
void dosyaYaz(string dosyaYolu, string sonuc){
  ofstream dosyaYaz(dosyaYolu);
  if ( dosyaYaz.is_open() ){
    dosyaYaz << sonuc;
    dosyaYaz.close();
  }
}
void dortislem(string veri,string dosyaYolu) {

    bool esittir = false;
    int sayac = 0, esittirSayi = 0;
    string isaret;
    int oncekiler[3] = { -1,-1,-1 };
    int a[3];

    for (int i = 0; i < veri.length(); i++) {
        string temp;
        temp.append(1, veri[i]);

        for (int a = 0; a < 3; a++) {
            if (temp.compare(degisken[a][0]) == 0 && esittir == false) {
                degisken[a][1] = "0";
                oncekiler[a] = a;
                sayac++;
            }
        }
        if (veri[i] == '=') {
            esittir = true;
        }
        if (esittir == true && (veri[i] == '+' || veri[i] == '-' || veri[i] == '*' || veri[i] == '/')) {
            isaret = veri[i];
        }
    }
    sayac = 0;
    cout << "Esittirden onceki sayilar: " << endl;
    for (int i = 0; i < 3; i++) {
        if (oncekiler[i] != -1) {
            a[sayac] = oncekiler[i];
            cout << degisken[oncekiler[i]][0] << " : " << degisken[oncekiler[i]][1] << endl;
            sayac++;
            break;
        }
    }
    cout << "Esittirden sonraki sayilar: " << endl;
    for (int i = 0; i < 3; i++) {
        if (oncekiler[i] == -1) {
            a[sayac] = i;
            cout << degisken[i][0] << " : " << degisken[i][1] << endl;
            sayac++;
        }
    }

    cout << "dort islem icin kullanilacak olan isaret: " + isaret << endl;

    cout << "islem yap: " << endl;

    double sonuc = stod(degisken[a[0]][1]);

    if (isaret == "+")
        sonuc = stod(degisken[a[1]][1]) + stod(degisken[a[2]][1]);
    else if (isaret == "-")
        sonuc = stod(degisken[a[1]][1]) - stod(degisken[a[2]][1]);
    else if (isaret == "*")
        sonuc = stod(degisken[a[1]][1]) * stod(degisken[a[2]][1]);
    else if (isaret == "/")
        sonuc = stod(degisken[a[2]][1]) / stod(degisken[a[1]][1]);

    dosyaYaz(dosyaYolu,to_string(sonuc));
    cout << "sonuc: " << sonuc << endl;
    if('dosyaYolu' = "sample5.inp"){
      cout<<"buraya girdi"<<endl;
    }
}
void veriOku(string dosyaYolu, int satirNumarasi, string cikisYolu) {

    string veri;
    bool k[3], s[3], esittir = false, dortislemKontrol = false;
    int id, i = 0, sayac = 0;

    ifstream dosyaOku(dosyaYolu);

    if (dosyaOku.is_open()) {
        for (int i = 0; i <= satirNumarasi; i++)
            getline(dosyaOku, veri);
        dosyaOku.close();
    }
    for (i = 0; i < veri.length(); i++) {
        while (isalpha(veri[i]) && k[sayac] != true) {
            degisken[satirNumarasi][0] = veri[i];
            k[sayac] = true;
        }
        while (veri[i] == '=' && esittir != true) {
            esittir = true;
            for (int k = i; k < veri.length(); k++) {
                if (isalpha(veri[k]) && dortislemKontrol != true) {
                    dortislemKontrol = true;
                    dortislem(veri,cikisYolu);
                }
            }
        }
        while (isdigit(veri[i])) {
            degisken[satirNumarasi][1] += veri[i];
            i++;
        }
    }
}

void sample1(){
  string dosyaYolu = "sample1.inp";
  string cikisYolu = "sample1.out";
  int satirNumarasi = 2;
  for (int i = 0; i <= satirNumarasi; i++) {
      veriOku(dosyaYolu, i,cikisYolu);
  }
  sifirla(); // global egisken sifirlama
}
void sample2(){
  string dosyaYolu = "sample2.inp";
  string cikisYolu = "sample2.out";
  int satirNumarasi = 2;
  for (int i = 0; i <= satirNumarasi; i++) {
      veriOku(dosyaYolu, i,cikisYolu);
  }
  sifirla(); // global egisken sifirlama
}
void sample3(){
  string dosyaYolu = "sample3.inp";
  string cikisYolu = "sample3.out";
  int satirNumarasi = 2;
  for (int i = 0; i <= satirNumarasi; i++) {
      veriOku(dosyaYolu, i,cikisYolu);
  }
  sifirla(); // global egisken sifirlama
}
void sample4(){
  string dosyaYolu = "sample4.inp";
  string cikisYolu = "sample4.out";
  int satirNumarasi = 2;
  for (int i = 0; i <= satirNumarasi; i++) {
      veriOku(dosyaYolu, i,cikisYolu);
  }
  sifirla(); // global egisken sifirlama
}
void sample5(){
  string dosyaYolu = "sample5.inp";
  string cikisYolu = "sample5.out";
  int satirNumarasi = 2;
  for (int i = 0; i <= satirNumarasi; i++) {
      veriOku(dosyaYolu, i,cikisYolu);
  }
  sifirla(); // global egisken sifirlama
}
int main(){
  // sample1();
  // sample2();
  // sample3();
  // sample4();
  sample5();
  // system("CLS");
  return 0;
}
