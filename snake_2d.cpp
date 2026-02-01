#include<bits/stdc++.h>
#include<Windows.h>
#include<conio.h>
using namespace std;

enum Direction{STOP=0,LEFT,RIGHT,UP,DOWN};
Direction dir;

bool gameover;
const int height=20;
const int width=20;

int headX,headY,fruitX,fruitY,score;
int tailX[100],tailY[100];
int tail_length;

void setup();
void draw();
void input();
void logic();

int main()
{
    char start;
    cout<<"\t------------------"<<endl;
    cout<<"\t\t :Snake king: "<<endl;
    cout<<"\t------------------"<<endl;
    cout<<"Press 's' to start: ";
    cin>>start;

    if(start=='s')
    {
        setup();
        while(!gameover)
        {
            draw();
            input();
            logic();
            Sleep(80);
        }
    }
    return 0;
}

void setup()
{
    gameover=false;
    dir=STOP;
    headX=width/2;
    headY=height/2;
    srand(time(0));
    fruitX=rand()%(width-1);
    fruitY=rand()%(height-1);
    score=0;
    tail_length=0;
}

void draw()
{
    system("cls");

    cout<<"\t\t";
    for(int i=0;i<width;i++)
    {
        cout<<"#";
    }
    cout<<endl;

    for(int i=0;i<height;i++)
    {
        for(int j=0;j<width;j++)
        {
            if(j==0)
            {
                cout<<"\t\t#";
            }

            if(i==headY && j==headX)
            {
                cout<<"O";
            }
            else if(i==fruitY && j==fruitX)
            {
                cout<<"F";
            }
            else
            {
                bool print=false;
                for(int k=0;k<tail_length;k++)
                {
                    if(tailX[k]==j && tailY[k]==i)
                    {
                        cout<<"o";
                        print=true;
                        break;
                    }
                }
                if(!print)
                {
                    cout<<" ";
                }
            }

            if(j==width-1)
            {
                cout<<"#";
            }
        }
        cout<<endl;
    }

    cout<<"\t\t";
    for(int i=0;i<width;i++)
    {
        cout<<"#";
    }
    cout<<endl;
    cout<<"\t\tScore: "<<score<<endl;
}

void input()
{
    if(_kbhit())
    {
        switch(getch())
        {
            case 'a':
            dir=LEFT;
            break;

            case 'd':
            dir=RIGHT;
            break;

            case 'w':
            dir=UP;
            break;

            case 's':
            dir=DOWN;
            break;

            case 'x':
            gameover=true;
            break;

            default:
            break;
        }
    }
}

void logic()
{
    int prevx=tailX[0];
    int prevy=tailY[0];
    int prev2x,prev2y;

    tailX[0]=headX;
    tailY[0]=headY;

    for(int i=1;i<tail_length;i++)
    {
        prev2x=tailX[i];
        prev2y=tailY[i];
        tailX[i]=prevx;
        tailY[i]=prevy;
        prevx=prev2x;
        prevy=prev2y;
    }

    switch(dir)
    {
        case LEFT:
        headX--;
        break;

        case RIGHT:
        headX++;
        break;

        case UP:
        headY--;
        break;

        case DOWN:
        headY++;
        break;

        default:
        break;
    }

    if(headX>=width)
    {
        headX=0;
    }
    else if(headX<0)
    {
        headX=width-1;
    }

    if(headY>=height)
    {
        headY=0;
    }
    else if(headY<0)
    {
        headY=height-1;
    }

    for(int i=0;i<tail_length;i++)
    {
        if(tailX[i]==headX && tailY[i]==headY)
        {
            gameover=true;
        }
    }

    if(headX==fruitX && headY==fruitY)
    {
        score+=10;
        fruitX=rand()%(width-1);
        fruitY=rand()%(height-1);
        tail_length++;
    }
}
