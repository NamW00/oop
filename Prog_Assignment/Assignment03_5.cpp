#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>

using namespace std;

// 추상 기상 클래스
class Shape {
public:
    virtual double getArea() const = 0;
    virtual bool intersects(double cx, double cy, double r) const = 0;
    virtual void print() const = 0;
    virtual ~Shape() {}
};

// 직사각형 클래스
class Rect : public Shape {
    int xmin, xmax, ymin, ymax;
public:
    Rect(int x1, int x2, int y1, int y2) : xmin(x1), xmax(x2), ymin(y1), ymax(y2) {}

    double getArea() const override {
        return (double)(xmax - xmin) * (ymax - ymin);
    }

    bool intersects(double cx, double cy, double r) const override {
        // 원의 중심 - 사각형 위 최단 거리 점 찾기
        double closestX = max((double)xmin, min(cx, (double)xmax));
        double closestY = max((double)ymin, min(cy, (double)ymax));

        double dx = cx - closestX;
        double dy = cy - closestY;

        // 피타고라스 정리 : 제곱 형태로 비교
        return (dx * dx + dy * dy) <= (r * r);
    }

    void print() const override {
        cout << "R " << xmin << " " << xmax << " " << ymin << " " << ymax << endl;
    }
};

// 원 클래스
class Circle : public Shape {
    int x, y, r;
public:
    Circle(int x, int y, int r) : x(x), y(y), r(r) {}

    double getArea() const override {
        return M_PI * r * r;
    }

    bool intersects(double cx, double cy, double cr) const override {
        double dx = x - cx;
        double dy = y - cy;
        double distanceSq = dx * dx + dy * dy;
        double radiusSum = (double)r + cr;

        return distanceSq <= (radiusSum * radiusSum);
    }

    void print() const override {
        cout << "C " << x << " " << y << " " << r << endl;
    }
};

bool compareShapes(Shape* a, Shape* b) {
    return a->getArea() < b->getArea();
}

int main() {
    int n;
    if (!(cin >> n)) return 0;

    vector<Shape*> shapes;

    for (int i = 0; i < n; ++i) {
        char type;
        cin >> type;
        if (type == 'R') {
            int x1, x2, y1, y2;
            cin >> x1 >> x2 >> y1 >> y2;
            shapes.push_back(new Rect(x1, x2, y1, y2));
        }
        else if (type == 'C') {
            int x, y, r;
            cin >> x >> y >> r;
            shapes.push_back(new Circle(x, y, r));
        }
    }

    // 추가로 주어지는 기준 원 정보
    int targetX, targetY, targetR;
    cin >> targetX >> targetY >> targetR;

    // 조건에 맞는 도형 필터링
    vector<Shape*> result;
    for (Shape* s : shapes) {
        if (s->intersects(targetX, targetY, targetR)) {
            result.push_back(s);
        }
    }

    // 면적 순 정렬
    sort(result.begin(), result.end(), compareShapes);

    for (Shape* s : result) {
        s->print();
    }

    for (Shape* s : shapes) {
        delete s;
    }

    return 0;
}