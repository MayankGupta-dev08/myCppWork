#include<iostream>
using namespace std;

class ShopItem
{
    int id;
    float price;
    public:
        void setData(int a, float b){
            id = a;
            price = b;
        }
        void getData(void){
            cout<<"Price of item: "<<id<<" is Rs. "<<price<<"/-"<<endl;
        }
};

// int main(){
//     // If Object Array of class ShopItem is used
//     int p, i, size = 3;
//     float q;
    
//     ShopItem ob[size];

//     for (i = 0; i < size; i++){
//         cout<<"Enter Id and price of item "<< i+1<<endl;
//         cin>>p>>q;
//         ob[i].setData(p, q); 
//     }

//     cout<<"----------------------------------------"<<endl
//         <<"Detail of items are:-"<<endl;    
//     for (i = 0; i < size; i++){
//         cout<<"Item number: "<<i+1<<endl;
//         ob[i].getData();
//     }
    
//     return 0;
// }

int main(){
    int size = 3;
    // int *ptr = new int [34];

    // ShopItem *ptr = new ShopItem [size];
    ShopItem obj[size];
    ShopItem *ptr = obj;
    int p, i;
    float q;
    for (i = 0; i < size; i++){
        cout<<"Enter Id and price of item "<< i+1<<endl;
        cin>>p>>q;
        // (*ptr).setData(p, q);
        ptr->setData(p, q);
        ptr++; 
    }

    for (int j = 0; j < size; j++)
        --ptr;
        
    for (i = 0; i < size; i++){
        cout<<"Item number: "<<i+1<<endl;
        ptr->getData();
        ptr++;
    }
    
    return 0;
}

// ------------Output------------
// Enter Id and price of item 1
// 101 69.33
// Enter Id and price of item 2
// 102 45.22
// Enter Id and price of item 3
// 103 99.25
// ----------------------------------------
// Detail of items are:-
// Item number: 1
// Price of item: 101 is Rs. 69.33/-
// Item number: 2
// Price of item: 102 is Rs. 45.22/-
// Item number: 3
// Price of item: 103 is Rs. 99.25/-