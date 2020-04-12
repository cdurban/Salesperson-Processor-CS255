# COMPSCI255-Project7
This is my solution to Project 7. This project takes an input file, “sales.txt”, and processes it. The file contains multiple 
yearly sales reports for multiple different salespeople.

In order to be able to process this data, I am using a Salesperson object. This object holds id, first and last name, and an 
OrderedList holding sales data.

As it traverses through the data, it decides if this is a new salesperson, or if this salesperson already exists. If this person 
already exists, the OrderedList is added onto the existing salesperson’s list. If not, a new Salesperson object is created, and 
the data is added.

Once the entire list has been traverses, the program prompts the user to enter the number of largest sales to be displayed for 
each salesperson. It will output the top highest sales, and if the salesperson has fewer than the requested number of sales, 
it will output all of that salesperson’s sales.

This Project uses an OrderedList<>, created by myself for Project 6
