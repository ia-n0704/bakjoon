#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <map>

using namespace std;

// 면을 탐색하여 닫힌 경로를 찾는 함수
vector<int> traverseFace(int startU, int startV, const map<int, vector<int>>& graph, set<pair<int, int>>& visitedEdges) {
    vector<int> face;
    int u = startU, v = startV;

    do {
        face.push_back(u);
        visitedEdges.insert({u, v});
        
        // 다음 간선(u, v)에서 v의 반시계 방향 간선 찾기
        const vector<int>& neighbors = graph.at(v);
        auto it = find(neighbors.begin(), neighbors.end(), u);
        int nextIndex = (it - neighbors.begin() + 1) % neighbors.size();
        u = v;
        v = neighbors[nextIndex];
    } while (u != startU || v != startV);

    return face;
}

// 시작점을 기준으로 사전순 최소 순열 계산
vector<int> minRotation(const vector<int>& sequence) {
    int n = sequence.size();
    vector<int> minSeq = sequence;

    for (int i = 0; i < n; ++i) {
        vector<int> rotated(sequence.begin() + i, sequence.end());
        rotated.insert(rotated.end(), sequence.begin(), sequence.begin() + i);
        minSeq = min(minSeq, rotated);
    }
    return minSeq;
}

// 그래프에서 모든 면을 찾는 함수
vector<vector<int>> findFaces(int n, const vector<vector<int>>& connections) {
    map<int, vector<int>> graph;
    set<pair<int, int>> edges;

    // 그래프 구성
    for (int i = 1; i <= n; ++i) {
        const vector<int>& neighbors = connections[i - 1];
        for (size_t j = 0; j < neighbors.size(); ++j) {
            graph[i].push_back(neighbors[j]);
            edges.insert({i, neighbors[j]});
        }
    }

    set<pair<int, int>> visitedEdges;
    vector<vector<int>> faces;

    for (const auto& edge : edges) {
        if (visitedEdges.find(edge) == visitedEdges.end()) {
            vector<int> face = traverseFace(edge.first, edge.second, graph, visitedEdges);
            faces.push_back(minRotation(face));
        }
    }

    // 사전순으로 정렬
    sort(faces.begin(), faces.end());
    return faces;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> connections(n);

    // 입력 처리
    for (int i = 0; i < n; ++i) {
        int x;
        while (cin >> x && x != 0) {
            connections[i].push_back(x);
        }
    }

    // 문제 해결
    vector<vector<int>> faces = findFaces(n, connections);

    // 출력
    for (const auto& face : faces) {
        for (int pillar : face) {
            cout << pillar << " ";
        }
        cout << endl;
    }

    return 0;
}
