#include <iostream>

using namespace std;

int *completionTime(int count, int *burstTime);

int *turnaroundTime(int count, int *arrivalTime, int *completionTime);

int *waitingTime(int count, int *arrivalTime, int *turnaround);

int main()
{
    int count;
    cout << "Enter number of Processes:";
    cin >> count;

    // int *processes = new int[count];
    int *arrivalTime = new int[count];
    int *burstTime = new int[count];
    for (int i = 0; i < count; i++)
    {
        cout << "Process " << i + 1 << ":" << endl;
        cout << "Arrival Time: ";
        cin >> arrivalTime[i];
        cout << "Burst Time: ";
        cin >> burstTime[i];
    }

    int *completion = completionTime(count, burstTime);

    for (int i = 0; i < count; i++)
    {
        cout << "Completion Time for Process " << i + 1 << " is: " << completion[i] << endl;
    }
    cout << endl;
    int *turnaround = turnaroundTime(count, arrivalTime, completion);
    float averageTurnaround = 0;

    for (int i = 0; i < count; i++)
    {
        cout << "Turnaround Time for Process " << i + 1 << " is: " << turnaround[i] << endl;
        averageTurnaround += turnaround[i];
    }
    averageTurnaround /= count;
    cout << "Average Turnaround Time: " << averageTurnaround << endl;

    cout << endl;
    int *waiting = waitingTime(count, turnaround, burstTime);
    float averageWaiting = 0;
    for (int i = 0; i < count; i++)
    {
        cout << "Waiting Time for Process " << i + 1 << " is: " << waiting[i] << endl;
        averageWaiting += waiting[i];
    }
    averageWaiting /= count;
    cout << "Average Waiting Time: " << averageWaiting << endl;
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

int *turnaroundTime(int count, int *arrivalTime, int *completionTime)
{
    int *turn = new int[count];

    for (int i = 0; i < count; i++)
        turn[i] = completionTime[i] - arrivalTime[i];

    return turn;
}
int *waitingTime(int count, int *turnaround, int *burstTime)
{
    int *waitTime = new int[count];

    for (int i = 0; i < count; i++)
        waitTime[i] = turnaround[i] - burstTime[i];

    return waitTime;
}
