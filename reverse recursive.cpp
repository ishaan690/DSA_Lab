#include<stdio.h>
int rev(int n,int revse){
     if(n==0){
        return revse;
    }
    else{
        int x=n%10;
        revse=revse*10+x;
        rev(n/10,revse);
    }
}
int main() {
    int num= 1234;
    printf("%d", rev(num,0));
    return 0;
}
