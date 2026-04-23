#define PI 3.14
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern "C" {
#include "extApi.h"
}

int main(int argc, char* argv[])
{


    //conecta com o coppelia
    int clientID = simxStart((simxChar*)"127.0.0.1", 19999, true, true, 2000, 5);

    extApi_sleepMs(500);

    //verifica conexao com simulador
    if (clientID == -1) {
        printf("Erro conectando ao Coppelia!\n");
        return 0;
    }
    else {
        printf("Conectado ao Coppelia!\n");
    }
    const char* vecJunt[6] = {

        "/base_link_respondable[0]/joint_1",
        "/base_link_respondable[0]/joint_2",
        "/base_link_respondable[0]/joint_3",
        "/base_link_respondable[0]/joint_4",
        "/base_link_respondable[0]/joint_5",
        "/base_link_respondable[0]/joint_6"
    };
    simxInt handler[6];
    for (int i = 0; i < 6; i++) {

        simxGetObjectHandle(clientID, vecJunt[i], &handler[i], (simxInt)simx_opmode_oneshot_wait);
    }
    simxFloat posInicJuntas[6] = { -21.8494, -37.3499, -3.5898, 66.9170, -16.5260, 8.2349 }; // -55.000000, -38.700000, -5.000000, -0.00000, -3.000000, -0.000000

    FILE* arquivo = NULL;
    arquivo = fopen("digitos_lista_voto.txt", "rt");

    if (arquivo == NULL) {
        printf("erro na leitura dos votos");
        exit(1);
    }
    char linha[1000];
    int i = 1;
    while (fgets(linha, sizeof(linha), arquivo)) {
        for (int h = 0; h < strlen(linha); h++) {
            if (linha[h] >= '0' && linha[h] <= '9') {
                int numero = linha[h] - '0';

                if (numero == 0) {
                    for (int i = 0; i < 6; i++) {
                        simxSetJointTargetPosition(clientID, handler[i], posInicJuntas[i] * PI / 180, (simxInt)simx_opmode_oneshot_wait);
                        extApi_sleepMs(1000);
                    }
                    simxFloat Juntasangulo[6] = { -16.000000, -48.000000, -2.000000, -0.00000, -3.000000, -0.000000 };
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
                if (numero == 1) {
                    for (int i = 0; i < 6; i++) {
                        simxSetJointTargetPosition(clientID, handler[i], posInicJuntas[i] * PI / 180, (simxInt)simx_opmode_oneshot_wait);
                        extApi_sleepMs(1000);
                    }
                    simxFloat Juntasangulo[6] = { -14.0000, -49.3000, 11.1000, 55.5000, -13.6000, 25.1000 };
                    simxSetJointTargetPosition(clientID, handler[0], Juntasangulo[0] * PI / 180, (simxInt)simx_opmode_oneshot_wait);
                    simxSetJointTargetPosition(clientID, handler[3], Juntasangulo[3] * PI / 180, (simxInt)simx_opmode_oneshot_wait);
                    simxSetJointTargetPosition(clientID, handler[4], Juntasangulo[4] * PI / 180, (simxInt)simx_opmode_oneshot_wait);
                    simxSetJointTargetPosition(clientID, handler[5], Juntasangulo[5] * PI / 180, (simxInt)simx_opmode_oneshot_wait);
                    extApi_sleepMs(1000);
                    simxSetJointTargetPosition(clientID, handler[2], Juntasangulo[2] * PI / 180, (simxInt)simx_opmode_oneshot_wait);
                    extApi_sleepMs(100);
                    simxSetJointTargetPosition(clientID, handler[1], Juntasangulo[1] * PI / 180, (simxInt)simx_opmode_oneshot_wait);
                    extApi_sleepMs(1000);
                    for (int i = 0; i < 6; i++) {
                        simxSetJointTargetPosition(clientID, handler[i], posInicJuntas[i] * PI / 180, (simxInt)simx_opmode_oneshot_wait);
                    }
                }
                if (numero == 2) {
                    for (int i = 0; i < 6; i++) {
                        simxSetJointTargetPosition(clientID, handler[i], posInicJuntas[i] * PI / 180, (simxInt)simx_opmode_oneshot_wait);
                        extApi_sleepMs(1000);
                    }
                    simxFloat Juntasangulo[6] = { -18.2660, -51.6495, 14.9966, 55.8428, -18.4520, 22.0264 };
                    simxSetJointTargetPosition(clientID, handler[0], Juntasangulo[0] * PI / 180, (simxInt)simx_opmode_oneshot_wait);
                    simxSetJointTargetPosition(clientID, handler[3], Juntasangulo[3] * PI / 180, (simxInt)simx_opmode_oneshot_wait);
                    simxSetJointTargetPosition(clientID, handler[4], Juntasangulo[4] * PI / 180, (simxInt)simx_opmode_oneshot_wait);
                    simxSetJointTargetPosition(clientID, handler[5], Juntasangulo[5] * PI / 180, (simxInt)simx_opmode_oneshot_wait);
                    extApi_sleepMs(1000);
                    simxSetJointTargetPosition(clientID, handler[2], Juntasangulo[2] * PI / 180, (simxInt)simx_opmode_oneshot_wait);
                    extApi_sleepMs(100);
                    simxSetJointTargetPosition(clientID, handler[1], Juntasangulo[1] * PI / 180, (simxInt)simx_opmode_oneshot_wait);
                    extApi_sleepMs(1000);
                    for (int i = 0; i < 6; i++) {
                        simxSetJointTargetPosition(clientID, handler[i], posInicJuntas[i] * PI / 180, (simxInt)simx_opmode_oneshot_wait);
                    }
                }
                if (numero == 3) {
                    for (int i = 0; i < 6; i++) {
                        simxSetJointTargetPosition(clientID, handler[i], posInicJuntas[i] * PI / 180, (simxInt)simx_opmode_oneshot_wait);
                        extApi_sleepMs(1000);
                    }
                    simxFloat Juntasangulo[6] = { -22.9456, -54.3660, 20.3182, 52.7861, -22.0168, 22.3452 };
                    simxSetJointTargetPosition(clientID, handler[0], Juntasangulo[0] * PI / 180, (simxInt)simx_opmode_oneshot_wait);
                    simxSetJointTargetPosition(clientID, handler[3], Juntasangulo[3] * PI / 180, (simxInt)simx_opmode_oneshot_wait);
                    simxSetJointTargetPosition(clientID, handler[4], Juntasangulo[4] * PI / 180, (simxInt)simx_opmode_oneshot_wait);
                    simxSetJointTargetPosition(clientID, handler[5], Juntasangulo[5] * PI / 180, (simxInt)simx_opmode_oneshot_wait);
                    extApi_sleepMs(1000);
                    simxSetJointTargetPosition(clientID, handler[2], Juntasangulo[2] * PI / 180, (simxInt)simx_opmode_oneshot_wait);
                    extApi_sleepMs(100);
                    simxSetJointTargetPosition(clientID, handler[1], Juntasangulo[1] * PI / 180, (simxInt)simx_opmode_oneshot_wait);
                    extApi_sleepMs(1000);
                    for (int i = 0; i < 6; i++) {
                        simxSetJointTargetPosition(clientID, handler[i], posInicJuntas[i] * PI / 180, (simxInt)simx_opmode_oneshot_wait);
                    }
                }
                if (numero == 4) {
                    for (int i = 0; i < 6; i++) {
                        simxSetJointTargetPosition(clientID, handler[i], posInicJuntas[i] * PI / 180, (simxInt)simx_opmode_oneshot_wait);
                        extApi_sleepMs(1000);
                    }
                    simxFloat Juntasangulo[6] = { -14.9076, -48.1209, 3.5239, 83.2011, -11.3886, -3.8602 };
                    simxSetJointTargetPosition(clientID, handler[0], Juntasangulo[0] * PI / 180, (simxInt)simx_opmode_oneshot_wait);
                    simxSetJointTargetPosition(clientID, handler[3], Juntasangulo[3] * PI / 180, (simxInt)simx_opmode_oneshot_wait);
                    simxSetJointTargetPosition(clientID, handler[4], Juntasangulo[4] * PI / 180, (simxInt)simx_opmode_oneshot_wait);
                    simxSetJointTargetPosition(clientID, handler[5], Juntasangulo[5] * PI / 180, (simxInt)simx_opmode_oneshot_wait);
                    extApi_sleepMs(1000);
                    simxSetJointTargetPosition(clientID, handler[2], Juntasangulo[2] * PI / 180, (simxInt)simx_opmode_oneshot_wait);
                    extApi_sleepMs(100);
                    simxSetJointTargetPosition(clientID, handler[1], Juntasangulo[1] * PI / 180, (simxInt)simx_opmode_oneshot_wait);
                    extApi_sleepMs(1000);
                    for (int i = 0; i < 6; i++) {
                        simxSetJointTargetPosition(clientID, handler[i], posInicJuntas[i] * PI / 180, (simxInt)simx_opmode_oneshot_wait);
                    }
                }
                if (numero == 5) {
                    for (int i = 0; i < 6; i++) {
                        simxSetJointTargetPosition(clientID, handler[i], posInicJuntas[i] * PI / 180, (simxInt)simx_opmode_oneshot_wait);
                        extApi_sleepMs(1000);
                    }
                    simxFloat Juntasangulo[6] = { -19.2771, -50.3057, 7.1980, 75.2429, -16.2303, 1.2187 };
                    simxSetJointTargetPosition(clientID, handler[0], Juntasangulo[0] * PI / 180, (simxInt)simx_opmode_oneshot_wait);
                    simxSetJointTargetPosition(clientID, handler[3], Juntasangulo[3] * PI / 180, (simxInt)simx_opmode_oneshot_wait);
                    simxSetJointTargetPosition(clientID, handler[4], Juntasangulo[4] * PI / 180, (simxInt)simx_opmode_oneshot_wait);
                    simxSetJointTargetPosition(clientID, handler[5], Juntasangulo[5] * PI / 180, (simxInt)simx_opmode_oneshot_wait);
                    extApi_sleepMs(1000);
                    simxSetJointTargetPosition(clientID, handler[2], Juntasangulo[2] * PI / 180, (simxInt)simx_opmode_oneshot_wait);
                    extApi_sleepMs(100);
                    simxSetJointTargetPosition(clientID, handler[1], Juntasangulo[1] * PI / 180, (simxInt)simx_opmode_oneshot_wait);
                    extApi_sleepMs(1000);
                    for (int i = 0; i < 6; i++) {
                        simxSetJointTargetPosition(clientID, handler[i], posInicJuntas[i] * PI / 180, (simxInt)simx_opmode_oneshot_wait);
                    }
                }
                if (numero == 6) {
                    for (int i = 0; i < 6; i++) {
                        simxSetJointTargetPosition(clientID, handler[i], posInicJuntas[i] * PI / 180, (simxInt)simx_opmode_oneshot_wait);
                        extApi_sleepMs(1000);
                    }
                    simxFloat Juntasangulo[6] = { -23.7670, -52.9507, 12.1766, 68.8394, -20.2616, 4.7305 };
                    simxSetJointTargetPosition(clientID, handler[0], Juntasangulo[0] * PI / 180, (simxInt)simx_opmode_oneshot_wait);
                    simxSetJointTargetPosition(clientID, handler[3], Juntasangulo[3] * PI / 180, (simxInt)simx_opmode_oneshot_wait);
                    simxSetJointTargetPosition(clientID, handler[4], Juntasangulo[4] * PI / 180, (simxInt)simx_opmode_oneshot_wait);
                    simxSetJointTargetPosition(clientID, handler[5], Juntasangulo[5] * PI / 180, (simxInt)simx_opmode_oneshot_wait);
                    extApi_sleepMs(1000);
                    simxSetJointTargetPosition(clientID, handler[2], Juntasangulo[2] * PI / 180, (simxInt)simx_opmode_oneshot_wait);
                    extApi_sleepMs(100);
                    simxSetJointTargetPosition(clientID, handler[1], Juntasangulo[1] * PI / 180, (simxInt)simx_opmode_oneshot_wait);
                    extApi_sleepMs(1000);
                    for (int i = 0; i < 6; i++) {
                        simxSetJointTargetPosition(clientID, handler[i], posInicJuntas[i] * PI / 180, (simxInt)simx_opmode_oneshot_wait);
                    }
                }
                if (numero == 7) {
                    for (int i = 0; i < 6; i++) {
                        simxSetJointTargetPosition(clientID, handler[i], posInicJuntas[i] * PI / 180, (simxInt)simx_opmode_oneshot_wait);
                        extApi_sleepMs(1000);
                    }
                    simxFloat Juntasangulo[6] = { -17.4523, -47.1233, -3.2329, 110.7756, -13.2388, -32.4066 };
                    simxSetJointTargetPosition(clientID, handler[0], Juntasangulo[0] * PI / 180, (simxInt)simx_opmode_oneshot_wait);
                    simxSetJointTargetPosition(clientID, handler[3], Juntasangulo[3] * PI / 180, (simxInt)simx_opmode_oneshot_wait);
                    simxSetJointTargetPosition(clientID, handler[4], Juntasangulo[4] * PI / 180, (simxInt)simx_opmode_oneshot_wait);
                    simxSetJointTargetPosition(clientID, handler[5], Juntasangulo[5] * PI / 180, (simxInt)simx_opmode_oneshot_wait);
                    extApi_sleepMs(1000);
                    simxSetJointTargetPosition(clientID, handler[2], Juntasangulo[2] * PI / 180, (simxInt)simx_opmode_oneshot_wait);
                    extApi_sleepMs(100);
                    simxSetJointTargetPosition(clientID, handler[1], Juntasangulo[1] * PI / 180, (simxInt)simx_opmode_oneshot_wait);
                    extApi_sleepMs(1000);
                    for (int i = 0; i < 6; i++) {
                        simxSetJointTargetPosition(clientID, handler[i], posInicJuntas[i] * PI / 180, (simxInt)simx_opmode_oneshot_wait);
                    }
                }
                if (numero == 8) {
                    for (int i = 0; i < 6; i++) {
                        simxSetJointTargetPosition(clientID, handler[i], posInicJuntas[i] * PI / 180, (simxInt)simx_opmode_oneshot_wait);
                        extApi_sleepMs(1000);
                    }
                    simxFloat Juntasangulo[6] = { -20.1898, -48.3009, 0.4615, 96.1806, -16.6250, -21.2284 };
                    simxSetJointTargetPosition(clientID, handler[0], Juntasangulo[0] * PI / 180, (simxInt)simx_opmode_oneshot_wait);
                    simxSetJointTargetPosition(clientID, handler[3], Juntasangulo[3] * PI / 180, (simxInt)simx_opmode_oneshot_wait);
                    simxSetJointTargetPosition(clientID, handler[4], Juntasangulo[4] * PI / 180, (simxInt)simx_opmode_oneshot_wait);
                    simxSetJointTargetPosition(clientID, handler[5], Juntasangulo[5] * PI / 180, (simxInt)simx_opmode_oneshot_wait);
                    extApi_sleepMs(1000);
                    simxSetJointTargetPosition(clientID, handler[2], Juntasangulo[2] * PI / 180, (simxInt)simx_opmode_oneshot_wait);
                    extApi_sleepMs(100);
                    simxSetJointTargetPosition(clientID, handler[1], Juntasangulo[1] * PI / 180, (simxInt)simx_opmode_oneshot_wait);
                    extApi_sleepMs(1000);
                    for (int i = 0; i < 6; i++) {
                        simxSetJointTargetPosition(clientID, handler[i], posInicJuntas[i] * PI / 180, (simxInt)simx_opmode_oneshot_wait);
                    }
                }
                if (numero == 9) {
                    for (int i = 0; i < 6; i++) {
                        simxSetJointTargetPosition(clientID, handler[i], posInicJuntas[i] * PI / 180, (simxInt)simx_opmode_oneshot_wait);
                        extApi_sleepMs(1000);
                    }
                    simxFloat Juntasangulo[6] = { -26.9448, -52.2335, 5.2789, 85.4281, -19.7282, -13.6511 };
                    simxSetJointTargetPosition(clientID, handler[0], Juntasangulo[0] * PI / 180, (simxInt)simx_opmode_oneshot_wait);
                    simxSetJointTargetPosition(clientID, handler[3], Juntasangulo[3] * PI / 180, (simxInt)simx_opmode_oneshot_wait);
                    simxSetJointTargetPosition(clientID, handler[4], Juntasangulo[4] * PI / 180, (simxInt)simx_opmode_oneshot_wait);
                    simxSetJointTargetPosition(clientID, handler[5], Juntasangulo[5] * PI / 180, (simxInt)simx_opmode_oneshot_wait);
                    extApi_sleepMs(1000);
                    simxSetJointTargetPosition(clientID, handler[2], Juntasangulo[2] * PI / 180, (simxInt)simx_opmode_oneshot_wait);
                    extApi_sleepMs(100);
                    simxSetJointTargetPosition(clientID, handler[1], Juntasangulo[1] * PI / 180, (simxInt)simx_opmode_oneshot_wait);
                    extApi_sleepMs(1000);
                    for (int i = 0; i < 6; i++) {
                        simxSetJointTargetPosition(clientID, handler[i], posInicJuntas[i] * PI / 180, (simxInt)simx_opmode_oneshot_wait);
                    }
                }
                

                
                
            }
            else {
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



    }
    // Fecha a conexao 
    fclose(arquivo);
    simxFinish(clientID);

    return(0);
}
