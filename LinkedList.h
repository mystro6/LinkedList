
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <ostream>

using namespace std;

template <class T>
struct node
{
    T info;
    node<T> *link;
};

template <class T>
class LinkedList
{
    public:
        LinkedList()       //Constructor will make head null
        {
            head=0,last = 0;
            sizeOfList = 0;
        }
        virtual ~LinkedList()
        {
            deleteAll();
        }
        void insertFirst(T& item)
        {
            node<T> *p;

            if(sizeOfList != 0)
            {
                p = new node<T>;
                p->link = head;
                head = p;
                head ->info = item;
                sizeOfList++;
            }
            else
            {
                p = new node<T>;
                head = p;
                p->link = nullptr;
                p->info = item;
                sizeOfList++;
            }
        }
        void insertLast(T& item)
        {
            node<T> *r = new node<T>;
            r->info = item;
            r->link = 0;

            if(last != 0)
            {
                last->link = r;
                last = r;
            }
            else
            {
                head = last = r;
            }
            sizeOfList++;
        }
        // These 2 functions below should be used only if all items are unique. Unless it wont work correctly
        node<T>* insertItemAfter(T& pre,T& item)   // pre is the info of the node which our item's node will be placed after and it will return it's address
        {
            node<T> *p = new node<T>;
            node<T> *r = head;
            p->info = item;

            while(r->info != pre)
            {
                r = r->link;
            }
            if(r == 0)
            {
                return 0;
            }
            p->link = r->link;
            r->link = p;
            return p;
        }

        node<T>* insertItemBefore(T& bef,T& item)   // bef is the item of the node which our item's node will be placed before and it will return it's address
        {
            node<T> *p = new node<T>;
            node<T> *r = head;
            p->info = item;

            while(r->link->info != bef)
            {
                r = r->link;
            }
            if(p == 0)
            {
                return 0;
            }
            p->link = r->link;
            r->link = p;
            return p;
        }

        void deleteItem(T& item)
        {
            node<T> *p = head,*r = head;

            if(head->info == item)
            {
                head = head->link;
                delete p;
                sizeOfList--;
            }
            else
            {
                p = p->link;
                while(p != 0 && p->info != item)
                {
                    r = r->link;
                    p = p->link;
                }

                if(p != 0)
                {
                    r->link = p->link;
                    delete p;
                }
            }
        }

        void deleteFirst()
        {
            node<T> *p = head;
            head = head->link;
            delete p;
            sizeOfList--;
        }

        void deleteLast()
        {
            node<T> *p = head;

            while(p->link != last)
            {
                p = p->link;
            }

            p->link = nullptr;
            delete last;
            last = p;
            sizeOfList--;
        }

        void deleteAll()
        {
            node<T> *p=head;
            while(p != 0)
            {
                head = head->link;
                delete p;
                p = head;
            }
            sizeOfList=0;
        }

        node<T>* searchInfo(T& item)    //returns the address of the item you are looking for if there is no such item returns null
        {
            node<T> *p = head;
            while(p != 0 && p->info != item)
            {
                p=p->link;
            }
            return p;
        }

        //friend ostream& operator<<(ostream& os, const LinkedList& LL);

        void printList()
        {
            node<T> *p;

            for(p=head;p != nullptr;p = p->link)
            {
                cout << p->info << endl;
            }
        }

    protected:
        node<T> *head,*last;
        int sizeOfList;


    private:
};

#endif // LINKEDLIST_H
