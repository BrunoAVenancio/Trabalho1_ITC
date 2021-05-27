#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct cadeias{
    char cadeia[21];
}cadeias_t;

typedef struct transicoes{
    char q;
    char x;
    char qq;
}transicoes_t;

int main(){
    int varQ = 0, indexSigma = 0, quantSimbolos = 0, numEstIniciais = 0; 
    int quantEstAceit = 0, indexEstAceit = 0, numTransicoes = 0, indexTrans = 0;
    int numCadeias = 0, indexCadeias = 0;
    char sigma[10], lixo, *estAceit, *auxCadeia;
    cadeias_t *cadeias;
    transicoes_t *transicoes;
    
    estAceit = (char*)calloc(11,sizeof(char));
   
    //linha1
    while(1){
        fflush(stdin);
        scanf("%d", &varQ);
        if(varQ > 0 && varQ < 11)
            break;
        else
            printf("Valor fora do intervalo 1<=n<=10. Informe outro valor.\n");
    }
    printf("1\n");
    
    fflush(stdin);
  
    //linha2
    scanf("%d", &quantSimbolos);
    for(indexSigma = 0; indexSigma < quantSimbolos; indexSigma++){
        scanf("%c", &lixo);
        scanf("%c", &sigma[indexSigma]);
    }
    printf("2\n");
    
    //linha 3
    while(1){
        fflush(stdin);
        scanf("%d", &numEstIniciais);
        if(numEstIniciais > 0 && numEstIniciais < 11)
            break;
        else
            printf("Quantidade de estados iniciais fora do intervalo 1<=n<=10. Informe outro valor.\n");
    }
        printf("3\n");
    
    //linha 4
    fflush(stdin);
    scanf("%d", &quantEstAceit);
    for(indexEstAceit = 0; indexEstAceit < quantEstAceit; indexEstAceit++){
        fflush(stdin);
        scanf("%c", &lixo);
        scanf("%c", &estAceit[indexEstAceit]);
        indexEstAceit++;
    }
        printf("4\n");
    
    //linha 5
    while(1){
        fflush(stdin);
        scanf("%d", &numTransicoes);
        if(numTransicoes > 0 && numTransicoes < 51)
            break;
        else
            printf("Numero de transicoes fora do intervalo 1<=n<=50. Informe outro valor.\n");

    }
        printf("5\n");

    transicoes = (transicoes_t *)calloc(numTransicoes,sizeof(transicoes_t));
    //linha 6
    while(indexTrans  < numTransicoes){
        fflush(stdin);
        scanf("%c", &lixo);
        scanf("%c", &transicoes[indexTrans].q);
        scanf("%c", &lixo);
        scanf("%c", &transicoes[indexTrans].x);
        scanf("%c", &lixo);
        scanf("%c", &transicoes[indexTrans].qq);
        indexTrans++;
    }
        printf("6\n");
    
    //linha 7
    while(1){
        fflush(stdin);
        scanf("%d", &numCadeias);
        scanf("%c", &lixo);
        if(numCadeias > 0 && numCadeias < 11)
            break;
        else
            printf("Numero de cadeias fora do intervalo 1<=n<=10. Informe outro numero.\n");
    }
    printf("7\n");
 
    cadeias = (cadeias_t *)calloc(numCadeias,sizeof(cadeias_t));
    auxCadeia = (char *)calloc(21,sizeof(char));
    
    
    
    //linha 8
    while(indexCadeias  < numCadeias){
        fflush(stdin);
        fgets(auxCadeia, 20, stdin);
        printf("indexCadeias = %d, cadeialida = %s", indexCadeias, auxCadeia);
        strcpy(cadeias[indexCadeias].cadeia, auxCadeia);
        indexCadeias++;
    }
    
    printf("varQ: %d  quantSimbolos: %d\n" , varQ, quantSimbolos);
    for(int i=0; i<quantSimbolos; i++){
        printf("Sigma[%d]: %c\n" , i, sigma[i]);
    }
    printf("numEstIniciais: %d quantEstAceit: %d\n", numEstIniciais, quantEstAceit);
    for(int i=0; i<indexEstAceit-1; i++){
        printf("EstAceit[%d]: %c\n" , i, estAceit[i]);
    }
    printf("numTransicoes: %d\n", numTransicoes);
    for(int i=0; i<indexTrans; i++){
        printf("transicoes[%d]: %c %c %c\n" , i, transicoes[i].q, transicoes[i].x, transicoes[i].qq);
    }
    printf("numCadeias: %d\n", numCadeias);
    for(int i=0; i<indexCadeias; i++){
        printf("Cadeia[%d]: %s\n" , i, cadeias[i].cadeia);
    }
    
    free(cadeias);
    free(estAceit);
}
