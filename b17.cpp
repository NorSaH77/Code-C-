#include<iostream>
#include<iomanip>

using namespace std;

class Nhanvien {
    private:
        string hoten, gioitinh, quequan, chucvu;
        int namsinh, namlam;
    public:
        Nhanvien(string ht="", string cv="", string gt="", string qq="", int ns=0, int nl=0): hoten(ht), chucvu(cv), gioitinh(gt), quequan(qq), namsinh(ns), namlam(nl){}

        friend ostream& operator << (ostream& o, const Nhanvien& nv);

        friend istream& operator >> (istream& i, Nhanvien& nv);
};

ostream& operator << (ostream& o, const Nhanvien& nv){
    o << setw(25) << left << nv.hoten 
      << setw(15) << left << nv.chucvu
      << setw(15) << left << nv.gioitinh
      << setw(15) << left << nv.quequan
      << setw(15) << left << nv.namsinh
      << setw(15) << left << nv.namlam
      << endl;
    return o;
}

istream& operator >> (istream& i, Nhanvien& nv){
    cout << "Nhap ho ten : ";
    getline(i, nv.hoten);
    cout << "Nhap chuc vu :";
    getline(i, nv.chucvu);
    cout << "Nhap gioi tinh : ";
    getline(i, nv.gioitinh);
    cout << "Nhap que quan : ";
    getline(i, nv.quequan);
    cout << "Nhap nam sinh : ";
    i >> nv.namsinh;
    cout << "Nhap nam vao lam : ";
    i >> nv.namlam;
    return i;
}

int main(){
    const int Nam = 2024;
    int n = 0;
    cout << "Nhap so nhan vien : ";
    cin >> n;
    cin.ignore();
    Nhanvien nv[n];
    for(int i = 0; i < n; i++){
        cout << "Nhap thong tin nhan vien thu " << i + 1 << ":" << endl;
        cin >> nv[i];
        cin.ignore();
    }
    cout << setw(25) << left << "Ho ten" 
        << setw(15) << left << "Chuc vu"
        << setw(15) << left << "Gioi tinh"
        << setw(15) << left << "Que quan"
        << setw(15) << left << "Nam sinh"
        << setw(15) << left << "Nam lam"
        << endl;
    for(int i = 0; i < n; i++){
        cout << nv[i];
    }
    return 0;
}