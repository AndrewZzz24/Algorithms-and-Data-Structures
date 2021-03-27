#include <iostream>
#include <vector>
#include <cmath>

class Point {
private:
    double x;
    double y;
public:
    Point(double x, double y) : x(x), y(y) {}

    double getX() const {
        return x;
    }

    double getY() const {
        return y;
    }
};

void input(int &n, std::vector<Point> &vert) {
    std::cin >> n;
    for (size_t i = 0; i < n; i++) {
        double x, y;
        std::cin >> x >> y;
        vert.emplace_back(x, y);
    }
}

double get_distance(Point &p1, Point &p2) {

    return sqrt(pow(p1.getX() - p2.getX(), 2) + pow(p1.getY() - p2.getY(), 2));

}

double find_min_mst(int n, std::vector<Point> &vert) {
    double result = 0;
    int prev_vert_index = -1;
    std::vector<int> key;
    key.assign(vert.size(), -1);
    key[0] = 0;
    while (true) {

        int index, value = -1;
        for (size_t i = 0, j = 1; i < key.size(); i++) {

            if (j == 1 && key[i] != -1) {
                j = 0;
                index = i;
                value = key[i];
            } else if (key[i] != -1 && key[i] < value) {
                index = i;
                value = key[i];
            }

        }

        if (value == -1) break;

        if (prev_vert_index != -1)
            result += get_distance(vert[index], vert[prev_vert_index]);

        for (size_t i = 0; i < vert.size(); i++) {

            if (i != index) {
                double tmp = get_distance(vert[i], vert[index]);
                if (key[i] > tmp || key[i]==-1)
                    key[i] = tmp;
            }

        }
        prev_vert_index = index;
        key[index] = -2;

    }
    return result;
}

int main() {
    freopen("C:\\Users\\Andrz\\CLionProjects\\Algorithms-and-Data-Structures\\Lab 10\\Task 2\\spantree.in", "r", stdin);
    freopen("C:\\Users\\Andrz\\CLionProjects\\Algorithms-and-Data-Structures\\Lab 10\\Task 2\\spantree.out", "w",
            stdout);
    int n;
    std::vector<Point> vertexes;
    input(n, vertexes);
    std::cout << find_min_mst(n, vertexes) << std::endl;
    return 0;
}