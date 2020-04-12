/*
 * Project:     Project 7
 * File:        Node.h
 * Author:      Chase Urban
 * Due:         Tuesday, April 14th, 2020
 * Description: Node file for OrderedList<>
 */

#ifndef NODE_H
#define NODE_H

template<class T>
class Node{
    
    public:
        /**
         * Constructor
         */
        Node(T d = T(), Node* l = NULL){
            data = d; 
            link = l;
        }
        
        //Accessor methods
        void setData(T d){data = d;}
        void setLink(Node* l){link = l;}
        
        //Mutator methods
        T getData(){return data;}
        Node* getLink(){return link;}
        const Node* getLink()const{return link;}
        
    private:
        T data;
        Node* link;
};


#endif /* NODE_H */

