#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Line {
    int x1, y1, x2, y2;
};

struct Point {
    int x, y;

    bool operator<(const Point& other) const {
        if (x != other.x) return x < other.x;
        return y < other.y;
    }
};

bool intersect(Line h, Line v, Point& res) {
    if (v.x1 >= h.x1 && v.x1 <= h.x2 && h.y1 >= v.y1 && h.y1 <= v.y2) {
        res.x = v.x1;
        res.y = h.y1;
        return true;
    }
    return false;
}

int main() {
    int N;
    if (!(cin >> N)) return 0;

    vector<Line> hor, ver;

    for (int i = 0; i < N; ++i) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if (y1 == y2) {
            hor.push_back({ x1, y1, x2, y2 });
        }
        else {
            ver.push_back({ x1, y1, x2, y2 });
        }
    }

    vector<Point> intersections;
    for (const auto& h : hor) {
        for (const auto& v : ver) {
            Point p;
            if (intersect(h, v, p)) {
                intersections.push_back(p);
            }
        }
    }

    sort(intersections.begin(), intersections.end());

    for (const auto& p : intersections) {
        cout << "[" << p.x << ", " << p.y << "]" << endl;
    }

    return 0;
}