#include <iostream>

using namespace std;

int *waitingTime(int count, int *burst);

int *completionTime(int count, int *burstTime);

int *turnaroundTime(int count, int *waitingTime, int *burstTime);

int main()
{
    int count;
    cout << "Enter number of Processes:";
    cin >> count;
    int *burstTime = new int[count];
    for (int i = 0; i < count; i++)
    {
        cout << "Process " << i + 1 << ":" << endl;
        cout << "Burst Time: ";
        cin >> burstTime[i];
    }
    // Completion Time

    int *completion = completionTime(count, burstTime);

    for (int i = 0; i < count; i++)
    {
        cout << "Completion Time for Process " << i + 1 << " is: " << completion[i] << endl;
    }
    cout << endl;

    // Waiting Time

    int *waiting = waitingTime(count, burstTime);
    float averageWaiting = 0;
    for (int i = 0; i < count; i++)
    {
        cout << "Waiting Time for Process " << i + 1 << " is: " << waiting[i] << endl;
        averageWaiting += waiting[i];
    }
    averageWaiting /= count;
    cout << "Average Waiting Time: " << averageWaiting << endl;
    cout << endl;

    // Turnaround Time

    int *turnaround = turnaroundTime(count, waiting, burstTime);
    float averageTurnaround = 0;

    for (int i = 0; i < count; i++)
    {
        cout << "Turnaround Time for Process " << i + 1 << " is: " << turnaround[i] << endl;
        averageTurnaround += turnaround[i];
    }
    averageTurnaround /= count;
    cout << "Average Turnaround Time: " << averageTurnaround << endl;

    cout << endl;
}

int *completionTime(int count, int *burstTime)
{
    int *complete = new int[count];
    complete[0] = burstTime[0];

    for (int i = 1; i < count; i++)
        complete[i] = complete[i - 1] + burstTime[i];

    return complete;
}

int *waitingTime(int count, int *burstTime)
{
    int *waitTime = new int[count];
    waitTime[0] = 0;

    for (int i = 1; i < count; i++)
        waitTime[i] = burstTime[i - 1] + waitTime[i - 1];

    return waitTime;
}

int *turnaroundTime(int count, int *waiting, int *burst)
{
    int *turn = new int[count];

    for (int i = 0; i < count; i++)
        turn[i] = waiting[i] + burst[i];

    return turn;
}