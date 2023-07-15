
#ifndef dosyaislemleri
#define dosyaislemleri

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h> //c90'a bool veri tipini  tanitabilmek icin

int dosyaKarakterSayisi(char *dosyaYolu){
  FILE *f;
  int i=0 , k=0;
  char ch;
  f = fopen (dosyaYolu,"r");
  while(!feof(f))
  {
    ch=getc(f);
    if(ch=='\n'){ k++; }
    i++;
  }
  return i;
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
void dosyaYaz(char *dosyayolu,char *veri,char *durum){
  FILE *fp;
  if ((fp = fopen (dosyayolu,durum)) == NULL ) // fp pointeri  NULL deger donduruyorsa dosya acilamamistir
    printf("dosya acma hatasi!"); // egerki durumda 'a' gonderiliyorsa  dosyanin sonuna yazilacaktir. 'w' gonderiliyorsa butun dosyaya o deger basilacaktir.

  fputs("\n",fp); // bir alt satira gecisi  saglar
  fputs(veri,fp); // veri icerisindeki  deger dosyaya gonderilir.
  fclose(fp); // acilmis olan dosya isleme kapatilir.
}
char* satirOku(char *dosyaYolu, int satir){
  FILE *f;
  int k=0,i=0;
  char ch, veri[1000], *rvalue;
  f = fopen (dosyaYolu,"r");
  while(!feof(f))
  {
    ch=getc(f);
    if(ch=='\n')
      k++;

    if(k == (satir+1))
    {
      veri[i] = '\0';
      break;
    }

    if (k == satir && ch != '\n'){
      veri[i] = ch;
      i++;
    }
  }
  rvalue = veri;
  return rvalue;
}
char* dosyaOku(char *dosyaYolu){
  char veri[1000], *rvalue;
  FILE *fp;
  int id, i=0;
  if ((fp = fopen (dosyaYolu, "r")) == NULL)
    return NULL;
  // printf("Dosya açma hatası!");
  while ((id=getc(fp))!= EOF){
    veri[i] = id;
    i++;
  }
  fclose(fp);
  rvalue = veri;
  return rvalue;
}
#endif
