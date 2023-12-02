# Prog2_Project
Project developed for the Programming 2 course at the University of Catania (UNICT).

# QUERY:
## Order Processing Program
The 'Orders.txt' file contains information about orders placed in a pizzeria in the following format:

LAST_NAME_CUSTOMER, PIZZA,QUANTITY, UNIT_PRICE

The fields LAST_NAME_CUSTOMER and PIZZA are of textual type, the QUANTITY field is an integer, and the UNIT_PRICE is a decimal number. It is assumed that there are no repetitions in last names.

The candidate is required to write a C++ program that, using appropriate data structures, can:

Load the information from the file.

Group the orders by customer.

Find all orders for a given customer, print them on the screen, and calculate the total spent.

Remove customers from orders who have spent less than the average. (BONUS: Save them to a file.)

BONUS: Compile a ranking of the most sold pizzas.

Provide a main function that successfully executes the required methods outlined above.

Additionally, include a concise PDF document explaining the design choices, justifying decisions related to data structures and algorithms.

NB: The project will be compiled and executed using the g++ command. Sophisticated implementations or compilations managed by external IDEs will require the student to demonstrate equivalent proficiency in using g++.

## Design Choices
## Data Structure Used: List
The use of the List data structure is essential due to the need for a dynamic data structure to allocate objects from the 'Orders.txt' file. The necessity to compare multiple elements suggests the overload of comparison operators.

## Libraries Used:
**< iostream >** : Library for using objects like **cout**, **cin**, etc.

**< fstream >** : For **reading** the txt file and **writing** the "Deleted Customers" **file**.

**< string >** : Library for using **string variables**.

**< sstream >** : Library for **string streams**.

## File Headers:
Cliente.h
ListaDL.h

## File Implementations:
Cliente.cpp
ListaDL.cpp
main.cpp

The choice of creating ListaDL.cpp and Cliente.cpp files was arbitrary and to maintain a specific order in writing. The alternative was to declare and implement the class directly within the header.

## Used Classes:
Cliente.h and Cliente.cpp
ListaDL.h and ListaDL.cpp

In the Cliente.h class, I initialized the entire client class by passing the parameters of the orders (Last Name, Pizza, Quantity, Price) and declared the class methods. In Cliente.cpp, I implemented the methods contained in the header file.

In the ListaDL.h class, I initialized a doubly linked list with all its methods (insertion, search, removal). In ListaDL.cpp, I implemented the methods contained in the header file.
