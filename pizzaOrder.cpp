//============================================================================
// Name        : PizzaOrder.cpp
// Author      : Pranav Kharche
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstdlib>
using namespace std;

#define MAX_LIMIT 20

class OrderList {

    struct Queue {
        int que[MAX_LIMIT];
        int rear;
        int front;

    } Q;
    //typedef Queue Q;

    int isQfull() {
        if (Q.front == (Q.rear + 1) % MAX_LIMIT)
            return 1;
        else return 0;
    }

    int isQempty() {
        if (Q.front == -1)
            return 1;
        else
            return 0;
    }

public:

    OrderList() {
        Q.rear = -1;
        Q.front = -1;
    }

    int accept(int);
    int ready();
    void display();

};

int OrderList::accept(int item) {

    {

        if (Q.front == -1) {
            Q.front = 0;
            Q.rear = 0;
            Q.que[Q.rear] = item;
        } else {
            Q.rear = (Q.rear + 1) % MAX_LIMIT;
            Q.que[ Q.rear] = item;
        }
    }

    return Q.rear;

}

int OrderList::ready() {
    int ord;
    ord = Q.que[Q.front];

    cout << "\nOrder " << ord << " is READY!" << endl;
    Q.front = (Q.front + 1) % MAX_LIMIT;

    return ord;

}

void OrderList::display() {
    cout << "\nOrders in List are..."<<endl;
    for (int i = Q.front; i <= Q.rear; i++) {
        cout <<"\t"<< Q.que[i] << endl;
    }
}

int main() {
    OrderList obj;
    int item;
    int ch = 0;
    int nOfOrder;


    do {
        cout << "\n **********Menu**********";
        cout << "\n 1.Accept order";
        cout << "\n 2.Display order list";
        cout << "\n 3.Ready order";
        cout << "\n 4.Exit"<<endl;
        cin>>ch;
        switch (ch) {
            case 1:
                cout << "\n How many orders you want to add : ";
                cin>>nOfOrder;
                for (int i = 0; i < nOfOrder; i++) {
                    cout << "\n Enter order No."<<i+1<<" : ";
                    cin>>item;
                    obj.accept(item);
                }
                break;

            case 2:
                obj.display();
                break;

            case 3:
                obj.ready();
                break;
            default:
                cout << "Exited!";
                exit(EXIT_FAILURE);

        }
    } while (ch != 4);

    exit(EXIT_SUCCESS);
}
