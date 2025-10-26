#include<stdio.h>
#include<time.h>
#include<conio.h>

#ifdef _WIN32
  #include <windows.h>
  #define sleep_ms(ms) Sleep(ms)
#else
  #include <unistd.h>
  #define sleep_ms(ms) usleep((ms) * 1000)
#endif

#include "arraylist.h"
#include "matrix.h"
#include "timer.h"

int main() {
    int rows = 20; int cols = 10;
    int **matrix = init_matrix(rows,cols);
    int p_row = 0; int p_col = 0;

    time_t start_time = timer_init();
    while(1) {
        printf("\033[2J\033[1;1H");
        update_matrix_index(matrix,p_row,p_col);
        display_matrix(matrix,rows,cols);
        while(timer_checker(&start_time,3) != 1) {
            if(_kbhit()) {
                char key = _getch();
                switch (key) {
                    case 72: printf("UP pressed\n"); break;     // arrow up
                    case 80: printf("DOWN pressed\n"); break;   // arrow down
                    case 75: printf("LEFT pressed\n"); break;   // arrow left
                    case 77: printf("RIGHT pressed\n"); break;  // arrow right
                    case 27: return 0; // ESC key exits
                    default: printf("Key: %d\n", key); break;
                }
                start_time = timer_init();
                break;
            }
        }
    }
    free_matrix(matrix,rows);

    return 0;
}

// printf("\033[2J\033[1;1H");