#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Função para o ataque
int atacar() {
    return rand() % 20 + 5; // Dano entre 5 e 25
}

// Função para defesa
int defender() {
    return rand() % 10 + 5; // Bloqueio entre 5 e 15
}

int main() {
    srand(static_cast<unsigned int>(time(0)));

    int vidaJogador1 = 100, vidaJogador2 = 100;
    int turno = 1;

    while (vidaJogador1 > 0 && vidaJogador2 > 0) {
        cout << "Turno " << turno++ << endl;

        // Jogador 1 ataca e Jogador 2 tenta defender
        int dano1 = atacar();
        int defesa1 = defender();
        int danoTotal1 = dano1 - defesa1;
        if (danoTotal1 < 0) danoTotal1 = 0;

        vidaJogador2 -= danoTotal1;
        cout << "Jogador 1 ataca com " << dano1 << " de dano. Jogador 2 defende " 
             << defesa1 << ". Dano total: " << danoTotal1 << ". Vida do Jogador 2: " << vidaJogador2 << endl;

        if (vidaJogador2 <= 0) break;

        // Jogador 2 ataca e Jogador 1 tenta defender
        int dano2 = atacar();
        int defesa2 = defender();
        int danoTotal2 = dano2 - defesa2;
        if (danoTotal2 < 0) danoTotal2 = 0;

        vidaJogador1 -= danoTotal2;
        cout << "Jogador 2 ataca com " << dano2 << " de dano. Jogador 1 defende " 
             << defesa2 << ". Dano total: " << danoTotal2 << ". Vida do Jogador 1: " << vidaJogador1 << endl;

        cout << "------------------------------------" << endl;
    }

    if (vidaJogador1 > 0)
        cout << "Jogador 1 venceu!" << endl;
    else
        cout << "Jogador 2 venceu!" << endl;

    return 0;
}
