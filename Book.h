#include <iostream>
#include <string.h>
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
        void SetID(string id);
        void SetName(string name);
        void SetYear(int year);
        void SetAmount(int Amount);
        void SetStatus(bool status);
};