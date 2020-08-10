#include <iostream>
using namespace std;

int main()
{
    // P0, P1, P2, P3, P4 are the Process names here

    int pCount, rCount, i, j;
    cout << "Enter the number of Processes:\n";
    cin >> pCount;

    cout << "Enter the number of Resources:\n";
    cin >> rCount;

    /* ======= ALLOCATION of each Resource to each Process ====== */

    int **allocate = new int *[pCount];

    cout << "Enter the Allocation Matrix: \n";

    for (i = 0; i < pCount; i++)
    {
        cout << "P" << i + 1 << ": ";
        allocate[i] = new int[rCount];
        for (j = 0; j < rCount; j++)
            cin >> allocate[i][j];
    }

    /* ======= MAXIMUM Resources required to each Process for each Resource ====== */

    int **max = new int *[pCount];

    cout << "Enter the Maximum Matrix: \n";

    for (i = 0; i < pCount; i++)
    {
        cout << "P" << i + 1 << ": ";
        max[i] = new int[rCount];
        for (j = 0; j < rCount; j++)
            cin >> max[i][j];
    }

    /* ======= Availability of the Resources ====== */

    int *available = new int[rCount];

    cout << "Enter the Available Resources: \n";

    for (i = 0; i < rCount; i++)
        cin >> available[i];

    int *finish = new int[pCount], *sequence = new int[pCount];

    for (i = 0; i < pCount; i++)
        finish[i] = 0;

    /* ======= NEED of the Resources for each Process to each Resources ====== */
    int **need = new int *[pCount];
    for (i = 0; i < pCount; i++)
    {
        need[i] = new int[rCount];
        for (j = 0; j < rCount; j++)
            need[i][j] = max[i][j] - allocate[i][j];
    }

    int k, y = 0, index = 0;

    for (k = 0; k < 5; k++)
    {
        for (i = 0; i < pCount; i++)
        {
            if (finish[i] == 0)
            {

                int flag = 0;
                for (j = 0; j < rCount; j++)
                {
                    if (need[i][j] > available[j])
                    {
                        flag = 1;
                        break;
                    }
                }

                if (flag == 0)
                {
                    sequence[index++] = i;
                    for (y = 0; y < rCount; y++)
                        available[y] += allocate[i][y];
                    finish[i] = 1;
                }
            }
        }
    }

    cout << "\n\nThe SAFE Sequence will be as follows:" << endl
         << endl;
    for (i = 0; i < pCount; i++)
        cout << i + 1 << ": P" << sequence[i] << endl;

    return (0);
}
