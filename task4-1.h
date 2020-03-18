#include <iostream>
#include <sstream>
#include <string>

class queue {
private:
    struct node_t {
        node_t * next;
        node_t *head;
        node_t *tail;
        double value;
        int size;
    };
    node_t * head;
    node_t * tail;
    int size = 0;

public:
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
    void operator =(queue const & other);
    void push(double value);
    int getsize();
    void clear();
    void extraction();
    void print(std::ostream & stream);
    ~queue();
};