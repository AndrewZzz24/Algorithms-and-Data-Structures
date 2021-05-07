#include <iostream>
#include <string>
#include <vector>
#include <cmath>

const long long x = 7;
const long long k = 9999999;

int main() {

    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    //freopen("search2.in", "r", stdin);
    //freopen("search2.out", "w", stdout);

    std::vector<long long> answer;
    std::string s1, s2;

    std::cin >> s1 >> s2;
    //s2 += "    ";
    long long hash_s1 = 0, hash_sub = 0;
    for (long long i = 0; i < s1.length(); i++) {

        int s1_h, s2_h;
        if (s1[i] >= 'A' && s1[i] <= 'Z') s1_h = s1[i] - 'A';
        if (s1[i] >= 'a' && s1[i] <= 'z') s1_h = s1[i] - 'a';
        if (s2[i] >= 'A' && s2[i] <= 'Z') s2_h = s2[i] - 'A';
        if (s2[i] >= 'a' && s2[i] <= 'z') s2_h = s2[i] - 'a';
        hash_s1 = (hash_s1 * x + s1_h) % k;
        hash_sub = (hash_sub * x + s2_h) % k;

    }

    for (long long i = 0; i < s2.length() - s1.length() + 1; i++) {

        if (hash_s1 == hash_sub) {

            bool okay = true;
            for (long long j = i; j < i + s1.length(); j++)

                if (s2[j] != s1[j - i]) {

                    okay = false;
                    break;

                }

            if (okay)
                answer.push_back(i + 1);

        }
        std::cout << hash_sub << ' ' << s2[i] << ' ' << s2[i + s1.length()] << std::endl;

        if (i + s1.length() < s2.length()) {

            int s1_h, s2_h;

            if (s2[i + s1.length()] >= 'A' && s2[i + s1.length()] <= 'Z') s1_h = s2[i + s1.length()] - 'A';
            if (s2[i + s1.length()] >= 'a' && s2[i + s1.length()] <= 'z') s1_h = s2[i + s1.length()] - 'a';

            if (s2[i] >= 'A' && s2[i] <= 'Z') s2_h = s2[i] - 'A';
            if (s2[i] >= 'a' && s2[i] <= 'z') s2_h = s2[i] - 'a';

            hash_sub = (long long) (hash_sub * x - s2_h * std::pow(x, s1.length()) + s1_h) % k;

        }

    }

    std::cout << answer.size() << std::endl;

    for (auto i: answer)
        std::cout << i << ' ';

    std::cout << std::endl;

    return 0;
}