/*JOGO DA VELHA*/
//Declaração das bibliotecas
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
main(){
  //Declaração dos tipos de dados que serão utilizados
  int matriz[3][3];
  int i,j,jogada,linha=0,coluna=0,termino,velha=1;
  char jog1[15],jog2[15];
  //Cabeçalho
  printf("\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0  JOGO DA VELHA"
               "  \xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\n\n\n\n");
  //Informações adicionais
  printf("DESENVOLVIDO POR: Alberto Luiz Pontes Siqueira RA:188681 e \n");
  printf("                  Alice David dos Santos RA:188650\n\n");
  printf("CURSO: Tecnologia em Desenvolvimento de Sistemas para Internet\n\n");
  printf("DISCIPLINA: Algoritmo e Logica de Programacao II\n\n");
  printf("PROFESSOR: Alexandre Ponce de Oliveira\n\n");
  printf("UNISALESIANO\n\n\n");
  system("pause");
  system("cls");
  //Solicita os nomes dos jogadores 
  printf("Digite o nome do JOGADOR 1:");
  scanf("%s",&jog1);
  printf("Digite o nome do JOGADOR 2:");
  scanf("%s",&jog2);
  //Define o simbolo que o jogador vai utilizar
  printf("\n%s => 1 e %s => 2",jog1,jog2);
  //Preenche a matriz
  for(i=0;i<3;i++){
    for(j=0;j<3;j++){
      matriz[i][j]=0;
      printf("\n");
    }
  }
  //Imprime a matriz já preenchida
  for(i=0;i<3;i++){
    for(j=0;j<3;j++){
      printf("%d",matriz[i][j]);
    }
    printf("\n");
  }
  printf("\n\n");
  //Laço para controlar o número de jogadas
  for(jogada=1;jogada<10;jogada++){
    termino=0;
    //Teste controlar a vez do jogador
    if(jogada%2==1){
    //Inicia laço para repetir a jogadda caso a coordenada for invalida
      while(termino==0){
        printf("%s, sua vez",jog1);
        printf("\nDigite a linha:");
        scanf("%d",&linha);
        printf("Digite a coluna:");
        scanf("%d",&coluna);
        printf("\n\n");
        //Teste para verificar se a posição está ocupada
        if(matriz[linha-1][coluna-1]==0){
          matriz[linha-1][coluna-1]=1;
          termino=1;
        }
        else{
          printf("Posicao ocupada. Jogue novamente.\n\n");
           system("pause"); 
        } 
        //Limpa a tela 
        system("cls");
        //Imprime a matriz após a jogada 
        for(i=0;i<3;i++){
          for(j=0;j<3;j++){
            printf("%d",matriz[i][j]);
          }
          printf("\n");
        }
        //Teste para verificar se o jogador ganhou
        if((matriz[0][0]==1&&matriz[0][1]==1&&matriz[0][2]==1)||
        (matriz[1][0]==1&&matriz[1][1]==1&&matriz[1][2]==1)||
        (matriz[2][0]==1&&matriz[2][1]==1&&matriz[2][2]==1)||
        (matriz[0][0]==1&&matriz[1][0]==1&&matriz[2][0]==1)||
        (matriz[0][1]==1&&matriz[1][1]==1&&matriz[1][2]==1)||
        (matriz[0][2]==1&&matriz[1][2]==1&&matriz[2][2]==1)||
        (matriz[0][0]==1&&matriz[1][1]==1&&matriz[2][2]==1)||
        (matriz[0][2]==1&&matriz[1][1]==1&&matriz[2][0]==1)){
          printf("%s, voce venceu!!!\n",jog1);
          jogada=10;
          velha=0;
        }//Fecha o teste lógico para as posições
      }//Fecha o teste para controlar a vez do jogador
    }//Fecha while que controla a repetição caso coordenada digitada for inválida
    //Inicia a vez do jogador 2   
    else{
      termino=0;
      //Inicia laço para repetir a jogada caso a coordenada for invalida
      while(termino==0){
        printf("%s, sua vez.",jog2);
        printf("\nDigite a linha:");
        scanf("%d",&linha);
        printf("Digite a coluna:");
        scanf("%d",&coluna);
        printf("\n\n");
        //Teste para verificar se a posição está ocupada
        if(matriz[linha-1][coluna-1]==0){
          matriz[linha-1][coluna-1]=2;
          termino=1;
        }
        else{
          printf("Posicao ocupada, jogue novamente.\n\n");
          system("pause");
        }//Fecha os testes para verificar se a posicao está ocupada
        //Limpa a tela
        system("cls");
        //Imprime a matriz após a jogada
        for(i=0;i<3;i++){
          for(j=0;j<3;j++){
            printf("%d",matriz[i][j]);
          }
          printf("\n");
        }
        //Teste lógico para verificar se o jogador ganhou
        if((matriz[0][0]==2&&matriz[0][1]==2&&matriz[0][2]==2)||
        (matriz[1][0]==2&&matriz[1][1]==2&&matriz[1][2]==2)||
        (matriz[2][0]==2&&matriz[2][1]==2&&matriz[2][2]==2)||
        (matriz[0][0]==2&&matriz[1][0]==2&&matriz[2][0]==2)||
        (matriz[0][1]==2&&matriz[1][1]==2&&matriz[1][2]==2)||
        (matriz[0][2]==2&&matriz[1][2]==2&&matriz[2][2]==2)||
        (matriz[0][0]==2&&matriz[1][1]==2&&matriz[2][2]==2)||
        (matriz[0][2]==2&&matriz[1][1]==2&&matriz[2][0]==2)){
          printf("%s, voce ganhou\n",jog2);
          jogada=10;
          velha=0;
        }//Fecha o teste para verificar se o jogador ganhou 
      }///Fecha while que controla a repetição caso coordenada digitada for inválida
    }//Fecha teste do jogador 2   
  }//Fecha o laço que controla o numero de jogadas
  if(velha==1){
    printf("Nenhum vencedor, VELHA!!!");
  }
  system("pause"); 
}