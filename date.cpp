#include<iostream>

using namespace std;

class date{
    private:
        int ngay, thang, nam;
    public:
        date(){}

        date(int d, int m, int y): ngay(d), thang(m), nam(y){}

        ~date(){}

        void nhap(){
            cout << "Nhap ngay : ";
            cin >> ngay;
            cout << "Nhap thang : ";
            cin >> thang;
            cout << "Nhap nam : ";
            cin >> nam;
        }

        void xuat(){
            if(ngay < 10 && thang < 10)
            cout << "0" << ngay << "-" << "0" << thang << "-" << nam << endl;
            else if(ngay < 10)
            cout << "0" << ngay << "-" << thang << "-" << nam << endl;
            else if (thang < 10)
            cout << ngay << "-" << "0" << thang << "-" << nam << endl;
            else
            cout << ngay << "-" << thang << "-" << nam << endl;            
        }

        void check(){
            //nam nhuan
            if(nam % 400 == 0 && nam > 0 && nam <= 2024){
                //thang co 29 ngay
                if(thang == 2){
                    if(ngay > 29 || ngay <= 0){
                        cout << "Vui long nhap lai!!!" << endl;
                        return nhap();
                    }
                }
                //thang co 31 ngay
                else if(thang == 1 || thang == 3 || thang == 5 || thang == 7 || thang == 8 || thang == 10 || thang == 12){
                    if(ngay > 31 || ngay <= 0){
                        cout << "Vui long nhap lai!!!" << endl;
                        return nhap();
                    }
                }
                //thang bthg
                else{
                    if(ngay > 30 || ngay <= 0){
                        cout << "Vui long nhap lai!!!" << endl;
                        return nhap();
                    }
                }
            }
            //nam khong nhuan
            else if(nam > 0 && nam <= 2024){
                //thang co 31 ngay
                if(thang == 1 || thang == 3 || thang == 5 || thang == 7 || thang == 8 || thang == 10 || thang == 12){
                    if(ngay > 31 || ngay <= 0){
                        cout << "Vui long nhap lai!!!" << endl;
                        return nhap();
                    }
                }
                //thang co 28 ngay
                else if(thang == 2){
                    if(ngay > 28 || ngay <= 0){
                        cout << "Vui long nhap lai!!!" << endl;
                        return nhap();
                    }
                }
                //thang bthg
                else{
                    if(ngay > 30 || ngay <= 0){
                        cout << "Vui long nhap lai!!!" << endl;
                        return nhap();
                    }
                }
            }else{
                cout << "Vui long nhap lai!!!" << endl;
                return nhap();
            }
        }

        friend date operator ++ (date& dt);
        friend date operator -- (date& dt);
};

date operator ++ (date& dt){
    //nam nhuan
    if(dt.nam % 400 == 0){
        //thang 29 ngay
        if(dt.thang == 2){
            if(dt.ngay == 29){
                dt.ngay = 1;
                dt.thang++;
            }
            else{
                dt.ngay++;
            }
        }
        //thang 31 ngay
        else if(dt.thang == 1 || dt.thang == 3 || dt.thang == 5 || dt.thang == 7 || dt.thang == 8 || dt.thang == 10){
            if(dt.ngay == 31){
                dt.ngay = 1;
                dt.thang++;
            }
            else{
                dt.ngay++;
            }
        }
        //thang cuoi nam
        else if(dt.thang == 12 && dt.ngay == 31){
            dt.ngay = 1;
            dt.thang = 1;
            dt.nam++;
        }
        //thang bthg
        else{
            if(dt.ngay == 30){
                dt.ngay = 1;
                dt.thang++;
            }
            else{
                dt.ngay++;
            }
        }
    }
    //nam k nhuan
    else{
        //thang 28 ngay
        if(dt.thang == 2){
            if(dt.ngay == 28){
                dt.ngay = 1;
                dt.thang++;
            }
            else{
                dt.ngay++;
            }
        }
        //thang 31 ngay
        else if(dt.thang == 1 || dt.thang == 3 || dt.thang == 5 || dt.thang == 7 || dt.thang == 8 || dt.thang == 10){
            if(dt.ngay == 31){
                dt.ngay = 1;
                dt.thang++;
            }
            else{
                dt.ngay++;
            }
        }
        //thang cuoi nam
        else if(dt.thang == 12 && dt.ngay == 31){
            dt.ngay = 1;
            dt.thang = 1;
            dt.nam++;
        }
        //thang bthg
        else{
            if(dt.ngay == 30){
                dt.ngay = 1;
                dt.thang++;
            }
            else{
                dt.ngay++;
            }
        }
    }
    return dt;
};

date operator -- (date& dt){
    //nam nhuan
    if(dt.nam % 4 == 0 && dt.nam % 100 != 0){
        //29 ngay
        if(dt.thang == 3 && dt.ngay == 1){
            dt.thang--;
            dt.ngay = 29;
        }
        //31 ngay
        else if((dt.thang == 11 || dt.thang == 9 || dt.thang == 8 || dt.thang == 6 || dt.thang == 4 || dt.thang == 2) && dt.ngay ==1){
            dt.thang--;
            dt.ngay == 31;        
        }
        // 1/1
        else if(dt.ngay == 1 && dt.thang == 1){
            dt.thang = 12;
            dt.ngay = 31;
            dt.nam--;
        }
        //ngay bthg 
        else if (dt.ngay == 1){
            dt.thang--;
            dt.ngay = 30;
        }
        else{
            dt.ngay--;
        }
    }
    //nam k nhuan
    else{
        //28 ngay
        if(dt.thang == 3 && dt.ngay == 1){
            dt.thang--;
            dt.ngay = 28;
        }
        // 31 ngay
        else if((dt.thang == 11 || dt.thang == 9 || dt.thang == 8 || dt.thang == 6 || dt.thang == 4 || dt.thang == 2) && dt.ngay == 1){
            dt.thang--;
            dt.ngay == 31;        
        }
        // 1/1
        else if(dt.ngay == 1 && dt.thang == 1){
            dt.thang = 12;
            dt.ngay = 31;
            dt.nam--;
        }
        //ngay bthg 
        else if (dt.ngay == 1){
            dt.thang--;
            dt.ngay = 30;
        }
        else{
            dt.ngay--;
        }
    }
    return dt;
};

int main(){
    date dt;
    dt.nhap();
    dt.check();
    dt.xuat();
    //++dt;
    //dt.xuat();
    --dt;
    dt.xuat();
    return 0;
}