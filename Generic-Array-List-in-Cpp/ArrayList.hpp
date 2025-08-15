#ifndef ARRAYLIST_HPP
#define ARRAYLIST_HPP

#include <iostream>
#include <algorithm>

using namespace std;

template <typename Object>
class ArrayList {
    private:
        Object *items;
        int length;
        int capacity;

        void reserve(int newCapacity) {
            Object *tmp = new Object[newCapacity];
            copy(items, items + length, tmp);
            delete [] items;
            items = tmp;
            capacity = newCapacity;
        }
    public:
        ArrayList() {
            capacity = 2;
            length = 0;
            items = new Object[capacity];
        }

        ArrayList(const ArrayList<Object> &right) {
            length = 0;
            capacity = max(2,right.getCapacity());
            items = new Object[capacity];
            for (int i = 0; i < right.size(); i++) add(right.elementAt(i));
        }

        int size() const {
            return length;
        }

        int getCapacity() const {
            return capacity;
        }

        bool isEmpty()const {
            return length == 0;
        }

        int indexOf(const Object& item) const {
            for (int index = 0; index < length; index++) {
                if (items[index] == item) return index;
            }
        throw "Item not found.";
        }

        const Object& elementAt(int index) const {
            if (index < 0 || index >= length) throw "Index out of range";
            return items[index];
        }

        void insert(int index,const Object& item) {
            if (index < 0 || index > length) throw "Index out of range";
            if (length == capacity) reserve(2*capacity);
            for (int i = length-1;i >= index;i--) items[i+1] = items[i];
            items[index] = item;
            length++;
        }

        void add(const Object& item) {
            insert(length,item);
        }

        const Object& first() {
            if (isEmpty()) throw "List is empty";
            return items[0];
        }

        const Object& last() {
            if (isEmpty()) throw "List is empty";
            return items[length-1];
        }

        void removeAt(int index) {
            if (index < 0 || index >= length) throw "Index out of range";
            for (int i = index+1;i < length;i++) items[i-1] = items[i];     
            length--;       
        }

        void remove(const Object& item) {
            int index = indexOf(item);
            removeAt(index);
        }

        void removeAll(const Object& item) {
            for (int i = 0; i < length; ) {
                if (items[i] == item) {
                    removeAt(i);
                } else {
                    i++;
                }
            }
        }

        void clear() {
            length = 0;
            reserve(2);
        }

        bool find(const Object& item) {
            
            for (int index = 0; index < length; index++) {
                if (items[index] == item) return true;
            }
            return false;
        }

        ~ArrayList() {
            delete [] items;
        }

        ArrayList& operator=(const ArrayList<Object>& right) {
            if (this != &right) {
                delete[] items;
                length = right.size();
                capacity = right.getCapacity();
                items = new Object[capacity];
                for (int i = 0; i < length; i++) {
                    items[i] = right.elementAt(i);
                }
            }
            return *this;
        }

    // Iterator
    class Iterator {
    private:
        ArrayList<Object>& list;
        int index;

    public:
        Iterator(ArrayList<Object>& lst, int idx) : list(lst), index(idx) {}

        bool operator!=(const Iterator& other) const {
            return index != other.index;
        }

        Object& operator*() {
            return list.items[index];
        }

        const Iterator& operator++() {
            index++;
            return *this;
        }
    };
        Iterator begin() {
        return Iterator(*this, 0);
    }

    Iterator end() {
        return Iterator(*this, length);
    }

    friend ostream& operator<<(ostream& os, const ArrayList<Object>& list) {
        for (int i = 0; i < list.length; i++) {
            os << list.items[i] << " ";
        }
        return os;
    }
};

#endif
