#include <stdio.h>
#define SIZE 100

int queue[SIZE];
int front = -1, rear = -1;

void enqueue(int x)
{
    if (rear == SIZE - 1)
    {
        printf("Queue Overflow");
        return;
    }

    if (front == -1)
        front = 0;

    rear++;
    queue[rear] = x;
}

void display()
{
    for (int i = front; i <= rear; i++)
    {
        printf("%d ", queue[i]);
    }
}

int main()
{
    int n, x;

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &x);
        enqueue(x);
    }

    display();

    return 0;
}