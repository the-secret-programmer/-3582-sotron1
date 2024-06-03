#include <fstream>

using namespace std;

ifstream cin("sotron1.in");
ofstream cout("sotron1.out");

bool isBlack(int i, int j){
if(i%2==0){
    return !(j%2);
}
else{
    return j%2;
}
}

const int N = 240;

int v[N+1][N+1];

int main()
{
    int n;

    cin>>n;

    for (int i = 1; i<=n;i++){
        for (int j = 1; j<=n;j++){
            cin>>v[i][j];
        }
    }
    int sumax = -100;


    for (int ln = 1; ln<=n;ln++){
        int i = ln, j = 1;
        int s_c = 0;
        while(i<=n&&j<=n&&i>=1&&j>=1){
            int x_i = v[i][j];

            if(s_c<0){
                s_c=x_i;
            }
            else{
                s_c+=x_i;
            }
            sumax = max(sumax,s_c);
            if(isBlack(i,j)){
                i--;
            }
            else{
                j++;
            }
        }
    }

    for (int cl = 1; cl<=n;cl++){
        int i = n, j = cl;
        int s_c = 0;
        while(i<=n&&j<=n&&i>=1&&j>=1){
            int x_i = v[i][j];

            if(s_c<0){
                s_c=x_i;
            }
            else{
                s_c+=x_i;
            }
            sumax = max(sumax,s_c);
            if(isBlack(i,j)){
                i--;
            }
            else{
                j++;
            }
        }
    }

    cout<<sumax;
    return 0;
}
