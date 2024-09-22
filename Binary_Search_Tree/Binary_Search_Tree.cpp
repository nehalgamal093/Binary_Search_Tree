#include <iostream>
#include "BST.h"
using namespace std;


int main()
{
    BST<int> b;
    b.insert(125);
    b.insert(40);
    b.insert(200);
    b.insert(30);
    b.insert(50);
    b.insert(150);
    b.insert(250);
    b.insert(45);
    b.insert(175);
    b.insert(230);
    b.insert(500);
    b.insert(35);
    b.insert(48);
    b.insert(160);
    b.insert(180);
    b.insert(240);
    b.insert(220);
    b.print();
}

