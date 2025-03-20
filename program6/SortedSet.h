#ifndef SORTEDSET_H
#define SORTEDSET_H

#include "IntList.h"

class SortedSet : public IntList {
public:
    // Constructors & Destructor
    SortedSet();
    SortedSet(const SortedSet&);
    SortedSet(const IntList&);

    // Destructor
    ~SortedSet();

    // Accessors
    bool in(int data) const;
    SortedSet operator|(const SortedSet& other) const;
    SortedSet operator&(const SortedSet& other) const;

    // Mutators
    void add(int data);
    void push_front(int data);
    void push_back(int data);
    void insert_ordered(int data);
    SortedSet& operator|=(const SortedSet& other);
    SortedSet& operator&=(const SortedSet& other);    
};

#endif