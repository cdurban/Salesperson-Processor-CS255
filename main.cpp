/*
 * Project:     Project 7
 * File:        main.cpp
 * Author:      Chase Urban
 * Due:         Tuesday, April 14th, 2020
 * Description: Main function to process a sales input file, and generate a
 *              report with a specified highest number of sales.
 */

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <list>
#include <stack>

#include "Salesperson.h"

using namespace std;

int main(int argc, char** argv) {

    //Opens an ifstream, causes an error if the file cannot be found
    ifstream salesFile;
    salesFile.open("sales.txt");
    if(!salesFile){
        cout << "Unable to open file sales.txt";
        exit(1);
    }
    
    //Initializes the variables for the loop to use
    int year, id, count, sale;
    string first, last;
    OrderedList<int> sales;
    Salesperson person = Salesperson(id, first, last, sales);
    Salesperson match = Salesperson(id, first, last, sales);
    bool entered = false;
    //Initializes the salespeople list
    list<Salesperson> salespeople = list<Salesperson>();
    
    //Loops while the file is not at end of file
    while(!salesFile.eof()){
        //Takes the year, id, name, and count of sales
        salesFile >> year;
        salesFile >> id;
        salesFile >> first;
        salesFile >> last;
        salesFile >> count;
        sales = OrderedList<int>();
        //Loops through for the number of sales specified by the last input
        for(int c = 0; c < count; c++){
            salesFile >> sale;
            sales.insert(sale);            
        }
        person = Salesperson(id, first, last, sales);
        entered = false;
        
        //Enters the salespeople into the list
        if(salespeople.size() > 0){
            list<Salesperson>::iterator it;
            for(it = salespeople.begin(); it != salespeople.end(); it++){
                if(person == *it){
                    match = *it;
                    match.mergeSales(sales);
                    *it = match;
                    entered = true;
                }
            }
            if(!entered)
                salespeople.push_back(person);
        }
        else{
            salespeople.push_back(person);
        }
    }
    //Closes the sales.txt file
    salesFile.close();
    
    //Finds the number of sales to be reported
    cout << "Welcome to Sales Report Generator\n";
    cout << "Enter the number of sales to be reported for each salesperson: ";
    int r;
    cin >> r;
    cout << endl;
    
    //Initializes values for the report output
    Salesperson report = Salesperson(id, first, last, sales);
    stack<int> reportStack;
    int toReport = r;
    cout << "Here is your report:" << endl;
    list<Salesperson>::iterator it;
    for(it = salespeople.begin(); it != salespeople.end(); it++){
        //Prepares the id, and name for the output
        toReport = r;
        report = *it;
        id = report.getId();
        first = report.getFirst();
        last = report.getLast();
        cout << id << " " << first << " " << last << " ";   
        
        //Checks if there are enough sales to report
        sales = report.getSales();
        if(toReport > sales.getSize()){
            cout << "does not have " << toReport << " sales. ";
            cout << "Showing all " << sales.getSize() << " sales: ";
            toReport = sales.getSize();
        }
        sales = sales.kLargest(toReport);
        
        //Uses a stack to print sales in reverse order.
        reportStack = stack<int>();
        OrderedList<int>::iterator itr;
        for(itr = sales.begin(); itr != sales.end(); itr++)
            reportStack.push(*itr);
        for(int i = 0; i < toReport; i++){
            cout << reportStack.top() << " ";
            reportStack.pop();
        }
        cout << endl;
    }
    
    return 0;
}

