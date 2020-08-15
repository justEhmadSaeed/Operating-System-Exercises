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

void BEST_FIT(Process *proc, int Pcount, Block *block, int Bcount);

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
    // Best Fit Call
    BEST_FIT(proc, Pcount, block, Bcount);

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

void BEST_FIT(Process *proc, int Pcount, Block *block, int Bcount)
{
    // Best Fit Algorithm Implementation

    for (int i = 0; i < Pcount; i++)
    {
        int minBlock = -1;
        for (int j = 0; j < Bcount; j++)
        {
            if (block[j].size >= proc[i].size)
            {
                if (minBlock == -1 || block[minBlock].size > block[j].size)
                    minBlock = j;
            }
        }
        if (minBlock != -1)
        {
            proc[i].bid = block[minBlock].bid;
            block[minBlock].size -= proc[i].size;
        }
    }
}
