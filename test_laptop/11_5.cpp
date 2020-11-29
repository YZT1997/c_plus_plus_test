//
// Created by yang zhengtao on 2020/11/29.
//
#include "fstream"
using namespace std;
struct Date{
    int month, day, year;
};

int main(){
    Date dt = {10, 1, 2020};
    ofstream file("date.dat", ios_base::binary);
    file.write(reinterpret_cast<char*>(&dt), sizeof(dt));
    file.close();
    return 0;
}
