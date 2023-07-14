#include <stdio.h>
#include <stdbool.h>

#define N 5 // Nombre de nœuds dans le réseau

int messages[N]; // Tableau pour stocker les messages d'élection

void LCR_Algorithm(int node_id) {
    int i;
    bool leader_elected = false;

    for (i = 0; i < N; i++) {
        if (i == node_id) {
            messages[i] = node_id; // Envoi du message d'élection au nœud suivant
        }
        else {
            messages[i] = -1; // Initialisation des autres messages à une valeur invalide
        }
    }

    while (!leader_elected) {
        for (i = 0; i < N; i++) {
            if (messages[i] == node_id) {
                // Le nœud a reçu son propre message, il est élu leader
                printf("Le nœud %d est le leader.\n", node_id);
                leader_elected = true;
                break;
            }

            if (messages[i] != -1 && messages[i] > node_id) {
                // Transmission du message d'élection au nœud suivant
                messages[(i + 1) % N] = messages[i];
            }
        }
    }
}

int main() {
    int i;

    for (i = 0; i < N; i++) {
        LCR_Algorithm(i); // Appel de l'algorithme LCR pour chaque nœud
    }

    return 0;
}