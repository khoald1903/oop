#include "List.h"


bool asc(Book a, Book b)
{
    return a.GetID().compare(b.GetID()) <= 0 ;
}

bool desc(Book a, Book b)
{
    return a.GetID().compare(b.GetID()) >= 0;
}

istream &operator>>(istream &in, Book &book)
{
    while (true)
    {
        fflush(stdin);
        cout << "Moi nhap id:";
        in >> book.ID;

        if (book.ID.length() != 9)
        {
            cout << "ID phai 9 ki tu! Moi nhap lai\n";
            continue;
        }
        int i = 0;
        if (book.ID[0] < '1' || book.ID[0] > '5')
        {
            cout << "Ki tu dau ma so phai lon hon bang 1 va nho hon bang 5! Moi nhap lai\n";
            continue;
        }

        for (i = 1; i < book.ID.length(); i++)
        {
            if (book.ID[i] < '0' || book.ID[i] > '9')
            {
                cout << "ID phai thoa man 0 <= id[i] <= 9! Moi nhap lai!\n";
            }
            continue;
        }
        break;
    }
    cout << "Moi nhap ten:";
    fflush(stdin);
    getline(in, book.Name);
    cout << "Moi nhap so luong:";
    in >> book.Amount;

    while (true)
    {
        cout << "Moi nhap nhap nam:";
        in >> book.Year;
        if ((int)(log10(book.Year) + 1) != 4)
        {
            cout << "Nam xuat ban gom 4 chu cai, moi nhap lai!\n";
        }
        else
            break;
    }
    if (book.Amount)
        book.Status = true;
    else
        book.Status = false;
    return in;
}

ostream &operator<<(ostream &out, Book book)
{
    out << "ID: " << book.ID << "   Trang thai: " << ((book.Status == true) ? "true" : "false") << "   Ten sach: " << book.Name
         << "   Nam xuat ban:" << book.Year << "   So luong: " << book.Amount << endl;
    return out;
}

ostream &operator<<(ostream &out, List& L)
{
    if (L.Getsize() == 0)
        out << "Danh sach rong!\n";
    else
    {
        out << "\t\t\t\t\t\tDanh sach: " << endl;
        for (int i = 0; i < L.Getsize(); i++)
        {
            out << L.p[i];
        }
    }

    cout << "\t\t+---------------------------------------------------------------------" << endl;
    return out;
}

istream &operator>>(istream &in, List& L)
{
    if(L.p != NULL) delete[] L.p;

    cout << "Nhap kich thuoc danh sach";
    in >> L.size;

    L.p = new Book[L.size];

    for(int i = 0; i < L.size; i++)
    {
        in >> L.p[i];
    }
    return in;
}


    void Menu()
{
    cout << "\t\t+------------------------     Menu         -------------------------+" << endl;
    cout << "\t\t|                                                                    |" << endl;
    cout << "\t\t|                  1.  Danh sach cac cuon sach                       |" << endl;  //Hiển thị danh sách
    cout << "\t\t|                  2.  Them sach vao dau danh sach                   |" << endl;  //Thêm sách vào đầu danh sách
    cout << "\t\t|                  3.  Them sach vao cuoi danh sach                  |" << endl;  //Thêm sách vào cuối danh sách
    cout << "\t\t|                  4.  Them sach vao vi tri thu k                    |" << endl;  //Thêm sách vào vị trí thứ k
    cout << "\t\t|                  5.  Tang so luong sach cua sach o dau             |" << endl;  // Tăng số lượng sách ở đầu
    cout << "\t\t|                  6.  Tang so luong sach cua sach o cuoi            |" << endl;   //Tăng số lượng sách ở cuối
    cout << "\t\t|                  7.  Tang so luong sach cua sach o vi tri k        |" << endl;   //Tăng số lượng sách ở vị trí k
    cout << "\t\t|                  8.  Giam so luong sach cua sach o dau             |" << endl;   //Giam so luong sach ở đầu
    cout << "\t\t|                  9.  Giam so luong sach cua sach o cuoi            |" << endl;   //Giảm số lượng sách ở cuối
    cout << "\t\t|                  10.  Giam so luong sach cua sach o vi tri k       |" << endl;   //Giảm số lượng sách ở vị trí k
    cout << "\t\t|                  11.  Cap nhat thong tin sach                      |" << endl;   //Cập nhật thông tin sách có id
    cout << "\t\t|                  12.  Xoa sach o dau danh sach                     |" << endl;   //Xoá sách ở đầu danh sách
    cout << "\t\t|                  13.  Xoa sach o cuoi danh sach                    |" << endl;   //Xoá sách ở cuối
    cout << "\t\t|                  14.  Xoa sach o vi tri thu k                      |" << endl;   //Xoá sách ở vị trí thứ k
    cout << "\t\t|                  15.  Tim kiem sach theo ID                        |" << endl;   //Tìm kiếm sách theo id rồi đưa ra thông tin sách
    cout << "\t\t|                  16.  Sap xep danh sach tang dan                   |" << endl;   //Sắp xếp tăng dần theo ID
    cout << "\t\t|                  17.  Sap xep danh sach giam dan                   |" << endl;   //Sắp xếp giảm dần theo ID
    cout << "\t\t|                  18.  Nhap moi hoan toan danh sach                 |" << endl;
    cout << "\t\t|                  19.  Thoat                                        |" << endl;
    cout << "\t\t+---------------------------------------------------------------------" << endl;
}

int main()
{
    List a;
    while(true)
    {
        Menu();
        int d;
        cin >> d;
        if(d == 1)
        {
            a.ShowList();
        }
        else if(d == 2)
        {
            Book book;
            cin >> book;
            a.AddFirst(book);
        }
        else if(d == 3)
        {
            Book book;
            cin >> book;
            a.AddLast(book);
        }
        else if(d == 4)
        {
            int k;
            cout << "Moi nhap vi tri thu k:";
            cin >> k;
            Book book;
            cin >> book;
            a.AddIndexK(book,k);
        }
        else if (d == 5)
        {
            a.IncreaseAmountBookFirst();
        }
        else if (d == 6)
        {
            a.IncreaseAmountBookLast();
        }
        else if (d == 7)
        {
            int k;
            cout << "Moi nhap vi tri: "; cin >> k;
            a.IncreaseAmountBookIndexK(k);
        }
        else if (d == 8)
        {
            a.ReduceAmountBookFirst();
        }
        else if (d == 9)
        {
            a.ReduceAmountBookLast();
        }
        else if (d == 10)
        {
            int k;
            cout << "Moi nhap vi tri: ";
            cin >> k;
            a.ReduceAmountBookIndexK(k);
        }
        else if(d == 11)
        {
            a.UpdateInfor();
        }
        else if(d == 12)
        {
            a.DeleteFirst();
        }
        else if(d == 13)
        {
            a.DeleteLast();
        }
        else if(d == 14)
        {
            int k;
            cout << "Moi nhap vi tri can xoa: "; cin >> k;
            a.DeleteIndexK(k);
        }
        else if(d == 15)
        {
            fflush(stdin);
            string str;
            cout << "Moi nhap ID sach can tim:";
            getline(cin, str);
            //tim kiem
            a.mergeSort(0, a.Getsize() - 1, asc);
            int k = a.Binary_search(str);
            if(k == -1) cout << "Khong tim thay ID\n";
            else
            {
                cout << a.Getindex(k);
            }
        }
        else if(d == 16)
        {
            //Sap xep tang
            a.mergeSort(0, a.Getsize() - 1, asc);
        }
        else if(d == 17)
        {
            //sap xep giam
            a.mergeSort(0, a.Getsize() - 1, desc);
        }
        else if (d == 18)
        {
            // sap xep giam
            cin >> a;
        }
        else if (d == 19)
        {
            cout << "Ket thuc chuong trinh!" << endl;
            break;
        }
    }

   
}
