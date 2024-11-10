#include <iostream>
#include<iomanip>
using namespace std;

class matran{
    private:
        int row, column;
        int** arr;


    public:
        matran( int r, int c) : row(r), column(c){
            arr = new int*[row];
            for(int i = 0; i < row; i++){
                arr[i] = new int[column];
            }
        }


        ~matran(){
            for(int i = 0; i < row; i++){
                delete[] arr[i];
            }
            delete[] arr;
        }



        void nhap(){
            cout << "Nhap so hang, cot cua ma tran : ";
            cin >> row >> column;
        }


        void xuat(){
            cout << "Ma tran ban vua nhap la : " << endl;
            for(int i = 0; i < row; i++){
                for(int j = 0; j < column; j++){
                    cout << setw(6) << left << arr[i][j];
                }
                cout << endl;
            } 
            int size
        }

};

int main() {
    int row, column;
    cout << "Nhap so hang, cot cua ma tran : ";
    cin >> row >> column;
    matran mt(row,column);
    mt.xuat();
    return 0;
}
