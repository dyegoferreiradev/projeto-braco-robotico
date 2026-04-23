#define PI 3.14
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern "C" {
#include "extApi.h"
}

int conectarCoppelia() { // funcao que faz a conexao com o copelia
    int clientID = simxStart((simxChar*)"127.0.0.1", 19999, true, true, 2000, 5);
    extApi_sleepMs(500);
    return clientID;
}

void fecharConexao(int clientID) { // funcao que encerra a conexao com o copelia
    simxFinish(clientID);
}

void verificarConexao(int clientID) { // testa a conexao com o copelia
    if (clientID == -1) {
        printf("Erro conectando ao Coppelia!\n");
        exit(0);
    }
    else {
        printf("Conectado ao Coppelia!\n");
    }
}

FILE* abrirArquivo(const char* nomeArquivo) { // recebe o nome de um arquivo como parâmetro e tenta abri-lo
    FILE* arquivo = fopen(nomeArquivo, "rt"); // tenta abrir o arquivo com o nome fornecido em modo de leitura de texto ("rt").
    if (arquivo == NULL) { // verifica se ocorreu um erro durante a abertura do arquivo.
        printf("Erro na abertura do arquivo %s, que possui os votos!\n", nomeArquivo);
        exit(1);
    }
    return arquivo;
}

void executarMovimento(int numero, int clientID, simxInt* handler, const simxFloat* posInicJuntas) {
    if (numero >= 0 && numero <= 9) {
        simxFloat Juntasangulo[6];

        switch (numero) { // switch com o angulo que cada junta deve estar para apertar seu respectivo numero
        case 0:
            Juntasangulo[0] = -16.000000;
            Juntasangulo[1] = -48.000000;
            Juntasangulo[2] = -2.000000;
            Juntasangulo[3] = -0.00000;
            Juntasangulo[4] = -3.000000;
            Juntasangulo[5] = -0.000000;
            break;
        case 1:
            Juntasangulo[0] = -14.0000;
            Juntasangulo[1] = -49.3000;
            Juntasangulo[2] = 11.1000;
            Juntasangulo[3] = 55.5000;
            Juntasangulo[4] = -13.6000;
            Juntasangulo[5] = 25.1000;
            break;
        case 2:
            Juntasangulo[0] = -18.2660;
            Juntasangulo[1] = -51.6495;
            Juntasangulo[2] = 14.9966;
            Juntasangulo[3] = 55.8428;
            Juntasangulo[4] = -18.4520;
            Juntasangulo[5] = 22.0264;
            break;
        case 3:
            Juntasangulo[0] = -22.9456;
            Juntasangulo[1] = -54.3660;
            Juntasangulo[2] = 20.3182;
            Juntasangulo[3] = 52.7861;
            Juntasangulo[4] = -22.0168;
            Juntasangulo[5] = 22.3452;
            break;
        case 4:
            Juntasangulo[0] = -14.9076;
            Juntasangulo[1] = -48.1209;
            Juntasangulo[2] = 3.5239;
            Juntasangulo[3] = 83.2011;
            Juntasangulo[4] = -11.3886;
            Juntasangulo[5] = -3.8602;
            break;
        case 5:
            Juntasangulo[0] = -19.2771;
            Juntasangulo[1] = -50.3057;
            Juntasangulo[2] = 7.1980;
            Juntasangulo[3] = 75.2429;
            Juntasangulo[4] = -16.2303;
            Juntasangulo[5] = 1.2187;
            break;
        case 6:
            Juntasangulo[0] = -23.7670;
            Juntasangulo[1] = -52.9507;
            Juntasangulo[2] = 12.1766;
            Juntasangulo[3] = 68.8394;
            Juntasangulo[4] = -20.2616;
            Juntasangulo[5] = 4.7305;
            break;
        case 7:
            Juntasangulo[0] = -17.4523;
            Juntasangulo[1] = -47.1233;
            Juntasangulo[2] = -3.2329;
            Juntasangulo[3] = 110.7756;
            Juntasangulo[4] = -13.2388;
            Juntasangulo[5] = -32.4066;
            break;
        case 8:
            Juntasangulo[0] = -20.1898;
            Juntasangulo[1] = -48.3009;
            Juntasangulo[2] = 0.4615;
            Juntasangulo[3] = 96.1806;
            Juntasangulo[4] = -16.6250;
            Juntasangulo[5] = -21.2284;
            break;
        case 9:
            Juntasangulo[0] = -26.9448;
            Juntasangulo[1] = -52.2335;
            Juntasangulo[2] = 5.2789;
            Juntasangulo[3] = 85.4281;
            Juntasangulo[4] = -19.7282;
            Juntasangulo[5] = -13.6511;
            break;
        }

        // move as juntas para a posicao inicial
        for (int i = 0; i < 6; i++) {
            simxSetJointTargetPosition(clientID, handler[i], posInicJuntas[i] * PI / 180, (simxInt)simx_opmode_oneshot_wait);
            extApi_sleepMs(1000);
        }

        // aplica as posicoes das juntas para o numero especifico
        simxSetJointTargetPosition(clientID, handler[0], Juntasangulo[0] * PI / 180, (simxInt)simx_opmode_oneshot_wait);
        simxSetJointTargetPosition(clientID, handler[3], Juntasangulo[3] * PI / 180, (simxInt)simx_opmode_oneshot_wait);
        simxSetJointTargetPosition(clientID, handler[4], Juntasangulo[4] * PI / 180, (simxInt)simx_opmode_oneshot_wait);
        simxSetJointTargetPosition(clientID, handler[5], Juntasangulo[5] * PI / 180, (simxInt)simx_opmode_oneshot_wait);
        extApi_sleepMs(1000);
        simxSetJointTargetPosition(clientID, handler[2], Juntasangulo[2] * PI / 180, (simxInt)simx_opmode_oneshot_wait);
        extApi_sleepMs(100);
        simxSetJointTargetPosition(clientID, handler[1], Juntasangulo[1] * PI / 180, (simxInt)simx_opmode_oneshot_wait);
        extApi_sleepMs(1000);
        // move as juntas para a posicao inicial
        for (int i = 0; i < 6; i++) {
            simxSetJointTargetPosition(clientID, handler[i], posInicJuntas[i] * PI / 180, (simxInt)simx_opmode_oneshot_wait);
        }
    }
    else { // caso nao entre no if, ou seja, nao se trate de um numero, entre nesse else, que no caso faz o confirma ser pressionado
        for (int i = 0; i < 6; i++) {
            simxSetJointTargetPosition(clientID, handler[i], posInicJuntas[i] * PI / 180, (simxInt)simx_opmode_oneshot_wait);
            extApi_sleepMs(1000);
        }
        simxFloat Juntasangulo[6] = { -31.2658, -53.2645, -3.7972, 98.6531, -22.9278, -43.0228 };
        simxSetJointTargetPosition(clientID, handler[0], Juntasangulo[0] * PI / 180, (simxInt)simx_opmode_oneshot_wait);
        simxSetJointTargetPosition(clientID, handler[3], Juntasangulo[3] * PI / 180, (simxInt)simx_opmode_oneshot_wait);
        simxSetJointTargetPosition(clientID, handler[4], Juntasangulo[4] * PI / 180, (simxInt)simx_opmode_oneshot_wait);
        simxSetJointTargetPosition(clientID, handler[5], Juntasangulo[5] * PI / 180, (simxInt)simx_opmode_oneshot_wait);
        extApi_sleepMs(1000);
        simxSetJointTargetPosition(clientID, handler[1], Juntasangulo[1] * PI / 180, (simxInt)simx_opmode_oneshot_wait);
        extApi_sleepMs(500);
        simxSetJointTargetPosition(clientID, handler[2], Juntasangulo[2] * PI / 180, (simxInt)simx_opmode_oneshot_wait);
        extApi_sleepMs(1000);
        for (int i = 0; i < 6; i++) {
            simxSetJointTargetPosition(clientID, handler[i], posInicJuntas[i] * PI / 180, (simxInt)simx_opmode_oneshot_wait);
        }

    }


}


int main(int argc, char* argv[])
{
    int clientID = conectarCoppelia();
    verificarConexao(clientID);

    const char* vecJunt[6] = { // vetor de nomes das juntas no CoppeliaSim

        "/base_link_respondable[0]/joint_1",
        "/base_link_respondable[0]/joint_2",
        "/base_link_respondable[0]/joint_3",
        "/base_link_respondable[0]/joint_4",
        "/base_link_respondable[0]/joint_5",
        "/base_link_respondable[0]/joint_6"
    };
    simxInt handler[6]; // vetor para armazenar os identificadores das juntas
    for (int i = 0; i < 6; i++) {

        simxGetObjectHandle(clientID, vecJunt[i], &handler[i], (simxInt)simx_opmode_oneshot_wait);
    }
    simxFloat posInicJuntas[6] = { -21.8494, -37.3499, -3.5898, 66.9170, -16.5260, 8.2349 };  // posicoes iniciais das juntas em graus

    FILE* arquivo = abrirArquivo("digitos_lista_voto.txt");

    char linha[1000];
    int i = 1;

    while (fgets(linha, sizeof(linha), arquivo)) {
        for (int h = 0; h < strlen(linha); h++) {
            if (linha[h] >= '0' && linha[h] <= '9') {
                int numero = linha[h] - '0';
                executarMovimento(numero, clientID, handler, posInicJuntas);
            }
            else {
                executarMovimento(-1, clientID, handler, posInicJuntas); // Se o caractere nao for um numero, executa um movimento de apertar confirma
            }
        }
    }


    // Fecha a conexao e o arquivo
    fclose(arquivo);
    fecharConexao(clientID);

    return(0);
}