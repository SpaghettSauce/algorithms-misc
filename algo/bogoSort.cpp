#include <iostream>
#include <random>

using namespace std;
int bogoSort(int arr[],int n)
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(0, n);

    int randomValue = distrib(gen);
}


int main(){
    int arr[3] = {3,2,1};
    arr[3] = bogoSort(arr[3],3);
    for (int i = 0; i < 3; i++)
    {
        cout<< arr[i];
    }

}
//TBD