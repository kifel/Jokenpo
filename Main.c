#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>


int main(int argc, char *argv[]){

    int jogador, computador, count,jw, pw, emt, espadaj, espadap;
    char res;

    do
    {   
        count = 1;
        jw = 0;
        pw = 0;
        emt = 0;
        espadaj = 0;
        espadap = 0;
        
        do
        {
        printf("\n____________JoKenPo____________\n\n");
        printf("1. PEDRA\n");
        printf("2. PAPEL\n");
        printf("3. TESOURA\n");
        printf("4. ESPADA\n");
        printf("Digite a opcao desejada: ");
        scanf("%d",&jogador);
        printf("\n_______________________________\n\n");

        if(jogador == 1){
            printf("Jogador escolheu PEDRA\n");
        }else if(jogador == 2){
            printf("Jogador escolheu PAPEL\n");
        }else if(jogador == 3){
            printf("Jogador escolheu TESOURA\n");
        }else if(jogador == 4){
            if(espadaj < 1){
                printf("Jogador escolheu ESPADA\n");
            }
            espadaj++;
            if(espadaj > 1){
                system("cls");
                printf("opcao invalida\n");
                printf("So pode ser usado uma vez por jogo\n");
                jogador = 0;
            }
        }else{
            printf("opcao invalida\n");
            jogador = 0;
        }

        while(jogador == 0)
        {
            printf("_______________________________\n");
            printf("Digite a opcao desejada: ");
            scanf("%d",&jogador);
            if(jogador == 1){
                printf("Jogador escolheu PEDRA\n");
            }else if(jogador == 2){
                printf("Jogador escolheu PAPEL\n");
            }else if(jogador == 3){
                printf("Jogador escolheu TESOURA\n");
            }else if(jogador == 4){
                if(espadaj < 1){
                    printf("Jogador escolheu ESPADA\n");
                }
                espadaj++;
                if(espadaj > 1){
                    system("cls");
                    printf("opcao invalida\n");
                    printf("So pode ser usado uma vez por jogo\n");
                    jogador = 0;
            }
            }else{
                printf("opcao invalida\n");
                jogador = 0;
            }
        }
        // lógica do computador
        srand(time(NULL));
        computador=("%d",rand()%4 + 1);
        
        if(computador == 1){
            printf("Computador escolheu PEDRA\n");
        }else if(computador == 2){
            printf("Computador escolheu PAPEL\n");
        }else if(computador == 3){
            printf("Computadorescolheu TESOURA\n");
        }else if(computador == 4){
            if(espadap < 1){
                printf("Computador escolheu ESPADA\n");
            }
            espadap++;
            if(espadap > 1){
                computador = 0;
            }
        }else{
            printf("opcao invalida\n");
        }

        while (computador == 0)
        {
            srand(time(NULL));
            computador=("%d",rand()%4 + 1);
        
            if(computador == 1){
                printf("Computador escolheu PEDRA\n");
            }else if(computador == 2){
                printf("Computador escolheu PAPEL\n");
            }else if(computador == 3){
                printf("Computadorescolheu TESOURA\n");
            }else if(computador == 4){
                if(espadap < 1){
                    printf("Computador escolheu ESPADA\n");
                }
                espadap++;
                if(espadap > 1){
                    computador = 0;
            }
            }else{
                printf("opcao invalida\n");
            }
        }
        //lógica para determinar o vencedor
        printf("_______________________________\n");
        if(jogador==computador)
        {
            printf("EMPATE\n");
            emt++;
        }
        else if ((jogador==1 && computador==3) || (jogador==2 && computador==1) ||
        (jogador==3 && computador==2) || (jogador==4 && computador==3) || (jogador==4 && computador==2) || (jogador==4 && computador==1))
        {
            printf("JOGADOR VENCEU\n");
            jw++;
        }
        else
        {
            printf("COMPUTADOR VENCEU\n");
            pw++;
        }

        count++;
        } while (count <= 5);
        system("cls");
        printf("Jogador %d x %d Computador\n",jw,pw);
        printf("Teve %d empates\n",emt);
        
        printf("Deseja jogar novamente ? [S/N] ");
        scanf("%s",&res);
        res = toupper(res);  
    } while (res=='S');
   
    return 0;
}