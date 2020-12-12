#include <iostream>
#include "Btree.h"
using namespace std;

int main(){
    Btree b;
    b.insert("ARCADE","Adventure","Hollywood",2.23);
    b.insert("ARCA","Adventure","Holy",2.23);
    b.insert("Cyberpunk2077","criminal","Holy",3.4);//-
    b.insert("Warrior1800T","criminal","Holy",3.4);//-
    b.insert("Bumer200433","criminal","стс 90-x",1.45);
    b.insert("Girls1999","","Holy",4.3);//-
    b.insert("Toys2020","Adventure","Holly",1.43);
    b.insert("Cars2020","Adventure","Holy",5.23);//-
    b.insert("Hobbit2018","Adventure","Holy",2.13);//-

    b.print();
    b.deleteElemnt("Holy");
    cout<<"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
    b.print();


    b.cutTree();





}

