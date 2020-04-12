/*
 * Project:     Project 7
 * File:        Salesperson.cpp
 * Author:      Chase Urban
 * Due:         Tuesday, April 14th, 2020
 * Description: A salesperson object to hold id, name, and sales. Has a method to
 *              combine this object's sales OrderedList with another.
 */

#include <cstdlib>

#include "Salesperson.h"
/**
* Constructor
*/
Salesperson::Salesperson(int i, std::string f, std::string l, OrderedList<int> s){
    id = i;
    first = f, last = l;
    sales = s;
}

/**
  * Merges the sales of this salesperson with another OrderedList
  * Precondition: OrderedList of sales
  */
void Salesperson::mergeSales(OrderedList<int> s){
    sales = sales + s;
}

/**
  * Assignment operator
  * Precondition: Salesperson to set this salesperson equal to
  */
void Salesperson::operator =(const Salesperson& s){
    id = s.id;
    first = s.first;
    last = s.last;
    sales = s.sales;
}
/**
 * Returns the id of this salesperson
 * Postcondition: The id of this salesperson
 */
int Salesperson::getId()const{
    return id;
}

/**
 * Returns the first name of this salesperson
 * Postcondition: The first name of this salesperson
 */
std::string Salesperson::getFirst()const{
    return first;
}

/**
 * Returns the last name of this salesperson
 * Postcondition: The last name of this salesperson
 */
std::string Salesperson::getLast()const{
    return last;
}

/**
 * Returns the sales OrderedList of this salesperson
 * Postcondition: The sales OrderedList of this salesperson
 */
OrderedList<int> Salesperson::getSales()const{
    return sales;
}

/**
 * > operator
 * Precondition: Salesperson to check
 * Postcondition: Whether this salesperson is greater than the other
 */
bool Salesperson::operator >(const Salesperson &s){
    if(this->id > s.id)
        return true;
    else
        return false;
}

/**
 * < operator
 * Precondition: Salesperson to check
 * Postcondition: Whether this salesperson is less than the other
 */
bool Salesperson::operator <(const Salesperson &s){
    if(this->id < s.id)
        return true;
    else
        return false;
}

/**
 * == operator
 * Precondition: Salesperson to check
 * Postcondition: Whether this salesperson is equal to the other
 */
bool Salesperson::operator ==(const Salesperson &s){
    if(this->id == s.id)
        return true; 
    else
        return false;
}
