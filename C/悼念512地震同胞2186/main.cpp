#include <iostream>
#include <stdio.h>
#include <string.h>


using namespace std;

int main()
{
    int n;
    int volunteers;
    int team1,team2,team3;
    int guide1,guide2,guide3;
    while(scanf("%d",&n)!=EOF){
        for(int i=0;i<n;i++){
            scanf("%d",&volunteers);
            team1 = volunteers/2;
            team2 = (volunteers - team1)*2/3;
            team3 = volunteers - team1 - team2;
            if(team1%10!=0)    guide1 = team1/10+1;
            else guide1 = team1/10;
            if(team2%10!=0)guide2 = team2/10+1;
            else guide2 = team2/10;
            if(team3%10!=0) guide3 = team3/10+1;
            else guide3 = team3/10;
            cout<<guide1+guide2+guide3<<endl;
        }
    }
    return 0;
}
