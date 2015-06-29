// CSCI 3300
// Assignment: 3
// Author:     Magus Pereira
// File:       pqueue.cpp
// Tab stops:  2

/*  Implements priority que
 */

#include "pqueue.h"
#include <cstdio>
#include <iostream>

using namespace std;

struct PQCell
{
    PQItemType item;
    PQPriorityType priority;
    PQCell* next;
    
    PQCell(PQItemType itm, PQPriorityType pr, PQCell* nxt)
    {
        item     = itm;
        priority = pr;
        next     = nxt;
    }
};

bool isEmpty(const PriorityQueue& q)
{
    PQCell* c = q.pointr;
    
    if (c == NULL)
    {
        return true;
    }
    return false;
}


void insertCell(const PQItemType& x, PQPriorityType p, PQCell*& c)
{
    if (c == NULL || p <= c->priority)
    {
        c = new PQCell(x, p, c);
    }
    else
    {
        insertCell(x, p, c->next);
    }
}

void insert(const PQItemType& x, PQPriorityType p, PriorityQueue& q)
{
    insertCell(x, p, q.pointr);
}

void remove(PQItemType& x, PQPriorityType& p, PriorityQueue& q)
{
    if (!isEmpty(q))
    {
        PQCell* holdr = q.pointr;
        q.pointr      = q.pointr -> next;
        x             = holdr -> item;
        p             = holdr -> priority;
        
        delete holdr;
    }
}

void printHelpr(ItemPrinter pi, PriorityPrinter pp, PQCell*& c)
{
    if (c != NULL)
    {
        pi(c ->item);
        pp(c ->priority);
        
        printHelpr(pi, pp, c->next);
    }
}

void printPriorityQueue(const PriorityQueue& q, ItemPrinter pi, PriorityPrinter pp)
{
    PQCell* c = q.pointr;
    
    printHelpr(pi, pp, c);
}

