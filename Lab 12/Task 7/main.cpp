#include <iostream>
#include <vector>
#include <algorithm>

std::vector<std::vector<int>> maxtrix;
std::vector<int> a;

void findans(int i, int j) {
    if (maxtrix[i][j] == 0)
        return;
    if (maxtrix[i - 1][j] == maxtrix[i][j])
        findans(i - 1, j);
    else {
        findans(i - 1, j - a[i]);
        std::cout << i << ' ';
    }
}

int main() {

    //freopen("knapsack.in", "r", stdin);
    //freopen("knapsack.out", "w", stdout);

    int s, n;

    std::cin >> s >> n;
    a.resize(n);

    for (int i = 0; i < n; i++)
        std::cin >> a[i];


    for (int i = 0; i < n; i++) {

        maxtrix.push_back({0});

        for (int j = 0; j < s; j++)

            maxtrix[i].push_back(0);

    }

    for (int i = 1; i <= n; i++) {

        for (int j = 1; j <= s; j++) {

            if (j >= a[i])
                maxtrix[i][j] = std::max(maxtrix[i - 1][j], maxtrix[i - 1][j - a[i]]);

            else
                maxtrix[i][j] = maxtrix[i - 1][j];

        }

    }
    findans(n - 1, s - 1);


}