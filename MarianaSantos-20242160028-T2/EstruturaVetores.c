#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define TAM 10

#include "EstruturaVetores.h"

typedef struct {
    int qtdeOcupadas;
    int tamanhoAlocado;
    int *elementos;
} EstruturaAuxiliar;

EstruturaAuxiliar *vetorPrincipal[TAM];

/*
Objetivo: criar estrutura auxiliar na posição 'posicao'.
com tamanho 'tamanho'

Rertono (int)
    SUCESSO - criado com sucesso
    JA_TEM_ESTRUTURA_AUXILIAR - já tem estrutura na posição
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    SEM_ESPACO_DE_MEMORIA - Sem espaço de memória
    TAMANHO_INVALIDO - o tamanho deve ser maior ou igual a 1
*/
int criarEstruturaAuxiliar(int posicao, int tamanho) {
    //condicional para verificar se a posição existe na estrutura 
    if (posicao > TAM || posicao < 1) {
        return POSICAO_INVALIDA;
    }

    int estruturaIndice = posicao - 1;

    if (vetorPrincipal[estruturaIndice] != NULL) {
        return JA_TEM_ESTRUTURA_AUXILIAR;
    }

    if (tamanho < 1) {
        return TAMANHO_INVALIDO;
    }

    EstruturaAuxiliar *estruturaNova = (EstruturaAuxiliar *) malloc(sizeof(EstruturaAuxiliar));
    if (estruturaNova == NULL) {
        return SEM_ESPACO_DE_MEMORIA; 
    }
    
    estruturaNova->elementos = (int *) malloc(tamanho * sizeof(int));
    if (estruturaNova->elementos == NULL) {
        free(estruturaNova--);
        return SEM_ESPACO_DE_MEMORIA;
    }
    
    estruturaNova->tamanhoAlocado = tamanho; 
    estruturaNova->qtdeOcupadas = 0;

    vetorPrincipal[estruturaIndice] = estruturaNova;

    return SUCESSO; 
}

/*
Objetivo: inserir número 'valor' em estrutura auxiliar da posição 'posicao'
Rertono (int)
    SUCESSO - inserido com sucesso
    SEM_ESPACO - não tem espaço
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
CONSTANTES
*/
int inserirNumeroEmEstrutura(int posicao, int valor) {
    //condicional para verificar se a posição existe na estrutura 
    if (posicao > TAM || posicao < 1) {
        return POSICAO_INVALIDA;
    }
    
    int estruturaIndice = posicao - 1;
    EstruturaAuxiliar *auxiliar = vetorPrincipal[estruturaIndice];

    if (vetorPrincipal[estruturaIndice] == NULL) {
        return SEM_ESTRUTURA_AUXILIAR;
    }

    if (auxiliar->qtdeOcupadas < auxiliar->tamanhoAlocado) {
        auxiliar->elementos[auxiliar->qtdeOcupadas] = valor;
        auxiliar->qtdeOcupadas++;
        return SUCESSO;
    } else {
        return SEM_ESPACO;
    }
}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar no final da estrutura.
ex: suponha os valores [3, 8, 7, 9,  ,  ]. Após excluir, a estrutura deve ficar da seguinte forma [3, 8, 7,  ,  ,  ].
Obs. Esta é uma exclusão lógica

Rertono (int)
    SUCESSO - excluido com sucesso
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int excluirNumeroDoFinaldaEstrutura(int posicao) {
    //condicional para verificar se a posição existe na estrutura 
    if (posicao > TAM || posicao < 1) {
        return POSICAO_INVALIDA;
    }

    int estruturaIndice = posicao - 1; 
    EstruturaAuxiliar *auxiliar = vetorPrincipal[estruturaIndice];

    if (vetorPrincipal[estruturaIndice] == NULL) {
        return SEM_ESTRUTURA_AUXILIAR;
    }

    if (auxiliar->qtdeOcupadas == 0) {
        return ESTRUTURA_AUXILIAR_VAZIA;
    }

    auxiliar->qtdeOcupadas--;
        
    return SUCESSO;
}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar da posição 'posicao'.
Caso seja excluido, os números posteriores devem ser movidos para as posições anteriores
ex: suponha os valores [3, 8, 7, 9,  ,  ] onde deve ser excluido o valor 8. A estrutura deve ficar da seguinte forma [3, 7, 9,  ,  ,  ]
Obs. Esta é uma exclusão lógica
Rertono (int)
    SUCESSO - excluido com sucesso 'valor' da estrutura na posição 'posicao'
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    NUMERO_INEXISTENTE - Número não existe
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar

*/
int excluirNumeroEspecificoDeEstrutura(int posicao, int valor) {
    //condicional para verificar se a posição existe na estrutura 
    if (posicao > TAM || posicao < 1) {
        return POSICAO_INVALIDA;
    }
       
    int estruturaIndice = posicao - 1;
    EstruturaAuxiliar *auxiliar = vetorPrincipal[estruturaIndice];
    int achou = 0;
    int i, j;

    if (vetorPrincipal[estruturaIndice] == NULL) {
        return SEM_ESTRUTURA_AUXILIAR;
    }

    if (auxiliar->qtdeOcupadas == 0) {
        return ESTRUTURA_AUXILIAR_VAZIA;
    }

    for (i = 0; i < auxiliar->qtdeOcupadas; i++) {
        if (auxiliar->elementos[i] == valor) {
            achou = 1;
            break; 
        }
    }

    if (!achou) {
        return NUMERO_INEXISTENTE; 
    }

    for (j = i; j < auxiliar->qtdeOcupadas - 1; j++) {
        auxiliar->elementos[j] = auxiliar->elementos[j+1];
    }

    auxiliar->qtdeOcupadas--;

    return SUCESSO;
}

// se posição é um valor válido {entre 1 e 10}
int ehPosicaoValida(int posicao) {
    int retorno = 0;
    
    if (posicao > TAM || posicao < 1) {
        retorno = POSICAO_INVALIDA;
    } else
        retorno = SUCESSO;

    return retorno;
}
/*
Objetivo: retorna os números da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux

Retorno (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosEstruturaAuxiliar(int posicao, int vetorAux[]) {
    if (ehPosicaoValida(posicao) == POSICAO_INVALIDA) {
        return POSICAO_INVALIDA;
    }

    int estruturaIndice = posicao - 1;
    int i;

    if (vetorPrincipal[estruturaIndice] == NULL) {
        return SEM_ESTRUTURA_AUXILIAR;
    }

    EstruturaAuxiliar *auxiliar = vetorPrincipal[estruturaIndice];
    for (i = 0; i < auxiliar->qtdeOcupadas; i++) {
        vetorAux[i] = auxiliar->elementos[i];
    }

    return SUCESSO;
}

int compararDados(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
} 
/*
Objetivo: retorna os números ordenados da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao (1..10)'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosOrdenadosEstruturaAuxiliar(int posicao, int vetorAux[]) {

    if (ehPosicaoValida(posicao) == POSICAO_INVALIDA) {
        return POSICAO_INVALIDA;
    }
    
    int estruturaIndice = posicao - 1;
    
    if (vetorPrincipal[estruturaIndice] == NULL)
        return SEM_ESTRUTURA_AUXILIAR;

    EstruturaAuxiliar *auxiliar = vetorPrincipal[estruturaIndice];
    if (auxiliar->qtdeOcupadas == 0)
        return ESTRUTURA_AUXILIAR_VAZIA;

    memcpy(vetorAux, auxiliar->elementos, auxiliar->qtdeOcupadas * sizeof(int));
    qsort(vetorAux, auxiliar->qtdeOcupadas, sizeof(int), compararDados);

    return SUCESSO;
}

/*
Objetivo: retorna os números de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    TODAS_ESTRUTURAS_AUXILIARES_VAZIAS - todas as estruturas auxiliares estão vazias
*/
int getDadosDeTodasEstruturasAuxiliares(int vetorAux[]) {

    int i, j;
    int k = 0;
    int encontrouDados = 0;

    for (i = 0; i < TAM; i++) {
        EstruturaAuxiliar *auxiliar = vetorPrincipal[i];
        if (auxiliar != NULL && auxiliar->qtdeOcupadas > 0) {
            encontrouDados = 1;
            for (j = 0; j < auxiliar->qtdeOcupadas; j++) {
                vetorAux[k++] = auxiliar->elementos[j];
            }
        }
    }

    return encontrouDados ? SUCESSO : TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;
    
}

/*
Objetivo: retorna os números ordenados de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    TODAS_ESTRUTURAS_AUXILIARES_VAZIAS - todas as estruturas auxiliares estão vazias
*/
int getDadosOrdenadosDeTodasEstruturasAuxiliares(int vetorAux[]) {

    int resultadoOrdenacao = getDadosDeTodasEstruturasAuxiliares(vetorAux);
    int i;
    int total;

    if (resultadoOrdenacao == SUCESSO) {
        total = 0;
        for (i = 0; i < TAM; i++) {
            if (vetorPrincipal[i] != NULL) {
                total += vetorPrincipal[i]->qtdeOcupadas;
            }
        }
        qsort(vetorAux, total, sizeof(int), compararDados);
    }

    return resultadoOrdenacao;

}

/*
Objetivo: modificar o tamanho da estrutura auxiliar da posição 'posicao' para o novo tamanho 'novoTamanho' + tamanho atual
Suponha o tamanho inicial = x, e novo tamanho = n. O tamanho resultante deve ser x + n. Sendo que x + n deve ser sempre >= 1

Rertono (int)
    SUCESSO - foi modificado corretamente o tamanho da estrutura auxiliar
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    NOVO_TAMANHO_INVALIDO - novo tamanho não pode ser negativo
    SEM_ESPACO_DE_MEMORIA - erro na alocação do novo valor
*/
int modificarTamanhoEstruturaAuxiliar(int posicao, int novoTamanho) {
    //verifica de a posição indicada existe ou tá disponível
    if (ehPosicaoValida(posicao) == POSICAO_INVALIDA) {
        return POSICAO_INVALIDA;
    }
    
    int estruturaIndice = posicao - 1;
    EstruturaAuxiliar *auxiliar = vetorPrincipal[estruturaIndice];

    if (auxiliar == NULL) {
        
        return SEM_ESTRUTURA_AUXILIAR;
        
    }

    int tamanhoFinal = auxiliar->tamanhoAlocado + novoTamanho;

    if (tamanhoFinal < 1) {
        
        return NOVO_TAMANHO_INVALIDO;
        
    }

    int *novoArray = realloc(auxiliar->elementos, tamanhoFinal * sizeof(int));
    
    if (novoArray == NULL) {
        
        return SEM_ESPACO_DE_MEMORIA;
        
    }

    auxiliar->elementos = novoArray;
    auxiliar->tamanhoAlocado = tamanhoFinal;

    if (auxiliar->qtdeOcupadas > tamanhoFinal)
        auxiliar->qtdeOcupadas = tamanhoFinal;

    return SUCESSO;

}

/*
Objetivo: retorna a quantidade de elementos preenchidos da estrutura auxiliar da posição 'posicao'.

Retorno (int)
    POSICAO_INVALIDA - posição inválida
    SEM_ESTRUTURA_AUXILIAR - sem estrutura auxiliar
    ESTRUTURA_AUXILIAR_VAZIA - estrutura auxiliar vazia
    Um número int > 0 correpondente a quantidade de elementos preenchidos da estrutura
*/
int getQuantidadeElementosEstruturaAuxiliar(int posicao) {

    if (ehPosicaoValida(posicao) == POSICAO_INVALIDA) {
        return POSICAO_INVALIDA;
    }

    int estruturaIndice = posicao - 1;
    EstruturaAuxiliar *auxiliar = vetorPrincipal[estruturaIndice];

    if (auxiliar == NULL)
        return SEM_ESTRUTURA_AUXILIAR;

    if (auxiliar->qtdeOcupadas == 0)
        return ESTRUTURA_AUXILIAR_VAZIA;

    return auxiliar->qtdeOcupadas;

}

/*
Objetivo: montar a lista encadeada com cabeçote com todos os números presentes em todas as estruturas.

Retorno (No*)
    NULL, caso não tenha nenhum número nas listas
    No*, ponteiro para o início da lista com cabeçote
*/
No *montarListaEncadeadaComCabecote() {

    No *cabecote = (No *) malloc(sizeof(No));
    if (!cabecote)
        return NULL;

    cabecote->prox = NULL;
    
    No *atualNo = cabecote;
    
    int achouElementos = 0;
    
    int i, j;

    for (i = 0; i < TAM; i++) {
        EstruturaAuxiliar *estrutura = vetorPrincipal[i];
        if (estrutura && estrutura->qtdeOcupadas > 0) {
            for (j = 0; j < estrutura->qtdeOcupadas; j++) {
                No *novo = (No *) malloc(sizeof(No));
                if (!novo) {
                    destruirListaEncadeadaComCabecote(&cabecote);
                    return NULL;
                }
                novo->conteudo = estrutura->elementos[j];
                novo->prox = NULL;
                atualNo->prox = novo;
                atualNo = novo;
                achouElementos = 1;
            }
        }
    }

    if (!achouElementos) {
        free(cabecote);
        return NULL;
    }

    return cabecote;

}

/*
Objetivo: retorna os números da lista enceada com cabeçote armazenando em vetorAux.
Retorno void
*/
void getDadosListaEncadeadaComCabecote(No *inicio, int vetorAux[]){
    
    No *atualNo = inicio->prox; 
    
    int i = 0;
    
    while (atualNo != NULL) {
        vetorAux[i++] = atualNo->conteudo;
        atualNo = atualNo->prox;
    }
    
}

/*
Objetivo: Destruir a lista encadeada com cabeçote a partir de início.
O ponteiro inicio deve ficar com NULL.

Retorno 
    void.
*/
void destruirListaEncadeadaComCabecote(No **inicio) {

    No *atualNo = *inicio;
    
    while (atualNo != NULL) {
        No *prox = atualNo->prox;
        free(atualNo);
        atualNo = prox;
    }
    
    *inicio = NULL;

}

/*
Objetivo: inicializa o programa. deve ser chamado ao inicio do programa 

*/

void inicializar() {

    int i;
    
    for (i = 0; i < TAM; i++) {
        vetorPrincipal[i] = NULL;
    }

}

/*
Objetivo: finaliza o programa. deve ser chamado ao final do programa 
para poder liberar todos os espaços de memória das estruturas auxiliares.

*/

void finalizar() {

    int i;
    
    for (i = 0; i < TAM; i++) {
        if (vetorPrincipal[i] != NULL) {
            free(vetorPrincipal[i]->elementos); 
            free(vetorPrincipal[i]);           
            vetorPrincipal[i] = NULL;
        }
    }


}