#include <iostream>
#include "header.h"

using namespace std;


/**
 * receipt - displays receipt of all items ordered
 * @id: the identification number of an individual
 * Return: customers choice for order proceeding... idk
 */
int receipt(int id)
{
    int totalPrice = 0, choice, z;
    do
    {
        singleOrder *n = head;
        cout << "Items selected\t\tQuantity\tPrice" << endl;
        while(n)
        {
            if (n->id == id)
            {
                cout << n->item << "\t\t" << n->quantity << "\t\t" << n->price << endl;
                totalPrice += n->price;
            }
            n = n->next;
        }

        cout << endl << "\t\t\tTotal Price:     " << totalPrice << endl << endl;

        cout << "1. Accept and proceed to payment" << endl;
        cout << "2. Edit order" << endl;
        cout << "3. Cancel" << endl;

        cout << "Please select an option: ";
        do{
            cin >> choice;
            if (choice < 1 || choice > 3)
                cout << endl << "Invalid choice. Please reenter: ";
        }while(choice < 1 || choice > 3);
    }while(choice == 0);
    return choice;
}


/**
 * timeCalculate - a function that takes seconds and converts to correct format
 * return: nothing
 */
void timeCalculate(int seconds)
{
    int h, m, s;

    if (seconds < 60)
        cout << seconds << " seconds." << endl;

    else if (seconds < 3600)
    {
        m = seconds / 60;
        s = seconds % 60;
        if (m == 1)
            cout << m << " minute and " << s << " seconds." << endl;
        else
            cout << m << " minutes and " << s << " seconds." << endl;
    }
    else
    {
        h = seconds / 3600;
        m = h / 60;
        s = h % 60;
        if (h == 1)
        {
            if (m == 1)
                cout << h << " hour, " << m << " minute and " << s << " seconds."<< endl;
            else
                cout << h << " hour, " << m << " minutes and " << s << " seconds."<< endl;
        }
        else
        {
            if (m == 1)
                cout << h << " hours, " << m << " minute and " << s << " seconds."<< endl;
            else
                cout << h << " hours, " << m << " minutes and " << s << " seconds."<< endl;
        }

    }
}


/**
 * calculateNewID - a function that generates new id by checking queue
 * Return: the new id
 */
int calculateNewID()
{
    int id;
    if (!fr)
        id = 1000;
    else
        id = re->id + 1;
    return id;
}
