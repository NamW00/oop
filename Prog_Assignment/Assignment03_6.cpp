#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

struct Rectangle {
    long long x1, y1, x2, y2;
    long long area;

    void calculateArea() {
        area = (x2 - x1) * (y2 - y1);
    }
};

int main() {
    int N;
    if (scanf("%d", &N) != 1) return 0;

    vector<Rectangle> rects(N);
    for (int i = 0; i < N; ++i) {
        scanf("%lld %lld %lld %lld", &rects[i].x1, &rects[i].y1, &rects[i].x2, &rects[i].y2);
        rects[i].calculateArea();
    }

    double alpha;
    scanf("%lf", &alpha);

    long long max_enclosing_area = -1;
    double best_coverage = 0;

    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            long long enc_x1 = min(rects[i].x1, rects[j].x1);
            long long enc_y1 = min(rects[i].y1, rects[j].y1);
            long long enc_x2 = max(rects[i].x2, rects[j].x2);
            long long enc_y2 = max(rects[i].y2, rects[j].y2);
            long long enclosing_area = (enc_x2 - enc_x1) * (enc_y2 - enc_y1);

            if (enclosing_area == 0) continue;

            long long inter_x = max(0LL, min(rects[i].x2, rects[j].x2) - max(rects[i].x1, rects[j].x1));
            long long inter_y = max(0LL, min(rects[i].y2, rects[j].y2) - max(rects[i].y1, rects[j].y1));
            long long intersection_area = inter_x * inter_y;

            long long union_area = rects[i].area + rects[j].area - intersection_area;

            double coverage = (double)union_area / enclosing_area;

            if (coverage >= alpha) {
                if (enclosing_area > max_enclosing_area) {
                    max_enclosing_area = enclosing_area;
                    best_coverage = coverage;
                }
            }
        }
    }

    if (max_enclosing_area != -1) {
        printf("%.6f %lld\n", best_coverage, max_enclosing_area);
    }

    return 0;
}
/*
#include <iomanip> // setprecision 출력 범위 지정하기 fixed

struct Rect {
    int x1, y1, x2, y2;
};
int area(Rect r) {
    return (r.x2 - r.x1) * (r.y2 - r.y1);
}
int overapArea(Rect a, Rect b) {
    int w = min(a.x2, b.x2) - max(a.x1, b.x1);
    int h = min(a.y2, b.y2) - max(a.y1, b.y1);

}

int encloseArea(Rect a, Rect b) {

}

int main() {
    double bestCoverage = 0.0;
    int bstEnclose
}*/