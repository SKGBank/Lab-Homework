#include <stdio.h>

void TowerHanoi(int n, int source, int destination, int auxiliary);

int main() {
    TowerHanoi(3, 1, 3, 2);
    return 0;
}

void TowerHanoi(int n, int source, int destination, int auxiliary) {
    if (n == 1) {
        printf("Disc 1 from %d to %d\n", source, destination);
        return;
    }

    TowerHanoi(n - 1, source, auxiliary, destination);
    printf("Disc %d from %d to %d\n", n, source, destination);
    TowerHanoi(n - 1, auxiliary, destination, source);
}
