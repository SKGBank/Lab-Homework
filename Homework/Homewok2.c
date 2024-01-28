#include <stdio.h>

int main() {
    int n = 0;
    char runagain;
    char mode;
    char sort;
    int i = 0;

    do {
        printf("User input max number: ");
        scanf("%d", &n);
        printf("----|Normal series: ");
        for (i = 1; i <= n; i++) {
            printf("%d ", i);
        }//end do

        printf("\n");

        do {
            printf("Display Odd/Even/Normal? (o/e/n): ");
            scanf(" %c", &mode);

            if (mode == 'e') {
                printf("----|Even series: ");
                for (i = 2; i <= n; i += 2) 
                {
                    printf("%d ", i);
                }//end for
                break;
            }//end if
            else if (mode == 'o') {
                printf("----|Odd series: ");
                for (i = 1; i <= n; i += 2) {
                    printf("%d ", i);
                }//end for
                break;
            }//end else if
            else if (mode == 'n') {
                printf("----|Normal series: ");
                for (i = 1; i <= n; i++) {
                    printf("%d ", i);
                }
                break;
            }//end else if
        } while (true);

        printf("\n");

        do {
            printf("Display a='a-z' / z='z-a'? (a/z): ");
            scanf(" %c", &sort);

            switch (sort) {
            case 'z':
                printf("This is z: ");
                for (i = n; i >= 1; i--) {
                    printf("%d ", i);
                }//end switch z
                break;

            case 'a':
                printf("This is a: ");
                for (i = 1; i <= n; i++) {
                    printf("%d ", i);
                }//end switch a
                break;
            }//endswitch

        } while (sort != 'a' && sort != 'z');

        printf("\n");

        printf("Do you want to start again? (Y/N): ");
        scanf(" %c", &runagain);

    } while (runagain == 'y' || runagain == 'Y');

    printf("END\n");

    return 0;
}
