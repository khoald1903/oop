#include "List.cpp"

bool asc(Book a, Book b)
{
    return a.GetID().compare(b.GetID()) <= 0 ;
}

bool desc(Book a, Book b)
{
    return a.GetID().compare(b.GetID()) >= 0;
}

Book Create()
{
    string id, name;
    int amount, year;
    bool status;
    cout << "Moi nhap id:"; cin >> id;
    cout << "Moi nhap ten:"; cin >> name;
    cout << "Moi nhap so luong:"; cin >> amount;
    cout << "Moi nhap nhap nam:"; cin >> year;
    if(amount) status = true;
    else status = false;
    Book node(id,name,year,amount,status);
    return node;
}

void Menu()
{
    cout << "\t\t+------------------------     Menu         -------------------------+" << endl;
    cout << "\t\t|                                                                    |" << endl;
    cout << "\t\t|                      1.  Danh sach cac cuon sach                   |" << endl;
    cout << "\t\t|                      2.  Them sach vao dau danh sach               |" << endl;
    cout << "\t\t|                      3.  Them sach vao cuoi danh sach              |" << endl;
    cout << "\t\t|                      4.  Them sach vao vi tri thu k                |" << endl;
    cout << "\t\t|                      5.  Cap nhat thong tin sach                   |" << endl;
    cout << "\t\t|                      6.  Xoa sach o dau danh sach                  |" << endl;
    cout << "\t\t|                      7.  Xoa sach o cuoi danh sach                 |" << endl;
    cout << "\t\t|                      8.  Xoa sach o vi tri thu                     |" << endl;
    cout << "\t\t|                      9.  Tim kiem sach theo ID                     |" << endl;
    cout << "\t\t|                      10.  Sap xep danh sach tang dan               |" << endl;
    cout << "\t\t|                      11.  Sap xep danh sach giam dan               |" << endl;
    cout << "\t\t|                      12.  Thoat                                    |" << endl;
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

            a.AddFirst(Create());
        }
        else if(d == 3)
        {
            a.AddLast(Create());
        }
        else if(d == 4)
        {
            int k;
            cout << "Moi nhap vi tri thu k:";
            cin >> k;
            a.AddIndexK(Create(),k);
        }
        else if(d == 5)
        {
            a.UpdateInfor();
        }
        else if(d == 6)
        {
            a.DeleteFirst();
        }
        else if(d == 7)
        {
            a.DeleteLast();
        }
        else if(d == 8)
        {
            int k;
            cout << "Moi nhap vi tri can xoa: "; cin >> k;
            a.DeleteIndexK(k);
        }
        else if(d == 9)
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
                cout << "ID: " << a.Getindex(k).GetID() << "   trang thai " << a.Getindex(k).GetStatus() << "   ten sach:   " << a.Getindex(k).GetName()
                     << "   nam xuat ban: " << a.Getindex(k).GetYear() << "   So luong: " << a.Getindex(k).GetAmount() << endl;
            }
        }
        else if(d == 10)
        {
            //Sap xep tang
            a.mergeSort(0, a.Getsize() - 1, asc);
        }
        else if(d == 11)
        {
            //sap xep giam
            a.mergeSort(0, a.Getsize() - 1, desc);
        }
        else if(d == 12)
        {
            cout << "Ket thuc chuong trinh!" << endl;
            break;
        }
    }

   
}
