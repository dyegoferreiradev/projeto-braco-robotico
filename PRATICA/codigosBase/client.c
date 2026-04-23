  #include <stdio.h>
  #include <stdlib.h>
  #include <string.h>
  #include <sys/socket.h>
  #include <arpa/inet.h>
  #include <unistd.h>
  #include <time.h>

  #define SERVER_ADDRESS "127.0.0.1"
  #define SERVER_PORT 8888

  #define dimensaoLado 3
  #define OPEN 1
  #define CLOSE 0

  char matriz[3][3]; // Matriz do jogo 
  char matrixAux[3][3]; // Matriz auxiliar

  float posicaoBaseInicial[6] = { -1.02, 0.00, -0.34, 0.00, -0.95, -0.23 };
  float posicaoPeca[6] = { -1.62, -0.51, -0.74, -0.11, 0.09, -0.05 };
  float posicaoUp[6] = { -1.59, -0.09, -0.47, -0.04, -0.94, -0.15 };
  float posicaoUp2[6] = { -1.62, -0.33, -0.75, 0.00, 0.15, -0.20 };
  float Pos00[6] = { -0.25, -0.66, -0.50, 0.00, -0.35, -0.45 };
  float Pos01[6] = { -0.06, -0.66, -0.52, 0.00, -0.33, -0.22 };
  float Pos02[6] = { 0.16, -0.69, -0.47, 0.00, -0.37, 0.01 };
  float Pos10[6] = { -0.23, -0.86, -0.12, 0.00, -0.56, -0.40 };
  float Pos11[6] = { -0.06, -0.82, -0.17, 0.00, -0.50, -0.18 };
  float Pos12[6] = { 0.12, -0.85, -0.11, 0.00, -0.56, 0.01 };
  float Pos20[6] = { -0.21, -1.03, 0.25, 0.00, -0.71, -0.34 };
  float Pos21[6] = { -0.07, -1.02, 0.24, 0.00, -0.76, -0.18 };
  float Pos22[6] = { 0.09, -1.05, 0.30, 0.00, -0.80, -0.04 };

  void delay(int delayTime) {
      usleep(delayTime * 1000);
  }

  void initSocket(int* sock, char* buffer){

      struct sockaddr_in serv_addr;

      // Create a socket
      if ((*sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
          printf("\n Socket creation error \n");
          exit(1);
      }

      // Set the server address and port
      memset(&serv_addr, '0', sizeof(serv_addr));
      serv_addr.sin_family = AF_INET;
      serv_addr.sin_port = htons(SERVER_PORT);

      // Convert IPv4 and IPv6 addresses from text to binary form
      if (inet_pton(AF_INET, SERVER_ADDRESS, &serv_addr.sin_addr) <= 0) {
          printf("\n Invalid address/ Address not supported \n");
          exit(1);
      }

      // Connect to the server
      if (connect(*sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
          printf("\n Connection Failed \n");
          exit(1);
      }
  }

  void movJoints(int sock, char* buffer, float j1, float j2, float j3, float j4, float j5,float j6, int state){
      sprintf(buffer, "%f,%f,%f,%f,%f,%f,%d", j1, j2, j3, j4, j5, j6,state);
      send(sock, buffer, strlen(buffer), 0);
      int valread = read(sock, buffer, 2048);
      printf("Result: %s\n", buffer);
  }

  void pegarPeca(int sock, char buffer[2048], float posicaoPeca[6], float posicaoUp[6]) {
      movJoints(sock, buffer, posicaoUp[0], posicaoUp[1], posicaoUp[2], posicaoUp[3], posicaoUp[4], posicaoUp[5], OPEN);
      delay(2000);
      movJoints(sock, buffer, posicaoUp2[0], posicaoUp2[1], posicaoUp2[2], posicaoUp2[3], posicaoUp2[4], posicaoUp2[5], OPEN);
      delay(2000);
      movJoints(sock, buffer, posicaoPeca[0], posicaoPeca[1], posicaoPeca[2], posicaoPeca[3], posicaoPeca[4], posicaoPeca[5], CLOSE);
      delay(2000);
      movJoints(sock, buffer, posicaoUp[0], posicaoUp[1], posicaoUp[2], posicaoUp[3], posicaoUp[4], posicaoUp[5], CLOSE);
  }

  void moverParaPos00(float posicaoPeca[6], int sock, char buffer[2048]) {
      movJoints(sock, buffer, posicaoPeca[0], posicaoPeca[1], posicaoPeca[2], posicaoPeca[3], posicaoPeca[4], posicaoPeca[5], OPEN);
  }

  void moverParaPos01(float posicaoPeca[6], int sock, char buffer[2048]) {
      movJoints(sock, buffer, posicaoPeca[0], posicaoPeca[1], posicaoPeca[2], posicaoPeca[3], posicaoPeca[4], posicaoPeca[5], OPEN);
  }

  void moverParaPos02(float posicaoPeca[6], int sock, char buffer[2048]) {
      movJoints(sock, buffer, posicaoPeca[0], posicaoPeca[1], posicaoPeca[2], posicaoPeca[3], posicaoPeca[4], posicaoPeca[5], OPEN);
  }

  void moverParaPos10(float posicaoPeca[6], int sock, char buffer[2048]) {
      movJoints(sock, buffer, posicaoPeca[0], posicaoPeca[1], posicaoPeca[2], posicaoPeca[3], posicaoPeca[4], posicaoPeca[5], OPEN);
  }

  void moverParaPos11(float posicaoPeca[6], int sock, char buffer[2048]) {
      movJoints(sock, buffer, posicaoPeca[0], posicaoPeca[1], posicaoPeca[2], posicaoPeca[3], posicaoPeca[4], posicaoPeca[5], OPEN);
  }

  void moverParaPos12(float posicaoPeca[6], int sock, char buffer[2048]) {
      movJoints(sock, buffer, posicaoPeca[0], posicaoPeca[1], posicaoPeca[2], posicaoPeca[3], posicaoPeca[4], posicaoPeca[5], OPEN);
  }

  void moverParaPos20(float posicaoPeca[6], int sock, char buffer[2048]) {
      movJoints(sock, buffer, posicaoPeca[0], posicaoPeca[1], posicaoPeca[2], posicaoPeca[3], posicaoPeca[4], posicaoPeca[5], OPEN);
  }

  void moverParaPos21(float posicaoPeca[6], int sock, char buffer[2048]) {
      movJoints(sock, buffer, posicaoPeca[0], posicaoPeca[1], posicaoPeca[2], posicaoPeca[3], posicaoPeca[4], posicaoPeca[5], OPEN);
  }

  void moverParaPos22(float posicaoPeca[6], int sock, char buffer[2048]) {
      movJoints(sock, buffer, posicaoPeca[0], posicaoPeca[1], posicaoPeca[2], posicaoPeca[3], posicaoPeca[4], posicaoPeca[5], OPEN);
  }

  void IrParaPosicaoInicial(float posicaoPeca[6], int sock, char buffer[2048]) {
      movJoints(sock, buffer, posicaoPeca[0], posicaoPeca[1], posicaoPeca[2], posicaoPeca[3], posicaoPeca[4], posicaoPeca[5], CLOSE);
  }



  void gerarSeedParaNumAleatorio() // Função para gerar um número aleatório
  {
    int stime;
    int ltime;

    ltime=time(NULL); // Obtém o tempo atual em segundos
    stime=(unsigned) ltime/2; // Divide o tempo por 2
    srand(stime); // Inicializa o gerador de números aleatórios com a semente obtida
  }
  int jogadaCPU(int sock, char buffer[2048])  // Função para a jogada do computador
  {
    int x,y,mx,my;
    int k,j,i;
    int erro=0;

    x=(rand()%3); // Gera um número aleatório entre 0 e 2
    y=(rand()%3); // Gera um número aleatório entre 0 e 2

    if(matriz[x][y]!=' ') // Verifica se a posição escolhida está ocupada
      {
        jogadaCPU(sock, buffer); // Chama recursivamente a função se a posição estiver ocupada
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

        if (erro==0) {
      matriz[x][y]='O'; // Faz a jogada do computador
      printf("O pc jogou em %d %d\n",x+1,y+1);
        //MEXER JUNTAS E COLOCAR PECAS NO JOGO
        IrParaPosicaoInicial(posicaoBaseInicial, sock, buffer);
        pegarPeca(sock, buffer, posicaoPeca, posicaoUp);
        IrParaPosicaoInicial(posicaoBaseInicial, sock, buffer);
        if (x == 0 && y == 0) {
          moverParaPos00(Pos00, sock, buffer);
        }
        else if (x == 0 && y == 1) {
          moverParaPos01(Pos01, sock, buffer);
        }
        else if (x == 0 && y == 2) {
          moverParaPos02(Pos02, sock, buffer);
        }
        else if (x == 1 && y == 0) {
          moverParaPos10(Pos10, sock, buffer);
        }
        else if (x == 1 && y == 1) {
          moverParaPos11(Pos11, sock, buffer);
        }
        else if (x == 1 && y == 2) {
          moverParaPos12(Pos12, sock, buffer);
        }
        else if (x == 2 && y == 0) {
          moverParaPos20(Pos20, sock, buffer);
        }
        else if (x == 2 && y == 1) {
          moverParaPos21(Pos21, sock, buffer);
        }
        else if (x == 2 && y == 2) {
          moverParaPos22(Pos22, sock, buffer);
        }
      }


      else if (erro!=0) {
      matriz[mx][my]='O'; // Faz uma jogada defensiva se necessário
      printf("O pc jogou em %d %d\n",mx,my);
        //MEXER JUNTAS E COLOCAR PECAS NO JOGO
        IrParaPosicaoInicial(posicaoBaseInicial, sock, buffer);
        pegarPeca(sock, buffer, posicaoPeca, posicaoUp);
        IrParaPosicaoInicial(posicaoBaseInicial, sock, buffer);
        if (mx == 0 && my == 0) {
          moverParaPos00(Pos00, sock, buffer);
        }
        else if (mx == 0 && my == 1) {
          moverParaPos01(Pos01, sock, buffer);
        }
        else if (mx == 0 && my == 2) {
          moverParaPos02(Pos02, sock, buffer);
        }
        else if (mx == 1 && my == 0) {
          moverParaPos10(Pos10, sock, buffer);
        }
        else if (mx == 1 && my == 1) {
          moverParaPos11(Pos11, sock, buffer);
        }
        else if (mx == 1 && my == 2) {
          moverParaPos12(Pos12, sock, buffer);
        }
        else if (mx == 2 && my == 0) {
          moverParaPos20(Pos20, sock, buffer);
        }
        else if (mx == 2 && my == 1) {
          moverParaPos21(Pos21, sock, buffer);
        }
        else if (mx == 2 && my == 2) {
          moverParaPos22(Pos22, sock, buffer);
        }

      }
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

  void pegaValores(int sock, char buffer[2048])  // Função para obter os valores do jogador
  {
    int x,y;
    printf("\n\nDigite as coordenadas do tipo: Linha, Coluna: \n");
    scanf("%d%d",&x,&y);
    jogadaUser(x, y, sock, buffer);
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
  int jogadaUser(int a, int b, int sock, char buffer[2048]) // Função para a jogada do jogador
  {

    if((a>dimensaoLado)||(b>dimensaoLado)||(a<1)||(b<1)) // Verifica se as coordenadas estão dentro do limite da matriz
      {
        printf("Valores Inválidos %d,%d\n\n",a,b);
        printMatriz();
        pegaValores(sock, buffer);
      }
    else if(matriz[a-1][b-1]!=' ') // Verifica se a posição escolhida já está ocupada
      {
        printf("Casa já foi preenchida %d,%d \n\n",a,b);
        printMatriz();
        pegaValores(sock, buffer);
      }
    else {
      matriz[a-1][b-1]='X'; // Preenche a posição com 'X'
      //MEXER JUNTAS E COLOCAR PECAS
      IrParaPosicaoInicial(posicaoBaseInicial, sock, buffer);
      pegarPeca(sock, buffer, posicaoPeca, posicaoUp);
      IrParaPosicaoInicial(posicaoBaseInicial, sock, buffer);
      if (a-1 == 0 && b-1 == 0) {
        moverParaPos00(Pos00, sock, buffer);
      }
      else if (a-1 == 0 && b-1 == 1) {
        moverParaPos01(Pos01, sock, buffer);
      }
      else if (a-1 == 0 && b-1 == 2) {
        moverParaPos02(Pos02, sock, buffer);
      }
      else if (a-1 == 1 && b-1 == 0) {
        moverParaPos10(Pos10, sock, buffer);
      }
      else if (a-1 == 1 && b-1 == 1) {
        moverParaPos11(Pos11, sock, buffer);
      }
      else if (a-1 == 1 && b-1 == 2) {
        moverParaPos12(Pos12, sock, buffer);
      }
      else if (a-1 == 2 && b-1 == 0) {
        moverParaPos20(Pos20, sock, buffer);
      }
      else if (a-1 == 2 && b-1 == 1) {
        moverParaPos21(Pos21, sock, buffer);
      }
      else if (a-1 == 2 && b-1 == 2) {
        moverParaPos22(Pos22, sock, buffer);
      }
    }


  }


  void iniciaMatriz() // Função para inicializar a matriz
  {
    int k,j;
    for (k=0;k < dimensaoLado;k++)
      for(j=0;j < dimensaoLado;j++)
        matriz[k][j]=' '; // Preenche a matriz com espaços em branco
  }



  int main(int argc, char *argv[]) {

      //variaveis para conexao com o robo NAO MEXER
      int sock = 0;
      char buffer[2048] = {0};

      //conexao com o robo NAO MEXER
      initSocket(&sock, buffer);

      //Programe aqui ---------------------------------------------------

      int jogadas;
      gerarSeedParaNumAleatorio(); // Gera uma semente aleatória

      iniciaMatriz(); // Inicializa a matriz do jogo
      jogadas = 0; // Inicializa o número de jogadas
      do {
          printMatriz(); // Imprime a matriz na tela
          pegaValores(sock, buffer); // Obtém as coordenadas do jogador
          jogadas++; // Incrementa o número de jogadas
          if((verificaVitoria()==0)&&(jogadas<9)) { // Verifica se o jogo não terminou e ainda há jogadas disponíveis
          jogadaCPU(sock, buffer); // O computador faz uma jogada
          jogadas++; // Incrementa o número de jogadas
          }
        }
        while((verificaVitoria()==0)&&(jogadas<9)); // Continua enquanto não há vencedor e ainda há jogadas disponíveis
      printMatriz(); // Imprime a matriz final

      //-----------------------------------------------------------------

      // Encerra a conexao NAO MEXER
      close(sock);

      return 0;
  }