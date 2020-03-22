#include "task4-1.h"

    queue::queue() {
        head = nullptr; //начало
        tail = nullptr; //конец
    }

    queue::queue(queue const & other) {
        head = nullptr;
        tail = nullptr;
        for (node_t * ptr = other.gethead(); ptr; ptr = ptr->next) {
            push(ptr->value);
        }
    }

    void queue:: push(double value) {
        node_t * node = new node_t;
        node->value = value;
        node->next = nullptr;
        if( head == nullptr) {
            head = node;
            tail = node;
        }
        else {
            tail->next = node;
            tail = node;
        }
        size++;
    }

    int queue:: getsize()
    {
        return size;
    }

    void queue:: clear() {
        while (head != nullptr) {
            node_t * ptr = head->next;
            delete head;
            head = ptr;
            size--;
        }
    }

    void queue:: extraction() {
        if (head != nullptr) {
            node_t * ptr = head->next;
            delete head;
            head = ptr;
            size--;
        }
        else throw std::out_of_range("Out of range");
    }

    void queue:: print(std::ostream & stream) {
        if(head != nullptr) {
            node_t *ptr = head;
            if (ptr != nullptr) {
                while (ptr->next != nullptr) {
                    stream << ptr->value << "  ";
                    ptr = ptr->next;
                }
                if (tail != nullptr) {
                    stream << tail->value << "  ";
                }
            }
        }
        else stream << "nothing";
    }

    queue::~queue()
    {
        while (head) {
            node_t * temp = head;
            head = head->next;
            delete temp;
        }
    }