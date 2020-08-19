#include <iostream>

using namespace std;

struct Process
{
    int pid;
    int burst;
    int arrival;
    int priority;
};

void sortProcesses(int count, Process *procPrior);

int *completionTime(int count, Process *procPrior);

int *turnaroundTime(int count, int *completed, Process *procPrior);

int *waitingTime(int count, int *turnaround, Process *procPrior);

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
        cout << "Arrival Time: ";
        cin >> procPrior[i].arrival;
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

    // // Turnaround Time

    int *turnaround = turnaroundTime(count, completion, procPrior);
    float averageTurnaround = 0;

    for (int i = 0; i < count; i++)
    {
        cout << "Turnaround Time for Process " << procPrior[i].pid << " is: " << turnaround[i] << endl;
        averageTurnaround += turnaround[i];
    }
    averageTurnaround /= count;
    cout << "Average Turnaround Time: " << averageTurnaround << endl;

    cout << endl;

    // // Waiting Time

    int *waiting = waitingTime(count, turnaround, procPrior);
    float averageWaiting = 0;
    for (int i = 0; i < count; i++)
    {
        cout << "Waiting Time for Process " << procPrior[i].pid << " is: " << waiting[i] << endl;
        averageWaiting += waiting[i];
    }
    averageWaiting /= count;
    cout << "Average Waiting Time: " << averageWaiting << endl;
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
            if (procPrior[j].arrival > procPrior[j + 1].arrival)
            {

                Process temp = procPrior[j];
                procPrior[j] = procPrior[j + 1];
                procPrior[j + 1] = temp;
            }
            else if (procPrior[j].arrival == procPrior[j + 1].arrival)
            {
                if (procPrior[j].priority < procPrior[j + 1].priority)
                {
                    Process temp = procPrior[j];
                    procPrior[j] = procPrior[j + 1];
                    procPrior[j + 1] = temp;
                }
            }
        }
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

int *turnaroundTime(int count, int *completion, Process *procPrior)
{
    int *turn = new int[count];

    for (int i = 0; i < count; i++)
        turn[i] = completion[i] - procPrior[i].arrival;

    return turn;
}

int *waitingTime(int count, int *turnaround, Process *procPrior)
{
    int *waitTime = new int[count];

    for (int i = 0; i < count; i++)
        waitTime[i] = turnaround[i] - procPrior[i].burst;

    return waitTime;
}
