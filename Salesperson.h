/*
 * Project:     Project 7
 * File:        Salesperson.h
 * Author:      Chase Urban
 * Due:         Tuesday, April 14th, 2020
 * Description: A salesperson object to hold id, name, and sales. Has a method to
 *              combine this object's sales OrderedList with another.
 */

#include <cstdlib>
#include <string>

#ifndef SALESPERSON_H
#define SALESPERSON_H

#include "OrderedList.h"

class Salesperson {
public:
    /**
     * Constructor
     */
    Salesperson(int i, std::string f, std::string l, OrderedList<int> s);
    
    /**
     * Merges the sales of this salesperson with another OrderedList
     * Precondition: OrderedList of sales
     */
    void mergeSales(OrderedList<int> s);
    /**
     * Assignment operator
     * Precondition: Salesperson to set this salesperson equal to
     */
    void operator =(const Salesperson& s);
        
    /**
     * Returns the id of this salesperson
     * Postcondition: The id of this salesperson
     */
    int getId()const;
    /**
     * Returns the first name of this salesperson
     * Postcondition: The first name of this salesperson
     */
    std::string getFirst()const;
    /**
     * Returns the last name of this salesperson
     * Postcondition: The last name of this salesperson
     */
    std::string getLast()const;
    /**
     * Returns the sales OrderedList of this salesperson
     * Postcondition: The sales OrderedList of this salesperson
     */
    OrderedList<int> getSales()const;
    /**
     * > operator
     * Precondition: Salesperson to check
     * Postcondition: Whether this salesperson is greater than the other
     */
    bool operator >(const Salesperson& s);
    /**
     * < operator
     * Precondition: Salesperson to check
     * Postcondition: Whether this salesperson is less than the other
     */
    bool operator <(const Salesperson& s);
    /**
     * == operator
     * Precondition: Salesperson to check
     * Postcondition: Whether this salesperson is equal to the other
     */
    bool operator ==(const Salesperson& s);
    
private:
    //The id of this salesperson
    int id;
    //The first and last name of this salesperson
    std::string first, last;
    //The OrderedList containing all of the sales 
    OrderedList<int> sales;
    
};

#endif /* SALESPERSON_H */
