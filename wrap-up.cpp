#include <iostream>
#include "header.h"

using namespace std;


/**
 * collectOrder - a function that allows user who is first to collect their order
 * Return: nothing
 */
void collectOrder()
{
    string name;
    int id;

    if (fr)
    {
        cout << "Enter your name: ";
        cin >> name;
        if (fr->name == name)
        {
            singleOrder *s = head;
            cout << "Displaying your orders..." << endl;
            cout << "Items\t\t\tQuantity" << endl;
            id = fr->id;

            while (s)
            {
                if (id == s->id)
                    cout << s->item << "\t\t" << s->quantity << endl;
                s = s->next;
            }
            cout << endl << "Thank you for coming... Please come again..." << endl;

            allOrders *m = fr;
            fr = fr->next;
            delete m;

            singleOrder *p = head;
            while (p && p->id == id)
            {
                singleOrder *temp = p;
                p = p->next;
                head = p;
                delete temp;
            }
        }
        else
        {
            bool isthere = false;

            allOrders *x = fr;
            while(x)
            {
                if(x->name == name)
                {
                    isthere = true;
                    break;
                }
                x = x->next;
            }

            if(isthere)
                cout << "Your order is not done." << endl;
            else
                cout << "Name not in system." << endl;
        }


    }
    else
        cout << "No orders have been placed yet." << endl << endl;
}


/**
 * trackingOrder - a function that allows user to track their order
 * Return: nothing
 */
void trackingOrder()
{
    string name;
    int c = 0, time = 0;
    bool isthere = false;

    if (fr)
    {
        cout << "Enter your name: ";
        cin >> name;

        allOrders *f = fr;
        while(f)
        {
            if (f->name == name)
            {
                isthere = true;
                break;
            }
            c++;
            time = time + f->totaltime;
            f = f->next;
        }
        if (isthere == false)
            cout << "Name not in system." << endl;
        else
        {
            if (c == 0)
                cout << endl << "Your order is done. Please collect at the front desk" << endl;
            else if (c == 1)
            {
                cout << endl << "Your order is currently being prepared. Wait time is approximately ";
                timeCalculate(fr->next->totaltime);
            }

            else
            {
                cout << endl << "Number of people before you: "<< c << endl;
                cout << "Approximate time that'll take: ";
                timeCalculate(time);
            }
        }
    }
    else
        cout << "No orders have been placed yet." << endl << endl;
}
