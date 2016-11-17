#include <fstream>
#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

int slect(istream &input,ostream &output);

int main(const int argc,const char* argv[]){

    int round1 ;
    ifstream input;
    ofstream output;
    input.open(argv[1]);
    output.open(argv[2]);

    input >> round1;
    int all[round1]={0};

    for(int n=0;n<round1;n++){
        all[n] = slect(input,output);
        }
    for(int z=0;z<round1;z++){
     output << all[z] << endl ;
    }

    input.close();
    output.close();
    return 0;
    }

int slect(istream &input,ostream &output){
    char word[3];
    int sum=0;
    int a =0;
    int b =0;

    input >>  word[0];

    if(word[0]=='A'||word[0]=='S'||word[0]=='M'){

    input >>  word[1]>> word[2];

        switch(word[2]){
        case 'D':
            a=slect(input,output);
            b=slect(input,output);
            return a+b;
        break;
        case 'B':
            a=slect(input,output);
            b=slect(input,output);
            return a-b;
        break;
        case 'L':
            a=slect(input,output);
            b=slect(input,output);
            return a*b;
        break;
        case 'X':
            a=slect(input,output);
            b=slect(input,output);
            if(a>=b){
              return a;
            }else{
              return b;
            }
        break;
        case 'N':
            a=slect(input,output);
            b=slect(input,output);
            if(a<b){
              return a;
            }else{
              return b;
            }
        break;
              }  //  switch
    }else{

      return (word[0] - '0');

    }

}
