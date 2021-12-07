#include <iostream>
#include <vector>

using namespace std;

class Inputs
{
public:
    int ProcessNumber;
    int ArivalTime;
    int BurstTime;
};

int times = 0;
vector<int> readyQueue;
vector<int> output;


void showOutput(){
    int len = output.size();
    cout << "|";
    for (size_t i = 0; i < len; i++)
    {
        cout << " P"<<output.at(i)+1<<" |";
    }
    cout << "\n-";
    for (size_t i = 0; i < len*5; i++)
    {
        cout << "-";
    }
    cout << "\n0";
    for (size_t i = 0; i < len; i++)
    {
        if(i<10) cout <<"    "<<i+1;
        else if(i>0) cout <<"   "<<i+1;
        else if(i>99) cout <<"  "<<i+1;
    }
    cout << endl;
    
    
}

void prepareOutput(int n)
{
    output.push_back(n);
}

void updateRQ(Inputs *inp, int s)
{
    for (size_t i = 0; i < s; i++)
    {
        if (inp[i].ArivalTime <= times && inp[i].BurstTime > 0)
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
        if (inp[readyQueue[i]].BurstTime < min && inp[readyQueue[i]].BurstTime > 0)
        {
            min = inp[readyQueue[i]].BurstTime;
            tempIndex = readyQueue[i];
        }
    }

    /* reduce Burst times */
    if (tempIndex > -1)
    {
        prepareOutput(tempIndex);
        inp[tempIndex].BurstTime -= 1;
    }
}
void SJF(Inputs *inp, int s)
{
    if (readyQueue.size() && times)
    {
        return;
    }
    /* check times and update Ready Queue */
    updateRQ(inp, s);
    /* check and reduce Burst time */
    reduceBT(inp, s);

    if (readyQueue.size()) /* if ready queue is not empty */
    {
        readyQueue.clear();
        ++times;
        SJF(inp, s);
    }
}

int main()
{
    int bt, at, pn;
    cout << "how many process : ";
    cin >> pn;

    Inputs inp[pn];
    for (size_t i = 0; i < pn; i++)
    {
        inp[i].ProcessNumber = i + 1;
        cout << "Enter Arival Time for Process " << i + 1 << " : ";
        cin >> inp[i].ArivalTime;

        cout << "Enter Burst Time for Process " << i + 1 << " : ";
        cin >> inp[i].BurstTime;
    }

    SJF(inp, pn);
    showOutput();
    
    return 0;
}
