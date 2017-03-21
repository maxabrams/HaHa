/*
* Max Abrams
* file: HaHa.cpp
* Desription: HaHa string to Latin string converter. 
* Given an input string in HaHa, this will produce all Latin equivalents based on the rules at www.maxwellabrams.com/sandbox/ha.php
* 
* This is written in C++ for speed. On my test machine, a 26-ha long string took 58 seconds in C++, 14 minutes in Java, and crashed the broswer in JS.
*
* Compile instructions: gcc haha.cpp -o ha.out
* Usage example: ./ha.out ha > ha_output.txt
* ha_output.txt will contain: a
*
* Time your results (try LARGE haha strings ;)) with command: time ./ha.out hahaha > ha_output.txt
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VAL 26 //Maximum number to use (z = 26)
#define ARR_SIZE 50 //Maximum 

/*
* Convert input string of HaHa to a number of Ha's.
* (Note: It does not actually mater if it is ha's - any pair of two works for this logic)
*/
int convertHaToNum(char* str){
    if(strlen(str) % 2  != 0){
      printf("Error! Cannot make HaHa from odd number of letters! \n");
      return -1;
    }else{
      int numHa = strlen(str)/2;
      if(numHa > ARR_SIZE){
        printf("Error! This version only supports %d ha's! \n", ARR_SIZE);
        return -1;
      }
      return numHa;
    }
}

/*
* Print a completed Latin equivalent string 
*/
void print(int arr[], int arr_size){
  for (int i = 0; i < arr_size; i++){
    putchar(96 + arr[i]);
  }
  printf("\n");
}

/*
* Recursivley build a Latin equivalent string. 
* Note: there are 2^(n-1) possibile Latin strings for each HaHa string
*/
void makeCombo(int n, int i){
  
  static int arr[ARR_SIZE];
 
  if (n == 0){
    print(arr, i);
  }else if(n > 0){ 
      for (int j = 1; j <= MAX_VAL; j++){
        arr[i]= j;
        makeCombo(n-j, i+1);
      }
    }
}
 
/*
* Driver function 
*/
int main(int argc, char *argv[]){
  if(argc != 2){
    printf("Error! Please pass a HaHa string as an argument. Ex: hahaha \n");
    return -1;
  }

  int n = convertHaToNum(argv[1]);
  
  if(n != -1){
    makeCombo(n, 0);
    return 0;
  }else{
    return -1;
  }
}
