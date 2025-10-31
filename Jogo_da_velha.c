#include <stdio.h>
#include <stdlib.h>

char mat[3][3] = {' '}, venceu = 'n';
int i , j, cont = 0, verificaX = 0, verificaO = 0;

void verifica_X_ou_O(){
    if(mat[i][j] == 'X'){
        verificaX++;
    }
    else if(mat[i][j] == 'O'){
        verificaO++;
    }
}
void testando_linhas(){
    for(i = 0; i<3; i++){
        verificaX = 0;
        verificaO = 0;
        for(j = 0; j < 3; j++){
            verifica_X_ou_O();
        }
        if(verificaX == 3 || verificaO == 3){
            venceu = 's';
            break;
        }
    }
}
void testando_colunas(){
   for(j = 0; j<3; j++){
        verificaX = 0;
        verificaO = 0;
        for(i = 0; i < 3; i++){
            verifica_X_ou_O();
        }
        if(verificaX == 3 || verificaO == 3){
            venceu = 's';
            break;
        }
    }
}
void testando_diagonal(){
    verificaX = 0;
    verificaO = 0;
    j = 0;
    for(i = 0; i<3; i++){
        if(j == i){
            verifica_X_ou_O();
        }
        j++;
    }
    if(verificaX == 3 || verificaO == 3){
        venceu = 's';
    }
}
void testando_diagonalS(){
    verificaX = 0;
    verificaO = 0;
    j = 2;
    for (i = 0; i < 3; i++){
        verifica_X_ou_O();
        j--;
    }
    if(verificaX == 3 || verificaO == 3){
        venceu = 's';
    }
}
void imprimir_jogo(){
    printf("\n\n");
    for(i = 0; i < 3; i++){
        printf("\t\t");
        for (j = 0; j < 3; j++){
            if(mat[i][j] == 'X' || mat[i][j] == 'O'){
                if(j<2)
                    printf(" %c |", mat[i][j]);
                else
                    printf(" %c ", mat[i][j]);
            }
            else
                if(j<2)
                    printf("   |" );
                else
                    printf("  " );

        }
        if(i<2)
            printf("\n\t\t-----------\n");
        }
    printf("\n\n");
}
void preencher_matriz_com_espaco(){
    for(i = 0; i < 3; i++){
        for (j = 0; j < 3; j++){
            mat[i][j] = ' ';
        }
    }
}
int main(){
    int opc;
    do{
        int x,y, jogador = 1;

        printf("\n\t\tJOGO DA VELHA\n");
        printf("\n\t\t0 0| 0 1 | 0 2\n\t\t--------------\n\t\t1 0| 1 1 | 1 2\n\t\t--------------\n\t\t2 0| 2 1 | 2 2\n\n");
        printf("Para jogar eh bem simples, voce precisa digitar a casa corresponde a posicao que voce deseja\nExemplo: desejo jogar no meio, entao eu digito 1 1, segue as localizacoes acima!!!\n");
        do{
            printf("\nJOGADOR %d SUA VEZ!\n", jogador);
            printf("\nInforme a posicao que voce deseja jogar: ");
            scanf("%d%d", &x,&y);
            //verifica se a casa esta preenchida ou se o usuario digitou no intervalo correto
            while(mat[x][y] == 'X' || mat[x][y] == 'O' || x > 2 || x < 0 || y > 2 || y < 0 ){
                printf("\nJOGADOR %d SUA VEZ!\nPOSICAO QUE VOCE COLOCOU JA ESTA PREENCHIDA OU ESSE INTERVALO NAO EXISTE!!!\nESCOLHA OUTRA CASA PARA CONTINUAR O JOGO\n", jogador);
                printf("\nInforme a posicao que voce deseja jogar: ");
                scanf("%d%d", &x,&y);
            }
            if(cont % 2 == 0){
                jogador = 2;
                mat[x][y] = 'X';
            }
            else{
                jogador = 1;
                mat[x][y] = 'O';
            }
            cont+= 1;
            if (cont >= 5){
                testando_linhas();
                if (venceu == 'n'){
                    testando_colunas();
                }
                if (venceu == 'n'){
                    testando_diagonal();
                }
                if (venceu == 'n'){
                    testando_diagonalS();
                }
            }
            imprimir_jogo();

            //Em caso de empate
            if (cont == 9 && venceu == 'n'){
                venceu = 's';
                printf("O JOGO EMPATOU!!!\n");
            }
        }while(venceu == 'n');

        if(verificaX == 3)
            printf("APOS %d JOGADAS, O JOGADOR 1 VENCEU\n", cont);

        else if(verificaO == 3)
             printf("APOS %d JOGADAS, O JOGADOR 2 VENCEU\n", cont);

        printf("\tDESEJA JOGAR NOVAMENTE?\n1 - CONTINUAR\n2 - FINALIZAR\nDigite sua opcao: ");
        scanf("%d", &opc);
        if (opc == 1){
                venceu = 'n';
                cont = 0;
                preencher_matriz_com_espaco();
        }
    }while(opc != 2);
    return 0;
  }
