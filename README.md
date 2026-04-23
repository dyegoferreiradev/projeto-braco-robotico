# 🤖 Projeto: Jogo da Velha com Braço Robótico

## 📖 Sobre o Projeto
Este projeto prático foca na aplicação de conhecimentos de programação para resolver problemas reais de robótica. O objetivo central é o desenvolvimento de um sistema que permita a um braço robótico jogar partidas de Jogo da Velha de forma automatizada. As atividades práticas são realizadas no laboratório da Residência em Robótica e IA.

* **Linguagem utilizada:** C

## ⚙️ Funcionamento e Lógica
O software atua como o controlador entre a interface de comando e o hardware:
* **Representação:** O tabuleiro é processado como uma matriz 3x3.
* **Entrada de Dados:** As jogadas são inseridas manualmente através do terminal de comando.
* **Formato de Entrada:** Para que o braço processe o movimento, a entrada deve seguir o padrão: 
  * `X: (linha,coluna)` — Ex: `X: (0,1)`
  * `O: (linha,coluna)` — Ex: `O: (1,0)`
* **Ação Mecânica:** Após a leitura da coordenada, o programa comanda o braço robótico para realizar o movimento físico no tabuleiro.
* **Condição de Término:** O jogo prossegue até que ocorra uma vitória ou empate (velha).
