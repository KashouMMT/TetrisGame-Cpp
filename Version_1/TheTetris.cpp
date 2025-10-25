#include<iostream>
#include<cstdlib>
#include<thread>
#include<chrono>
#include<conio.h>
void intro();
void show_grid(std::string grid[20][10]);
bool clear_grid(std::string grid[20][10]);
void update_grid(std::string grid[20][10]);
void place_grid(std::string grid[20][10],int col,int row,std::string block[3][2]);
void place_grid_1(std::string grid[20][10],int col,int row,std::string Horizontal_Line_Block[2][2]);
void place_grid_2(std::string grid[20][10],int col,int row,std::string Vertical_Line_Block[3][1]);
void place_block(std::string grid[20][10],int col,int row,int block_number,std::string Block[3][2],std::string L_Block[3][2],std::string Another_L_Block[3][2],std::string reverse_L_Block[3][2],std::string Another_reverse_L_Block[3][2],std::string Vertical_Line_Block[3][1],std::string Horizontal_Line_Block[2][2]);
bool block_physics(std::string grid[20][10],int& col,int& row,int& block_number,std::string Block[3][2],std::string L_Block[3][2],std::string Another_L_Block[3][2],std::string reverse_L_Block[3][2],std::string Another_reverse_L_Block[3][2],std::string Vertical_Line_Block[3][1],std::string Horizontal_Line_Block[2][2],char move);
char get_user_input(char move);
int main()
{   
//████████╗███████╗████████╗██████╗░██╗░██████╗
//╚══██╔══╝██╔════╝╚══██╔══╝██╔══██╗██║██╔════╝
//░░░██║░░░█████╗░░░░░██║░░░██████╔╝██║╚█████╗░
//░░░██║░░░██╔══╝░░░░░██║░░░██╔══██╗██║░╚═══██╗
//░░░██║░░░███████╗░░░██║░░░██║░░██║██║██████╔╝
//░░░╚═╝░░░╚══════╝░░░╚═╝░░░╚═╝░░╚═╝╚═╝╚═════╝░
    intro();
    int score = 0;
    //Define mapping Grid
    std::string grid[20][10] = 
    {
        // 0    1    2    3    4    5    6    7    8    9  
        {" ."," ."," ."," ."," ."," ."," ."," ."," ."," ."},//0
        {" ."," ."," ."," ."," ."," ."," ."," ."," ."," ."},//1
        {" ."," ."," ."," ."," ."," ."," ."," ."," ."," ."},//2
        {" ."," ."," ."," ."," ."," ."," ."," ."," ."," ."},//3
        {" ."," ."," ."," ."," ."," ."," ."," ."," ."," ."},//4
        {" ."," ."," ."," ."," ."," ."," ."," ."," ."," ."},//5
        {" ."," ."," ."," ."," ."," ."," ."," ."," ."," ."},//6
        {" ."," ."," ."," ."," ."," ."," ."," ."," ."," ."},//7
        {" ."," ."," ."," ."," ."," ."," ."," ."," ."," ."},//8
        {" ."," ."," ."," ."," ."," ."," ."," ."," ."," ."},//9
        {" ."," ."," ."," ."," ."," ."," ."," ."," ."," ."},//10
        {" ."," ."," ."," ."," ."," ."," ."," ."," ."," ."},//11
        {" ."," ."," ."," ."," ."," ."," ."," ."," ."," ."},//12
        {" ."," ."," ."," ."," ."," ."," ."," ."," ."," ."},//13
        {" ."," ."," ."," ."," ."," ."," ."," ."," ."," ."},//14
        {" ."," ."," ."," ."," ."," ."," ."," ."," ."," ."},//15
        {" ."," ."," ."," ."," ."," ."," ."," ."," ."," ."},//16
        {" ."," ."," ."," ."," ."," ."," ."," ."," ."," ."},//17
        {" ."," ."," ."," ."," ."," ."," ."," ."," ."," ."},//18
        {" ."," ."," ."," ."," ."," ."," ."," ."," ."," ."} //19
    };
    while(true)
    {
        //Define Block Types.
        //Square Block, Block Number = 0
        std::string Block[3][2] = 
        {
        //   0    1    2    3    4
            {" ."," ."},//0
            {"[]","[]"},//1
            {"[]","[]"}//2//3
        };
        //L-Shaped Block, Block Number = 1
        std::string L_Block[3][2] =
        {
            {" ."," ."},
            {" .","[]"},
            {"[]","[]"}
        };
        // Reverse L-Shaped Block, Block Number = 2
        std::string reverse_L_Block[3][2] = 
        {  //col
            {" ."," ."},//row
            {"[]","[]"},
            {"[]"," ."}
        };
        // Reverse L-Shaped Block 2, Block Number =3
        std::string Another_reverse_L_Block[3][2] = 
        {
            {" ."," ."},
            {"[]","[]"},
            {" .","[]"}
        };
        // L-Shaped Block, Block Number = 4
        std::string Another_L_Block[3][2] =
        {
            {" ."," ."},
            {"[]"," ."},
            {"[]","[]"}
        };
        // Vertical Line Block, Block Number = 5
        std::string Vertical_Line_Block[3][1] = 
        {
            {" ."},
            {"[]"},
            {"[]"}
        };
        // Horizontal Line Block, Block Number = 6
        std::string Horizontal_Line_Block[2][2] = 
        {
            {" ."," ."},
            {"[]","[]"}
        };
        srand(time(0));
        int block_number = rand()%7;        // Randomly Select Block Type
        int row = 0;                        // Set Starting Row
        int col = rand()%9;                 // Randomly Select Starting Column
        char move;                          // Char Key for Movement
        bool loop_control = true;           // Game Looping Control
        while(loop_control)
        {
            place_block(grid,col,row,block_number,Block,L_Block,Another_L_Block,reverse_L_Block,Another_reverse_L_Block,Vertical_Line_Block,Horizontal_Line_Block); //Placing Block On Game Grid.
            std::cout<<"Press 'o' to quit the game."<<std::endl<<"Row = "<<row<<std::endl<<"Col = "<<col<<std::endl<<"Block Number = "<<block_number<<std::endl<<"Score = "<<score<<std::endl;
            show_grid(grid);
            move = get_user_input(move);    // Get User Input
            printf("\033[2J\033[1;1H");     // Clear Console Screen
            switch (move)                   // Calculate Each Block Physics By Block Movement
            {
                case 'a':
                    loop_control = block_physics(grid,col,row,block_number,Block,L_Block,Another_L_Block,reverse_L_Block,Another_reverse_L_Block,Vertical_Line_Block,Horizontal_Line_Block,move);
                    break;
                case 's':
                    loop_control = block_physics(grid,col,row,block_number,Block,L_Block,Another_L_Block,reverse_L_Block,Another_reverse_L_Block,Vertical_Line_Block,Horizontal_Line_Block,move);
                    break;
                case 'd':
                    loop_control = block_physics(grid,col,row,block_number,Block,L_Block,Another_L_Block,reverse_L_Block,Another_reverse_L_Block,Vertical_Line_Block,Horizontal_Line_Block,move);
                    break;
                case 'q':
                    loop_control = block_physics(grid,col,row,block_number,Block,L_Block,Another_L_Block,reverse_L_Block,Another_reverse_L_Block,Vertical_Line_Block,Horizontal_Line_Block,move);
                    break;
                case 'e':
                    loop_control = block_physics(grid,col,row,block_number,Block,L_Block,Another_L_Block,reverse_L_Block,Another_reverse_L_Block,Vertical_Line_Block,Horizontal_Line_Block,move);
                    break;
                case 'o':
                    exit(0);
                    break;
                default:
                    std::cout<<"Wrong Input. Try again.";
                    break;
            }
            place_block(grid,col,row,block_number,Block,L_Block,Another_L_Block,reverse_L_Block,Another_reverse_L_Block,Vertical_Line_Block,Horizontal_Line_Block);
        }
        bool row_cleared = true;            //Clearing Row 
        while(row_cleared) 
        {
            row_cleared = clear_grid(grid); // Checking Row Is Cleared Or Not.
            if(row_cleared) 
            {
                score++;
                show_grid(grid);
                std::this_thread::sleep_for(std::chrono::milliseconds(500));
                printf("\033[2J\033[1;1H");
            }
        }
    }
    return 0;
}

void place_block(std::string grid[20][10],int col,int row,int block_number,std::string Block[3][2],std::string L_Block[3][2],std::string Another_L_Block[3][2],std::string reverse_L_Block[3][2],std::string Another_reverse_L_Block[3][2],std::string Vertical_Line_Block[3][1],std::string Horizontal_Line_Block[2][2])
{
    switch(block_number)
    {
        case 0:
            place_grid(grid,col,row,Block);
            break;
        case 1:
            place_grid(grid,col,row,L_Block);   
            break;
        case 2: 
            place_grid(grid,col,row,reverse_L_Block);
            break;
        case 3: 
            place_grid(grid,col,row,Another_reverse_L_Block);
            break;
        case 4:
            place_grid(grid,col,row,Another_L_Block);
            break;
        case 5:
            place_grid_2(grid,col,row,Vertical_Line_Block);
            break;
        case 6:
            place_grid_1(grid,col,row,Horizontal_Line_Block);
            break;
        default:
            break;
    }
}

bool block_physics(std::string grid[20][10],int& col,int& row,int& block_number,std::string Block[3][2],std::string L_Block[3][2],std::string Another_L_Block[3][2],std::string reverse_L_Block[3][2],std::string Another_reverse_L_Block[3][2],std::string Vertical_Line_Block[3][1],std::string Horizontal_Line_Block[2][2],char move)
{
    switch(move)
    {    // 0 1 4
        case 'a':
            switch(block_number)
            {
                case 0:
                case 2:
                case 4:
                    if(col!=0 && grid[row+1][col-1] !="[]" && grid[row+2][col-1] !="[]")
                    { 
                        grid[row+1][col+1] =" .";
                        grid[row+2][col+1] =" .";
                        col--;
                        return true;
                    }
                    break;
                case 1:
                    if(col!=0 && grid[row+2][col-1]!="[]")
                    {
                        grid[row+1][col+1] =" .";
                        grid[row+2][col+1] =" .";
                        if(grid[row+1][col-1]=="[]")
                        {
                            L_Block[1][0] = "[]";
                            col--;
                            return true;
                        }
                        col--;
                    }
                    break;
                case 3:
                    if(col!=0 && grid[row+1][col-1] !="[]")
                    { 
                        grid[row+1][col+1] =" .";
                        grid[row+2][col+1] =" .";
                        if(grid[row+2][col-1] =="[]")
                        {
                            Another_reverse_L_Block[2][0] = "[]";
                            col--;
                            return false;
                        }
                        col--;
                    }
                    break;
                case 5:
                    if(col!=0 && grid[row+1][col-1]!="[]" && grid[row+2][col-1]!="[]")
                    {
                        grid[row][col] = " .";
                        grid[row+1][col] = " .";
                        grid[row+2][col] = " .";
                        col--;
                        return true;
                    }
                    break;
                case 6:
                    if(col!=0 && grid[row+1][col-1]!="[]")
                    {
                        grid[row+1][col+1] = " .";
                        col--;
                        return true;
                    }
            }
            break;
        case 's':
            switch (block_number)
            {
                case 0:
                case 1:
                case 4:
                    if(grid[row+3][col]!="[]" && grid[row+3][col+1]!="[]" && row!=17) row++;
                    else return false;
                    break;
                case 5:
                    if(grid[row+3][col]!="[]" && row!=17) row++;
                    else return false;
                    break;
                case 6:
                    if(grid[row+2][col]!="[]" && grid[row+2][col+1]!="[]" && row!=18) row++;
                    else return false;
                    break;
                case 2:
                    if(row!=17 && grid[row+3][col] != "[]")
                    {
                        if(grid[row+3][col+1] =="[]")
                        {
                            row++;
                            reverse_L_Block[2][1] = "[]";
                            return false;
                        }
                        else row++;
                    }
                    else return false;
                    break;
                case 3:
                    if(row!=17 && grid[row+3][col+1] != "[]")
                    {
                        if(grid[row+3][col] == "[]")
                        {
                            row++;
                            Another_reverse_L_Block[2][0] = "[]";
                            return false;
                        }
                        else row++;
                    }
                    else return false;
                    break;
            }
            break;
        case 'd':
            switch(block_number)
            {
                case 0:
                case 1:
                case 3:
                    if(col!=8 && grid[row+2][col+2] !="[]" && grid[row+1][col+2]!="[]")
                    {
                        grid[row+1][col] = " .";
                        grid[row+2][col] = " ."; 
                        col++;
                        return true;
                    }
                    break;
                case 2:
                    if(col!=8 && grid[row+1][col+2]!="[]")
                    {
                        grid[row+1][col] = " .";
                        grid[row+2][col] = " ."; 
                        if(grid[row+2][col+2]=="[]")
                        {
                            reverse_L_Block[2][1] = "[]";
                            col++;
                            return false;
                        }
                        col++;
                    }
                    break;
                case 4:
                    if(col!=8 && grid[row+2][col+2]!="[]")
                    {
                        grid[row+1][col] = " .";
                        grid[row+2][col] = " .";
                        if(grid[row+1][col+2]=="[]")
                        {
                            Another_L_Block[1][1] = "[]";
                            col++;
                            return true;
                        }
                        col++;
                    }
                    break;
                case 5:
                    if(col!=9 && grid[row+1][col+1]!="[]" && grid[row+2][col+1]!="[]")
                    {
                        grid[row][col] = " .";
                        grid[row+1][col] = " .";
                        grid[row+2][col] = " .";
                        col++;
                        return true;
                    }
                    break;
                case 6:
                    if(col!=8 && grid[row+1][col+2]!="[]")
                    {
                        grid[row+1][col] = " .";
                        col++;
                    }
                    break;
            }
            break;
        case 'q':
            if(block_number<4 && block_number!= 0)block_number++;
            if(block_number==5)
            {
                for(int i=0;i<3;i++)
                {
                    for(int j=0;j<2;j++)
                    {
                        grid[row+i][col+j] = " .";
                    }
                }
                block_number++;
            }
            break;
        case 'e':
            if(block_number>1 && block_number<5)block_number--;
            if(block_number==6)
            {
                for(int i=0;i<3;i++)
                {
                    for(int j=0;j<2;j++)
                    {
                        grid[row+i][col+j] = " .";
                    }
                }
                block_number--;
            }
            break;
        default:
            std::cout<<"Wrong Input. Try again."<<std::endl;
            break;
    }
    return true;
}

void place_grid(std::string grid[20][10],int col,int row,std::string block[3][2])
{
    for(int i=0; i<3; i++) 
    {
        for(int j=0; j<2;j++) 
        {
            if(col!=9)
            { 
                grid[row+i][col+j] = block[i][j];
            }
        }
    }
}

void place_grid_1(std::string grid[20][10],int col,int row,std::string Horizontal_Line_Block[2][2])
{
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++)
        {
            grid[row+i][col+j] = Horizontal_Line_Block[i][j];
        }
    }
}
void place_grid_2(std::string grid[20][10],int col,int row,std::string Vertical_Line_Block[3][1])
{
    for(int i=0;i<3;i++)
    {
        grid[row+i][col] = Vertical_Line_Block[i][0];
    }
}

void show_grid(std::string grid[20][10])
{
    std::cout<<"   0 1 2 3 4 5 6 7 8 9"<<std::endl;
    for(int i=0;i<20;i++)
    {
        std::cout<<"<!";
        for(int j=0;j<10;j++)
        {
            std::cout<<grid[i][j];
        }
        std::cout<<"!> "<<i<<std::endl;
    }
    std::cout<<"<!====================!>\n  \\/\\/\\/\\/\\/\\/\\/\\/\\/\\/";
}

bool clear_grid(std::string grid[20][10])
{
    bool row_cleared = false;
    for(int i=19;i>-1;i--)
    {
        if((grid[i][0]=="[]")&&(grid[i][1]=="[]")&&(grid[i][2]=="[]")&&(grid[i][3]=="[]")&&(grid[i][4]=="[]")&&(grid[i][5]=="[]")&&(grid[i][6]=="[]")&&(grid[i][7]=="[]")&&(grid[i][8]=="[]")&&(grid[i][9]=="[]"))
        {
            for(int j=0;j<10;j++)
            {
                grid[i][j] = " .";
            }
            row_cleared = true;
        }
    }
    if(row_cleared)
    {
        update_grid(grid);
    }
    
    return row_cleared;
}

void update_grid(std::string grid[20][10])
{
    for(int loop = 0;loop<20;loop++)
    {
        for(int i=0;i<19;i++)
        {
            for(int j=0;j<10;j++)
            {
                if(grid[i][j]=="[]" && grid[i+1][j]==" .")
                {
                    grid[i][j]=" .";
                    grid[i+1][j] = "[]";
                }
            }
        }
    }
}

char get_user_input(char move)
{
    auto start_time = std::chrono::high_resolution_clock::now();
    move = '\0';
    while(true)
    {
        if(_kbhit())
        {   
            move = _getch();
            break;
        }
        auto end_time = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed_time = end_time - start_time;
        if(elapsed_time.count()>=1.0)
        {
            move = 's';
            break;
        }
    }
    return move;
}

void intro()
{
    std::string title = "--------------------------------------------------------------\n _________  _______  _________  ________  ___  ________       \n|\\___   ___\\\\  ___ \\|\\___   ___\\\\   __  \\|\\  \\|\\   ____\\      \n\\|___ \\  \\_\\ \\   __/\\|___ \\  \\_\\ \\  \\|\\  \\ \\  \\ \\  \\___|_     \n     \\ \\  \\ \\ \\  \\_|/__  \\ \\  \\ \\ \\   _  _\\ \\  \\ \\_____  \\    \n      \\ \\  \\ \\ \\  \\_|\\ \\  \\ \\  \\ \\ \\  \\\\  \\\\ \\  \\|____|\\  \\   \n       \\ \\__\\ \\ \\_______\\  \\ \\__\\ \\ \\__\\\\ _\\\\ \\__\\____\\_\\  \\  \n        \\|__|  \\|_______|   \\|__|  \\|__|\\|__|\\|__|\\_________\\ \n                                                 \\|_________| \n                                                              \n--------------------------------------------------------------";
    for(char i : title)
    {
        std::cout<<i;
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }
    std::this_thread::sleep_for(std::chrono::seconds(5));
    printf("\033[2J\033[1;1H");
    std::cout<<"Tutorial: "<<std::endl<<"a : Move left\ns : Move down\nd : Move right\nq,e : Rotate Block\no : Quit"<<std::endl;
    std::cout<<std::endl<<"Press anything to start playing."<<std::endl;
    char temp;
    std::cin>>temp;
}