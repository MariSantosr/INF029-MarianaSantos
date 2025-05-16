#include <stdio.h>

int subtrair (int a, int b, int c) {

    return (a - b) - c; 
}

int main(){

    int n1;
    int n2; 
    int n3;
    int resultado;

    printf("Informe valor do 1º numero: \n");
    scanf("%d", &n1);
    printf("Informe valor do 2º numero: \n");
    scanf("%d", &n2);
    printf("Informe valor do 3º numero: \n");
    scanf("%d", &n3);

    resultado = subtrair(n1, n2, n3);

    printf("Resultado = %d\n", resultado);

}