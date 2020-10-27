#include <bits/stdc++.h>
using namespace std;

struct edge {
  int dest, time, dmg;
  edge(int de, int t, int dm) {
    dest = de;
    time = t;
    dmg = dm;
  }
};

// store all edges according to their starting node
vector<edge> paths[2002];
// minimum distance from node A for each hull damage
int dist[2002][202];
// a boolean array to check whether or not a node is already in the priority queue
bool inQueue[2002];

int main() {
  ios_base::sync_with_stdio(false);

  memset(dist, 63, sizeof(dist));
  int K, N, M;
  cin >> K >> N >> M;
  for (int i = 0; i < M; i++) {
    int a, b, t, h;
    cin >> a >> b >> t >> h;
    paths[a].push_back(edge(b, t, h));
    paths[b].push_back(edge(a, t, h));
  }
  int A, B;
  cin >> A >> B;

  // priority queue contains a pair of distance from A and starting node
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<> > pq;
  pq.push(make_pair(0, A));
  dist[A][0] = 0; // distance from A with 0 hull damage is obviously 0 (starting point)
  inQueue[A] = true;

  while (!pq.empty()) {
    int currentNode = pq.top().second; pq.pop();
    inQueue[currentNode] = false;

    // loop through every edge leading out from current node
    for (auto iEdge = paths[currentNode].begin(); iEdge != paths[currentNode].end(); iEdge++) {
      // loop through every possible hull damage taken up to current node
      for (int j = 0; j+(iEdge->dmg) < K; j++) {
        // the new distance is the shortest distance to the current node having taken j damage plus this edge's duration
        int newDist = dist[currentNode][j] + (iEdge->time);
        int nextNode = iEdge->dest;
        int nextDamage = j + (iEdge->dmg);
        if (newDist < dist[nextNode][nextDamage]) {
          // if the new distance to get to "nextNode" is shorter than what is currently stored, assign the new distance
          dist[nextNode][nextDamage] = newDist;
          if (!inQueue[nextNode]) {
            inQueue[nextNode] = true;
            pq.push(make_pair(newDist, nextNode));
          }
        }
      }
    }
  }

  int shortestDist = INT_MAX;
  for (int i = 0; i < K; i++) {
    if (dist[B][i] < shortestDist) {
      shortestDist = dist[B][i];
    }
  }
  if (shortestDist == INT_MAX) {
    cout << -1 << '\n';
  } else {
    cout << shortestDist << '\n';
  }

  return 0;
}