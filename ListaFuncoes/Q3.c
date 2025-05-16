#include <stdio.h>

int fatorial (int a) {
    
    if(a < 0){
        return -1;
    }

    int fatorial_num = 1;
    for(int i = 1; i <= a; i++) 
        fatorial_num *= i;

    return fatorial_num;

}

int main() {

    int num;
    int resultado;

    printf("Informe um número: \n");
    scanf ("%d", &num);

    resultado = fatorial(num);

    printf("Resultado: %d\n", resultado);

}