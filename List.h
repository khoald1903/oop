#include "Book.h"

class List
{
    private:
        Book *p;
        int size;

    public:
        List();
        ~List();
        void ShowList();
        void AddIndexK(Book ,int);
        void AddFirst(Book);
        void AddLast(Book);

        void IncreaseAmountBookFirst();
        void IncreaseAmountBookLast();
        void IncreaseAmountBookIndexK(int);

        void DeleteIndexK(int);
        void DeleteFirst();
        void DeleteLast();

        void ReduceAmountBookFirst();
        void ReduceAmountBookLast();
        void ReduceAmountBookIndexK(int);

        void UpdateInfor();

        int Binary_search(string); 
        Book Getindex(int);

        void mergeSort(int , int , bool Func(Book ,Book ));
        void merge(int , int , int , bool Func(Book ,Book ));

        int Getsize();
        Book &operator[](int);
        friend ostream &operator<<(ostream &out, List &L);
        friend istream &operator>>(istream &in, List &L);
};