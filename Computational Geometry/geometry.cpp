// Computational geometry template.
#include <bits/stdc++.h>
using namespace std;

using Real = long double;

const Real kEps = 1e-12L;
const Real kPi = 3.141592653589793238L;

// 浮点数符号：正数 1，负数 -1，近似为 0 返回 0
int sign(Real x) { return (x > kEps) - (x < -kEps); }

// 判断浮点数是否近似为 0
bool is_zero(Real x) { return !sign(x); }

// 点/向量
struct Point {
    Real x = 0, y = 0;

    Point() = default;
    Point(Real x, Real y) : x(x), y(y) {}

    Point operator+() const { return *this; }
    Point operator-() const { return {-x, -y}; }
    Point operator+(const Point& p) const { return {x + p.x, y + p.y}; }
    Point operator-(const Point& p) const { return {x - p.x, y - p.y}; }
    Point operator*(Real k) const { return {x * k, y * k}; }
    Point operator/(Real k) const { return {x / k, y / k}; }
    Point& operator+=(const Point& p) { return *this = *this + p; }
    Point& operator-=(const Point& p) { return *this = *this - p; }
    Point& operator*=(Real k) { return *this = *this * k; }
    Point& operator/=(Real k) { return *this = *this / k; }
};

using Vector = Point;
using Polygon = vector<Point>;

bool operator==(const Point& a, const Point& b) {
    return is_zero(a.x - b.x) && is_zero(a.y - b.y);
}

bool operator<(const Point& a, const Point& b) {
    if (!is_zero(a.x - b.x)) return a.x < b.x;
    return a.y < b.y - kEps;
}

ostream& operator<<(ostream& os, const Point& p) {
    return os << p.x << ' ' << p.y;
}

// 直线：point + t * dir
struct Line {
    Point p;
    Vector dir;

    Line() = default;
    Line(Point p, Vector dir) : p(p), dir(dir) {}

    // 由两点构造直线
    static Line from_points(Point a, Point b) {
        return {a, b - a};
    }

    // 由一般式 ax + by + c = 0 构造直线
    static Line from_equation(Real a, Real b, Real c) {
        if (is_zero(a)) return from_points({0, -c / b}, {1, -c / b});
        if (is_zero(b)) return from_points({-c / a, 0}, {-c / a, 1});
        return from_points({0, -c / b}, {1, -(a + c) / b});
    }
};

// 线段
struct Segment {
    Point a, b;
};

// 圆
struct Circle {
    Point center;
    Real radius = 0;
};

// 点积
Real dot(Vector a, Vector b) {
    return a.x * b.x + a.y * b.y;
}

// 叉积
Real cross(Vector a, Vector b) {
    return a.x * b.y - a.y * b.x;
}

// 叉积：向量 o->a 与 o->b
Real cross(Point o, Point a, Point b) {
    return cross(a - o, b - o);
}

// 向量长度的平方
Real norm2(Vector v) {
    return dot(v, v);
}

// 向量长度
Real norm(Vector v) {
    return sqrtl(norm2(v));
}

// 两点距离
Real distance(Point a, Point b) {
    return norm(a - b);
}

// 单位向量
Vector unit(Vector v) {
    return v / norm(v);
}

// 逆时针旋转 90 度的垂直向量
Vector perpendicular(Vector v) {
    return {-v.y, v.x};
}

// 向量逆时针旋转 rad 弧度
Vector rotate(Vector v, Real rad) {
    Real c = cosl(rad), s = sinl(rad);
    return {v.x * c - v.y * s, v.x * s + v.y * c};
}

// 两向量夹角，返回弧度
Real angle(Vector a, Vector b) {
    Real c = dot(a, b) / norm(a) / norm(b);
    return acosl(clamp(c, -1.0L, 1.0L));
}

// 三点方向：逆时针 1，顺时针 -1，共线 0
int orientation(Point a, Point b, Point c) {
    return sign(cross(a, b, c));
}

// 有向三角形面积的两倍
Real area2(Point a, Point b, Point c) {
    return cross(a, b, c);
}

// 三角形面积
Real triangle_area(Point a, Point b, Point c) {
    return fabsl(area2(a, b, c)) / 2;
}

// 判断两向量是否平行
bool are_parallel(Vector a, Vector b) {
    return is_zero(cross(a, b));
}

// 判断两直线是否平行
bool are_parallel(Line a, Line b) {
    return are_parallel(a.dir, b.dir);
}

// 判断两直线是否重合
bool are_same_line(Line a, Line b) {
    return are_parallel(a, b) && is_zero(cross(a.dir, b.p - a.p));
}

// 点和直线的位置关系：左侧 1，右侧 -1，线上 0
int point_line_relation(Point p, Line l) {
    return sign(cross(l.dir, p - l.p));
}

// 两直线交点；平行或重合时返回 nullopt
optional<Point> line_intersection(Line a, Line b) {
    Real d = cross(a.dir, b.dir);
    if (is_zero(d)) return nullopt;
    return a.p + a.dir * (cross(b.p - a.p, b.dir) / d);
}

// 点在直线上的投影
Point projection(Point p, Line l) {
    return l.p + l.dir * (dot(p - l.p, l.dir) / norm2(l.dir));
}

// 点关于直线的对称点
Point reflection(Point p, Line l) {
    return projection(p, l) * 2 - p;
}

// 点到直线的距离
Real distance_point_line(Point p, Line l) {
    return fabsl(cross(l.dir, p - l.p)) / norm(l.dir);
}

// 判断点是否在线段上
bool on_segment(Point p, Segment s) {
    return is_zero(cross(s.a, s.b, p)) && sign(dot(p - s.a, p - s.b)) <= 0;
}

// 点到线段的距离
Real distance_point_segment(Point p, Segment s) {
    Vector v = s.b - s.a;
    if (sign(dot(p - s.a, v)) <= 0) return distance(p, s.a);
    if (sign(dot(p - s.b, -v)) <= 0) return distance(p, s.b);
    return distance_point_line(p, Line::from_points(s.a, s.b));
}

// 判断两线段是否相交，包含端点和重合
bool segments_intersect(Segment a, Segment b) {
    int c1 = orientation(a.a, a.b, b.a), c2 = orientation(a.a, a.b, b.b);
    int c3 = orientation(b.a, b.b, a.a), c4 = orientation(b.a, b.b, a.b);
    if (c1 == 0 && on_segment(b.a, a)) return true;
    if (c2 == 0 && on_segment(b.b, a)) return true;
    if (c3 == 0 && on_segment(a.a, b)) return true;
    if (c4 == 0 && on_segment(a.b, b)) return true;
    return c1 * c2 < 0 && c3 * c4 < 0;
}

// 两线段唯一交点；不相交或重合时返回 nullopt
optional<Point> segment_intersection(Segment a, Segment b) {
    if (!segments_intersect(a, b)) return nullopt;
    return line_intersection(Line::from_points(a.a, a.b), Line::from_points(b.a, b.b));
}

// 多边形有向面积的两倍
Real polygon_area2(const Polygon& p) {
    Real area = 0;
    int n = p.size();
    for (int i = 0; i < n; ++i) area += cross(p[i], p[(i + 1) % n]);
    return area;
}

// 多边形面积
Real polygon_area(const Polygon& p) {
    return fabsl(polygon_area2(p)) / 2;
}

// 点在简单多边形内的判定，返回 -1：内部，0：边界，1：外部
int point_in_polygon(Point q, const Polygon& p) {
    bool inside = false;
    int n = p.size();
    for (int i = 0, j = n - 1; i < n; j = i++) {
        if (on_segment(q, {p[j], p[i]})) return 0;
        bool cross_y = (p[i].y > q.y) != (p[j].y > q.y);
        Real x = p[j].x + (p[i].x - p[j].x) * (q.y - p[j].y) / (p[i].y - p[j].y);
        if (cross_y && sign(x - q.x) > 0) inside = !inside;
    }
    return inside ? -1 : 1;
}

// 判断多边形是否为严格凸多边形
bool is_convex(const Polygon& p) {
    int n = p.size(), dir = 0;
    if (n < 3) return false;
    for (int i = 0; i < n; ++i) {
        int turn = orientation(p[i], p[(i + 1) % n], p[(i + 2) % n]);
        if (turn == 0) continue;
        if (dir && dir != turn) return false;
        dir = turn;
    }
    return dir != 0;
}

// 凸包，返回逆时针序；边界共线点不保留
Polygon convex_hull(Polygon p) {
    sort(p.begin(), p.end());
    p.erase(unique(p.begin(), p.end()), p.end());
    if (p.size() <= 1) return p;

    Polygon hull;
    for (Point q : p) {
        while (hull.size() >= 2 && orientation(hull[hull.size() - 2], hull.back(), q) <= 0) {
            hull.pop_back();
        }
        hull.push_back(q);
    }

    auto lower_size = hull.size();
    for (int i = p.size() - 2; i >= 0; --i) {
        while (hull.size() > lower_size && orientation(hull[hull.size() - 2], hull.back(), p[i]) <= 0) {
            hull.pop_back();
        }
        hull.push_back(p[i]);
    }

    hull.pop_back();
    return hull;
}

// 圆和直线交点，返回 0/1/2 个点
vector<Point> circle_line_intersection(Circle c, Line l) {
    Point p = projection(c.center, l);
    Real d = distance(p, c.center);
    if (sign(d - c.radius) > 0) return {};
    if (is_zero(d - c.radius)) return {p};
    Real h = sqrtl(c.radius * c.radius - d * d);
    Vector v = unit(l.dir);
    return {p - v * h, p + v * h};
}

// 两圆交点，返回 0/1/2 个点；同心圆返回空
vector<Point> circle_circle_intersection(Circle a, Circle b) {
    Real d = distance(a.center, b.center);
    if (is_zero(d) || sign(d - a.radius - b.radius) > 0 ||
        sign(fabsl(a.radius - b.radius) - d) > 0) {
        return {};
    }

    Vector v = (b.center - a.center) / d;
    Real x = (a.radius * a.radius - b.radius * b.radius + d * d) / (2 * d);
    Real y2 = a.radius * a.radius - x * x;
    Point p = a.center + v * x;
    if (is_zero(y2)) return {p};

    Vector h = perpendicular(v) * sqrtl(max<Real>(0, y2));
    return {p - h, p + h};
}