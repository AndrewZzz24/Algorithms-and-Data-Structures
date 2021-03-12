#include <iostream>
#include <vector>

short player;

void
input(std::vector<std::vector<int>> &vertexes, std::vector<int> &used, std::vector<int> &result, int &num_of_vertexes,
      int &num_of_edges, int &start) {
    std::cin >> num_of_vertexes >> num_of_edges >> start;
    int edge_start, edge_end;
    vertexes.resize(num_of_vertexes);
    used.resize(num_of_vertexes);
    for (int i = 0; i < num_of_edges; i++) {
        std::cin >> edge_start >> edge_end;
        vertexes[edge_start - 1].push_back(edge_end - 1);
    }
}

void DFS(int vertex, std::vector<std::vector<int>> &vertexes, std::vector<int> &used, std::vector<int> &result) {
    used[vertex] = 1;
    for (int i = 0; i < vertexes[vertex].size(); i++) {
        int tmp = vertexes[vertex][i];
        if (!used[tmp]) {
            player *= -1;
            DFS(tmp, vertexes, used, result);
        }
    }
    if (player == 1)
        std::cout << "First Player Wins" << std::endl;
    else

    //result.push_back(vertex);
}

int main() {
//    freopen("game.in", "r", stdin);
//    freopen("game.out", "w", stdout);
    freopen("C:\\Users\\Andrz\\CLionProjects\\Algorithms-and-Data-Structures\\Lab 9\\Task 6\\game.in", "r",
            stdin);
    freopen("C:\\Users\\Andrz\\CLionProjects\\Algorithms-and-Data-Structures\\Lab 9\\Task 6\\game.out", "w",
            stdout);
    std::vector<std::vector<int>> vertexes;
    std::vector<int> used;
    std::vector<int> result;
    int n, m, s;
    input(vertexes, used, result, n, m, s);
    player = 1;
    DFS(s, vertexes, used, result);
    return 0;
}