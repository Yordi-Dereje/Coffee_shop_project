#include <iostream>
#include "header.h"

using namespace std;


/**
 * populateMenu - a function that populates the menu
 * Return: nothing
 */
void populateMenu()
{
    string itemArr[8] = {"Coffee\t", "Macchiato", "Tea\t", "Double\t", "Espresso", "Latte\t", "Iced Americano", "Frappuccino"};
    int priceArr[8] = {40, 40, 30, 65, 75, 60, 40, 50};
    int timeArr[8] = {30, 45, 20, 60, 45, 60, 30, 45};

    menu *l = NULL, *it;

    menu *it1 = new menu();
    it1->value = 1;
    it1->item = itemArr[0];
    it1->price = priceArr[0];
    it1->time = timeArr[0];
    mHead = it1;
    l = mHead;

    for (int i = 1; i < 8 ; i++)
    {
        it = new menu();
        it->value = i+1;
        it->item = itemArr[i];
        it->price = priceArr[i];
        it->time = timeArr[i];
        l->next = it;
        it->next = NULL;
        l = it;
    }
}


/**
 * alterMenu - a function that contains choices to perform crud operations on the menu
 * Return: nothing
 */
void alterMenu()
{
    int c, p, t, i = 0, num;
    string n;
    char y;

    do
    {
        cout << "\tWelcome" << endl;
        cout << "1. Add an item" << endl;
        cout << "2. Edit an item" << endl;
        cout << "3. Delete an item"  << endl;
        cout << "4. Display menu" << endl;
        cout << "5. Display all orders" << endl;
        cout << "0. Return to main menu" << endl;

        cout << endl << "Choice: ";
        cin >> c;

        system("cls");
        switch(c)
        {
        case 1:
            addItem();
            break;
        case 2:
            updateItem();
            break;
        case 3:
            deleteItem();
            break;
        case 4:
            p = displayMenu(2);
            cout << endl;
            break;
        case 5:
            displayAllOrders();
            cout << endl;
            break;
        case 0:
            break;
        default:
             cout << "Invalid choice. Enter again..." << endl;
             break;
        }
        system("pause");
        system("cls");

    }while(c != 0);
}


/**
 * displayMenu - a function that displays menu items
 * @choice: value passed to choose the properties of items to be displayed
 * Return: the count of the items
 */
int displayMenu(int choice)
{
    int c = 0;
    menu *m = mHead;

    switch(choice)
    {
    case 1: //for customer
        cout << "\tNumber\tItem Name\t\tPrice" << endl << endl;

        while(m)
        {
            cout << "\t" << m->value << "\t" << m->item <<"\t\t" << m->price << endl;
            m = m->next;
            c++;
        }
        break;

    case 2: //for employee
        cout << "\tNumber\tItem Name\t\tPrice\t\tTime" << endl << endl;

        while(m)
        {
            cout << "\t" << m->value << "\t" << m->item << "\t\t" << m->price << "\t\t" << m->time << endl;
            m = m->next;
            c++;
        }
        break;
    }
    return c;
}


/**
 * addItem - a function that adds a new item to the menu
 * Return: nothing
 */
void addItem()
{
    int p, t, i = 2;
    string n;

    cout << "Enter item: ";
    cin >> n;
    if (n.length() < 8)
        n = n + "\t";

    cout << "Enter price: ";
    do
    {
        cin >> p;
        if(p < 0 || p > 500)
            cout << "Invalid format. Enter again: ";
    }while(p < 0 || p > 500);


    cout << "Enter time taken: ";
    do
    {
        cin >> t;
        if(t < 0 || t > 200)
            cout << "Invalid format. Enter again: ";
    }while(t < 0 || t > 200);

    menu *mm = mHead;
    while(mm->next)
    {
        i++;
        mm = mm->next;
    }

    menu *m = new menu();
    m->value = i;
    m->item = n;
    m->price = p;
    m->time = t;
    mm->next=m;
    m->next = NULL;

    cout << "Menu item inserted..." << endl;
}


/**
 * updateItem - a function that edits an item in the menu
 * Return: nothing
 */
void updateItem()
{
    string n;
    int p, t, num, i;

    cout << "Displaying all menu items" << endl;
    i = displayMenu(2);

    cout << endl << "Enter value of the item you'll be editing: ";
    do
    {
        cin >> num;
        if (num < 0 || num > i)
            cout << "Invalid input. Please enter again" << endl;
    }while(num < 0 || num > i);

    menu *m2 = mHead;
    while(m2)
    {
        if (m2->value == num)
        {
            cout << "Item name: " << m2->item << endl;
            cout << "Item price: " << m2->price << endl;
            cout << "Item time: " << m2->time << endl;
            break;
        }
        m2 = m2->next;
    }

    cout << "\nEnter new name: ";
    cin >> n;
    if (n.length() < 8)
        n = n + "\t";

    cout << "Enter new price: ";
    cin >> p;

    cout << "Enter new time: ";
    cin >> t;

    menu *m3 = mHead;
    while(m3)
    {
        if (m3->value == num)
        {
            m3->item = n;
            m3->price = p;
            m3->time = t;
            break;
        }
        m3 = m3->next;
    }

    cout << "Menu item updated..." << endl;
}

/**
 * deleteItem - a function that removes an item from the menu
 * Return: nothing
 */
void deleteItem()
{
    int c, p, t, i = 0, num;
    string n;
    char y;

    i = displayMenu(2);

    cout << endl << "Enter value of the item you'll be removing: ";
    do
    {
        cin >> num;
        if (num < 0 || num > i)
            cout << "Invalid input. Please enter another number\n";
    }while(num < 0 || num > i);

    menu *m2 = mHead;
    while(m2)
    {
        if (m2->value == num)
        {
            cout << "Item name: " << m2->item << endl;
            cout << "Item price: " << m2->price << endl;
            cout << "Item time: " << m2->time << endl;
            break;
        }
        m2 = m2->next;
    }

    cout << "Do you want to remove this item?";
    cin >> y;
    if (y == 'y')
    {
        menu *m3 = mHead;
        menu *pre = NULL;

        while(m3)
        {
            if (m3->value == num)
            {
                menu *temp = m3;
                pre->next = m3->next;
                delete temp;
            }
            else if (m3->value > num)
            {
                m3->value-= 1;
            }
            pre = m3;
            m3 = m3->next;
        }
        cout << "Menu item removed..." << endl;
    }
}
