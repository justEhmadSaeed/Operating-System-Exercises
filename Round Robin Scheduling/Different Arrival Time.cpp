#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int i, count, time, remain, temps = 0, time_quantum;

    int waitingTime = 0, turnaround = 0;

    cout << "Enter the total number of process=" << endl;
    cin >> count;

    remain = count;

    // assigning the number of process to remain variable

    vector<int> arrivalTime(count);
    vector<int> burstTime(count);
    vector<int> rt(count);

    for (i = 0; i < count; i++)
    {
        cout << "Enter the Arrival time: ";
        cin >> arrivalTime[i];
        
        cout << " Burst time: ";
        cin >> burstTime[i];
        rt[i] = burstTime[i];
    }

    cout << "Enter the value of time QUANTUM:" << endl;
    cin >> time_quantum;

    for (time = 0, i = 0; remain != 0;)
    {
        if (rt[i] <= time_quantum && rt[i] > 0)
        {
            time += rt[i];
            rt[i] = 0;
            temps = 1;
        }

        else if (rt[i] > 0)
        {
            rt[i] -= time_quantum;
            time += time_quantum;
        }

        if (rt[i] == 0 && temps == 1)
        {
            remain--;
            cout << "Process " << i + 1 << "  Turnaround Time: " << time - arrivalTime[i] << "  Waiting Time: " << time - arrivalTime[i] - burstTime[i] << endl;

            waitingTime += time - arrivalTime[i] - burstTime[i];
            turnaround += time - arrivalTime[i];
            temps = 0;
        }

        if (i == count - 1)
            i = 0;
        else if (arrivalTime[i + 1] <= time)
            i++;
        else
            i = 0;
    }

    cout << "Average waiting time " << waitingTime * 1.0 / count << endl;
    cout << "Average turn around time " << turnaround * 1.0 / count << endl;
    ;

    return 0;
}