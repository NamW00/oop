#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <set>

using namespace std;

class WordFinder {
private:
    set<string> dictionary;
    vector<vector<char>> grid;
    int gridSize;

    // 8방향 탐색을 위한 오프셋 (상, 하, 좌, 우, 대각선 4방향)
    const int dr[8] = { -1, 1, 0, 0, -1, -1, 1, 1 };
    const int dc[8] = { 0, 0, -1, 1, -1, 1, -1, 1 };

public:
    // 1. 사전 데이터 로드
    bool loadDictionary(const string& filename) {
        ifstream file(filename);
        if (!file.is_open()) return false;

        string word;
        while (file >> word) {
            dictionary.insert(word);
        }
        file.close();
        return true;
    }

    // 2. 격자 데이터 입력
    void inputGrid() {
        cin >> gridSize;
        grid.assign(gridSize, vector<char>(gridSize));
        for (int i = 0; i < gridSize; i++) {
            for (int j = 0; j < gridSize; j++) {
                cin >> grid[i][j];
            }
        }
    }

    // 3. 특정 단어가 격자에 존재하는지 검사 (내부 로직)
    bool searchWord(const string& target) {
        int len = target.length();

        for (int r = 0; r < gridSize; r++) {
            for (int c = 0; c < gridSize; c++) {
                // 시작 글자가 맞을 때만 탐색 시작
                if (grid[r][c] == target[0]) {
                    if (checkAllDirections(r, c, target)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }

    // 4. 특정 위치에서 8방향 탐색 (Helper 함수)
    bool checkAllDirections(int r, int c, const string& target) {
        for (int dir = 0; dir < 8; dir++) {
            int currR = r, currC = c;
            bool match = true;

            for (int k = 0; k < target.length(); k++) {
                if (isOutOfBounds(currR, currC) || grid[currR][currC] != target[k]) {
                    match = false;
                    break;
                }
                currR += dr[dir];
                currC += dc[dir];
            }
            if (match) return true;
        }
        return false;
    }

    // 5. 경계 검사 (Helper 함수)
    bool isOutOfBounds(int r, int c) {
        return (r < 0 || r >= gridSize || c < 0 || c >= gridSize);
    }

    // 6. 전체 찾기 실행 및 결과 출력
    void findAndPrint() {
        set<string> found;
        for (const string& target : dictionary) {
            if (searchWord(target)) {
                found.insert(target);
            }
        }

        for (const string& s : found) {
            cout << s << endl;
        }
    }
};

int main() {
    WordFinder wf;

    if (!wf.loadDictionary("dictionary.txt")) {
        cerr << "사전 파일을 열 수 없습니다." << endl;
        return 1;
    }

    wf.inputGrid();
    wf.findAndPrint();

    return 0;
}