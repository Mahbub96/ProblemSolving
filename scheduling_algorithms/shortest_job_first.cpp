#include <iostream>
#include <vector>

using namespace std;

class Inputs
{
public:
    int processName;
    int arivalTime;
    int burstTime;
    int copyOfBurstTime;

    /* variables for calculating waiting time and turned around time */
    int runningWaittingTime;
    int prevActiveTime;

    Inputs()
    {
        processName = 0;
        arivalTime = 0;
        burstTime = 0;
        copyOfBurstTime = 0;

        runningWaittingTime = 0;
        prevActiveTime = 0;
    }

    void getArivalTime(int t)
    {
        arivalTime = t;
        prevActiveTime = t;
    }
    void getBurstTime(int t)
    {
        burstTime = t;
        copyOfBurstTime = t;
    }
    int waittingTime()
    {
        return runningWaittingTime;
    }
    int turnAroundTime()
    {
        return runningWaittingTime + copyOfBurstTime;
    }
};

/* using global varibales for easily access */
int times = 0;
vector<int> readyQueue;
vector<int> output;

/**
 * @brief This Function is all about printing gantt chart and others tables
 *
 * @param inp array of object for processes
 * @param n length of that particular array of objects
 */
void printOutput(Inputs *inp, int n)
{
    cout << "\n******OUTPUTS******\n"
         << endl;
    int len = output.size();
    cout << "Gantt chart : " << endl;
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
    cout << "Process \t Waiting Time \t Turn Around Time" << endl;
    for (size_t i = 0; i < n; i++)
    {
        cout << "  P" << i + 1 << " \t\t\t" << inp[i].waittingTime() << "\t\t" << inp[i].turnAroundTime() << endl;
    }
}

/**
 * @brief This function will update Ready Queue list and that will command us which process will be executed
 *
 * @param inp array of object for processes
 * @param s length of that particular array of objects
 */
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

/**
 * @brief Reduce Burst time to know how many BT need to complete a job for a perticular process
 *
 * @param inp array of object of process
 * @param s length of this array of objects
 */
void reduceBT(Inputs *inp, int s)
{
    int min = 99999999; /* looks like inf */
    int len = readyQueue.size();
    int tempIndex = -1;
    for (size_t i = 0; i < len; i++)
    {
        if (inp[readyQueue[i]].burstTime < min && inp[readyQueue[i]].burstTime > 0) /*find min burst time from ready state */
        {
            min = inp[readyQueue[i]].burstTime;
            tempIndex = readyQueue[i];
        }
    }

    output.push_back(tempIndex); /* getting queue ready for making gantt chart */

    /* reduce Burst times */
    if (tempIndex > -1)
    {
        /* check waiting time */
        if (inp[tempIndex].prevActiveTime != times && inp[tempIndex].prevActiveTime + 1 != times)
        {
            inp[tempIndex].runningWaittingTime += times - inp[tempIndex].prevActiveTime;
        }

        inp[tempIndex].prevActiveTime = times + 1; /* update active time */

        inp[tempIndex].burstTime -= 1;
    }
}

/**
 * @brief It's a boolean function and it will return either finish or not
 * @param inp array of object for processes
 * @param s length of that particular array of objects
 * @return bool
 */
bool isFinish(Inputs *inp, int s)
{
    for (size_t i = 0; i < s; i++)
    {
        if (inp[i].burstTime > 0)
            return false;
    }
    return true;
}

/**
 * @brief SJF - stands for shortest job first
 * here we need 2 perameters
 *
 * @param inp  input array of objects ,here we have all the informations about current process
 * @param s size(times) of that array of objects
 */
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
    // freopen("input.txt", "r", stdin); /* for input from files */
    int bt, at, pn;
    cout << "how many process : ";
    cin >> pn;

    Inputs inp[pn];
    for (size_t i = 0; i < pn; i++)
    {
        int temp;
        inp[i].processName = i + 1;
        cout << "Enter Arival Time for Process " << i + 1 << " : ";
        cin >> temp;
        inp[i].getArivalTime(temp);

        cout << "Enter Burst Time for Process " << i + 1 << " : ";
        cin >> temp;
        inp[i].getBurstTime(temp);
    }

    SJF(inp, pn); /* sends inputs and process numbers */
    printOutput(inp, pn);

    return 0;
}
