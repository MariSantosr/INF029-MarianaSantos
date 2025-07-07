#include <stdio.h>
#define TAM 11

int main() {

//variaveis 
int num;
char letra;
char texto[TAM];
float numDecimal;
double numDouble;

//ponteiros 

printf("Digite um numero inteiro: ");
scanf("%d", &num);
getchar();

printf("Digite uma letra: ");
scanf("%c", &letra);

getchar();
printf("Digite um texto de ate 10 caracteres: ");
fgets(texto, TAM, stdin);

printf("Digite um numero decimal float: ");
scanf("%f", &numDecimal);

printf("Digite um numero decimal double: ");
scanf("%lf", &numDouble);


//Saída sem ponteiro
printf("\n--- Dados lidos ---\n");
printf("Numero inteiro: %d\n", num);
printf("Letra: %c\n", letra);
printf("Texto: %s", texto);
printf("Numero float: %.2f\n", numDecimal);
printf("Numero double: %.2lf\n", numDouble);

//Saída com ponteiro

return 0;

}