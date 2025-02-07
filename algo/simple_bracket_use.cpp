#include <iostream>
#include <string>

using namespace std;
void brackets_use(string bracket){
    int q = 0;
    for(int i =0; i< size(bracket); i++)
    {
        if (bracket[i] == '(')
        {
            q++;
        }
        else if (bracket[i] == ')')
        {
            q++;
        }
    }
    if (q % 2 != 0 )
    {
        cout<<"stoopid";
    }
    else {
        cout<< "yeeepi";
    }

}



int main(){
    string bracket;
    cin>>bracket;
    brackets_use(bracket);
    return 0;
}