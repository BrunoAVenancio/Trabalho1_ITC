#include "acceptStateHandler.h"

typedef struct cadeias{
    char cadeia[21];
}cadeias_t;

typedef struct transicoes{
    char q;
    char x;
    char qq;
}transicoes_t;

int main()
{       


   // 3 estados no total q0,q1,q2
   // q2 estado final;
    node *list_states[3];
    for(int i = 0; i< 3; i++)
    {
        list_states[i] = createLinkedList();
    }

    // teste do pdf do professor
    pushNode(list_states[0],1,'a');
    pushNode(list_states[0],1,'b');
    pushNode(list_states[1],1,'a');
    pushNode(list_states[1],2,'b');
    pushNode(list_states[2],0,'a');
    pushNode(list_states[2],2,'b');

    //Peguei um aleatorio da net
    // pushNode(list_states[0],0,'0');
    // pushNode(list_states[0],0,'1');
    // pushNode(list_states[0],1,'0');
    // pushNode(list_states[0],2,'1');
    // pushNode(list_states[1],3,'0');
    // pushNode(list_states[2],3,'1');
    // pushNode(list_states[3],3,'0');
    // pushNode(list_states[3],3,'1');

    printNode(list_states);
    int isAcceptable = hasPath(list_states,0,"1100",0,2,0);
    if(isAcceptable)
    {
        printf("Aceitou\n");
    } else
    {
        printf("Rejeitou\n");
    }

    for(int i = 0; i < 3; i++)
    {
        free_linkedList(list_states[i]);
    }

    // int varQ = 0, indexSigma = 0, quantSimbolos = 0, numEstIniciais = 0; 
    // int quantEstAceit = 0, indexEstAceit = 0, numTransicoes = 0, indexTrans = 0;
    // int numCadeias = 0, indexCadeias = 0;
    // char sigma[10], lixo, *estAceit, *auxCadeia;
    // cadeias_t *cadeias;
    // transicoes_t *transicoes;
    
    // estAceit = (char*)calloc(11,sizeof(char));
   
    //linha1
//     while(1){
//         fflush(stdin);
//         scanf("%d", &varQ);
//         if(varQ > 0 && varQ < 11)
//             break;
//         else
//             printf("Valor fora do intervalo 1<=n<=10. Informe outro valor.\n");
//     }
//     printf("1\n");
    
//     fflush(stdin);
  
//     //linha2
//     scanf("%d", &quantSimbolos);
//     for(indexSigma = 0; indexSigma < quantSimbolos; indexSigma++){
//         scanf("%c", &lixo);
//         scanf("%c", &sigma[indexSigma]);
//     }
    
//     //linha 3
//     while(1){
//         fflush(stdin);
//         scanf("%d", &numEstIniciais);
//         if(numEstIniciais > 0 && numEstIniciais < 11)
//             break;
//         else
//             printf("Quantidade de estados iniciais fora do intervalo 1<=n<=10. Informe outro valor.\n");
//     }
//         printf("3\n");
    
//     //linha 4
//     fflush(stdin);
//     scanf("%d", &quantEstAceit);
//     for(indexEstAceit = 0; indexEstAceit < quantEstAceit; indexEstAceit++){
//         scanf("%c", &lixo);
//         scanf("%c", &estAceit[indexEstAceit]);
//         // se ja alocar o estAceit com tamanho indices que correspondem o estado, tipo estAceit[1] corresponde ao q1,
//         // e com isso, se o estAceit[1] = 1, quer dizer eh estado de aceitacao, se for = 0 , logo eh falso
//     }
//         printf("4\n");
    
//     //linha 5
//     while(1){
//         fflush(stdin);
//         scanf("%d", &numTransicoes);
//         if(numTransicoes > 0 && numTransicoes < 51)
//             break;
//         else
//             printf("Numero de transicoes fora do intervalo 1<=n<=50. Informe outro valor.\n");

//     }
//         printf("5\n");

//     transicoes = (transicoes_t *)calloc(numTransicoes,sizeof(transicoes_t));
//     //linha 6
//     while(indexTrans  < numTransicoes){
//         fflush(stdin);
//         scanf("%c", &lixo);
//         scanf("%c", &transicoes[indexTrans].q);
//         scanf("%c", &lixo);
//         scanf("%c", &transicoes[indexTrans].x);
//         scanf("%c", &lixo);
//         scanf("%c", &transicoes[indexTrans].qq);
//         indexTrans++;
//     }
//         printf("6\n");
    
//     //linha 7
//     while(1){
//         fflush(stdin);
//         scanf("%d", &numCadeias);
//         scanf("%c", &lixo);
//         if(numCadeias > 0 && numCadeias < 11)
//             break;
//         else
//             printf("Numero de cadeias fora do intervalo 1<=n<=10. Informe outro numero.\n");
//     }
//     printf("7\n");
 
//     cadeias = (cadeias_t *)calloc(numCadeias,sizeof(cadeias_t));
//     auxCadeia = (char *)calloc(21,sizeof(char));
    
    
    
//     //linha 8
//     while(indexCadeias  < numCadeias){
//         fflush(stdin);
//         fgets(auxCadeia, 20, stdin);
//         printf("indexCadeias = %d, cadeialida = %s", indexCadeias, auxCadeia);
//         strcpy(cadeias[indexCadeias].cadeia, auxCadeia);
//         indexCadeias++;
//     }
    
//     //prints para testar se entradas funcionaram
//    printf("varQ: %d  quantSimbolos: %d\n" , varQ, quantSimbolos);
//     for(int i=0; i<quantSimbolos; i++){
//         printf("Sigma[%d]: %c\n" , i, sigma[i]);
//     }
//     printf("numEstIniciais: %d quantEstAceit: %d\n", numEstIniciais, quantEstAceit);
//     for(int i=0; i<indexEstAceit-1; i++){
//         printf("EstAceit[%d]: %c\n" , i, estAceit[i]);
//     }
//     printf("numTransicoes: %d\n", numTransicoes);
//     for(int i=0; i<indexTrans; i++){
//         printf("transicoes[%d]: %c %c %c\n" , i, transicoes[i].q, transicoes[i].x, transicoes[i].qq);
//     }
//     printf("numCadeias: %d\n", numCadeias);
//     for(int i=0; i<indexCadeias; i++){
//         printf("Cadeia[%d]: %s\n" , i, cadeias[i].cadeia);
//     }
    
    // free(cadeias);
    // free(estAceit);
}
