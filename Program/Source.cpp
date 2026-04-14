#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <set>

using namespace std;

int main() {
    set<string> dict;
    ifstream file("dictionary.txt");
    string word;
    while (file >> word) {
        dict.insert(word);
    }
    file.close();

    int N;
    cin >> N;
    vector<vector<char>> grid(N, vector<char>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> grid[i][j];
        }
    }

    set<string> found;

    int dr[] = { -1, 1, 0, 0, -1, -1, 1, 1 };
    int dc[] = { 0, 0, -1, 1, -1, 1, -1, 1 };

    for (const string& target : dict) {
        int len = target.length();
        bool isFound = false;

        for (int r = 0; r < N && !isFound; r++) {
            for (int c = 0; c < N && !isFound; c++) {

                if (grid[r][c] == target[0]) {
                    for (int dir = 0; dir < 8; dir++) {
                        int currR = r, currC = c;
                        bool match = true;

                        for (int k = 0; k < len; k++) {
                            if (currR < 0 || currR >= N || currC < 0 || currC >= N || grid[currR][currC] != target[k]) {
                                match = false;
                                break;
                            }
                            currR += dr[dir];
                            currC += dc[dir];
                        }

                        if (match) {
                            found.insert(target);
                            isFound = true;
                            break;
                        }
                    }
                }
            }
        }
    }

    for (const string& s : found) {
        cout << s << endl;
    }

    return 0;
}