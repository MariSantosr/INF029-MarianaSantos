#include <stdio.h>
//Estrutura de Ponteiros em linguagem C
//Definição -Um ponteiro é uma variável capaz de armazenar um endereço de memória ou o endereço de outra variável.
//Estrutura de declaração
/* void main() {
  int a;
  int b;
  int c;
  int *ptr;  // declara um ponteiro para um inteiro
             // um ponteiro para uma variável do tipo inteiro
  a = 90;
  b = 2;
  c = 3;
  ptr = &a;
  printf("Valor de ptr: %p, Conteúdo de ptr: %d\n", ptr, *ptr);
  printf("B: %d, C: %d", b, c);
}*/

// Leitura de um ponteiro 
/* void main()
{
  int x;
  int *ptr;
  ptr = &x;
  printf("O endereço de X é: %p\n", ptr);
}*/

int main() {
    
    int var = 15;
    int *ptr;
    
    ptr = &var;
    
    printf("Conteúdo da variável: %d\n", var);
    printf("Endereço da variável: %p\n", &var);
    printf("Conteúdo apontado por ptr: %d\n", *ptr);
    printf("Endereço apontado por ptr: %p\n", ptr);
    printf("Endereço do ptr: %p\n", &ptr);
    
    *ptr = 73;
    
    printf("\n\n");
    printf("Conteúdo da variável: %d\n", var);
    printf("Endereço da variável: %p\n", &var);
    printf("Conteúdo apontado por ptr: %d\n", *ptr);
    printf("Endereço apontado por ptr: %p\n", ptr);
    printf("Endereço do ptr: %p\n", &ptr);

    return 0;
}

/* Resumo sobre Ponteiros
*ptr = O apontado por, conteúdo do endereço da variável que ptr aponta 
ptr = o endereço da variável 
&ptr = o endereço do ponteiro
*/