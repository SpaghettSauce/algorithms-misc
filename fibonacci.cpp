#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int n;
    cin >> n;

//Binet
    float b;
    b = (pow((1+sqrt(5))/2,n)) - (pow((1-sqrt(5))/2,n));
    cout<<"Через формулу Бине: "<<int(b/sqrt(5));

//Matrix 
 int arr[2][2] = {{0,1},{1,1}};
 int def[2][2];
 for (int q=0;q<n;q++){
    for (int i=0; i<2; i++){
        for (int j=0; j<2; j++){
            def[i][j] = arr[i][j] * arr[j][i];
             cout<<"\t"<<def[i][j];
        }
    }
 }

/*for (int i=0;i<2;i++){
    for (int j=0; j<2; j++){
        cout<<"\t"<<def[i][j];
    }
    cout<<endl;
}*/

//Подсчетом
    return 0;
}