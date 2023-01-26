#include <iostream>
#include "header.h"

using namespace std;


/**
 * frontMenu - a function that gets displayed first when the program is run
 * Return: nothing
 */
void frontMenu()
{
    cout << "Welcome to coffee shop" << endl;

    cout << endl;
    cout << "\t1. Place an order" << endl;
    cout << "\t2. Collect order" << endl;
    cout << "\t3. Track order" << endl;
    cout << "\t9. Admin" << endl;
    cout << "\t0. Exit" << endl;
    cout << endl << "Choice: ";
}


/**
 * newOrder - a function that takes new orders
 * Return: nothing
 */
void newOrder()
{
    string n;
    int id = calculateNewID(), r;

    cout << "Enter your name: ";
    cin >> n;

    system("cls");

    cout << "Welcome " << n << endl << endl;

    placeOrder(id);

    do
    {
        r = receipt(id);

        switch(r)
        {
        case 1:
            finalizeOrder(id, n);
            break;
        case 2:
            system("cls");
            editOrder(id);
            break;
        case 3:
            removeOrder(id);
            break;
        }
    }while(r == 2);

}


/**
 * placeOrder - a function that allows user to place an order
 * @id: the identification number of an individual
 * Return: nothing
 */
void placeOrder(int id)
{
    int i, c, q;
    bool newOrd = true;
    char x;

    c = displayMenu(1);
    do{
        cout << endl << "Enter order: ";
        do{
            cin >> i;
            if (i < 1 || i > c)
                cout << "Invalid choice. Enter again: ";
        }while (i < 1 || i > c);

        cout <<"Quantity: ";
        do{
            cin >> q;
            if (q < 0 || q > 50)
                cout << "Invalid choice. Enter again: ";
        }while (q < 0 || q > 50);

        //checks if item has been chosen before and increments value if it did
        newOrd = updateOrder(id, i, q, newOrd);

        //if item has not been chosen earlier
        if (newOrd)
            insertOrder(id, i, q);

        do{
            cout << "Do you wanna add an order(y/n): ";
            cin >> x;
            if (x != 'n' && x != 'y' && x != 'N' && x != 'Y')
                cout << "Invalid choice. Enter again" << endl;
        }while(x != 'n' && x != 'y' && x != 'N' && x != 'Y');

    }while(x == 'y' || x == 'Y');
    system("cls");
}


/**
 * insertOrder - retrieves item orders and adds them to the double linked list
 * @id: the identification number of the individual
 * @i: the value assigned to the item
 * Return: nothing
 */
void insertOrder(int id, int i, int q)
{
    menu *p = mHead;

    while(p)
    {
        singleOrder *s = new singleOrder();
        if (i == p->value)
        {
            s->id = id;
            s->value = p->value;
            s->item = p->item;
            s->quantity = q;
            s->price = p->price * s->quantity;
            s->time = p->time;
           if (head == NULL || tail == NULL)
           {
                head = s;
                tail = s;
                s->prev = NULL;
                s->next = NULL;
           }
           else
           {
                tail->next = s;
                s->prev = tail;
                s->next = NULL;
                tail = s;
           }
           break;
        }
        else
            p = p->next;
    };
}


/**
 * updateOrder - checks if item has been ordered before and if so increments
 * @id: the identification number of the individual
 * @i: the value assigned to the item
 * @q: quantity of the item
 * @newOrd: a variable to set if item has been found
 * Return: the status of the item
 */
bool updateOrder(int id, int i, int q, bool newOrd)
{
    singleOrder *a = head;

    while(a)
    {
        if (a->value == i && a->id == id)
        {
            int p = a->price / a->quantity;
            a->quantity = a->quantity + q;
            a->price = p * a->quantity;
            newOrd = false;
            break;
        }
        a = a->next;
    };
    return newOrd;
}


/**
 * removeOrder - a function that removes all items ordered by the individual
 * @id: the identification number of an individual
 * Return: nothing
 */
void removeOrder(int id)
{
    singleOrder *s = tail;
        while(s && s->id == id)
        {
            tail = s->prev;
            s->prev->next = NULL;
            delete s;
        }
        cout <<"Transaction canceled\n";
}


/**
 * finalizeOrder - adds all orders made by an individual into the queue
 * @id: the identification number of an individual
 * @n: name of the individual
 * Return: nothing
 */
void finalizeOrder(int id, string n)
{
    int totI = 0, totQ = 0, totP = 0, totT = 0;

    // accessing all items ordered by the individual
    singleOrder *m = head;
    while(m)
    {
        if(id == m->id)
        {
            totI += 1;
            totQ += m->quantity;
            totP += m->price;
            totT += m->time;
        }
        m = m->next;
    }

    //adding the properties to the queue
    allOrders *z = new allOrders();
    z->id = id;
    z->name = n;
    z->itemcount = totI;
    z->totalquantity =totQ;
    z->totalprice = totP;
    z->totaltime = totT;
    z->next = NULL;

    if(!fr)
        fr = re = z;
    else
    {
        re->next = z;
        re = z;
    }
    cout << endl << "Payment confirmed. Thank you for ordering." << endl << endl;
}


/**
 * editOrder - a function that allows user to edit order before confirmation
 * @id: the identification number of an individual
 * Return: nothing
 */
void editOrder(int id)
{
    int n, q, c, z;

    do
    {
        c = showItemsOrdered(id);

        cout << endl;
        cout << "1. Add a new item." << endl;
        cout << "2. Update an ordered item." << endl;
        cout << "3. Remove an item." << endl;
        cout << "0. Finish" << endl;
        cout << "Choice: ";

        do
        {
            cin >> n;
            if (n < 0 || n > 3)
                cout << "Invalid input. Enter again: ";
        }while(n < 0 || n > 3);

        switch(n){
        case 1:
            placeOrder(id);
            break;

        case 2:
            cout << "Enter number assigned to your order: ";
            do
            {
                cin >> q;
                if (q < 1 || q > c)
                    cout << "Invalid input. Enter again: ";
            }while(q < 1 || q > c);

            z = findItemValue(id, q);
            updateSingleOrder(id, z);
            break;

        case 3:
            cout << "Enter number assigned to your order: ";
            do
            {
                cin >> q;
                if (q < 1 || q > c)
                    cout << "Invalid input. Enter again: ";
            }while(q < 1 || q > c);

            z = findItemValue(id, q);
            removeSingleOrder(id, z);
            break;
        }

        system("cls");

    }while (n != 0);
}


/**
 * updateSingleOrder - a function that edits an item previously ordered
 * @id: the identification number of an individual
 * @i: the value assigned to the item
 * Return: nothing
 */
void updateSingleOrder(int id, int i)
{
    int q, p;
    singleOrder *s = tail;

    while(s)
    {
        if (s->id == id && s->value == i)
        {
            cout << "Item: " << s->item << endl;
            cout << "Quantity: " << s->quantity << endl;
            cout << "Enter new quantity: ";
            cin >> q;
            p = s->price / s->quantity;
            s->quantity = q;
            s->price = p * s->quantity;

            break;
        }
        s = s->prev;
    }
}


/**
 * removeSingleOrder - a function that removes an item previously ordered
 * @id: the identification number of an individual
 * @i: the value assigned to the item
 * Return: nothing
 */
void removeSingleOrder(int id, int i)
{
    singleOrder *s = tail, *temp;

    while(s)
    {
        if (s->id == id && s->value == i)
        {
            temp = s;
            if (head == s)
                head = s->next;
            else
            {
                if (s->next)
                    s->next->prev = s->prev;
                if (s->prev)
                    s->prev->next = s->next;
            }
            delete temp;
            break;
        }
        s = s->prev;
    }
}


/**
 * showItemsOrdered - a function that displays all items ordered by the individual
 * @id: the identification number of an individual
 * Return: total count of items
 */
int showItemsOrdered(int id)
{
    int c = 1;

    cout << "Your current orders..." << endl;
    cout << "No\tOrder\t\t\tQuantity" << endl;

    singleOrder *s = tail;
    if (!s)
        c = 0;

    while(s && s->id == id)
    {
        cout <<  c << "\t" << s->item << "\t\t" << s->quantity << endl;
        s = s->prev;
        c++;
    }

    return c;
}


/**
 * findItemValue - a function that finds item value from order
 * @id: the identification number of an individual
 * @i: the value assigned to the order
 * Return: total count of items
 */
int findItemValue(int id, int i)
{
    int c = 1, val;

    singleOrder *s = tail;
    while(s && s->id == id)
    {
        if (c == i)
        {
            val = s->value;
            break;
        }
        s = s->prev;
        c++;
    }
    return val;
}

/**
 * displayAllOrders - a function that displays all pending orders in queue
 * Return: nothing
 */

void displayAllOrders()
{
    allOrders *a = fr;
    while(a)
    {
        cout << "ID: " << a->id << endl;
        cout << "Items\t\tQuantity" << endl;
        singleOrder *s = head;
        while(s)
        {
            if (s->id == a->id)
                cout << s->item << "\t" << s->quantity << endl;
            s = s->next;
        }
        cout << endl << endl;
        a = a->next;
    }
    if (!a)
        cout << "No orders have been placed yet..." << endl;
}
