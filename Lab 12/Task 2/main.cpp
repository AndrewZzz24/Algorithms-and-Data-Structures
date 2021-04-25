#include <iostream>
#include <vector>
#include <cmath>

const int INF = 2e9;

int main() {

    int n;
    std::cin >> n;
    std::vector<int> a(n);

    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    std::vector<int> d(n + 1, INF);
    std::vector<int> parent(n, -1);

    int maximum = -INF, res_num = 0, index_start = -2;
    for (int i = 0; i < n; i++) {

        int index = i;
        int left = -1, right = n - 1, middle;

        while (right - left != 1) {

            middle = (right + left) / 2;

            if (d[middle] != INF && a[index] > a[d[middle]])
                left = middle;
            else
                right = middle;
        }

        d[right] = index;

        if (right != 0)
            parent[index] = d[right - 1];

        if (d[right + 1] == INF && a[d[right]] >= maximum) {

            maximum = a[d[right]];
            index_start = d[right];
            res_num = right + 1;

        }
    }

    std::cout << res_num << std::endl;
    std::vector<int> result;

    while (index_start != -1 && res_num != 0) {

        result.push_back(a[index_start]);
        index_start = parent[index_start];

    }

    for (int i = result.size() - 1; i >= 0; i--)
        std::cout << result[i] << ' ';

    std::cout << std::endl;

}