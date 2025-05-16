#include <stdio.h>

int somar (int a, int b) {

    return a + b;
}

int main () {

    int n1;
    int n2;
    int resultado;

    printf("Informe valor do 1º numero: \n");
    scanf("%d", &n1);
    printf("Informe valor do 2º numero: \n");
    scanf("%d", &n2);

    resultado = somar(n1, n2);

    printf("Resultado: %d\n", resultado);
    
}