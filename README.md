# Coffee Shop Project

This project is a simple coffee shop simulation built using **C++**, featuring data structures such as **single linked lists**, **double linked lists**, and a **queue** (implemented using a linked list). The project mimics the process of taking customer orders and assigning them a place in a queue.

## Project Description

This CLI-based coffee shop simulation allows customers to place orders, which are then added to a queue. The shop processes these orders in the sequence they are received, simulating a real-world coffee shop scenario. The project demonstrates the practical use of linked lists for managing customer orders and a queue for processing them efficiently.

## Features

- **Single Linked List**: Used for handling customer data and other relevant operations.
- **Double Linked List**: Provides flexibility for navigating through the list in both directions.
- **Queue (Linked List)**: Manages customer orders by placing them in a queue, processed in a first-come, first-served order.
- **Menu-Driven Interface**: Users can navigate through various options in the coffee shop through a menu system.

## Data Structures

- **Single Linked List**: Implements a basic linked list where each node points to the next node.
- **Double Linked List**: Extends the single linked list with the ability to navigate forward and backward.
- **Queue**: A linear structure that uses the linked list implementation to manage orders. The first customer in is the first customer served (FIFO).

## Menu System

The program features an interactive menu-driven system, allowing the user to perform various actions:

1. **New Order**: Adds a customer's new order to the queue.
2. **Collect Order**: Processes the next order in the queue.
3. **Tracking Order**: Tracks the status of current orders in the system.
9. **Alter Menu**: Modify the menu items for the coffee shop.
0. **Exit**: Ends the simulation with a friendly goodbye message.

Each action is executed via a switch-case structure, making the program's flow easy to follow.

## Installation

To run this project, you need a C++ compiler installed. Follow these steps to install and compile the project:

1. Clone the repository:
   ```bash
   git clone https://github.com/Yordi-Dereje/coffee-shop-project.git
   ```
   
2. Navigate to the project directory:
   ```bash
   cd coffee-shop-project
   ```

4. Compile the program:
   ```bash
   g++ main.cpp -o coffee_shop
   ```

5. Run the executable:
   ```bash
   ./coffee_shop
   ```

## Usage

Once the program is running, a menu will be displayed where the user can choose options to manage orders:

- **New Order**: Start by adding a new customer's order, which will be placed in the queue.
- **Collect Order**: When the coffee is ready, the next order in line will be collected.
- **Tracking Order**: Check the current status of all orders.
- **Alter Menu**: Make changes to the coffee shop's menu if necessary.
- **Exit**: Choose 0 to exit the program.

Each operation is followed by a pause, and the screen is cleared for a clean display after each action.

## Function Prototypes and Structures

All function prototypes and structures related to the linked lists and queue are defined in the **header file** (`header.h`). This file includes:

- **Structures** for single and double linked lists.
- **Function prototypes** for:
  - `newOrder()`: Adds a new order to the queue.
  - `collectOrder()`: Processes the next order.
  - `trackingOrder()`: Displays the status of orders.
  - `alterMenu()`: Modifies the coffee shop's menu.
