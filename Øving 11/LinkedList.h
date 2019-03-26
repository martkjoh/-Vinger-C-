#pragma once

#include <memory>
#include <ostream>
#include <iostream>

using namespace::std;


template <typename T> class Node 
{   
    private:
        const T value;              
        unique_ptr<Node <T>> next; 
        Node<T>* prev;                 
    
    public:
        Node(): value{}, next{nullptr}, prev{nullptr} {}
        Node(const T& value, unique_ptr<Node <T>> next, Node <T>* prev): 
            value{value}, next{move(next)}, prev{prev} {}
        ~Node() = default;
        
        T getValue() const { return value; }
        Node <T>* getNext() const { return next.get(); }
        Node <T>* getPrev() const { return prev; }

        friend ostream& operator<<(ostream& os, const Node <T>& node)
        {
            os << node->getValue() << endl;
            return os;
        }

        template <typename U> 
        friend class LinkedList;
};


template <typename T> class LinkedList 
{
    private:

        unique_ptr<Node <T>> head;
        Node <T>* const tail;
    
    public:
        LinkedList(): head{make_unique<Node <T>>()}, tail{head.get()} {}
        ~LinkedList() = default;

        bool isEmpty() const { return !head->next; }
        Node <T>* begin() const { return head.get(); }
        Node <T>* end() const { return tail; }



        Node <T>* insert(Node <T>* pos, const T& value)
        {
            // Hvis value skal settes inn først, må next peke på det som nå er head
            if (pos == head.get())
            {
                head = make_unique<Node <T>>(value, move(head), nullptr);
                pos->prev = head.get();
                return head.get();
            }

            // Setter pos til next i den nye noden, og det som er før pos før den nye noden
            unique_ptr<Node <T>> newNode = make_unique<Node <T>>(value, move(pos->prev->next), pos->prev);

            // Setter den nye noden inn etter elementet før pos
            pos->prev->next = move(newNode);
            
            // setter inn den nye noden før pos 
            pos->prev = pos->prev->next.get();
            return pos->prev;
        }

        // Returnerer en pointer til Node med samme value som argumentet, eller tail hvis det ikke fins.
        Node <T>* find(const T& value)
        {
            Node <T>* node = head.get();
            while (node)
            {
                if (node->getValue() == value){return node;}
                node = node->getNext();
            }
            return tail;
        }

        // Fjerner noden på pos, og returner pointer til neste node
        Node <T>* remove(Node <T>* pos)
        {
            // Hvis head skal fjærnes, må next settes til head, og prev er nullptr.
            if (pos == head.get())
            {
                head = move(pos->next);
                head->prev = nullptr;
                return head.get();
            }

            // Ellementet før pos må peke på det etter pos som neste element
            pos->prev->next = move(pos->next);

            // Ellementet etter pos må peke tilbake på det etter pos, pos ikke er sist
            if (pos->next){pos->next->prev = pos->prev;}
            return pos->next.get();
        }

        // The remove function takes a string and removes the first node which contains the value.
        void remove(const T& value)
        {
            remove(find(value));
        }
        
        friend ostream& operator <<(ostream& os, const LinkedList <T>& list)
        {
            Node <T>* node = list.head.get();
            while (node)
            {
                os << node->getValue() << endl;
                node = node->getNext();
            }
            return os;
        }
};


void testLinkedList()
{
    LinkedList <int> l;
    l.insert(l.begin(), 1);
    l.insert(l.end(), 2);
    l.insert(l.end(), 5);
    cout << l << endl;
    l.insert(l.begin(), -3);
    l.remove(2);
    cout << l << endl;
}
