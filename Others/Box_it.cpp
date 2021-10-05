#include <bits/stdc++.h>

using namespace std;

//Implement the class Box
//l,b,h are integers representing the dimensions of the box
class Box
{
    long int length, bredth, height;

public:
    // The class should have the following functions :

    // Constructors:
    // Box();
    Box()
    {
        height = 0;
        length = 0;
        bredth = 0;
    }
    // Box(int,int,int);
    Box(int l, int b, int h)
    {
        this->length = l;
        this->bredth = b;
        this->height = h;
    }
    // Box(Box);
    Box(Box &b)
    {
        this->length = b.length;
        this->bredth = b.bredth;
        this->height = b.height;
    }
    // int getLength(); // Return box's length
    int getLength() { return length; }
    // int getBreadth (); // Return box's breadth
    int getBreadth() { return bredth; }
    // int getHeight ();  //Return box's height
    int getHeight() { return height; }
    // long long CalculateVolume(); // Return the volume of the box
    long long int CalculateVolume() { return this->height * this->bredth * this->length; }

    //Overload operator < as specified
    //bool operator<(Box& b)
    bool operator<(Box &b)
    {
        if (this->length < b.length)
            return true;
        else if (this->bredth < b.bredth && this->length == b.length)
            return true;
        else if (this->height < b.height && this->bredth == b.bredth && this->length == b.length)
            return true;
        else
            return false;
    }
};

//Overload operator << as specified
ostream &operator<<(ostream &out, Box &B)
{
    // out << B.getHeight
    out << B.getLength() << " " << B.getBreadth() << " " << B.getHeight();
    return out;
}
void check2()
{
    int n;
    cin >> n;
    Box temp;
    for (int i = 0; i < n; i++)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            cout << temp << endl;
        }
        if (type == 2)
        {
            int l, b, h;
            cin >> l >> b >> h;
            Box NewBox(l, b, h);
            temp = NewBox;
            cout << temp << endl;
        }
        if (type == 3)
        {
            int l, b, h;
            cin >> l >> b >> h;
            Box NewBox(l, b, h);
            if (NewBox < temp)
            {
                cout << "Lesser\n";
            }
            else
            {
                cout << "Greater\n";
            }
        }
        if (type == 4)
        {
            cout << temp.CalculateVolume() << endl;
        }
        if (type == 5)
        {
            Box NewBox(temp);
            cout << NewBox << endl;
        }
    }
}

int main()
{
    check2();
}