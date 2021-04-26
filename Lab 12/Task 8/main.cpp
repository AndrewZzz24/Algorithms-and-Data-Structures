#include <iostream>
#include <vector>

int main() {


    std::vector<std::vector<int>> d;
    std::vector<int> a;

    int n, infinity = 1000000000;

    std::cin >> n;
    a.resize(n);

    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    for (int i = 0; i < n; i++) {

        d.push_back({0});

        for (int j = 0; j < n; j++) {

            d[i].push_back(0);
            if (i == j)
                d[i][j] = 1;

        }

    }

    for (int i = n - 2; i > -1; i--) {

        for (int j = i + 1; j < n; j++) {

            if (a[i] != a[j])
                d[i][j] = (d[i][j - 1] + d[i + 1][j] - d[i + 1][j - 1]) % infinity;
            else
                d[i][j] = (d[i + 1][j] + d[i][j - 1] + 1) % infinity;

        }

    }

    std::cout << (d[0][n - 1] + infinity) % infinity << std::endl;

    return 0;

}