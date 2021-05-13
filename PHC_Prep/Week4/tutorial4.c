#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void words(FILE* f);
void printfile(FILE* f);
void contains(char *dna,int a[]);
float d_euclid(int a[5],int b[5]);
void frequencies(char *dna,float a[]);

int main(){
  FILE *f;
  int i,a[5];
  printfile(f);
  words(f);
  contains("AAAA",a);
  for(i=0;i<5;i++){
    printf("%d",a[i]);
  }
  printf("\n");
  contains("ACTU",a);
  for(i=0;i<5;i++){
    printf("%d",a[i]);
  }
  printf("\n");
  contains("GGUU",a);
  for(i=0;i<5;i++){
    printf("%d",a[i]);
  }
  printf("\n");

  int b[5];
  contains("AAAA",a);
  contains("AAAA",b);
  printf("The Euclid distance betweent the two strings is %f",d_euclid(a,b));
  printf("\n");
  contains("AAAA",a);
  contains("AAAC",b);
  printf("The Euclid distance betweent the two strings is %f",d_euclid(a,b));
  printf("\n");
  contains("AAAA",a);
  contains("GGGG",b);
  printf("The Euclid distance betwee nt the two strings is %f",d_euclid(a,b));
  printf("\n");

  int c[5];
  contains("ATUU",a);
  contains("ACCG",b);
  contains("GTUU",c);
  if(d_euclid(a,b) < d_euclid(a,c)){
    printf("Your DNA is closer to the ACCG fragment\n");
  }
  else{
    printf("Your DNA is closer to the GTUU fragment\n");
  }
  float d[5];
  frequencies("GTUU",d);
  for(i=0;i<5;i++){
    if(d[i]==1){
      d[i]=0;
    }
    printf("%0.2f ",d[i]);
  }
  printf("\n");

  fclose(f);
}
void words(FILE* f){

  char c;
  int count = 1;
  f = fopen("tutorial4.txt","r");
  c = fgetc(f);
  while(c != EOF){
    c = fgetc(f);
    if (c == *" " || c == *"." || c == *"," || c == *"?" || c == *"!"){
      count++;
    }
  }
  if(f == NULL){
    printf("Error!");
    exit(1);
  }
  printf("%d\n",count);
}
void printfile(FILE* f){
  char c;
  f = fopen("tutorial4.txt","r");
  c = fgetc(f);
  while (c != EOF){
    printf("%c",c);
    c = fgetc(f);
  }
  fclose(f);
}
void contains(char *dna,int a[5]){
  int i;
  char ch;
  for(i=0;i<5;i++){
    a[i]=0;
  }
  i=0;
  do{
    ch = dna[i];
    if(ch == 'A'){
      a[0]=1;
    }
    if(ch == 'C'){
      a[1]=1;
    }
    if(ch == 'G'){
      a[2]=1;
    }
    if(ch == 'T'){
      a[3]=1;
    }
    if(ch == 'U'){
      a[4]=1;
    }
    i++;
  }while(ch != '\0');
}
float d_euclid(int a[5],int b[5]) {
  float d = 0;
  int i;
  for(i=0;i<5;i++){
    d = d+pow(a[i]-b[i],2);
  }
  d=sqrt(d);
  return d;
}
void frequencies(char *dna,float a[5]) {
  int i;
  char ch;
  for(i=0;i<5;i++){
    a[i]=1;
  }
  i=0;
  while(ch != '\0'){
    ch = dna[i];
    if(ch == 'A'){
      a[0] *= 0.5;
    }
    if(ch == 'C'){
      a[1] *= 0.5;
    }
    if(ch == 'G'){
      a[2] *= 0.5;
    }
    if(ch == 'T'){
      a[3] *= 0.5;
    }
    if(ch == 'U'){
      a[4] *= 0.5;
    }
    i++;
  }
}
