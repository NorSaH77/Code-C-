#include<iostream>

using namespace std;

class Phanso{
    private:
    int ts, ms;

    public:
    Phanso (int t = 0, int m = 1): ts(t), ms(m){
    } 

    void nhap(){
        do{
            cout << "Nhap vao tu so lon hon 0, mau so : ";
            cin >> ts >> ms;
        }while(ts < 1);
    }

    void xuat(){
        if(ms == 1){
            cout << "Phan so ban vua nhap la :" << ts << endl;    
        }else if(ms < 0){
            cout << "Phan so ban vua nhap la :" << -ts << "/" << -ms << endl;
        }else{
            cout << "Phan so ban vua nhap la :" << ts << "/" << ms << endl;
        }
    }

    void xuat1(){
        cout << ts << "/" << ms;
    }

    void toigian(){
        int uc = 1;
        if(ts > ms){
            for(int i = ts; i <= ts; i--){
                if(ts % i == 0 && ms % i == 0){
                    uc = i;
                    break;
                }
            }
        }else if (ms > ts){
            for(int i = ms; i <= ms; i--){
                if(ts % i == 0 && ms % i == 0){
                    uc = i;
                    break;
                }
            }
        }
        ts /= uc;
        ms /= uc;
        if(ms < 0){
            cout << "Phan so sau khi toi gian la : " << -ts << "/" << -ms << endl;
        }else{
            cout << "Phan so sau khi toi gian la : " << ts << "/" << ms << endl;
        }
    }

    friend bool operator == (Phanso& Ps1, Phanso& Ps2);
    friend bool operator < (Phanso& Ps1, Phanso& Ps2);
    friend bool operator > (Phanso& Ps1, Phanso& Ps2);
};

bool operator == (Phanso& Ps1, Phanso& Ps2){
    if(Ps1.ms == Ps2.ms && Ps1.ts == Ps2.ts){
        return true;
    }else{
        return false;
    }
}

bool operator < (Phanso& Ps1, Phanso& Ps2){
    if(Ps1.ts * Ps2.ms < Ps1.ms * Ps2.ts){
        return true;
    }else{
        return false;
    }
}

bool operator > (Phanso& Ps1, Phanso& Ps2){
    if(Ps1.ts * Ps2.ms > Ps1.ms * Ps2.ts){
        return true;
    }else{
        return false;
    }
}

int main(){
    Phanso Ps1;
    Ps1.nhap();
    Ps1.xuat();
    Ps1.toigian();
    Phanso Ps2;
    Ps2.nhap();
    Ps2.xuat();
    Ps2.toigian();
    bool a = Ps1 == Ps2;
    bool b = Ps1 < Ps2;
    bool c = Ps1 > Ps2;
    if(a == 1){
        cout << "2 phan so bang nhau" << endl;
    }else if (b == 1){
        cout << "Phan so 1 nho hon phan so 2"<< endl;
    }else if(c == 1){
        cout << "Phan so 1 lon hon phan so 2"<< endl;
    }
    return 0;
}