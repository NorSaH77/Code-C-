#include<iostream>
#include<iomanip>

using namespace std;

class Matran {
    private:
        int row, column;
        int** mang;


    public:
        Matran(int r, int c): row(r), column(c){
            mang = new int*[row];
            for(int i = 0; i < row; i++){
                mang[i] = new int[column];
            }
        }


        void nhap(){
            cout << "Nhap tung phan tu cua mang 1 :" << endl;
            for(int i = 0; i < row; i++){
                for(int j = 0; j < column; j++){
                    cout << "Nhap phan tu thu [" << i << "][" << j << "] : ";   
                    cin >> mang[i][j];
                }
            }
        }


        void xuat(){
            cout << "Ma tran ban vua nhap la : " << endl;
            for(int i = 0; i < row; i++){
                for(int j = 0; j < column; j++){
                    cout << setw(6) << left << mang[i][j];
                }
                cout << endl;
            } 
        }


        void tong(){
            int tong = 0;
            for(int i = 0; i < row; i++){
                for(int j = 0; j < column; j++){
                    if(mang[i][j] == mang[0][j] || mang[i][j] == mang[i][0] || mang[i][j] == mang[i][column-1] || mang[i][j] == mang[row-1][j]){
                        tong += mang[i][j];
                    }
                }
            }
            cout << "Tong cac phan tu nam tren 4 duong vien la : " << tong << endl;
        }


        friend void hamban(Matran mt);
};


void hamban(Matran mt){
    int** mang = new int*[mt.row];
    for(int i = 0; i < mt.row; i++){
        mang[i] = new int[mt.column];
    }
    cout << "Nhap tung phan tu cua mang 2 :" << endl;
    for(int i = 0; i < mt.row; i++){
        for(int j = 0; j < mt.column; j++){
            cout << "Nhap phan tu thu [" << i << "][" << j << "] : ";   
            cin >> mang[i][j];
        }
    }
    cout << "Ma tran ban vua nhap la : " << endl;
    for(int i = 0; i < mt.row; i++){
        for(int j = 0; j < mt.column; j++){
            cout << setw(6) << left << mang[i][j];
        }
        cout << endl;
    } 
    cout << "Tong 2 ma tran la : " << endl;
    for(int i = 0; i < mt.row; i++){
        for(int j = 0; j < mt.column; j++){
            cout << setw(6) << left << mt.mang[i][j] + mang[i][j];
        }
        cout << endl;
    }
}


int main(){
    int row, column;
    cout << "Nhap so hang, so cot cua ma tran : ";
    cin >> row >> column;
    Matran mt(row,column);
    mt.nhap();
    mt.xuat();
    mt.tong();
    hamban(mt);
    return 0;
}