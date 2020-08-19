#include <iostream>

using namespace std;

struct Process
{
    int pid;
    int burst;
    int priority;
};

void sortProcesses(int count, Process *procPrior);

int *waitingTime(int count, Process *procPrior);

int *completionTime(int count, Process *procPrior);

int *turnaroundTime(int count, int *waitingTime, Process *procPrior);

int main()
{
    int count;
    cout << "Enter number of Processes:";
    cin >> count;
    Process *procPrior = new Process[count];
    for (int i = 0; i < count; i++)
    {
        procPrior[i].pid = i + 1;
        cout << "Process " << i + 1 << ":" << endl;
        cout << "Burst Time: ";
        cin >> procPrior[i].burst;
        cout << "Priority: ";
        cin >> procPrior[i].priority;
        cout << endl;
    }
    // Sort them according to Priority
    sortProcesses(count, procPrior);
    cout << endl;

    // Completion Time

    int *completion = completionTime(count, procPrior);

    for (int i = 0; i < count; i++)
    {
        cout << "Completion Time for Process " << procPrior[i].pid << " is: " << completion[i] << endl;
    }
    cout << endl;

    // // Waiting Time

    int *waiting = waitingTime(count, procPrior);
    float averageWaiting = 0;
    for (int i = 0; i < count; i++)
    {
        cout << "Waiting Time for Process " << procPrior[i].pid << " is: " << waiting[i] << endl;
        averageWaiting += waiting[i];
    }
    averageWaiting /= count;
    cout << "Average Waiting Time: " << averageWaiting << endl;
    cout << endl;

    // // Turnaround Time

    int *turnaround = turnaroundTime(count, waiting, procPrior);
    float averageTurnaround = 0;

    for (int i = 0; i < count; i++)
    {
        cout << "Turnaround Time for Process " << procPrior[i].pid << " is: " << turnaround[i] << endl;
        averageTurnaround += turnaround[i];
    }
    averageTurnaround /= count;
    cout << "Average Turnaround Time: " << averageTurnaround << endl;

    cout << endl;
}

void sortProcesses(int count, Process *procPrior)
{
    bool swapped;
    for (int i = 0; i < count - 1; i++)
    {
        swapped = false;
        for (int j = 0; j < count - i - 1; j++)
        {
            if (procPrior[j].priority < procPrior[j + 1].priority)
            {
                Process temp = procPrior[j];
                procPrior[j] = procPrior[j + 1];
                procPrior[j + 1] = temp;
                swapped = true;
            }
        }
        // If no two elements were swapped by inner loop, then break
        if (swapped == false)
            break;
    }
}

int *completionTime(int count, Process *procPrior)
{
    int *complete = new int[count];
    complete[0] = procPrior[0].burst;

    for (int i = 1; i < count; i++)
        complete[i] = complete[i - 1] + procPrior[i].burst;

    return complete;
}

int *waitingTime(int count, Process *procPrior)
{
    int *waitTime = new int[count];
    waitTime[0] = 0;

    for (int i = 1; i < count; i++)
        waitTime[i] = procPrior[i - 1].burst + waitTime[i - 1];

    return waitTime;
}

int *turnaroundTime(int count, int *waiting, Process *procPrior)
{
    int *turn = new int[count];

    for (int i = 0; i < count; i++)
        turn[i] = waiting[i] + procPrior[i].burst;

    return turn;
}