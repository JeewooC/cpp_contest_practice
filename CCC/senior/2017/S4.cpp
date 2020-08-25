#include <bits/stdc++.h>
using namespace std;

class UF {
 public:
  UF(int N) {
    cnt = N;
    id = new int[N+1];
    sz = new int[N+1];
    for (int i = 0; i < N+1; i++) {
      id[i] = i;
      sz[i] = 1;
    }
  }

  ~UF() {
    delete [] id;
    delete [] sz;
  }

  int root(int i) {
    while (i != id[i]) {
      id[i] = id[id[i]];
      i = id[i];
    }
    return i;
  }

  bool connected(int p, int q) {
    return root(p) == root(q);
  }

  void merge(int p, int q) {
    int pRoot = root(p);
    int qRoot = root(q);
    if (pRoot == qRoot) return;
    if (sz[pRoot] < sz[qRoot]) {
      id[pRoot] = qRoot;
      sz[qRoot] += sz[pRoot];
    } else {
      id[qRoot] = pRoot;
      sz[pRoot] += sz[qRoot];
    }
    cnt--;
  }

  int getCount() {
    return cnt;
  }

 private:
  int *id, *sz, cnt;
};

class Pipe {
 public:
  int src, dest, cost, active;
};

bool comparePipes (Pipe i, Pipe j) {
  if (i.cost != j.cost) {
    return i.cost < j.cost;
  }
  return i.active == 1;
}

int main() {
  int N, M, D;
  cin >> N >> M >> D;
  vector<Pipe> pipes;
  for (int i = 0; i < M; i++) {
    int A, B, C;
    cin >> A >> B >> C;
    if (i < N-1) {
      Pipe p = {A, B, C, 1};
      pipes.push_back(p);
    } else {
      Pipe p = {A, B, C, 0};
      pipes.push_back(p);
    }
  }
  sort(pipes.begin(), pipes.end(), comparePipes);

  int days = 0, i = 0;
  UF uf = UF(N);

  while (uf.getCount() > 1) {
    int src = pipes.at(i).src;
    int dest = pipes.at(i).dest;
    int active = pipes.at(i).active;

    if (!uf.connected(src, dest)) {
      uf.merge(src, dest);
      if (active == 0) {
        days++;
      }
    }
    i++;
  }

  cout << days << endl;
}