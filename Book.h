#include <iostream>
#include <string.h>
#include "math.h"
using namespace std;

class Book
{
    private:
        string ID;
        string Name;
        int Year;
        int Amount;
        bool Status;
    public:
        Book();
        Book(string id, string name, int year, int amount, bool status);
        ~Book();
        string GetID();
        string GetName();
        int GetYear();
        int GetAmount();
        bool GetStatus();
        void SetID(string);
        void SetName(string);
        void SetYear(int);
        void SetAmount(int);
        void SetStatus(bool);

        friend istream &operator>>(istream &, Book &);
        friend ostream &operator<<(ostream &, Book );
        
};  