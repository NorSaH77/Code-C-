#include<iostream>
#include<iomanip>

using namespace std;

class nhanvien{
    private:
        string hoten;
        string gioitinh;
        int namsinh, namvaolam;
    public:
        int getnvl(){
            return namvaolam;
        }
        friend ostream& operator << (ostream& o, nhanvien& a);
        friend istream& operator >> (istream& i, nhanvien& a);
};

ostream& operator << (ostream& o, nhanvien& a){
    o << setw(20) << left << a.hoten
    << setw(15) << left << a.gioitinh
    << setw(15) << left << a.namsinh
    << setw(15) << left << a.namvaolam
    << endl;
    return o;
};

istream& operator >> (istream& i, nhanvien& a){
    cout << "Nhap ho ten : ";
    getline(i,a.hoten);
    cout << "Nhap gioi tinh : ";
    getline(i,a.gioitinh);
    cout << "Nhap nam sinh : ";
    i >> a.namsinh;
    cout << "Nhap nam vao lam : ";
    i >> a.namvaolam;
    i.ignore();
    return i;
};

int main(){
    int n,b = 2024;
    cout << "Nhap so nhan vien : ";
    cin >> n;
    cin.ignore();
    nhanvien a[n];
    for(int i=0; i < n; i++){
        cout << "Nhap nhan vien thu " << i+1 << " : " << endl;
        cin >> a[i];
    }
    cout << setw(20) << left << "Ho ten:"
    << setw(15) << left << "Gioi tinh:"
    << setw(15) << left << "Nam sinh:"
    << setw(15) << left << "Nam vao lam:"
    << endl;
    for(int i=0; i < n; i++){
        cout << a[i]; 
    }
    cout << "Nhan vien lam viec tren 20 nam la :" << endl;
    cout << setw(20) << left << "Ho ten:"
    << setw(15) << left << "Gioi tinh:"
    << setw(15) << left << "Nam sinh:"
    << setw(15) << left << "Nam vao lam:"
    << endl;
    for(int i=0; i < n; i++){
        if(b - a[i].getnvl() > 20){
            cout << a[i]; 
        }
    }
    return 0;
}