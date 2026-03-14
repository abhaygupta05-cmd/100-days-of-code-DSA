#include <stdio.h>

#define SIZE 100

int queue[SIZE];
int front = -1, rear = -1;

int stack[SIZE];
int top = -1;

void enqueue(int x)
{
    if (rear == SIZE - 1)
        return;

    if (front == -1)
        front = 0;

    queue[++rear] = x;
}

int dequeue()
{
    if (front == -1 || front > rear)
        return -1;

    return queue[front++];
}

void push(int x)
{
    stack[++top] = x;
}

int pop()
{
    return stack[top--];
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

    while (front <= rear)
    {
        push(dequeue());
    }

    while (top != -1)
    {
        enqueue(pop());
    }

    for (int i = front; i <= rear; i++)
    {
        printf("%d ", queue[i]);
    }

    return 0;
}