#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PLAYERS 10

// Structure to represent a player
typedef struct {
    char name[30];
} Player;

// Queue data structure
typedef struct {
    Player players[MAX_PLAYERS];
    int front, rear, size;
} Queue;

// Function to initialize the queue
void initializeQueue(Queue *q) {
    q->front = q->rear = q->size = 0;
}

// Function to add a player to the queue
void enqueue(Queue *q, Player player) {
    if (q->size < MAX_PLAYERS) {
        q->players[q->rear] = player;
        q->rear = (q->rear + 1) % MAX_PLAYERS;
        q->size++;
    } else {
        printf("Queue is full.\n");
    }
}

// Function to simulate passing the potato
void simulateGame(Queue *q, int passes) {
    while (q->size > 1) {
        for (int i = 1; i <= passes; i++) {
            printf("Pass %d: %s\n", i, q->players[q->front].name);
            q->front = (q->front + 1) % MAX_PLAYERS;
        }

        printf("%s is eliminated.\n", q->players[q->front].name);
        q->front = (q->front + 1) % MAX_PLAYERS;
        q->size--;
    }
}

int main() {
    Queue playerQueue;
    initializeQueue(&playerQueue);

    Player newPlayer;
    int passes;

    // Adding players to the queue
    while (1) {
        printf("Enter player name (or 'q' to finish adding players): ");
        scanf("%s", newPlayer.name);
        if (strcmp(newPlayer.name, "q") == 0) {
            break;
        }
        enqueue(&playerQueue, newPlayer);
    }

    printf("Enter the number of passes before a player gets eliminated: ");
    scanf("%d", &passes);

    simulateGame(&playerQueue, passes);

    // Display the final winner
    printf("The winner is: %s\n", playerQueue.players[playerQueue.front].name);

    return 0;
}
