#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define dimensaoLado 3

char matriz[3][3]; // Matriz do jogo 
char matrixAux[3][3]; // Matriz auxiliar 

void iniciaMatriz(); // Protótipo da função para inicializar a matriz
void printMatriz(); // Protótipo da função para imprimir a matriz
int jogadaUser(int a, int b); // Protótipo da função para a jogada do jogador
void clrscr(void); // Protótipo da função para limpar a tela
void pegaValores(void); // Protótipo da função para obter os valores do jogador
int verificaVitoria(void); // Protótipo da função para verificar se houve vitória
int jogadaCPU(); // Protótipo da função para a jogada do computador
void gerarSeedParaNumAleatorio(); // Protótipo da função para gerar um número aleatório

int main(void)
{
  int jogadas;
  gerarSeedParaNumAleatorio(); // Gera uma semente aleatória

  iniciaMatriz(); // Inicializa a matriz do jogo
  jogadas = 0; // Inicializa o número de jogadas
  do {
      printMatriz(); // Imprime a matriz na tela
      pegaValores(); // Obtém as coordenadas do jogador
      jogadas++; // Incrementa o número de jogadas
      if((verificaVitoria()==0)&&(jogadas<9)) { // Verifica se o jogo não terminou e ainda há jogadas disponíveis
      jogadaCPU(); // O computador faz uma jogada
      jogadas++; // Incrementa o número de jogadas
      }
    }
    while((verificaVitoria()==0)&&(jogadas<9)); // Continua enquanto não há vencedor e ainda há jogadas disponíveis
  printMatriz(); // Imprime a matriz final
  return(0); // Retorna 0 indicando sucesso
}

void gerarSeedParaNumAleatorio() // Função para gerar um número aleatório
{
  int stime;
  int ltime;

  ltime=time(NULL); // Obtém o tempo atual em segundos
  stime=(unsigned) ltime/2; // Divide o tempo por 2
  srand(stime); // Inicializa o gerador de números aleatórios com a semente obtida
}
int jogadaCPU() // Função para a jogada do computador
{
  int x,y,mx,my;
  int k,j,i;
  int erro=0;

  x=(rand()%3); // Gera um número aleatório entre 0 e 2
  y=(rand()%3); // Gera um número aleatório entre 0 e 2

  if(matriz[x][y]!=' ') // Verifica se a posição escolhida está ocupada
    {
      jogadaCPU(); // Chama recursivamente a função se a posição estiver ocupada
      return(1); // Retorna 1 indicando que houve erro
    }
  else
    {
      for(i=0;i<3;i++)
   for(j=0;j<3;j++)
     matrixAux[i][j]=matriz[i][j]; // Copia a matriz para uma matriz auxiliar

      for(i=0;i<3;i++)
   for(j=0;j<3;j++)
     {
       if (matriz[i][j]==' ')
         {
      matriz[i][j]='O'; // Faz uma jogada de teste para o computador
      if((verificaVitoria()!=0)) // Verifica se o computador venceu
        {
          mx=i;
          my=j;
          erro=2;
         }
      else
        {
          matriz[i][j]='X'; // Faz uma jogada de teste para o jogador
          if((verificaVitoria()!=0)&&(erro!=2)) // Verifica se o jogador pode vencer na próxima jogada
            {
         mx=i;
         my=j;
         erro=1;
            }
        }
         matriz[i][j]=' '; // Limpa a posição para o próximo teste
              }
     }

      for(i=0;i<3;i++)
   for(j=0;j<3;j++)
     matriz[i][j]=matrixAux[i][j]; // Restaura a matriz original

      if (erro==0)
    matriz[x][y]='O'; // Faz a jogada do computador
    
      if (erro!=0)
   matriz[mx][my]='O'; // Faz uma jogada defensiva se necessário
   
    }
}

int verificaVitoria() // Função para verificar se houve vitória
{
  int erro=0;

  int i;
  if ((matriz[0][0]==matriz[1][1])&&(matriz[1][1]==matriz[2][2])&&(matriz[0][0]!=' ')) // Verifica a diagonal principal
   {
     erro=1;
   }
  
  for(i=0;i<dimensaoLado;i++)
    {
      if ((matriz[i][0]==matriz[i][1])&&(matriz[i][1]==matriz[i][2])&&(matriz[i][0]!=' ')) // Verifica linhas
   {
     erro=1;
   }
      if ((matriz[0][i]==matriz[1][i])&&(matriz[1][i]==matriz[2][i])&&(matriz[0][i]!=' ')) // Verifica colunas
   {
     erro=1;
   }
    }
  if ((matriz[2][0]==matriz[1][1])&&(matriz[1][1]==matriz[0][2])&&(matriz[2][0]!=' ')) // Verifica a diagonal secundária
   {
     erro=1;
   }

  return(erro); // Retorna se houve vitória ou não
}

void pegaValores(void) // Função para obter os valores do jogador
{
  int x,y;
  printf("\n\nDigite as coordenadas do tipo: Linha, Coluna: \n");
  scanf("%d%d",&x,&y);
  jogadaUser(x,y);
}

void clrscr(void) // Função para limpar a tela
{
  system("clear");
}

int jogadaUser(int a, int b) // Função para a jogada do jogador
{
  clrscr();
  if((a>dimensaoLado)||(b>dimensaoLado)||(a<1)||(b<1)) // Verifica se as coordenadas estão dentro do limite da matriz
    {
      printf("Valores Inválidos %d,%d\n\n",a,b);
      printMatriz();
      pegaValores();
    }
  else if(matriz[a-1][b-1]!=' ') // Verifica se a posição escolhida já está ocupada
    {
      printf("Casa já foi preenchida %d,%d \n\n",a,b);
      printMatriz();
      pegaValores();
    }
  else
    matriz[a-1][b-1]='X'; // Preenche a posição com 'X'
}

void printMatriz() // Função para imprimir a matriz
{
  int i;
  printf("\n\n");
  for(i=0;i<dimensaoLado;i++)
    {
      printf(" %c | %c | %c\n",matriz[i][0],matriz[i][1],matriz[i][2]); // Imprime cada linha da matriz
      if(i<dimensaoLado-1)
   printf("------------\n");
    }
}

void iniciaMatriz() // Função para inicializar a matriz
{
  int k,j;
  for (k=0;k < dimensaoLado;k++)
    for(j=0;j < dimensaoLado;j++)
      matriz[k][j]=' '; // Preenche a matriz com espaços em branco
}


