#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Point {
public:
    int x, y;

    bool equals(const Point& P) const {
        return (x == P.x && y == P.y);
    }
};

bool cw(const Point& a, const Point& b, const Point& c) {
    return a.x * (c.y - b.y) + b.x * (a.y - c.y) + c.x * (b.y - a.y) > 0;
}

bool ccw(const Point& a, const Point& b, const Point& c) {
    return a.x * (c.y - b.y) + b.x * (a.y - c.y) + c.x * (b.y - a.y) < 0;
}

bool cll(const Point& a, const Point& b, const Point& c) {
    return a.x * (c.y - b.y) + b.x * (a.y - c.y) + c.x * (b.y - a.y) == 0;
}

vector<Point> convex_hull(vector<Point>& points) {
    if (points.size() <= 2) return points;

    sort(points.begin(), points.end(), [](const Point& o1, const Point& P) {
        if (o1.x == P.x) return o1.y - P.y;
        return o1.x - P.x;
    });

    vector<Point> up, down;
    Point first = points.front(), last = points.back();

    up.push_back(first);
    down.push_back(first);

    for (size_t i = 1; i < points.size(); ++i) {
        if (i == points.size() - 1 || !ccw(first, points[i], last)) {
            while (up.size() >= 2 && ccw(up[up.size() - 2], up.back(), points[i])) {
                up.pop_back();
            }
            up.push_back(points[i]);
        }
        if (i == points.size() - 1 || !cw(first, points[i], last)) {
            while (down.size() >= 2 && cw(down[down.size() - 2], down.back(), points[i])) {
                down.pop_back();
            }
            down.push_back(points[i]);
        }
    }

    points.clear();
    for (const auto& p : up) points.push_back(p);
    for (size_t i = down.size() - 2; i > 0; --i) points.push_back(down[i]);

    sort(points.begin(), points.end(), [](const Point& o1, const Point& P) {
        if (o1.x == P.x) return o1.y - P.y;
        return o1.x - P.x;
    });

    points.erase(unique(points.begin(), points.end(), [](const Point& a, const Point& b) { return a.equals(b); }), points.end());

    return points;
}

int main() {
    vector<Point> points = {
        {0, 0},
        {1, 1},
        {2, 2},
        {0, 2},
        {2, 0},
        {1, 2},
        {2, 1}
    };

    vector<Point> convex_hull_vector = convex_hull(points);

    for (const auto& x : convex_hull_vector) {
        cout << x.x << " " << x.y << endl;
    }

    return 0;
}
