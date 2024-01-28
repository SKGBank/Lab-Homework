#include <stdio.h>
#include <string.h>
struct Human {
	char Name[ 20 ] ;
	int  Age ;
};
void PrintHuman(struct Human Arr[],int N) ;
void PrintHumanAboveAvg(struct Human Arr[],int N,float Avg);
void Sort(struct Human Arr[],int N,int Mode = 1);
float AverageAge( struct Human Arr[], int N );

int main() {
	int N = 8 ;
	
	struct Human Person[8];
	strcpy( Person[ 0 ].Name,"Boom" ) ;
	strcpy( Person[ 1 ].Name,"Game" ) ;
	strcpy( Person[ 2 ].Name,"Top" ) ;
	strcpy( Person[ 3 ].Name,"Non" ) ;
	strcpy( Person[ 4 ].Name,"Bas" ) ;
	strcpy( Person[ 5 ].Name,"Fluk" ) ;
	strcpy( Person[ 6 ].Name,"Kim" ) ;
	strcpy( Person[ 7 ].Name,"Mig" ) ;
	
	Person[0].Age = 20;
	Person[1].Age = 21;
	Person[2].Age = 22;
	Person[3].Age = 18;
	Person[4].Age = 19;
	Person[5].Age = 17;
	Person[6].Age = 16;
	Person[7].Age = 23;
	
	//---| Not Sort
    PrintHuman( Person, N ) ;  
	
	//---| Sort 0-9
	Sort( Person, N, 1) ; 
	PrintHuman( Person, N ) ;
    
    //---| Sort 9-0
	Sort( Person, N, 2) ;
	PrintHuman( Person, N ) ; 
	
	//---| Find Average
	float AVG = AverageAge( Person , N );
	printf("------------------------------------------------------------");
	printf("\nAverage Age = %.2f\n",AVG);
	PrintHumanAboveAvg( Person, N, AVG );
	return 0;
}//end function

void PrintHuman(struct Human Arr[],int N){
	int i = 0;
	printf("--| Human : \n");
	for(i = 0 ; i < N ; i++)
	printf(" %s (%d) ", Arr[ i ].Name, Arr[ i ].Age);
	printf("\n") ;
}// end function


void PrintHumanAboveAvg(struct Human Arr[],int N,float Avg){
	int i = 0;
	printf("--| Human : \n");
	for(i = 0 ; i < N ; i++) if(Arr[ i ].Age > Avg) printf(" %s (%d) ", Arr[ i ].Name, Arr[ i ].Age);
	printf("\n") ;
}// end function

/**
 Mode = 1 0-9
 Mode = 2 9-0
*/
void Sort(struct Human Arr[],int N,int Mode ) {
	int i = 0 ;
	int j = 0 ;
	struct Human hold ;
	
	for(i = 0 ; i < N ; i++){
		for(j = i + 1 ; j < N ; j++ ) {
			if(Mode == 1){
			if(Arr [ i ].Age > Arr[ j ].Age){
				hold     = Arr[ i ] ;
				Arr[ i ] = Arr[ j ] ;
				Arr[ j ] = hold ;
			}// end if swap
		} else if(Mode == 2){
			if(Arr [ i ].Age < Arr[ j ].Age){
				hold     = Arr[ i ] ;
				Arr[ i ] = Arr[ j ] ;
				Arr[ j ] = hold ;
			}//end if swap
		}// end if
	} // end for  j
}//end for i
} // end funtion

float AverageAge( struct Human Arr[], int N ){
	float Output = 0 ;
	float Sum    = 0 ;
	for(int i = 0 ; i < N ; i++){
		Sum += Arr[ i ].Age ;
	}//end for
	Output = Sum / N ;
	return Output ;
} // end funtion

