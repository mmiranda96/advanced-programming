#include <stdio.h>
#include <unistd.h>

void receiveSinal(int sig) {
    printf("Hello world!\n");
    printf("Signal received: %d\n", sig);
}

int main() {
    signal(SIGUSR1, receiveSignal);
    while (1) {}
    return 0;
}