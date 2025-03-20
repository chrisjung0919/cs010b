#include "IntList.h"

class SortedSet: public IntList {
public:
    SortedSet();
    SortedSet(const SortedSet &);
    SortedSet(const IntList &);

    ~SortedSet();

    bool in(int value) const;
    SortedSet operator|(const SortedSet &) const;
    SortedSet operator&(const SortedSet &) const;

    void add(int value);
    void push_front(int value);
    void push_back(int value);
    void insert_ordered(int value);

private:
    void remove_duplicates();
};