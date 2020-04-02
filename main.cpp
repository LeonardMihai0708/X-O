#include <iostream>

using namespace std;
int Start(){
    char h[4][4];
    cout<<"Hey! Good to see you!"<<endl;
    cout<<"Let's Play"<<endl;
    for(int i=1; i<=3;i++)
        for(int j=1; j<=3;j++)
            h[i][j]='*';
    for(int i=1; i<=3;i++)
        {
            for(int j=1; j<=3;j++)
                cout<<h[i][j];
            cout<<endl;
        }
    cout<<"What's the position? (with the numbers (right side of keyboard))"<<endl;
}

void citireVector(char v[4][4]){
    for(int i=1; i<=3; i++)
        for(int j=1; j<=3;j++)
            v[i][j]=' ';
}

void afisareVector(char v[4][4]){
    for(int i=1; i<=3; i++)
        {
            for(int j=1; j<=3;j++)
                cout<<v[i][j]<<" ";
            cout<<endl;
        }
}

int verify_Game(char v[4][4]){
    if((v[1][1]== 'x' && v[1][2]== 'x' && v[1][3]== 'x') || (v[1][1]== 'o' && v[1][2]== '0' && v[1][3]== '0'))
        return 0;
    if((v[2][1]== 'x' && v[2][2]== 'x' && v[2][3]== 'x') || (v[2][1]== 'o' && v[2][2]== 'o' && v[2][3]== 'o'))
        return 0;
    if((v[3][1]== 'x' && v[3][2]== 'x' && v[3][3]== 'x') || (v[3][1]== 'o' && v[3][2]== 'o' && v[3][3]== 'o'))
        return 0;
    if((v[1][1]== 'x' && v[2][2]== 'x' && v[3][3]== 'x') || (v[1][1]== 'o' && v[2][2]== 'o' && v[3][3]== 'o'))
        return 0;
    if((v[3][1]== 'x' && v[2][2]== 'x' && v[1][3]== 'x') || (v[3][1]== 'o' && v[2][2]== 'o' && v[1][3]== 'o'))
        return 0;
    if((v[1][1]== 'x' && v[2][1]== 'x' && v[3][1]== 'x') || (v[1][1]== 'o' && v[2][1]== 'o' && v[3][1]== 'o'))
        return 0;
    if((v[1][2]== 'x' && v[2][2]== 'x' && v[3][2]== 'x') || (v[1][2]== 'o' && v[2][2]== 'o' && v[3][2]== 'o'))
        return 0;
    if((v[1][3]== 'x' && v[2][3]== 'x' && v[3][3]== 'x') || (v[1][3]== 'o' && v[2][3]== 'o' && v[3][3]== 'o'))
        return 0;
    return 1;
}

int play_again(){
    int y;
    cout<<endl;
    cout<<"Play again? (1 -> yes; 0 -> nope)";
    cin>>y;
    if(y==1)
        return 1;
    else return 0;
}

int verify_take(char v[4][4], int press){
    if(press == 7 && (v[1][1]=='x' || v[1][1]=='o'))
        return 1;
    if(press == 8 && (v[1][2]=='x' || v[1][2]=='o'))
        return 1;
    if(press == 9 && (v[1][3]=='x' || v[1][3]=='o'))
        return 1;
    if(press == 4 && (v[2][1]=='x' || v[2][1]=='o'))
        return 1;
    if(press == 5 && (v[2][2]=='x' || v[2][2]=='o'))
        return 1;
    if(press == 6 && (v[2][3]=='x' || v[2][3]=='o'))
        return 1;
    if(press == 1 && (v[3][1]=='x' || v[3][1]=='o'))
        return 1;
    if(press == 2 && (v[3][2]=='x' || v[3][2]=='o'))
        return 1;
    if(press == 3 && (v[3][3]=='x' || v[3][3]=='o'))
        return 1;
    return 0;
}

int game_overfor(char v[4][4]){
    int kk=1;
    for(int i=1;i<=3;i++)
        for(int j=1;j<=3;j++)
            if(v[i][j] == ' ')
                kk=0;
    if(kk==0)
        return 0;
    else return 1;
}

void onGame(char v[4][4]){
    int nr=1,ok=1,press, ok2=0,y=0;
    cin>>press;
    while(ok==0 || ok!=3){
        if(press == 1){
            if(nr%2 == 1)
                v[3][1] = 'x';
                else v[3][1] = 'o';
        }
        if(press == 2){
            if(nr%2 == 1)
                v[3][2] = 'x';
                else v[3][2] = 'o';
        }
        if(press == 3){
            if(nr%2 == 1)
                v[3][3] = 'x';
                else v[3][3] = 'o';
        }
        if(press == 4){
            if(nr%2 == 1)
                v[2][1] = 'x';
                else v[2][1] = 'o';
        }
        if(press == 5){
            if(nr%2 == 1)
                v[2][2] = 'x';
                else v[2][2] = 'o';
        }
        if(press == 6){
            if(nr%2 == 1)
                v[2][3] = 'x';
                else v[2][3] = 'o';
        }
        if(press == 7){
            if(nr%2 == 1)
                v[1][1] = 'x';
                else v[1][1] = 'o';
        }
        if(press == 8){
            if(nr%2 == 1)
                v[1][2] = 'x';
                else v[1][2] = 'o';
        }
        if(press == 9){
            if(nr%2 == 1)
                v[1][3] = 'x';
                else v[1][3] = 'o';
        }

        ok = verify_Game(v);
        afisareVector(v);
        int gof = game_overfor(v);
        if(gof == 1)
            {
                ok==3;
                cout<<"No player win";
                break;
            }
        if(ok==0)
            {
                cout<<"Game Over"<<endl;
                cout<<"The winner is:";
                if(nr%2==1) cout<<" Player 1."; else cout<<" Player 2.";
                break;
            } else cin>>press;
        int ver = verify_take(v,press);
        while(ver!=0 && ok==1){
            if(ver == 1)
                {
                    cout<<"This position is occupied"<<endl;
                    cin>>press;
                    ver = verify_take(v,press);
                }
        }
        nr++;
    }
}

int main()
{
    char v[4][4],k=1;
    int a;
    do{
        citireVector(v);
        Start();
        onGame(v);
        a= play_again();
        if(a != 1)
            k=0;
    }while(k==1);
    return 0;
}
