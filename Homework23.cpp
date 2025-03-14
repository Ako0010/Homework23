#include <iostream>
#include <cassert>
using namespace std;
#include "timeclass.h"
#include "vectorclass.h"

int main() {
    Time time1;
    time1();
    cout << (time1 == time1 ? "true" : "false") << endl;

    Time time2(5, 30, 45);
    time2();
    cout << (time2 == time2 ? "true" : "false") << endl;

    cout << (time1 == time2 ? "true" : "false") << endl;

    Time time3;
    cout << (!time3 ? "true" : "false") << endl;

    ++time2;
    time2();
    cout << (time2 == Time(5, 30, 46) ? "true" : "false") << endl;

    time2++;
    time2();
    cout << (time2 == Time(5, 30, 47) ? "true" : "false") << endl;

    --time2;
    time2();
    cout << (time2 == Time(5, 30, 46) ? "true" : "false") << endl;

    time2--;
    time2();
    cout << (time2 == Time(5, 30, 45) ? "true" : "false") << endl;

    Time time4(5, 30, 46);
    cout << (time2 != time4 ? "false" : "true") << endl;

    cout << (time1 < time2 ? "true" : "false") << endl;

    cout << (time4 > time2 ? "true" : "false") << endl;

    cout << endl;

    Vector v1;
    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);
    cout << "Vector v1 push_back edildikden sonra: ";
    v1.print();

    Vector v2;
    v2.push_back(40);
    v2.push_back(50);
    cout << "Vector v2 push_back edildikden sonra: ";
    v2.print();

    Vector v3 = v1 + v2;
    cout << "Vector v3 operator+ ile birlesdikden sonra: ";
    v3.print();

    cout << "v1 ve v2 eyni mi? " << (v1 == v2 ? "Beli" : "Xeyr") << endl;
    cout << "v1 ve v2 ferqlidirmi? " << (v1 != v2 ? "Beli" : "Xeyr") << endl;

    ++v1;
    cout << "v1 vectoru prefix operator++ den sonra: ";
    v1.print();

    v2++;
    cout << "v2 vectoru postfix operator++ den sonra: ";
    v2.print();

    --v1;
    cout << "v1 vectoru prefix operator-- den sonra: ";
    v1.print();

    v2--;
    cout << "v2 vectoru postfix operator-- den sonra: ";
    v2.print();

    v1.insert_by_index(1, 25);
    cout << "v1 vectoruna index 1 de 25 elave olunduqdan sonra: ";
    v1.print();

    v1.delete_by_index(2);
    cout << "v1 vectorundan index 2 deyer silindikden sonra: ";
    v1.print();

    size_t index = v2.find(40);
    if (index != numeric_limits<size_t>::max()) {
        cout << "v2 de 40 elementi tapildi, index: " << index << endl;
    }
    else {
        cout << "v2 de 40 elementi tapilmadi." << endl;
    }

    index = v2.rfind(40);
    if (index != numeric_limits<size_t>::max()) {
        cout << "v2 de 40 elementi tersine tapildi, index: " << index << endl;
    }
    else {
        cout << "v2 de 40 elementi tersine tapilmadi." << endl;
    }

    v1.pop_back();
    cout << "v1 vectoru pop_back edildikden sonra: ";
    v1.print();
    v1.pop_front();
    cout << "v1 vectoru pop_front edildikden sonra: ";
    v1.print();



    return 0;
}

