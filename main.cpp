#include "task4-1.h"
using namespace std;

int main()
{
    queue list;
    list.push(3);
    list.push(45);
    list.push(2);
    list.push(1);
    list.print(cout);
    cout << endl << "size" << list.getsize();
    list.extraction();
    cout << endl;
    list.print(cout);
    list.clear();
    cout << endl;
    list.print(cout);
    cout << endl << "size" << list.getsize();
}
