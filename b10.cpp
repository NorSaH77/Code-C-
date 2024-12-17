#include<iostream>
#include<iomanip>

using namespace std;

class nhansu{
    private:
        string mnv, ht;
        int ns;
    public:
        void nhap(){
            cout << "Nhap ma nhan vien : ";
            getline(cin,mnv);
            cout << "Nhap ho ten : ";
            getline(cin,ht);
            cout << "Nhap nam sinh : ";
            cin >> ns;
            cin.ignore();
        }

        void xuat(){
            cout << setw(15) << left << mnv
            << setw(20) << left << ht
            << setw(15) << left << ns;
        }
};

class canbo : public nhansu{
    private:
        float lcb, hsl;
    public:
        void Nhap(){
            nhap();
            cout << "Nhap he so luong : ";
            cin >> hsl;
            cout << "Nhap luong co ban : ";
            cin >> lcb;
            cin.ignore();
        }

        void Xuat(){
            xuat();
            cout << setw(15) << left << hsl
            << setw(15) << left << lcb;
        }

        friend float tinhluong(const canbo& a);
};

float tinhluong(const canbo& a){
    float c = a.hsl * a.lcb; 
    return c;
};

int main(){
    int n;
    cout << "Nhap so can bo : ";
    cin >> n;
    cin.ignore();
    canbo a[n];
    for(int i=0; i < n; i++){
        cout << "Nhap can bo thu " << i+1 << " : " << endl;
        a[i].Nhap();
    }
    cout << setw(15) << left << "MNV:"
    << setw(20) << left << "Ho ten:"
    << setw(15) << left << "Nam sinh:"
    << setw(15) << left << "He so luong:"
    << setw(15) << left << "luong co ban:"
    << setw(15) << left << "luong:"
    << endl;
    for(int i=0; i < n; i++){
        a[i].Xuat();
        float luong = tinhluong(a[i]);
        cout << luong << fixed << setprecision(3) << endl;
    }
    return 0;
}