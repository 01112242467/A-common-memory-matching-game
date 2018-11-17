#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;


int main()
{
    //random function
    int a[8],c=0;
    for(int i = 0; i < 8; ++i)
    {
        a[i] = 0;
    }
    int n, mat[4][4];
    srand((unsigned)time(NULL));
    for(int i = 0; i < 4; ++i)
    {
        for(int j = 0; j < 4; ++j)
        {
            n = rand()%8;
            if(a[n] == 2)
            {
                --j;
                continue;
            }
            else
            {
                mat[i][j] = n+1;
                a[n]++;
            }
        }
    }
    for(int i = 0; i < 4; ++i)
    {
        for(int j = 0; j < 4; ++j)
            cout << mat[i][j] << ((j+1 == 4) ? '\n': ' ');
    }
    cout<<endl;
    cout<<"   "<<"0"<< "  "<<"1"<<"  "<<"2"<<"  "<<"3"<<endl;
    for(int i = 0; i < 4; ++i)
    {
        for(int j = 0; j < 4; ++j)
        {
            if(j==0)
            {
                cout<<c<<"  ";
                c++;
            }
        cout << "*" << "  ";
    }
    cout<<endl;
    }
    //the game

    vector<int>v;
    while(true)
    {
        cout<<"please enter the number of row and col to choose your first photo "<<endl;
        int x1,y1,x2,y2,c=0;
        cin>>x1>>y1;
        cout<<"please enter the number of row and col to choose your second photo "<<endl;
        cin>>x2>>y2;
        if(mat[x1][y1]==mat[x2][y2])
        {
            v.push_back(mat[x1][y1]);
           c+=1;
            for(int i=0 ; i<4 ; i++)
            {
                for(int j=0 ; j<4 ; j++)
                {
                    if(find(v.begin(), v.end(), mat[i][j]) != v.end())
                        cout<<mat[i][j]<<"  ";
                    else
                        cout<<"*"<<"  ";
                }
                cout<<endl;
            }
        }
        else
        {
            for(int i=0 ; i<4 ; i++)
            {
                for(int j=0 ; j<4 ; j++)
                {
                    if((i==x1 &&j==y1) || (i==x2 && j==y2) ||(find(v.begin(), v.end(), mat[i][j]) != v.end()) )
                        cout<<mat[i][j]<<"  ";
                    else
                    {
                        cout<<"*"<<"  ";
                    }

                }
                cout<<endl;
            }
            cout<<endl<<endl;
            for(int i=0 ; i<4 ; i++)
            {
                for(int j=0 ; j<4 ; j++)
                {
                    if(find(v.begin(), v.end(), mat[i][j]) != v.end())
                        cout<<mat[i][j]<<"  ";
                    else

                        cout<<"*"<<"  ";
                }
                cout<<endl;
            }
        }
        if(c==8)
        {
            cout<<"congratulation ! "<<endl;
            break;
        }
    }
    return 0;
}

