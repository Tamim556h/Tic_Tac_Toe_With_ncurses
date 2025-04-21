//Tamim Hossen bsse1650

#include <ncurses.h>
#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>
void drawboard();
int  player1Move(char x,char y);
int  player2Move(char x, char y);
int  Computer(char x,char p2);
int cheekWinner( );
int cheekTie( );

char a1=' ',a2=' ',a3=' ',a4=' ',a5=' ',a6=' ',a7=' ',a8=' ',a9=' ';
bool flag=true;
int main(){

    initscr();            // Start ncurses mode
    noecho();             // Don't echo user input
    cbreak();             // Disable line buffering
    keypad(stdscr, TRUE); // Enable arrow keys
    start_color();        // for color

    init_pair(1, COLOR_CYAN, COLOR_BLACK);
    init_pair(2, COLOR_RED, COLOR_BLACK);
    init_pair(3, COLOR_GREEN, COLOR_BLACK);
    init_pair(4, COLOR_YELLOW, COLOR_BLACK);


        if(flag==false){
            return 0;
        }

    attron(COLOR_PAIR(1));
    printw(" Wealcome to Tic - Tac - Toe Game\n\n");
    
    while(1){

        attron(COLOR_PAIR(1));
        addstr("\n To play with your friends press 1.\n");
        addstr(" To play with computer press 2.\n");
        addstr(" For exit press 'Q'\n");
        attroff(COLOR_PAIR(1));
        refresh();
        
        char ch;
        ch = getch();

            if(ch=='1'){

                a1=' ',a2=' ',a3=' ',a4=' ',a5=' ',a6=' ',a7=' ',a8=' ',a9=' ';
                int n;
                int running=1;
                while (running==1){

                    drawboard();
                    char Player1,Player2;
                    char p1='X';
                    char p2='O';

                    player1Move(n,p1);
                        if(flag==false){
                            return 0;
                        }
                        clear();
                        drawboard();
                        
                        if(cheekWinner( )){
                            running=0;
                            break;
                        }
                        else if(cheekTie( )){
                            running = 0;
                            break;
                        }

                    player2Move(n,p2);        
                        if(flag==false){
                            return 0;
                        }
                        clear();
                        drawboard();
                        
                        if(cheekWinner( )){
                            running=0;
                            break;
                        }
                        else if(cheekTie( )){
                            running = 0;
                            break;
                        }     
                    refresh();              
                }
            }

            else if(ch=='2'){

                a1=' ',a2=' ',a3=' ',a4=' ',a5=' ',a6=' ',a7=' ',a8=' ',a9=' ';
                int n;
                int running=1;
                while (running==1){

                    drawboard();
                    char Player1,Player2;
                    char p1='X';
                    char p2='O';


                    player1Move(n,p1);
                        if(flag==false){
                            return 0;
                        }
                        clear();
                        drawboard();
                        if(cheekWinner( )){
                            running=0;
                            break;
                        }
                        else if(cheekTie( )){
                            running = 0;
                            break;
                        }

                    Computer(n,p2);
                        clear();
                        drawboard();
                        if(cheekWinner( )){
                            running=0;
                            break;
                        }
                        else if(cheekTie( )){
                            running = 0;
                            break;
                        }               
                    refresh();    
                }
            } 
            else if(ch=='Q'|| ch=='q'){
                printw(" Thanks for Playing ");
                return 0;
            } 
            else{
                attron(COLOR_PAIR(2));
                printw(" Wrong input\n\n");
                attroff(COLOR_PAIR(2));
            }  
            refresh();       
    } 
    refresh();
    endwin();  // End ncurses mode

}

int player1Move(char x,char p1){

    attron(COLOR_PAIR(3));
    printw(" Player 1 move [ X ]:\n");
    printw(" Enter a spot to place a marker (1-9)");
    attroff(COLOR_PAIR(3));
    x = getch();
        if(x=='Q' || x=='q'){
            flag=false;
            return 0;
        }
        else if(x=='1' && a1==' ') a1=p1;
        else if(x=='2' && a2==' ') a2=p1;
        else if(x=='3'&& a3==' ') a3=p1;
        else if(x=='4'&& a4==' ') a4=p1;
        else if(x=='5' && a5==' ') a5=p1;
        else if(x=='6' && a6==' ') a6=p1;
        else if(x=='7' && a7==' ') a7=p1;
        else if(x=='8' && a8==' ') a8=p1;
        else if(x=='9' && a9==' ') a9=p1;
        else{
            attron(COLOR_PAIR(2));
            printw("\n Wrong input\n");
            player1Move( x, p1);
            attroff(COLOR_PAIR(2));
        }
        clear();
}

int player2Move(char x,char p2){

    attron(COLOR_PAIR(3));
    printw(" Player 2 move [ O ]:\n");
    printw(" Enter a spot to place a marker (1-9)");
    attroff(COLOR_PAIR(3));
    x = getch();
        if(x=='Q' || x=='q'){
            flag=false;
            return 0;
        }
        else if(x=='1' && a1==' ') a1=p2;
        else if(x=='2' && a2==' ') a2=p2;
        else if(x=='3'&& a3==' ') a3=p2;
        else if(x=='4'&& a4==' ') a4=p2;
        else if(x=='5' && a5==' ') a5=p2;
        else if(x=='6' && a6==' ') a6=p2;
        else if(x=='7' && a7==' ') a7=p2;
        else if(x=='8' && a8==' ') a8=p2;
        else if(x=='9' && a9==' ') a9=p2;
        else{
            attron(COLOR_PAIR(2));
            printw("\n Wrong input\n");
            player2Move( x, p2);
            attroff(COLOR_PAIR(2));
        }
        clear();
}

int Computer(char y,char p2){

    bool flag=true;
    printw(" computer move:\n");
    printw("Computer mark a place");

        if (a1 == a2 && a1 == 'O' && a3 == ' ')
                a3=p2;
            else if (a1 == a4 && a1 == 'O' && a7 == ' ')
                a7=p2;
            else if (a1 == a5 && a1 == 'O' && a9 == ' ')
                a9=p2;
            else if (a2 == a5 && a2 == 'O' && a8 == ' ')
                a8=p2;
            else if (a2 == a3 && a2 == 'O' && a1 == ' ')
                a1=p2;
            else if (a3 == a6 && a3 == 'O' && a9 == ' ')
                a9=p2;
            else if (a3 == a5 && a3 == 'O' && a7 == ' ')
                a7=p2;
            else if (a4 == a5 && a4 == 'O' && a6 == ' ')
                a6=p2;
            else if (a4 == a7 && a4 == 'O' && a1 == ' ')
                a1=p2;
            else if (a5 == a6 && a5 == 'O' && a4 == ' ')
                a4=p2;
            else if (a5 == a9 && a5 == 'O' && a1 == ' ')
                a1=p2;
            else if (a5 == a8 && a5 == 'O' && a2 == ' ')
                a2=p2;
            else if (a5 == a7 && a5 == 'O' && a3 == ' ')
                a3=p2;
            else if (a6 == a9 && a6 == 'O' && a3 == ' ')
                a3=p2;
            else if (a7 == a8 && a7 == 'O' && a9 == ' ')
                a9=p2;
            else if (a8 == a9 && a8 == 'O' && a7 == ' ')
                a7=p2;
            else if (a1 == a3 && a1 == 'O' && a2 == ' ')
                a2=p2;
            else if (a7 == a9 && a7 == 'O' && a8 == ' ')
                a8=p2;
            else if (a1 == a9 && a1 == 'O' && a5 == ' ')
                a5=p2;
            else if (a3 == a7 && a3 == 'O' && a5 == ' ')
                a5=p2;
            else if (a1 == a7 && a1 == 'O' && a4 == ' ')
                a4=p2;
            else if (a2 == a8 && a2 == 'O' && a5 == ' ')
                a5=p2;
            else if (a3 == a9 && a3 == 'O' && a6 == ' ')
                a6=p2;
            else if (a4 == a6 && a4 == 'O' && a5 == ' ')
                a5=p2;

                else if (a1 == a2 && a1 == 'X' && a3 == ' '){
                    a3=p2; flag=false;}
                else if (a1 == a4 && a1 == 'X' && a7 == ' '){
                    a7=p2;flag=false;}
                else if (a1 == a5 && a1 == 'X' && a9 == ' '){
                    a9=p2;flag=false;}
                else if (a2 == a5 && a2 == 'X' && a8 == ' '){
                    a8=p2;flag=false;}
                else if (a2 == a3 && a2 == 'X' && a1 == ' '){ 
                    a1=p2;flag=false;}
                else if (a3 == a6 && a3 == 'X' && a9 == ' ')
                {  a9=p2;flag=false;}
                else if (a3 == a5 && a3 == 'X' && a7 == ' ')
                {  a7=p2;flag=false;}
                else if (a4 == a5 && a4 == 'X' && a6 == ' ')
                {  a6=p2;flag=false;}
                else if (a4 == a7 && a4 == 'X' && a1 == ' ')
                {  a1=p2;flag=false;}
                else if (a5 == a6 && a5 == 'X' && a4 == ' ')
                {  a4=p2;flag=false;}
                else if (a5 == a9 && a5 == 'X' && a1 == ' ')
                {  a1=p2;flag=false;}
                else if (a5 == a8 && a5 == 'X' && a2 == ' ')
                {  a2=p2;flag=false;}
                else if (a5 == a7 && a5 == 'X' && a3 == ' ')
                {  a3=p2;flag=false;}
                else if (a6 == a9 && a6 == 'X' && a3 == ' ')
                {  a3=p2;flag=false;}
                else if (a7 == a8 && a7 == 'X' && a9 == ' ')
                {  a9=p2;flag=false;}
                else if (a8 == a9 && a8 == 'X' && a7 == ' ')
                {  a7=p2;flag=false;}
                else if (a1 == a3 && a1 == 'X' && a2 == ' ')
                {  a2=p2;flag=false;}
                else if (a7 == a9 && a7 == 'X' && a8 == ' ')
                {  a8=p2;flag=false;}
                else if (a1 == a9 && a1 == 'X' && a5 == ' ')
                {  a5=p2;flag=false;}
                else if (a3 == a7 && a3 == 'X' && a5 == ' ')
                {  a5=p2;flag=false;}
                else if (a1 == a7 && a1 == 'X' && a4 == ' ')
                {  a4=p2;flag=false;}
                else if (a2 == a8 && a2 == 'X' && a5 == ' ')
                {  a5=p2;flag=false;}
                else if (a3 == a9 && a3 == 'X' && a6 == ' ')
                {  a6=p2;flag=false;}
                else if (a4 == a6 && a4 == 'X' && a5 == ' ')
                {  a5=p2;flag=false;}
                    
        else{
            if(a5==' '){ a5='O';flag=false;}
            else if(a1==' '){ a1='O'; flag=false;}
            else if(a3==' '){ a3='O'; flag=false;}
            else if(a7==' '){ a7='O'; flag=false;}
            else if(a9==' '){ a9='O'; flag=false;}
            else if(a8==' '){ a8='O'; flag=false;}
            else if(a4==' '){ a4='O'; flag=false;}
            else if(a6==' '){ a6='O'; flag=false;}
            else if(a2==' '){ a2='O'; flag=false;}
            
        }

    if(flag==true){
            if (a1 == a2 && a1 == 'O' && a3 == ' ')
                a3=p2;
            else if (a1 == a4 && a1 == 'O' && a7 == ' ')
                a7=p2;
            else if (a1 == a5 && a1 == 'O' && a9 == ' ')
                a9=p2;
            else if (a2 == a5 && a2 == 'O' && a8 == ' ')
                a8=p2;
            else if (a2 == a3 && a2 == 'O' && a1 == ' ')
                a1=p2;
            else if (a3 == a6 && a3 == 'O' && a9 == ' ')
                a9=p2;
            else if (a3 == a5 && a3 == 'O' && a7 == ' ')
                a7=p2;
            else if (a4 == a5 && a4 == 'O' && a6 == ' ')
                a6=p2;
            else if (a4 == a7 && a4 == 'O' && a1 == ' ')
                a1=p2;
            else if (a5 == a6 && a5 == 'O' && a4 == ' ')
                a4=p2;
            else if (a5 == a9 && a5 == 'O' && a1 == ' ')
                a1=p2;
            else if (a5 == a8 && a5 == 'O' && a2 == ' ')
                a2=p2;
            else if (a5 == a7 && a5 == 'O' && a3 == ' ')
                a3=p2;
            else if (a6 == a9 && a6 == 'O' && a3 == ' ')
                a3=p2;
            else if (a7 == a8 && a7 == 'O' && a9 == ' ')
                a9=p2;
            else if (a8 == a9 && a8 == 'O' && a7 == ' ')
                a7=p2;
            else if (a1 == a3 && a1 == 'O' && a2 == ' ')
                a2=p2;
            else if (a7 == a9 && a7 == 'O' && a8 == ' ')
                a8=p2;
            else if (a1 == a9 && a1 == 'O' && a5 == ' ')
                a5=p2;
            else if (a3 == a7 && a3 == 'O' && a5 == ' ')
                a5=p2;
            else if (a1 == a7 && a1 == 'O' && a4 == ' ')
                a4=p2;
            else if (a2 == a8 && a2 == 'O' && a5 == ' ')
                a5=p2;
            else if (a3 == a9 && a3 == 'O' && a6 == ' ')
                a6=p2;
            else if (a4 == a6 && a4 == 'O' && a5 == ' ')
                a5=p2;

            else{
                if(a5==' ') a5='O';
                else if(a1==' ') a1='O'; 
                else if(a3==' ') a3='O'; 
                else if(a7==' ') a7='O'; 
                else if(a9==' ') a9='O'; 
                else if(a8==' ') a8='O'; 
                else if(a4==' ') a4='O'; 
                else if(a6==' ') a6='O'; 
                else if(a2==' ') a2='O'; 
                
            }
    }   
    clear();     
}

void drawboard(){
    printw("\n");

    printw("      |     |     \n");
    attron(COLOR_PAIR(2));
    printw("   %c  |  %c  |  %c  \n",a1,a2,a3);
    attroff(COLOR_PAIR(2));
    printw(" _____|_____|_____\n");
    printw("      |     |     \n");
    attron(COLOR_PAIR(2));
    printw("   %c  |  %c  |  %c  \n",a4,a5,a6);
    attroff(COLOR_PAIR(2));
    printw(" _____|_____|_____\n");
    printw("      |     |     \n");
    attron(COLOR_PAIR(2));
    printw("   %c  |  %c  |  %c  \n",a7,a8,a9);
    attroff(COLOR_PAIR(2));
    printw("      |     |     \n");
    printw("\n");

}

int cheekWinner( ){
    attron(COLOR_PAIR(4));
    if(a1!=' '&& a1==a2 && a2==a3){

        printw(" WOW  %c is WIN\n Thanks for playing\n",a1);
        printw(" Play againe\n");
    }
    else if(a4!=' '&& a4==a5 && a5==a6){

       printw(" WOW %c is WIN\n Thanks for playing\n",a4);
       printw(" Play againe\n");
    }
    else if(a7!=' '&& a7==a8 && a8==a9){

        printw(" WOW %c is WIN\n Thanks for playing\n",a7);
        printw(" Play againe\n");
    }

     else if(a1!=' '&& a1==a4 && a4==a7){
        printw(" WOW %c is WIN\n Thanks for playing\n",a1);
        printw(" Play againe\n");
     }
    else if(a2!=' '&& a2==a5 && a5==a8){
        printw(" WOW %c is WIN\n Thanks for playing\n",a2);
        printw(" Play againe\n");
    }
    else if(a3!=' '&& a3==a6 && a6==a9){
        printw(" WOW %c is WIN\n Thanks for playing\n",a3);
        printw(" Play againe\n");
    }

    else if(a1!=' '&& a1==a5 && a5==a9){
        printw(" WOW %c is WIN\n Thanks for playing\n",a1);
        printw(" Play againe\n");
    }
    else if(a3!=' '&& a3==a5 && a5==a7){
        printw(" WOW %c is WIN\n Thanks for playing\n",a3);
        printw(" Play againe\n");
    }
    else {
        return 0;
    }
    attroff(COLOR_PAIR(4));
    return 1;
}

int cheekTie( ){

    for(int i=0;i<9;i++){
        if(a1==' '){
            return 0;
        }
        else if(a2==' '){
            return 0;
        }
        else if(a3==' '){
            return 0;
        }
        else if(a4==' '){
            return 0;
        } 
        else if(a5==' '){
            return 0;
        }
        else if(a6==' '){
            return 0;
        }
        else if(a7==' '){
            return 0;
        }
        else if(a8==' '){
            return 0;
        }
        else if(a9==' '){
            return 0;
        }
    }
    attron(COLOR_PAIR(4));
    printw(" It's a Tie !\n\n Thank's For playing \n\n");
    attroff(COLOR_PAIR(4));
    return 1;
 
}

