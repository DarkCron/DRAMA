// Code nodig om getint() en printint() te implementeren...
#include "stdio.h"
 
int getint() {
    int result;
    scanf("%d", &result);
    return result;
}
 
void printint(int getal) {
    printf("%d", getal);
}
 
void nieuweLijn() {
    printf("\n");
}
 
// Het eigenlijke programma...
 
int MAXLENGTH = 6;
 
/* 'Encrypted' form of the password...
 * Original password = 1 2 3 4 5 6
 */
int internalPasswd[6] = {3,6,9,10,15,12};
 
/*
 * Function encrypts a given password and checks whether it is equal
 * to the installed password.
 */
int encryptAndCheck(int passwd[]){
  register int i, j;
  register int equal;

  equal = 1; 
  i = 0;
  while( i < MAXLENGTH){
    passwd[i] = passwd[i] + passwd[(i + passwd[i]) % MAXLENGTH];
 
    j = 0;
    while (j < MAXLENGTH){
      printint(passwd[j++]);
    }
    nieuweLijn();
 
    i++;
  }
 
  i = 0;
  while( (i < MAXLENGTH) && (equal == 1)){
    if( internalPasswd[i] != passwd[i] ){
      equal = 0;
    }
    i++;
  }
  return equal;
}
 
 
void main(void){
  int access; 
  int passwd[6];
  register int i;
 
  /* initialization */
  
  access = 0;
  i = 0;
  while( i < MAXLENGTH ){
    passwd[i++] = 0;
  }
 
  /* get input */
  i = 0;
  passwd[i] = getint();
  
  while( ( i < MAXLENGTH ) && (passwd[i] != 0) ){
    i++;
    passwd[i] = getint();
  }
 
  /* check passwd */
  if ( encryptAndCheck(passwd) == 1 ){
    access = 1;
  }
 
  if( access == 1 ){
    /* allow user access */
    printint(1111);
  }else{
    /* deny user */
    printint(0);
  }
}
