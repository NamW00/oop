#include <iostream>
#include <vector>
#include <string>

using namespace std;

int N;
int board[20][20];

// 탐색 방향: 가로, 세로, 우하 대각선, 좌하 대각선
int dr[] = { 0, 1, 1, 1 };
int dc[] = { 1, 0, 1, -1 };

bool checkWinner(int r, int c, int color) {
    for (int i = 0; i < 4; i++) {
        int count = 1;

        // 정방향 탐색
        int nr = r + dr[i];
        int nc = c + dc[i];
        while (nr >= 0 && nr < N && nc >= 0 && nc < N && board[nr][nc] == color) {
            count++;
            nr += dr[i];
            nc += dc[i];
        }

        // 역방향 탐색 (이전 돌이 같은 색인지 확인하여 육목 및 중복 체크 방지)
        int pr = r - dr[i];
        int pc = c - dc[i];

        // 만약 5개가 연속되고, 시작점 이전의 돌이 같은 색이 아니라면 (새로운 오목의 시작점)
        if (count == 5) {
            if (pr < 0 || pr >= N || pc < 0 || pc >= N || board[pr][pc] != color) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (!(cin >> N)) return 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }

    int winner = 0; // 0: No Winner, 1: Black, 2: White

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j] != 0) {
                if (checkWinner(i, j, board[i][j])) {
                    winner = board[i][j];
                    goto end_search; // 승자를 찾으면 즉시 종료
                }
            }
        }
    }

end_search:
    if (winner == 1) cout << "Black" << endl;
    else if (winner == 2) cout << "White" << endl;
    else cout << "No Winner" << endl;

    return 0;
}