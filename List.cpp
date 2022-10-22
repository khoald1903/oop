#include "List.h"

List::List()
{
    this->p = NULL;
    size = 0;
}
List::~List()
{
    delete[] p;
}

int List::Getsize()
{
    return this->size;
}

Book& List::operator[](int i)
{ 
    static Book a; a.SetID(0);
    return (i > 0) && (i < size) ? *(p+i) : a;
}

void List::ShowList()
{
    if(size == 0) cout << "Danh sach rong!\n";
    else
    {
        cout << "\t\t\t\t\t\tDanh sach: " << endl;
        for (int i = 0; i < size; i++)
        {
            cout << "ID: " << p[i].GetID() << "   trang thai " << p[i].GetStatus() << "   ten sach:   " << p[i].GetName()
                 << "   nam xuat ban: " << p[i].GetYear() << "   So luong: " << p[i].GetAmount() << endl;
        }
    }
    
    cout << "\t\t+---------------------------------------------------------------------" << endl;
}

void List::AddIndexK(Book book, int k)
{
    Book *temp = new Book[size+1];
    for(int i = 0; i < k; i++)
    {
        temp[i] = p[i];
    }
    temp[k] = book;
    size++;
    for(int i = k+1; i < size; i++)
    {
        temp[i] = p[i-1];
    }
    delete[] p;
    p = temp;
    temp = new Book;
    delete temp;
}

void List::AddFirst(Book book)
{
    AddIndexK(book,0);
}

void List::AddLast(Book book)
{
    AddIndexK(book, size);
}

void List::DeleteIndexK(int k)
{
    Book *temp = new Book[size - 1];
    for (int i = 0; i < k; i++)
    {
        temp[i] = p[i];
    }
    for (int i = k + 1; i < size; i++)
    {
        temp[i-1] = p[i];
    }
    size--;
    delete[] p;
    p = temp;
    temp = new Book;
    delete temp;
}

void List::DeleteFirst()
{
    DeleteIndexK(0);
}

void List::DeleteLast()
{
    DeleteIndexK(size-1);
}



int List::Binary_search(string id)
{
    int lo = 0, hi = size-1;
    while (lo <= hi)
    {
        int mid = lo + (hi - lo) / 2;
        if (p[mid].GetID().compare(id) == 0)
            return mid;
        else if (p[mid].GetID().compare(id) < 0)
            lo = mid + 1;
        else
            hi = mid - 1;
    }
    // không tìm thấy giá trị target trong mảng A
    return -1;
}

void List::UpdateInfor()
{
    fflush(stdin);
    string str;
    cout << "Moi nhap ID sach can cap nhat thong tin: ";
    getline(cin,str);
    int i = 0, flag = 0;
    for(i = 0; i < size; i++)
    {
        if(p[i].GetID().compare(str) == 0)
        {
            flag = 1;
            break;
        }
    }
    if(flag = 0)
    {
        cout << " Khong tim thay ID sach can cap nhat!";
    }
    else
    {
        string id, name;
        int amount, year;
        bool status;
        cout << "Moi nhap id:";
        getline(cin, id); p[i].SetID(id);
        cout << "Moi nhap ten:";
        getline(cin, name); p[i].SetName(name);
        cout << "Moi nhap so luong:";
        cin >> amount; p[i].SetAmount(amount);
        cout << "Moi nhap nhap nam:";
        cin >> year; p[i].SetYear(year);
        if (amount)
            status = true;
        else
            status = false;
    }

}

void List::merge(int l, int m, int r, bool Func(Book a, Book b))
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    Book *L = new Book[n1], *R = new Book[n2];

    for (i = 0; i < n1; i++)
        L[i] = p[l + i];
    for (j = 0; j < n2; j++)
        R[j] = p[m + 1 + j];

    i = 0; 
    j = 0; 
    k = l; 
    while (i < n1 && j < n2)
    {
        if (Func(L[i], R[j]))
        {
            p[k] = L[i];
            i++;
        }
        else
        {
            p[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        p[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        p[k] = R[j];
        j++;
        k++;
    }
}

/* l là chỉ số trái và r là chỉ số phải của mảng cần được sắp xếp */
void List::mergeSort(int l, int r, bool Func(Book a, Book b))
{
    if (l < r)
    {
        int m = l + (r - l) / 2;

        mergeSort(l, m, Func);
        mergeSort(m + 1, r, Func);

        merge(l, m, r, Func);
    }
}

Book List::Getindex(int k)
{
     return p[k];
}
