#include "LinkedList.h"


// LinkedList
//
// Implementation of member functions of LinkedList class


Node* LinkedList::insert(Node* pos, const std::string& value)
{
    // Hvis value skal settes inn først, må next peke på det som nå er head
    if (pos == head.get())
    {
        head = make_unique<Node>(value, move(head), nullptr);
        pos->prev = head.get();
        return head.get();
    }

    // Setter pos til next i den nye noden, og det som er før pos før den nye noden
    unique_ptr<Node> newNode = make_unique<Node>(value, move(pos->prev->next), pos->prev);

    // Setter den nye noden inn etter elementet før pos
    pos->prev->next = move(newNode);
    
    // setter inn den nye noden før pos 
    pos->prev = pos->prev->next.get();
    return pos->prev;
}

// Returnerer en pointer til Node med samme value som argumentet, eller tail hvis det ikke fins.
Node* LinkedList::find(const std::string& value)
{
    Node* node = head.get();
    while (node)
    {
        if (node->getValue() == value){return node;}
        node = node->getNext();
    }
    return tail;
}

// Fjerner noden på pos, og returner pointer til neste node
Node* LinkedList::remove(Node* pos)
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
void LinkedList::remove(const std::string& value)
{
    remove(find(value));
}

std::ostream & operator<<(std::ostream & os, const LinkedList& list)
{
    Node* node = list.head.get();
    while (node)
    {
        cout << node->getValue() << endl;
        node = node->getNext();
    }
    return os;
}