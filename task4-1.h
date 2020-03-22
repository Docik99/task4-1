#include <iostream>
#include <sstream>
#include <string>

class queue {
public:
    struct node_t {
        node_t * next;
        double value;
        int size;
    };
    node_t * head;
    node_t * tail;
    int size = 0;


    node_t * gethead() const
    {
        return  head;
    }
    node_t * gettail() const
    {
        return  tail;
    }

    queue();
    queue(queue const & other);
    void push(double value);
    int getsize();
    void clear();
    void extraction();
    void print(std::ostream & stream);
    ~queue();
};