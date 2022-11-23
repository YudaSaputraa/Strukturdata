#include <iostream>
using namespace std;

int main()
{                                             // main
    int a, b = 10, *p, *q;                    // inisialisasi variable integer
    a = 25;                                   // deklarasi nilai dari a
    p = &a;                                   // deklarasi p = AND a
    cout << "Nilai a\t  = " << a << endl;     // menampilkan nilai a
    cout << "Nilai a+b = " << *p + b << endl; // menampilkan nilai pointer a + b
    q = &b;                                   // deklarasi q = AND b
    cout << "Nilai q\t  = " << *q;            // menampilkan nilai pointer q
}