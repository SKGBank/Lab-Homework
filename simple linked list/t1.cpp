#include <stdio.h>
#include <string.h>

struct studentNode{
    char name[20] ;
    int age ;
    char sex ;
    float gpa ;
    struct studentNode *next ;
} ;

void SaveNode( struct studentNode *child , char n[] , int a , char s , float g ) ;


int main(){
    struct studentNode *start , *now , **now2 ;
    start  = new struct studentNode ;
    SaveNode( start , "one" , 6 , 'M' ,3.11 ) ;
    start -> next = new struct studentNode ;
    SaveNode( start -> next , "two" , 8 , 'F' , 3.22 ) ;
    start -> next -> next = new struct studentNode ;
    SaveNode( start -> next -> next , "three" , 10 , 'M' , 3.33 ) ;
    start -> next -> next -> next = new struct studentNode ;
    SaveNode( start -> next -> next -> next , "four" , 12 , 'F' , 3.44 ) ;
    now = start ;
    now2 = &start ;
    printf( "%s\n" , now -> name ) ;
    printf( "%c\n" , (*now2) -> sex) ;
    return 0;
}

void SaveNode( struct studentNode *child , char n[] , int a , char s , float g ){
    strcpy( child -> name , n ) ; 
    child -> age = a ; 
    child -> sex = s ; 
    child -> gpa = g ; 
}

