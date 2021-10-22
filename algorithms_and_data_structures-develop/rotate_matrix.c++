#include <vector>
#include <iostream>
#include <cmath>
#include <sstream>
#include <cassert>
using namespace std;

void rotateLeftSingle(vector<int>& vec)
{
    int first = vec[0];
    for (unsigned int i = 0; i < vec.size()-1; ++i) {
        vec[i] = vec[+i];
    }
    vec[vec.size() -1] = first;
}

void rotate(vector<int> & vec, long r) {
    r = r % vec.size();
    for ( int i = 0; i < r; ++i) {
        rotateLeftSingle(vec);
    }
}


int main() {
    long M, N, R;
    cin >> M >> N >> R;
    int ** matrix = new int*[M];
    for ( int i = 0; i < M; ++i) {
        matrix[i] = new int[N];
    }
    for ( int i = 0; i < M; ++i) {
        for ( int j = 0; j < N; ++j) {
            cin >> matrix[i][j];
        }
    }
    int a  = 0, b = N-1, c = M-1, d = 0;
    int al, bl, cl, dl;
    while( a < c && d < b ) {
        vector<int> currLevel;
        al = a;
        bl = b;
        cl = c;
        dl = d;
        for ( int j = d; j <= b; ++j ) {
            currLevel.push_back(matrix[a][j]);
        }
        ++a;
        for ( int i = a; i <= c; ++i ) {
            currLevel.push_back(matrix[i][b]);
        }
        --b;
        for ( int j = b; j >= d; --j ) {
            currLevel.push_back(matrix[c][j]);
        }
        --c;
        for ( int i = c; i >= a; --i ) {
            currLevel.push_back(matrix[d][i]);
        }
        ++d;
        rotate(currLevel, R);
        int k = 0;


        for ( int j = dl; j <= bl; ++j ) {
            matrix[al][j] = currLevel[k];
            ++k;
        }
        ++al;
        for ( int i = al; i <= cl; ++i ) {
            matrix[i][bl] = currLevel[k];
            ++k;
        }
        --bl;
        for ( int j = bl; j >= dl; --j ) {
            matrix[cl][j] = currLevel[k];
            ++k;
        }
        --cl;
        for ( int i = cl; i >=al; --i ) {
            matrix[i][dl] = currLevel[k];
            ++k;
        }
        ++dl;
    }


    for ( int i = 0; i < M; ++i ) {
        for ( int j = 0; j < N; ++j ){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}