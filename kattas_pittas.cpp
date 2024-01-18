#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

void printBoard(char board[3][3]);
bool game(char board[3][3],int n,char ch);
bool konjeta(char board[3][3]);

int main()
{
    here:
    cout<<endl<<"kattas pittas khelne ke liye khuch niyam\nkisi block pr apna nishan rakhne ke liye us par likhe number type karen\nnmuber is praksr hai.."<<endl<<endl;
    cout<<"1"<<" | "<<"2"<<" | "<<"3"<<endl;
    cout<<"  |   |  "<<endl;
    cout<<"--+---+--"<<endl;
    cout<<"4"<<" | "<<"5"<<" | "<<"6"<<endl;
    cout<<"  |   |  "<<endl;
    cout<<"--+---+--"<<endl;
    cout<<"7"<<" | "<<"8"<<" | "<<"9"<<endl;
    cout<<"  |   |  "<<endl;
    cout<<"Aur ek aur baat agar apne bhari hui jagah ko phir se bhari toh hum aapko nahi chodenge"<<endl;
    cout<<"Aap kattas pittas khelne ke liye taiyaar hai"<<endl;
    cout<<"Game ko start karne ke liye koi bhi alphabet daba dijiye :";
    string start;
    getline(cin,start);
    char board[3][3];
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        board[i][j]=' ';
    }
    printBoard(board);
    char ch;
    int n;
    int count=0;
    while(true)
    {
        cout<<"*****************************************************KATTAS KI BARI**************************"<<endl;
        cout<<"'X' ka nishan banane ke liye number type karen :";
        ch='X';
        where :
        cin>>n;
        if((n>=1 && n<=9) && (game(board,n,ch) == true))
        {printBoard(board);}
        else
        {
            cout<<"YEEH KYA KAI"<<endl<<"BETA ABHI BAHUT KHUCH HAI SEEKHNE KO ZINDGI MEIN....................................."<<endl;
            cout<<"KRAPIYA KATTAS PHIR SE NUMBER TYPE KAREN";
            goto where;
        }
        count++;
        
        if(konjeta(board)==true)
        {
            cout<<"***************************************************KATTAS JEET GAYA HAI***********************************"<<endl;
            break;
        }
        if(count==9)
        {
            cout<<"No one wins"<<endl;
            break;
        }
        cout<<"*******************************************************PITTAS KI BARI***************************"<<endl;
        cout<<"'O' ka nishan banane ke liye number type karen : ";
        ch='O';
        there:
        cin>>n;
        if((n>=1 && n<=9) && (game(board,n,ch) == true))
        {printBoard(board);}
        else
        {
            cout<<"YEEH KYA KAI"<<endl<<"BETA ABHI BAHUT KHUCH HAI SEEKHNE KO ZINDGI MEIN...."<<endl;
            cout<<"KRAPIYA PITTAS PHIR SE NUMBER DALE";
            goto there;
        }
        count++;
        if(konjeta(board)==true)
        {
            cout<<"***************************************************PITTAS JEET GAYA HAI****************************************"<<endl;
            break;
        }
    }
    cout<<endl<<"If you wanna play again say y for yes and n for no"<<endl;
    char play;
    cin>>play;
    if(play=='y')
    goto here;
    else if(play=='n')
    cout<<endl<<endl<<"************************************************AAPKA DIN MANGALMAY HO*******************************************"<<endl;
    else
    cout<<endl<<endl<<"************************************************AAPSE SAHI VALUE BHI NAHI DALI KRAPIYA HAME TOH JANE DE.*********************************"<<endl;
    return 0;
}

void printBoard(char board[3][3])
{
    cout<<board[0][0]<<" | "<<board[0][1]<<" | "<<board[0][2]<<endl;
    cout<<"  |   |  "<<endl;
    cout<<"--+---+--"<<endl;
    cout<<board[1][0]<<" | "<<board[1][1]<<" | "<<board[1][2]<<endl;
    cout<<"  |   |  "<<endl;
    cout<<"--+---+--"<<endl;
    cout<<board[2][0]<<" | "<<board[2][1]<<" | "<<board[2][2]<<endl;
    cout<<"  |   |  "<<endl;
}

bool game(char board[3][3],int n,char ch)
{
    switch(n)
    {
        case 1:
        if(board[0][0]==' ')
        {
            board[0][0]=ch;
            return true;
            break;
        }
        else
        return false;
        break;
        case 2:
        if(board[0][1]==' ')
        {
            board[0][1]=ch;
            return true;
            break;
        }
        else
        return false;
        break;
        case 3:
        if(board[0][2]==' ')
        {
            board[0][2]=ch;
            return true;
            break;
        }
        else
        return false;
        break;
        case 4:
        if(board[1][0]==' ')
        {
            board[1][0]=ch;
            return true;
            break;
        }
        else
        return false;
        break;
        case 5:
        if(board[1][1]==' ')
        {
            board[1][1]=ch;
            return true;
            break;
        }
        else
        return false;
        break;
        case 6:
        if(board[1][2]==' ')            
        {
            board[1][2]=ch;
            return true;
            break;
        }
        else
        return false;
        break;
        case 7:
        if(board[2][0]==' ')
        {
            board[2][0]=ch;
            return true;
            break;
        }
        else
        return false;
        case 8:
        if(board[2][1]==' ')
        {
            board[2][1]=ch;
            return true;
            break;
        }
        else
        return false;
        break;
        case 9:
        if(board[2][2]==' ')
        {
            board[2][2]=ch;
            return true;
            break;
        }
        else
        return false;
        break;
        default:
        cout<<"Apka khuch nahi ho sakta"<<endl;
        return false;
        break;
    }
}

bool konjeta(char board[3][3])
{
    if((board[0][0]=='X' && board[0][1]=='X' && board[0][2]=='X') || (board[0][0]=='O' && board[0][1]=='O' && board[0][2]=='O'))
    return true;
    else if((board[1][0]=='X' && board[1][1]=='X' && board[1][2]=='X') || (board[1][0]=='O' && board[1][1]=='O' && board[1][2]=='O'))
    return true;
    else if((board[2][0]=='X' && board[2][1]=='X' && board[2][2]=='X') || (board[2][0]=='O' && board[2][1]=='O' && board[2][2]=='O'))
    return true;
    else if((board[0][0]=='X' && board[1][0]=='X' && board[2][0]=='X') || (board[0][0]=='O' && board[1][0]=='O' && board[2][0]=='O'))
    return true;
    else if((board[0][1]=='X' && board[1][1]=='X' && board[2][1]=='X') || (board[0][1]=='O' && board[1][1]=='O' && board[2][1]=='O'))
    return true;
    else if((board[0][2]=='X' && board[1][2]=='X' && board[2][2]=='X') || (board[0][2]=='O' && board[1][2]=='O' && board[2][2]=='O'))
    return true;
    else if((board[0][0]=='X' && board[1][1]=='X' && board[2][2]=='X') || (board[0][0]=='O' && board[1][1]=='O' && board[2][2]=='O'))
    return true;
    else if((board[0][2]=='X' && board[1][1]=='X' && board[2][0]=='X') || (board[0][2]=='O' && board[1][1]=='O' && board[2][0]=='O'))
    return true;
    else 
    return false;
} 
/*
        __________
            |          ____                            ____
            |  |   |  |    |   |\  | | /       \   /  |    |  |    |
            |  |---|  |____|   | \ | |/         \_/   |    |  |    |
            |  |   |  |    |   |  \| | \         |    |____|  |____| */