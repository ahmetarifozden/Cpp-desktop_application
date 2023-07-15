#include <iostream>
#include <fstream>
#include <string>

#ifdef __linux__

#else
  #include <Windows.h>
#endif

using namespace std;


string degisken[4][2];
double degiskenDeger[4];

bool degiskenDegerKontrol[4]; // buradaki 4 degisken haline getirilecek (otomatize edilecek)

string printOut(string veri){
  string rvalue;
  int indis = veri.find("OUT");
  indis += 3;

  for (int i = indis; i < veri.length(); i++)
    if (isalpha(veri[i]) || isdigit(veri[i])) // OUT'dan sonra sayi veya harf buldugunda bunu ciktiya ekler
      rvalue += veri[i];

  return rvalue;
}
int dosyaSatirSayisi(char *dosyaYolu){
  FILE *f;
  int k=0;
  char ch;
  f = fopen (dosyaYolu,"r");
  while(!feof(f))
  {
    ch=getc(f);
    if(ch=='\n'){ k++; }
  }
  return k;
}
//
// void sifirla(){
//   for (int i = 0; i < degisken.length(); i++) {
//     degisken[i][0].clear(); // buradaki string degiskeni tamamen sifirlar
//     degisken[i][1].clear(); // buradaki string degiskeni tamamen sifirlar
//   }
// }

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
void satirOku(string dosyaYolu, int satirNumarasi, string cikisYolu){

  string veri;

  ifstream dosyaOku(dosyaYolu);

  if (dosyaOku.is_open()) {
      for (int i = 0; i <= satirNumarasi; i++)
          getline(dosyaOku, veri);
      dosyaOku.close();
  }

  for (int i = 0; i < veri.length(); i++) {
    if (isalpha(veri[i]) ) { // satirda harf arar. buldugu harfi degisken icerisine yazdirir.


    }
  }
}
// 1.
// void sample1(){
//   string girisyolu = "inputFolder/Challange1.inp";
//   string cikisYolu = "outputFolder/Challange1.inp";
//   int satirSayisi = dosyaSatirSayisi(girisyolu);
//   for (int i = 0; i <= satirSayisi; i++) {
//       veriOku(girisyolu, i,cikisYolu);
//   }
//   sifirla(); // global egisken sifirlama
// }
// void sample2(){
//   string dosyaYolu = "inputFolder/Challange2.inp";
//   string cikisYolu = "outputFolder/Challange2.inp";
//   int satirNumarasi = 2;
//   for (int i = 0; i <= satirNumarasi; i++) {
//       veriOku(dosyaYolu, i,cikisYolu);
//   }
//   sifirla(); // global egisken sifirlama
// }
// void sample3(){
//   string dosyaYolu = "inputFolder/Challange3.inp";
//   string cikisYolu = "outputFolder/Challange3.inp";
//   int satirNumarasi = 2;
//   for (int i = 0; i <= satirNumarasi; i++) {
//       veriOku(dosyaYolu, i,cikisYolu);
//   }
//   sifirla(); // global egisken sifirlama
// }
// void sample4(){
//   string dosyaYolu = "inputFolder/Challange4.inp";
//   string cikisYolu = "outputFolder/Challange4.inp";
//   int satirNumarasi = 2;
//   for (int i = 0; i <= satirNumarasi; i++) {
//       veriOku(dosyaYolu, i,cikisYolu);
//   }
//   sifirla(); // global egisken sifirlama
// }
// void sample5(){
//   string dosyaYolu = "inputFolder/Challange5.inp";
//   string cikisYolu = "outputFolder/Challange5.inp";
//   int satirNumarasi = 2;
//   for (int i = 0; i <= satirNumarasi; i++) {
//       veriOku(dosyaYolu, i,cikisYolu);
//   }
//   sifirla(); // global egisken sifirlama
// }


string copyString(string veri, int baslangicIndis, int sonIndis){
  string rvalue;

  for (int i  = baslangicIndis; i < sonIndis; i++)
  rvalue +=  veri[i];

  return rvalue;
}

//
// void deneme(){
//   bool esittirKontrol;
//   string veri = "A2 = IF A1 > B1 THEN A1 ELSE B1";
//   int bulunanHarfSayisi=0, esittirIndis, type;
//   string bulunanHarf, bulunanSayi;
//
//   for (int i = 0; i < veri.length(); i++)
//     if (isalpha(veri[i]))
//       bulunanHarfSayisi ++;
//
//   if (bulunanHarfSayisi == 1)  // Bu  bir deger atama satiridir.
//     type = 1;
//
//   else if (veri.find("OUT") != -1) // Bu bir OUT satiridir
//     type = 2;
//
//   else if (veri.find("IF") != -1) // Bu bir IF satiridir
//     type = 3;
//
//   else if (bulunanHarfSayisi > 1) // Degiskenler arasi islem tespiti
//     type = 4;
//
//   if (type == 1) {
//     int sayac = 0;
//     while (degiskenDegerKontrol[sayac] == true)
//       sayac++;
//
//
//     for (int a = 0; a < veri.length(); a++) {
//       if (veri[a] == '=' && esittirKontrol != true )
//         esittirKontrol = true;
//
//       while (esittirKontrol != true &&degiskenDegerKontrol[sayac] != false && isdigit(veri[a]) || isalpha(veri[a]) ) {
//         degisken[sayac][0] += veri[a];
//         a++;
//         if (!isdigit(veri[a]) || !isalpha(veri[a]))
//           degiskenDegerKontrol[sayac] = true;
//
//       }
//       while (esittirKontrol == true && isdigit(veri[a])) {
//         degisken[sayac][1] += veri[a];
//         a++;
//       }
//
//     }
//     cout << degisken[0][0] << " = " << degisken[0][1]<<endl;
//   }
//   else if (type == 2) {
//     cout << printOut(veri)<<endl;
//   }
//   else if (type == 3) {
//     string veri = "A2 = IF A1 > B1 THEN A1 ELSE B1";
//
//     int baslangicIndis = 0;
//
//     int sonIndis = veri.find("=");
//     string ifEsitlik = copyString(veri,baslangicIndis, sonIndis);
//     string esitlikDegiskeni;
//
//     for (int i = 0; i < ifEsitlik.length(); i++) {
//       if (isdigit(ifEsitlik[i]) || isalpha(ifEsitlik[i]) ) {
//         esitlikDegiskeni += ifEsitlik[i];
//       }
//     }
//     cout << "esitlikDegiskeni: " << esitlikDegiskeni<<endl;
//
//
//     baslangicIndis = veri.find("IF");
//     baslangicIndis += 2;
//     sonIndis = veri.find("THEN");
//     string kosul = copyString(veri,baslangicIndis, sonIndis);
//     string isaret;
//     string kosulDegisken1, kosulDegisken2;
//     bool isaretKontrol;
//
//     for (int a = 0; a < kosul.length(); a++) {
//
//       if (isaretKontrol != true && (kosul[a] == '=' || kosul[a] == '>' || kosul[a] == '<')){
//         isaretKontrol = true;
//         isaret += kosul[a];
//         if ((kosul[a+1] == '=' || kosul[a+1] == '>' || kosul[a+1] == '<')) {
//           isaret += kosul[a+1];
//         }
//       }
//       if (isaretKontrol != true && (isdigit(kosul[a]) || isalpha(kosul[a])) ) {
//         kosulDegisken1 += kosul[a];
//       }
//       if (isaretKontrol == true && (isdigit(kosul[a]) || isalpha(kosul[a])) ) {
//         kosulDegisken2 += kosul[a];
//       }
//     }
//     cout << "isaret: " << isaret <<endl;
//     cout << kosul<<endl;
//
//
//
//     baslangicIndis = veri.find("THEN");
//     baslangicIndis += 4;
//     sonIndis = veri.find("ELSE");
//     string ifSonuc = copyString(veri,baslangicIndis, sonIndis);
//     string ifDegiskeni;
//     for (int i = 0; i < ifSonuc.length(); i++) {
//       if (isdigit(ifSonuc[i]) || isalpha(ifSonuc[i]) ) {
//         ifDegiskeni += ifSonuc[i];
//       }
//     }
//     cout << "ifDegiskeni: " << ifDegiskeni<<endl;
//
//
//     baslangicIndis = veri.find("ELSE");
//     baslangicIndis += 4;
//     sonIndis = veri.length();
//     string elseSonuc = copyString(veri,baslangicIndis, sonIndis);
//     string elseDegiskeni;
//     for (int i = 0; i < elseSonuc.length(); i++) {
//       if (isdigit(elseSonuc[i]) || isalpha(elseSonuc[i]) ) {
//         elseDegiskeni += elseSonuc[i];
//       }
//     }
//     cout << "elseDegiskeni: " << elseDegiskeni<<endl;
//
//
//     cout << endl<<endl<<endl;
//     if (isaret == ">") {
//       cout << degisken1 << "   "<<degisken2 <<"' den buyukse"<<endl;
//     }
//     else if (isaret == "=") {
//       cout << degisken1 << "   "<<degisken2 <<"' ye esitse"<<endl;
//     }
//     else if (isaret == "<") {
//       cout << degisken1 << "   "<<degisken2 <<"' den kucukse"<<endl;
//     }
//     else if (isaret == "<=") {
//       cout << degisken1 << "   "<<degisken2 <<"' e kucuk esitse"<<endl;
//     }
//     else if (isaret == ">=") {
//       cout << degisken1 << "   "<<degisken2 <<"' e buyuk esitse"<<endl;
//     }
//     else if (isaret == "==") {
//       cout << degisken1 << "   "<<degisken2 <<"' e esitse"<<endl;
//     }
//     cout << esitlikDegiskeni << " = " << ifDegiskeni;
//     cout << " Degilse " << esitlikDegiskeni << " = " << elseDegiskeni;
//
//
//   }
// }


int main(){

  /*
      type == 1 // bu bir deger atama satiridir Or: A1 = 10, B = 4;
      type == 2 // bu bir OUT satiridir
      type == 3 // bu bir IF satiridir
      type == 4 // Degiskenler arasi islem tespiti Or: A = B + C
  */


    string veri = "A2 = IF A1 > B1 THEN A1 ELSE B1";

    int baslangicIndis = 0;

    int sonIndis = veri.find("=");
    string ifEsitlik = copyString(veri,baslangicIndis, sonIndis);
    string esitlikDegiskeni;

    for (int i = 0; i < ifEsitlik.length(); i++) {
      if (isdigit(ifEsitlik[i]) || isalpha(ifEsitlik[i]) ) {
        esitlikDegiskeni += ifEsitlik[i];
      }
    }
    cout << "esitlikDegiskeni: " << esitlikDegiskeni<<endl;


    baslangicIndis = veri.find("IF");
    baslangicIndis += 2;
    sonIndis = veri.find("THEN");
    string kosul = copyString(veri,baslangicIndis, sonIndis);
    string isaret;
    string kosulDegisken1, kosulDegisken2;
    bool isaretKontrol;

    for (int a = 0; a < kosul.length(); a++) {

      if (isaretKontrol != true && (kosul[a] == '=' || kosul[a] == '>' || kosul[a] == '<')){
        isaretKontrol = true;
        isaret += kosul[a];
        if ((kosul[a+1] == '=' || kosul[a+1] == '>' || kosul[a+1] == '<')) {
          isaret += kosul[a+1];
        }
      }
      if (isaretKontrol != true && (isdigit(kosul[a]) || isalpha(kosul[a])) ) {
        kosulDegisken1 += kosul[a];
      }
      if (isaretKontrol == true && (isdigit(kosul[a]) || isalpha(kosul[a])) ) {
        kosulDegisken2 += kosul[a];
      }
    }
    cout << "isaret: " << isaret <<endl;
    cout << kosul<<endl;



    baslangicIndis = veri.find("THEN");
    baslangicIndis += 4;
    sonIndis = veri.find("ELSE");
    string ifSonuc = copyString(veri,baslangicIndis, sonIndis);
    string ifDegiskeni;
    for (int i = 0; i < ifSonuc.length(); i++) {
      if (isdigit(ifSonuc[i]) || isalpha(ifSonuc[i]) ) {
        ifDegiskeni += ifSonuc[i];
      }
    }
    cout << "ifDegiskeni: " << ifDegiskeni<<endl;


    baslangicIndis = veri.find("ELSE");
    baslangicIndis += 4;
    sonIndis = veri.length();
    string elseSonuc = copyString(veri,baslangicIndis, sonIndis);
    string elseDegiskeni;
    for (int i = 0; i < elseSonuc.length(); i++) {
      if (isdigit(elseSonuc[i]) || isalpha(elseSonuc[i]) ) {
        elseDegiskeni += elseSonuc[i];
      }
    }
    cout << "elseDegiskeni: " << elseDegiskeni<<endl;


    cout << endl<<endl<<endl;
    if (isaret == ">") {
      cout << kosulDegisken1 << "   "<<kosulDegisken2 <<"' den buyukse"<<endl;
    }
    else if (isaret == "=") {
      cout << kosulDegisken1 << "   "<<kosulDegisken2 <<"' ye esitse"<<endl;
    }
    else if (isaret == "<") {
      cout << kosulDegisken1 << "   "<<kosulDegisken2 <<"' den kucukse"<<endl;
    }
    else if (isaret == "<=") {
      cout << kosulDegisken1 << "   "<<kosulDegisken2 <<"' e kucuk esitse"<<endl;
    }
    else if (isaret == ">=") {
      cout << kosulDegisken1 << "   "<<kosulDegisken2 <<"' e buyuk esitse"<<endl;
    }
    else if (isaret == "==") {
      cout << kosulDegisken1 << "   "<<kosulDegisken2 <<"' e esitse"<<endl;
    }
    cout << esitlikDegiskeni << " = " << ifDegiskeni;
    cout << " Degilse " << esitlikDegiskeni << " = " << elseDegiskeni;



  return 0;
}
