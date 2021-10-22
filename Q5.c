#include <bits/stdc++.h>

using namespace std;
const int N = 2002;
int a[N][N], b[N][N], dirs[N][N], color[N / 2];
const int dx[] = {0, 0, -1};
const int dy[] = {-1, 1, 0};
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    //freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    if (n & 1) {
        cout << "NONE" <<endl;
        return 0;
    }
    for (int j = 0; j < n; j++) {
        // 第一行,最后一行，第一列，最后一列
        a[0][j] = a[n - 1][n - j - 1] = a[j][0] = a[n - j - 1][n - 1] = j / 2;
        b[0][j] = b[n - 1][n - j - 1] = b[j][0] = b[n - j - 1][n - 1] = 1;
        //1为向右边，0位左
//        dirs[0][j] = j & 1;
    }

    for(int i = 1; i < n - 1; ++i) {
        for(int j = 1; j < n - 1; ++j) {

            if(i == 1) {
                if(a[i - 1][j] == a[i - 1][j - 1]){
                    a[i][j] = a[i - 1][j + 1];
//                    b[i][j] = 1 ^ b[i - 1][j + 1];
                } else{
                    a[i][j] = a[i - 1][j - 1];
//                    b[i][j] = 1 ^ b[i - 1][j - 1];
                }
                continue;
            }


            if(a[i - 2][j] == a[i - 1][j - 1]){
                a[i][j] = a[i - 1][j + 1];
//                b[i][j] = 1 ^ b[i - 1][j + 1];
            }else{
                a[i][j] = a[i - 1][j - 1];
//                b[i][j] = 1 ^ b[i - 1][j - 1];
            }


        }

    }

//    for(int i = 0; i < n; ++i) {
//        for(int j = 0; j < n; ++j) {
//            cout<<a[i][j]<<"    ";
//        }
//         cout<<endl;
//    }

    // -1未涂色， 0颜色0,1 颜色1
    memset(color, -1, sizeof(color));
    // flag 是否有解
    bool flag = true;
    string s;
    for(int i = 0; i < n; ++i) {
        cin >> s;
        for(int j = 0; j < n; ++j){

            int col = (s[j] == 'S');
            if(i > 0 && i < n - 1 && j > 0 && j < n - 1) {
                //左上到右下的对角线
//                if(i == 2 && j == 2){
//                    cout<<"??ddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddd?"<<endl;
//                }
                if(a[i][j] == a[i - 1][j - 1] && a[i][j] == a[i + 1][j + 1]){
                    b[i][j] = 1 ^ b[i - 1][j - 1];
                }else{
                    b[i][j] = 1 ^ b[i - 1][j + 1];
                }
            }

            if(s[j] == '.') continue;
            if(!b[i][j]) col ^= 1;

            int &prv = color[a[i][j]];

            if(prv == -1 || prv == col) {
//                if(a[i][j] == 0){
//                    cout<<i<<" "<<j<<" "<<a[i][j]<<" "<<b[i][j]<<" "<<col<<" "<<b[i][j]<<endl;
//                }
                prv = col;
            } else{
//                cout<<j<<" "<<s[j]<<" "<<col<<" "<<prv<<" "<<a[i][j]<<" "<<b[i][j]<<endl;
                flag = false;
                goto out;
            }
        }
    }

out:
//    cout<<endl;
//    for(int i = 0; i < n; ++i) {
//        for(int j = 0; j < n; ++j) {
//            if(a[i][j] == 2)
//            cout<<b[i][j]<<"    ";
//            else{
//                cout<<'-'<<"    ";
//            }
//        }
//         cout<<endl;
//    }
    if(flag){
        int c = 0;
        for(int i = 0; i < n / 2; ++i) {
            c += color[i] != -1;
        }
        if(c == n / 2){
            cout<<"UNIQUE"<<endl;
            for(int i = 0; i < n; ++i) {
                for(int j = 0; j < n; ++j){
                    if(color[a[i][j]] == b[i][j]) {
                        cout<<'S';
                    } else{
                        cout<<'G';
                    }
                }
                cout<<endl;
            }

        } else{
            cout<<"MULTIPLE"<<endl;
        }

    } else{
        cout<<"NONE"<<endl;
    }

//    while(true) cin >> s;


    return 0;
}
