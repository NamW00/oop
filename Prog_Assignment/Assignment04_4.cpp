#include <iostream>
using namespace std;
const double PI = 3.14159165358979323846;

class Circle {
private:
    int x, y, r;
public:
    Circle(int x, int y, int r) :x(x), y(y), r(r) {}
    int getX() { return x; }
    int getY() { return y; }
    int getR() { return r; }

    double getArea() {
        return PI * r * r;
    }

    bool inter_otherCir(Circle& other) {
        int dx = x - other.x;
        int dy = y - other.y;
        int distSq = dx * dx + dy * dy;
        int rSum = r + other.r;
        int rDiff = r - other.r;

        return distSq <= rSum * rSum;
    }

    void print() {
        cout << "C " << x << " " << y << " " << r << "\n";
    }
};

class Rect {
private:
    int xmin, xmax, ymin, ymax;
public:
    Rect(int xmin, int xmax, int ymin, int ymax)
        : xmin(xmin), xmax(xmax), ymin(ymin), ymax(ymax) {}
    double getArea() {
        return (xmax - xmin) * (ymax - ymin);
    }

    bool inter_otherCir(Circle& circle) {
        int cx = circle.getX();
        int cy = circle.getY();
        int cr = circle.getR();

        // 1. 사각형의 성분 중 원의 중심과 가장 가까운 점 구하기
        int nx = (cx < xmin) ? xmin : ((cx > xmax) ? xmax : cx);
        int ny = (cy < ymin) ? ymin : ((cy > ymax) ? ymax : cy);

        int dx = cx - nx;
        int dy = cy - ny;
        if (dx * dx + dy * dy <= cr * cr) {
            return true; // 원이 사각형과 겹침 or 사각형이 원을 포함/접함
        }

        //2. 사각형이 원 내부에 있는 경우(포함)
        auto inCirc = [&](int px, int py) {
            int dxx = cx - px;
            int dyy = cy - py;
            return dxx * dxx + dyy * dyy <= cr * cr;
            };
        // 모든 점이 원 내부에 있는지
        if (inCirc(xmin, ymin) && inCirc(xmin, ymax) &&
            inCirc(xmax, ymin) && inCirc(xmax, ymax)) {
            return true;
        }

        return false;
    }
    void print() {
        cout << "R " << xmin << " " << xmax << " " << ymin << " " << ymax << "\n";
    }
};

struct Node {
    char type;
    Circle* cPtr;
    Rect* rPtr;
    double area;
    Node* next;

    Node(Circle* c) : type('C'), cPtr(c), rPtr(nullptr), area(c->getArea()), next(nullptr) {}
    Node(Rect* r) : type('R'), cPtr(nullptr), rPtr(r), area(r->getArea()), next(nullptr) {}

    ~Node() {
        if (cPtr) delete cPtr;
        if (rPtr) delete rPtr;
    }

    void print() {
        if (type == 'C') cPtr->print();
        else if (type == 'R') rPtr->print();
    }
};

int main() {
    return 0;
}