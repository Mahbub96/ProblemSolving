#include <iostream>
#include <vector>

using namespace std;

class Inputs
{
public:
    int processName;
    int arivalTime;
    int burstTime;
};

/* using global varibales for easily access */
int times = 0;
vector<int> readyQueue;
vector<int> output;

void Waitting_time()
{
}
void Turned_around_time()
{
}
void printOutput(Inputs *inp, int n)
{
    int waittingTimeRecords[n];

    int len = output.size();
    cout << " Gantt chart : " << endl;
    cout << "|";
    for (size_t i = 0; i < len; i++)
    {
        if (output.at(i) != -1)
        {
            cout << " P" << output.at(i) + 1 << " |";
        }
        else
            cout << "    |";
    }
    cout << "\n-";
    for (size_t i = 0; i < len * 5; i++)
    {
        cout << "-";
    }
    cout << "\n0";
    for (size_t i = 0; i < len; i++)
    {
        if (i < 10)
            cout << "    " << i + 1;
        else if (i > 0)
            cout << "   " << i + 1;
        else if (i > 99)
            cout << "  " << i + 1;
    }
    cout << endl;

    Waitting_time();
    Turned_around_time();
}
void updateRQ(Inputs *inp, int s)
{
    for (size_t i = 0; i < s; i++)
    {
        if (inp[i].arivalTime <= times && inp[i].burstTime > 0)
        {
            readyQueue.push_back(i);
        }
    }
}
void reduceBT(Inputs *inp, int s)
{
    int min = 99999999; /* looks like inf */
    int len = readyQueue.size();
    int tempIndex = -1;
    for (size_t i = 0; i < len; i++)
    {
        if (inp[readyQueue[i]].burstTime < min && inp[readyQueue[i]].burstTime > 0)
        {
            min = inp[readyQueue[i]].burstTime;
            tempIndex = readyQueue[i];
        }
    }

    output.push_back(tempIndex); /* getting ready for making gantt chart */

    /* reduce Burst times */
    if (tempIndex > -1)
    {
        inp[tempIndex].burstTime -= 1;
    }
}
bool isFinish(Inputs *inp, int s)
{
    for (size_t i = 0; i < s; i++)
    {
        if (inp[i].burstTime > 0)
            return false;
    }
    return true;
}
void SJF(Inputs *inp, int s)
{
    if (isFinish(inp, s))
    {
        return;
    }
    /* check times and update Ready Queue */
    updateRQ(inp, s);
    /* check and reduce Burst time */
    reduceBT(inp, s);

    if (readyQueue.size()) /* if ready queue is not empty */
        readyQueue.clear();

    ++times;
    SJF(inp, s);
}

int main()
{
    int bt, at, pn;
    cout << "how many process : ";
    cin >> pn;

    Inputs inp[pn], tmpInp[pn];
    for (size_t i = 0; i < pn; i++)
    {
        inp[i].processName = i + 1;
        cout << "Enter Arival Time for Process " << i + 1 << " : ";
        cin >> tmpInp[i].arivalTime;
        inp[i].arivalTime = tmpInp[i].arivalTime;

        cout << "Enter Burst Time for Process " << i + 1 << " : ";
        cin >> tmpInp[i].burstTime;
        inp[i].burstTime = tmpInp[i].burstTime;
    }

    SJF(tmpInp, pn);
    printOutput(inp, pn);

    return 0;
}
