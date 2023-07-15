#pragma warning(disable:4996)
//#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream> // ifstream + ofstream
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <math.h>
#include <direct.h>
#include <vector>

using namespace std;

class Train {
    int number;
    string time;
    string locate;
public:
    Train(int n,string t,string l):number{n},time{t},locate{l} {}
    Train() :Train(1, "12:00", "Moscow") {}

    int getNum() {
        return number;
    }
    string getTime() {
        return time;
    }
    string getLocate() {
        return locate;
    }

    friend ostream& operator<<(ostream& out, const Train& t1);
};

ostream& operator<<(ostream& out, const Train& t1) {
    out << "Num: " << t1.number << "\nTime: " << t1.time << "\nLocate: " << t1.locate << endl;
    return out;
}
void inputV(vector<Train>& v, int n = 1, string t = "12:00", string l = "Moscow") {
    v.push_back(Train(n,t,l));
}
void outV(vector <Train> v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << endl;
    }
}
void outVT(vector <Train> v,int t) {
    for (int i = 0; i < v.size(); i++) {
        if (v[i].getNum() == t) {
            cout << v[i].getNum() << "\n";
            cout << v[i].getTime() << "\n";
            cout << v[i].getLocate() << "\n";
        }
    }
}
void FilterV(vector<Train>& v) {
    int sum = 0;
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v.size() - 1; j++)
        {
            if (v[j].getNum() > v[j + 1].getNum()) {
                swap(v[j], v[j + 1]);
                sum++;
            }
        }
        if (sum == 0) {
            break;
        }
    }
}

int main()
{
    setlocale(0, "");
    srand(time(nullptr));


    vector<Train> t;

    inputV(t, 200,"12:00","MSK");
    inputV(t, 300, "13:00", "YKT");
    inputV(t, 400, "15:00", "SPB");
    inputV(t, 100, "11:00", "MSK");
    inputV(t, 600, "8:00", "MSK");

    outV(t);

    FilterV(t);
    cout << "------\n";
    outV(t);
    outVT(t,400);
}
