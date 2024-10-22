/*#include <iostream>
using namespace std;
int main(){
    int x,y,posx,posy;
    int max,max_temp;
    cout<<"размер матрицы: ";
    cin>>x>>y;
    int arr[x][y];
    for (int i =0; i<x;i++){
        for(int j = 0; j< y; j++){
            int num;
            cin>>num;
            arr[i][j] = num;
        }
    }
    max = arr[0][0];
    for (int i =0; i<x;i++){
        for(int j = 0; j< y; j++){
            max_temp = arr[i][j];
            if (max_temp > max){
                max = max_temp;
                posx = i;
                posy = j;
            }
        }
    }
    cout<<"Максимальное число: "<<max<<endl<<"Строка: "<<posx+1<<endl<<"Столбец: "<<posy+1;
    return 0;
}*/
/*
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int main() {
    int a, b, c;
    cin >> a >> b >> c;
    vector<int> sides = {a, b, c};
    sort(sides.begin(), sides.end());
    int sum_of_sqr_mins = sides[0] * sides[0] + sides[1] * sides[1];
    if (sides[2] >= sides[0] + sides[1]) {
        cout<<"Не возможен";  
    }
    else if (sum_of_sqr_mins == sides[2] * sides[2]) {
        cout<< "Прямоугольный";  
    } else if (sum_of_sqr_mins > sides[2] * sides[2]) {
        cout<< "Остроугольный";  
    } 
    else 
    {
        cout<< "Тупоугольный";   
    }
    return 0;
}
*/


/*#include <iostream>
using namespace std;

int function(float x,float y,char operation){
    if (operation == '+'){
        return x + y;
    }
    if (operation == '-'){
        return x - y;
    }
    if (operation == '*'){
        return x * y;
    }
    if (operation == '/'){
        return x / y;
    }
}

int main(){
    float x,y;
    char operation;
    cin>> x >> y >> operation;
    cout<< function(x,y,operation);
    return 0;
}*/


#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    return n * factorial(n - 1);
}

int main() {
    string word1, word2;
    cin >> word1;
    cin >> word2;

    if (word1.length() != word2.length()) {
        cout << 0 << endl;
        return 0;
    }

    sort(word1.begin(), word1.end());
    sort(word2.begin(), word2.end());

    if (word1 == word2) {
        int n = word1.length();
        int result = factorial(n);
        cout << result << endl;
    } else {
        cout << 0 << endl;
    }

    return 0;
}
