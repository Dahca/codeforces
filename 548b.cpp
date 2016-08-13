#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <cstdio>
using namespace std;

int main(){
    int n, m, q;
    // "Scan from stdin"
    scanf("%d %d %d", &n, &m, &q);
    // the next n lines describe the grid, and each line has m ints.
    //printf("> %d %d %d\n", n, m, q);
    // memory yay
    int** grid = new int*[n];
    for( int i = 0; i < n; i++){
        grid[i] = new int[m];
    }
    for( int x = 0; x < n; x++ ){
        string line;
        do{
            getline(cin, line);
        }while( line.size() <= 0);
        //printf("> \'%s\'\n", line.c_str());
        char* one_token = strtok((char*)line.c_str(), " ");
        for( int y = 0; y < m; y++ ){
            //printf("%s ", one_token);
            /*
             * This is an interesting function - it takes the string and returns the
             * first token it finds on the the initial input string. Then, if you give
             * it a NULL argument, it continues from the last string you gave it.
             */
            grid[x][y] = atoi(one_token);
            one_token = strtok(NULL, " ");
        }
    }
    // the next q lines contain information about the rounds
    for( int x = 0; x < q; x++ ){
        int i, j;
        string line;
        getline(cin, line);
        // normally const char*
        char* c_str = (char*) line.c_str();
        // "Scan from a string, not stdin" - the safe version
        sscanf(c_str, "%d %d", &i, &j);
        // the values range from 1 <= i,j <= n,m, so subtract 1 to match our system
        i--; j--;
        // invert the current state of the grid square
        grid[i][j] = ! grid[i][j];
        int global_max = 0;
        for( int i = 0; i < n; i++ ){
            int row_max = 0;
            int cur_count = 0;
            for( int j = 0; j <= m; j++ ){
                // update if needed
                row_max = cur_count > row_max ? cur_count : row_max;
                if( j == m ){
                    break;
                }
                // 1 is for eyes
                if( grid[i][j] ){
                    cur_count++;
                }
                else{
                    cur_count = 0;
                }

            }
            if ( row_max > global_max ){
                global_max = row_max;
            }
        }
        cout << global_max << endl;
    }
}
