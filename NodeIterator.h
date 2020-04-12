/*
 * Project:     Project 7
 * File:        NodeIterator.h
 * Author:      Chase Urban
 * Due:         Tuesday, April 14th, 2020
 * Description: Node Iterator file for OrderedList<>
 */

#ifndef NODEITERATOR_H
#define NODEITERATOR_H

#include <cstdlib>
#include "Node.h"

template<class T>
class NodeIterator:public std::iterator<std::forward_iterator_tag, T>{
    
    public:
        /**
         * Constructor for NodeIterator
         */
        NodeIterator(Node<T>* initial = NULL){
            current = initial;
        }
        
        /**
         * Dereference operator for NodeIterator
         * Postcondition: The data of type T at the position the iterator is at
         */
        T operator*(){
            return current->getData();
        }
        
        /**
         * Preincrement operator for NodeIterator
         * Postcondition: An iterator pointing at the next position 
         */
        NodeIterator& operator++(){
            current = current->getLink();
            return *this;
        }
        
        /**
         * Postincrement operator for NodeIterator
         * Postcondiditon: An iterator pointing at the current position, 
         *                 incrementing the iterator by one without returning 
         *                 the new copy
         */
        NodeIterator& operator++(int){
            NodeIterator orig(current);
            current = current->getLink();
            return orig;
        }
        
        /**
         * Equals operator for NodeIterator
         * Precondition: A NodeIterator to be checked for equivalence
         * Postcondition: A bool, whether the given NodeIterator is equal to 
         *                this one
         */
        bool operator==(const NodeIterator& target){
            return current == target.current;
        }
        
        /**
         * Not equals operator for NodeIterator
         * Precondition: A NodeIterator to be checked for equivalence
         * Postcondition: A bool, whether the given NodeIterator is not equal 
         *                to this one
         */
        bool operator!=(const NodeIterator& target){
            return current != target.current;
        }
        
    private:
        //The current Node this iterator is pointing to
        Node<T>* current;
            
};

#endif /* NODEITERATOR_H */

