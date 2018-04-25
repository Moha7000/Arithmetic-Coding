#include<bits/stdc++.h>
using namespace std;

float cdf [4] = {0 , 0.8 , 0.82 , 1};
float l[4] , u[4];
string input = "acba";
string output = "";

void rescale(int i){
    if(l[i] >= 0 && u[i] <= 0.5 ){
            output += '0';
            l[i] = 2*l[i] ;
            u[i] = 2*u[i] ;
        }
        else if(l[i] >= 0.5 && u[i] <= 1){
            output += '1';
            l[i] = 2*(l[i] - 0.5);
            u[i] = 2*(u[i] - 0.5);
        }

}
void encode (){
    for(int i = 1 ; i < (input.length() + 1) ; i++){
        l[i]= l[i-1] + (u[i-1] - l[i-1]) * cdf[ input[i-1]-96   -1 ];
        u[i]= l[i-1] + (u[i-1] - l[i-1]) * cdf[ input[i-1]-96 ];
        cout << l[i]<< endl;
        cout << u[i]<< endl;
        while( (l[i] >= 0 && l[i] <= 0.5 && u[i] >= 0 && u[i] <= 0.5) || (l[i] >= 0.5 && l[i] <= 1 && u[i] >= 0.5 && u[i] <= 1) )
            rescale(i);
    }
}
int main()
{
    l[0]=0;
    u[0]=1;

    encode();

    cout << output <<endl;

    return 0;
}
