#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

using namespace std;
#include <string>

/**
 * struct menu - singly linked list
 * @value: designated number to an item
 * @item: name of an item
 * @price: price of an item
 * @time: time taken to prepare the item
 * @next: points to the next node
 */
struct menu
{
    int value;
    string item;
    int price;
    int time;
    menu *next;
}*mHead = NULL;


/**
 * struct singleOrder - doubly linked list
 * @id: designated number to an individual
 * @value: designated number to an item
 * @item: name of an item
 * @quantity: amount of item ordered
 * @price: total price of the item
 * @time: total time taken to prepare the item
 * @prev: points to the previous node
 * @next: points to the next node
 */
struct singleOrder
{
    int id;
    int value;
    string item;
    int quantity;
    int price;
    int time;
    singleOrder *prev;
    singleOrder *next;
}*head = NULL, *tail = NULL;


/**
 * struct allOrders - queue
 * @id: designated number to an individual
 * @name: name of the individual
 * @itemcount: number of items ordered
 * @totalquantity: amount of all items ordered
 * @totalprice: total time calculated for all items
 * @totaltime: total time calculated for all items
 * @next: points to the next node
 */
struct allOrders
{
    int id;
    string name;
    int itemcount;
    int totalquantity;
    int totalprice;
    int totaltime;
    allOrders *next;
}*fr = NULL, *re = NULL;


void populateMenu();
int displayMenu(int i);
void alterMenu();
void addItem();
void updateItem();
void deleteItem();

void frontMenu();
bool updateOrder(int id, int i, int q, bool newOrd);
void insertOrder(int id, int i, int q);
void finalizeOrder(int id, string n);
void removeOrder(int id);
void removeSingleOrder(int id, int i);
void updateSingleOrder(int id, int i);
int showItemsOrdered(int id);
int findItemValue(int id, int i);
void editOrder(int id);
void newOrder();
void placeOrder(int id);
void displayAllOrders();

void timeCalculate(int seconds);
int calculateNewID();
int receipt(int id);

void collectOrder();
void trackingOrder();


#endif // HEADER_H_INCLUDED
