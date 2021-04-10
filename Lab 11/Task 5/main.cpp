#include <iostream>
#include <vector>
#include <set>
#include <cmath>
#include <algorithm>

//#define int long long
const long long inf = 2e18;

struct Edge {
    long long from_;
    long long to_;
    long long weight_;
};

void input(int &n, std::vector<Edge> &edges) {

    std::cin >> n;

    for (int j = 0; j < n; j++) {

        for (int i = 0; i < n; i++) {

            int tmp_num;
            std::cin >> tmp_num;
            if (tmp_num != std::pow(10, 9) && tmp_num != 0) {
                Edge tmp{};
                tmp.to_ = i;
                tmp.from_ = j;
                tmp.weight_ = tmp_num;
                edges.push_back(tmp);
            }
        }
    }

}

void Ford_Bellman_algorithm(int &n, int &s, std::vector<Edge> &edges) {

    std::vector<long long> distances;
    std::vector<long long> p;
    distances.assign(n, inf);
    p.assign(n, -1);
    distances[s] = 0;

    for (int i = 0; i < n - 1   ; i++) {

        for (unsigned j = 0; j < edges.size(); j++) {

            long long from = edges[j].from_;
            long long to = edges[j].to_;
            long long weight = edges[j].weight_;

            if (distances[from] + weight < distances[to]) {
                distances[to] = distances[from] + weight;
                p[to] = from;
            }

        }
    }
    std::vector<long long> answer;

    for (unsigned j = 0; j < edges.size(); j++) {

        long long from = edges[j].from_;
        long long to = edges[j].to_;
        long long weight = edges[j].weight_;

        if (distances[from] + weight < distances[to]) {

            for (int i = 0; i < n; i++)
                to = p[to];

            from = to;

            while (from != p[to]) {

                answer.push_back(to);
                to = p[to];

            }
            std::cout << "YES" << std::endl;
            std::cout << answer.size() << std::endl;
            std::reverse(answer.begin(), answer.end());
            break;

        }
    }

    if (answer.empty())

        std::cout << "NO" << std::endl;

    else {

        for (auto &i : answer)
            std::cout << i << ' ';

        std::cout << std::endl;
    }
}


signed main() {

    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    int n, num = 0;

    freopen("C:\\Users\\Andrz\\CLionProjects\\Algorithms-and-Data-Structures\\Lab 11\\Task 5\\negcycle.in", "r", stdin);
    freopen("C:\\Users\\Andrz\\CLionProjects\\Algorithms-and-Data-Structures\\Lab 11\\Task 5\\negcycle.out", "w",
            stdout);

    std::vector<Edge> edges;

    input(n, edges);
    Ford_Bellman_algorithm(n, num, edges);

    return 0;

}