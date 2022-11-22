#include <iostream>
#include <fstream>
#include "address.h"

int main()
{
    std::ifstream in("in.txt");
    if (in.is_open()) {
        int size;
        in >> size;
        address* arr = new address[size];
        for (int i = 0; i < size; i++) {
            arr[i].full(in);
        }
        in.close();
        arr->sort(arr, size);
        std::ofstream out("out.txt", std::ios::out);
        if (out.is_open()) {
            out << size; out << "\n";
            for (int i = 0; i < size; ++i) {
                arr[i].output(out);
            }
        }
    }
}
