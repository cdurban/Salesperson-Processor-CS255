/*
 * Project:     Project 7
 * File:        OrderedList.h
 * Author:      Chase Urban
 * Due:         Tuesday, April 14th, 2020
 * Description: OrderedList<> with added getSize() function
 */

#ifndef ORDEREDLIST_H
#define ORDEREDLIST_H

#include <cstdlib>
#include <iostream>

#include "NodeIterator.h"

template <class E>
class OrderedList{
    public:
        
        /**
         * Regular constructor
         */
        OrderedList(){
            size = 0;
            last = first = NULL;
        }

        /**
         * Copy constructor
         */
        OrderedList(const OrderedList &list){
            first = NULL;
            last= NULL;
            size = 0;
            for(Node<E> *n = list.first; n !=NULL; n=n->getLink()){
                this->insert(n->getData());
            }
        }

        /**
         * Destructor
         */
        ~OrderedList(){
            for (Node<E> *n = first; n!=NULL; n=first){
                first = first->getLink();
                delete n;
            }
            last = NULL;
            size=0;
        }
        
        /**
         * Returns the size of this OrderedList
         */
        int getSize(){
            return size;
        }

        /**
         * Remove function, removes the function at item E
         * Precondition: An item of type E
         * Postcondition: A boolean, whether the item was removed
         */
        bool remove(const E item){
            Node<E> *previous = NULL, *current = NULL;
            for(current = first; current != NULL && current->getData() != item;
                    previous = current, current = current->getLink());
            if(current == NULL)
                return false;
            if(previous == NULL){
                first = first->getLink();
                if(size == 1)
                    last = NULL;
                delete current;
            }
            else{
                previous->setLink(current->getLink());
                if(current == last)
                    last = previous;
                delete current;
            }
            size--;
            return true;
        }

        /**
         * A function to retrieve the k largest items of the OrderedList
         * Precondition: An int k, for the k largest items to be retrieved
         * Postcondition: An OrderedList containing the k largest items, or the
         *                the whole list if k is larger than the size of the list
         */
        OrderedList kLargest(int k){
            OrderedList<E> *li = new OrderedList<E>();
            Node<E>* n = first;
            int toSkip = size; 
            while (n != NULL && toSkip > k){
                n = n->getLink();
                toSkip--;
            }
            for(Node<E>* liHead = n; liHead != NULL; liHead = liHead->getLink()){
                li->insert(liHead->getData());
            }
            return *li;
        }

        /**
         * Gets the item at index k
         * Precondition: An integer, the index of the requested item
         * Postcondition: Item of type E, at index k
         */
        E get(int k){
            Node<E> *n;
            for(n = first; n != NULL && k > 0; --k, n = n->getLink());
            return n->getData();
        }

        /**
         * Insert function, inserts the item of type E at the required position
         * Precondition: An item of type E
         */
        void insert(E item){
            if(first == NULL){
                first = new Node<E>(item,NULL);
                last = first;
                size++;
                return;
            }
            if(item <= first->getData()){
                first = new Node<E>(item,first);
                size++;
                return;
            }
            else{
                for(Node<E>* n = first; n != NULL; n = n->getLink()){
                    if(n->getLink() == NULL){
                        n->setLink(new Node<E>(item, NULL));
                        last = n->getLink();
                        size++;
                        return;
                    }
                    if(n->getData() <= item && item < n->getLink()->getData()){
                        n->setLink(new Node<E>(item, n->getLink()));
                        size++;
                        return;
                    }
                }
            }
        }

        /**
         * Addition operator, goes through each list and combines them in order
         * Precondition: Another OrderedList
         * Postcondition: The 'sum' of the two lists, in order
         */
        OrderedList operator+(const OrderedList &list){
            OrderedList<E> *li = new OrderedList<E>();
            Node<E> *n = first, *o = list.first;
            while(n != NULL && o != NULL){
                if(o->getData() <= n->getData()){
                    li->addLast(o->getData());
                    o = o->getLink();
                    if(o == NULL){
                        while(n != NULL){
                            li->addLast(n->getData());
                            n = n->getLink();
                        }
                    }
                }
                else{
                    li->insert(n->getData());
                    n = n->getLink();
                    if(n == NULL){
                        while(o != NULL){
                            li->addLast(o->getData());
                            o = o->getLink();
                        }
                    }
                }
            }
            return *li;
        }

        /**
         * Assignment operator
         */
        void operator=(const OrderedList &list){
            first = NULL;
            last= NULL;
            size = 0;
            for(Node<E> *n = list.first; n !=NULL; n=n->getLink()){
                this->insert(n->getData());
            }
        }
        
        /**
         * Insertion operator
         */
        friend std::ostream& operator<<(std::ostream& out, 
                const OrderedList<E>& o){
            out << "[";
            for(Node<E> *n = o.first; n != NULL; n = n->getLink()){
                out << n->getData();
                if(n->getLink() != NULL)
                    out << ", ";
            }
            out << "]";
            return out;
        }
        
        //Typedef to define iterator type
        typedef NodeIterator<E> iterator;
        
        /**
         * Iterator begin() function
         */
        iterator begin(){
            return iterator(first);
        }
        
        /**
         * Iterator end() function
         */
        iterator end(){
            return iterator(NULL);
        }
    
    private:
        
        Node<E> *first;
        Node<E> *last;
        int size;

        /**
         * Function to add a given data to the end of an OrderedList, used when 
         * we know the data belongs at the end of the list
         */
        void addLast(E data){
            if(first == NULL)
                last = first = new Node<E>(data, NULL);
            else{
                last->setLink(new Node<E>(data, NULL));
                last = last->getLink();
            }
            size++;            
        }
};



#endif /* ORDEREDLIST_H */

