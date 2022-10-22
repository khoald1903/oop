#include "Book.cpp"

class List
{
    private:
        Book *p;
        int size;

    public:
        List();
        ~List();
        void ShowList();
        void AddIndexK(Book book, int k);
        void AddFirst(Book book);
        void AddLast(Book book);
        void DeleteIndexK(int k);
        void DeleteFirst();
        void DeleteLast();
        void UpdateInfor();
        int Binary_search(string id); 
        Book Getindex(int k);
        void mergeSort(int l, int r, bool Func(Book a, Book b));
        void merge(int l, int m, int r, bool Func(Book a, Book b));
        int Getsize();
        Book &operator[](int i);
};