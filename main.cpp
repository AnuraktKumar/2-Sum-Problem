//
//  main.cpp
//  Stanford_Course2_Week4
//
//  Created by Anurakt Kumar on 10/12/21.
//

#include <iostream>
#include <map>
#include <stdlib.h>
using namespace std;

int* generate_a_to_b(int a, int b){
    int *p;
    int j=0;
    p = (int *)(malloc(sizeof(int)*(b-a+1)));
    if(a<0){
        for(int i=a; i<0; i++){
            p[j++] = i;
        }
        for(int i=0; i<=b; i++){
            p[j++] = i;
        }
    }else{
        for(int i=a; i<=b; i++){
            p[j++] = i;
        }
    }
    return p;
}


int main() {
    //Here generate_a_to_b generates a series of number from a to b
    int *p = generate_a_to_b(-10000, 10000);
    long int t=0,count=0;
    //Creating a map from strings to integers
    map <long int, long int> map_one;
    //Creating an input file stream
    FILE *fptr;
    fptr = fopen("input_file.txt", "r");
    long int a=0;
    while(fscanf(fptr, "%ld", &a)!=EOF){
        map_one[a] = 1;
    }
    for (int i=0; i<20001; i++){
        for(map <long int, long int>::iterator itr=map_one.begin(); itr!=map_one.end(); itr++){
            t = p[i];
            a = t - (itr->first);
            //cout<<"t: "<<t<<" itr first: "<<(itr->first)<<endl;
            if (a!=(itr->first) && map_one.find(a)!=map_one.end()){
                count++;
                break;
            }
        }
        cout<<"t: "<<p[i]<<" count: "<<count<<endl;
    }
    return 0;
}
