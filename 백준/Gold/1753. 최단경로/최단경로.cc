#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <unordered_map>
#define MAX 1000000000
using namespace std;

int V, E, K;
vector<pair<int, int>> v[20001];

int ans[20001];

typedef struct _Info
{
  int cur, w;
} Info;

struct cmp
{
  bool operator()(const Info &a, const Info &b)
  {
    return a.w > b.w;
  }
};

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  fill(&ans[0], &ans[20001], MAX);
  cin >> V >> E;
  cin >> K;
  int s, e, w;
  for (int i = 0; i < E; i++)
  {
    cin >> s >> e >> w;
    v[s].push_back({e, w});
  }

  priority_queue<Info, vector<Info>, cmp> pq;
  ans[K] = 0;
  pq.push({K, 0});
  while (!pq.empty())
  {
    Info tmp = pq.top();
    pq.pop();
    if (ans[tmp.cur] < tmp.w)
      continue;
    for (int i = 0; i < v[tmp.cur].size(); i++)
    {
      pair<int, int> next = v[tmp.cur][i];
      int nxt_weight = next.second + tmp.w;
      if (ans[next.first] > nxt_weight)
      {
        ans[next.first] = nxt_weight;
        pq.push({next.first, nxt_weight});
      }
    }
  }

  for (int i = 1; i <= V; i++)
  {
    if (ans[i] == MAX)
      cout << "INF\n";
    else
      cout << ans[i] << '\n';
  }
  return 0;
}