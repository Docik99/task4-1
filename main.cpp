#include "task4-1.h"
using namespace std;

int main()
{
    /*queue list;
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
    cout << endl << "size" << list.getsize();*/
    queue queue2;
    for (int i = 1; i < 100; ++i) {
        queue2.push(1 + rand() % 100);
    }
    queue queue1(queue2);
    while (queue1.head != nullptr) {
        queue1.head = queue1.head->next;

        queue2.head = queue2.head->next;

        cout << queue1.head->value << " " << queue2.head->value << endl;
    }
}
