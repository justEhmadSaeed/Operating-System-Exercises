#include <iostream>
#include <iomanip>

using namespace std;

struct Block
{
    int bid;
    int size;
};
struct Process
{
    int pid;
    int size;
    int bid;
};

void FIRST_FIT(Process *proc, int Pcount, Block *block, int Bcount);

int main()
{
    int Pcount;
    cout << "Enter number of Processes:";
    cin >> Pcount;
    Process *proc = new Process[Pcount];
    cout << "Enter the size of each Process: \n";

    for (int i = 0; i < Pcount; i++)
    {
        proc[i].pid = i + 1;
        proc[i].bid = -1;
        cout << "Process " << i + 1 << " :" << endl;
        cin >> proc[i].size;
    }

    int Bcount;
    cout << "Enter number of Blocks:";
    cin >> Bcount;
    Block *block = new Block[Bcount];
    cout << "Enter the size of each Block: \n";

    for (int i = 0; i < Bcount; i++)
    {
        block[i].bid = i + 1;
        cout << "Block " << i + 1 << " :" << endl;
        cin >> block[i].size;
    }

    // First Fit Call
    FIRST_FIT(proc, Pcount, block, Bcount);

    // Printing the Output
    cout << "\nProcess ID" << setw(15) << right << "Process Size" << setw(15) << right << "Block ID" << endl
         << endl;
    for (int i = 0; i < Pcount; i++)
    {

        cout << proc[i].pid << setw(15) << right << proc[i].size << setw(15) << right;
        if (proc[i].bid != -1)
            cout << proc[i].bid << endl;
        else
            cout << "Not Allocated" << endl;
    }
    return 0;
}

void FIRST_FIT(Process *proc, int Pcount, Block *block, int Bcount)
{
    // First Fit Algorithm Implementation

    for (int i = 0; i < Pcount; i++)
    {
        for (int j = 0; j < Bcount; j++)
        {
            if (block[j].size >= proc[i].size)
            {
                proc[i].bid = block[j].bid;
                block[j].size -= proc[i].size;
                break;
            }
        }
    }
}
