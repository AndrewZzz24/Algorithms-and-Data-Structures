#include <iostream>
#include <vector>
#include <algorithm>

class Edges {

private:
    int left_end;
    int right_end;
    int weight;

public:

    Edges(int &l, int &r, int &w) : left_end(l), right_end(r), weight(w) {}

    int getLE() const {

        return left_end;

    };

    int getRE() const {

        return right_end;

    }

    int getW() const {

        return weight;

    }

    friend bool operator>(Edges &lhs, Edges &rhs) {

        return lhs.weight > rhs.right_end;

    }

    friend bool operator<(Edges &lhs, Edges &rhs) {

        return rhs.weight > lhs.weight;

    }

    friend bool operator==(Edges &lhs, Edges &rhs) {

        return lhs.weight == rhs.weight;

    }

};

void input(int &n, int &m, std::vector<Edges> &edges) {

    std::cin >> n >> m;

    for (size_t i = 0; i < m; i++) {

        int from, to, weight;

        std::cin >> from >> to >> weight;

        from--;
        to--;
        edges.emplace_back(from, to, weight);

    }

}

int find_min_mst(int n, std::vector<Edges> &edges) {

    int result = 0;
    std::vector<int> sets;

    for (size_t i = 0; i < n; i++)
        sets.push_back(i);

    std::sort(edges.begin(), edges.end());

    for (auto &edge : edges) {

        if (sets[edge.getLE()] != sets[edge.getRE()]) {

            result += edge.getW();
            int set1 = sets[edge.getLE()];
            int set2 = sets[edge.getRE()];
            sets[set2] = set1;
            for (auto &j : sets)
                if (j == set2) j = set1;

        }

    }

    return result;

}

int main() {

    freopen("C:\\Users\\Andrz\\CLionProjects\\Algorithms-and-Data-Structures\\Lab 10\\Task 3\\spantree3.in", "r",
            stdin);
    freopen("C:\\Users\\Andrz\\CLionProjects\\Algorithms-and-Data-Structures\\Lab 10\\Task 3\\spantree3.out", "w",
            stdout);

    int n, m;
    std::vector<Edges> edges;

    input(n, m, edges);
    std::cout << find_min_mst(n, edges) << std::endl;

    return 0;

}