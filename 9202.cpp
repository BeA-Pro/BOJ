#include <iostream>
#include <cstring>
#include <unordered_set>
using namespace std;

int w, b;
bool visited[4][4];
string map[4];
unordered_set<string> res;
int dy[8] = { -1, -1, -1, 0, 0, 1, 1, 1 }, dx[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };
int score[9] = { 0, 0, 0, 1, 1, 2, 3, 5, 11 };

struct trie {
    trie* next[26];
    bool isFinish;

    trie() {
        memset(this->next, NULL, sizeof(this->next));
        this->isFinish = false;
    }

    ~trie() {
        for (int i = 0; i < 26; ++i)
            if (this->next[i])
                delete this->next[i];
    }

    void insert(string key) {
        trie* pNode = this;
        for (int i = 0; i < key.length(); ++i) {
            int index = key[i] - 'A';
            if (!pNode->next[index])
                pNode->next[index] = new trie();
            pNode = pNode->next[index];
        }
        pNode->isFinish = true;
    }

    void search(int y, int x, string key) {
        // 기저조건 : 문자열은 8글자를 넘지 않음
        if (key.length() > 8)return;
        visited[y][x] = true;
        key += map[y][x];

        trie* pNode = this->next[map[y][x] - 'A'];
        if (pNode == NULL) {
            visited[y][x] = false;
            return;
        }
        if (pNode->isFinish) {
            res.insert(key);
        }

        for (int dir = 0; dir < 8; ++dir) {
            int ny = y + dy[dir], nx = x + dx[dir];
            if (ny < 0 || ny >= 4 || nx < 0 || nx >= 4)continue;
            if (visited[ny][nx])continue;
            pNode->search(ny, nx, key);
        }
        visited[y][x] = false;
    }
};

int main() {

    trie* root = new trie();
    cin >> w;
    for (int i = 0; i < w; ++i) {
        string s;
        cin >> s;
        root->insert(s);
    }
    cin >> b;
    for (int i = 0; i < b; ++i) {
        for (int j = 0; j < 4; ++j) {
            cin >> map[j];
        }
        res.clear();
        for (int y = 0; y < 4; ++y)
            for (int x = 0; x < 4; ++x)
                root->search(y, x, "");

        string longest = "";
        int Max = 0, match = res.size(), scoreSum = 0;
        for (string item : res) {
            if (Max == item.length()) {
                longest = longest < item ? longest : item;
            }
            else if (Max < item.length()) {
                Max = item.length();
                longest = item;
            }
            scoreSum += score[item.length()];
        }
        cout << scoreSum << " " << longest << " " << match << "\n";
    }
    return 0;
}

/*
#include <string>
#include <stdio.h>
#include <math.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <stack>
#include <climits>
#include <set>

#define p(a, b) make_pair(a, b)
#define SWAP(a, b, type) do { \
    type temp; \
    temp = a;  \
    a = b;     \
    b = temp;  \
} while (0)
#define INF 1000000000
#define endl '\n'
#define ll long long

using namespace std;

typedef struct _Trie{
    _Trie* next[26];
    bool END;
}Trie;

int T,W;
int dy[]={-1,-1,-1,0,0,1,1,1};
int dx[]={-1,1,0,-1,1,-1,1,0};
bool visit[4][4];
char boggle[4][4];
string ans;
int ans_cnt;
int ans_max;
Trie *head;

bool cmp(string a, string b){
    if(a.size() == b.size()) return a<b;
    return a.size() > b.size();
}

Trie* make_Trie(){
    Trie* temp = (Trie*)malloc(sizeof(Trie));
    for(int i=0;i<26;i++) temp->next[i] = NULL;
    temp->END=false;
    return temp;
}

void input_Trie(Trie *cur,int index, int size,string s){
    if(index==size){
        cur->END=true;
        return;
    }
    
    int num = s[index]-'A';
    if(cur->next[num]==NULL) cur->next[num]=make_Trie();
    input_Trie(cur->next[num],index+1,size,s);
    
}

void input() {
    cin>>W;
    string s;
    head = make_Trie();
    for(int i=0;i<W;i++){
        cin>>s;
        input_Trie(head,0,s.size(),s);
    }
    cin>>T;
}

void init() {
}

void dfs(Trie* cur,int y,int x,string tmp,map<string,int> &m,int cnt,vector<string> &all){
    //cout<<tmp<<'\n';
    if(cur->END==true){
        if(m.find(tmp)==m.end()){
            //cout<<"tmp "<<tmp<<'\n';
            m[tmp] = true;
            all.push_back(tmp);
        }
    }
    if(cnt==8) return;
    
    int num=boggle[y][x]-'A';
    if(cur->next[num]==NULL) return;
    
    tmp.push_back(boggle[y][x]);
    
    for(int i=0;i<8;i++){
        int ny=y+dy[i], nx=x+dx[i];
        if(0<=ny && ny<4 && 0<=nx && nx<4 && !visit[ny][nx]){
            visit[ny][nx]=true;
            dfs(cur->next[num],ny,nx,tmp,m,cnt+1,all);
            visit[ny][nx]=false;
        }
    }
}

void solution() {
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
            cin>>boggle[i][j];
    
    ans="";
    ans_cnt=0;
    ans_max=0;
    map<string,int> m;
    
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            string tmp="";
            vector<string> all;
            fill(&visit[0][0],&visit[3][4],false);
            visit[i][j]=true;
            dfs(head,i,j,tmp,m,0,all);
            if(all.size() > 0){
                sort(all.begin(), all.end(), cmp);
                for (int k = 0; k < all.size(); k++) {
                    ans_cnt += 1;
                    if(all[k].size()==8) ans_max+=11;
                    else if(all[k].size()==7) ans_max+=5;
                    else if(all[k].size()==6) ans_max+=3;
                    else if(all[k].size()==5) ans_max+=2;
                    else if(all[k].size()>=3) ans_max+=1;
                }
                
                if(all[0].size() > ans.size()) ans=all[0];
                else if(all[0].size() == ans.size() && all[0] < ans) ans=all[0];
            }
            all.clear();
        }
    }
    
    cout<<ans_max<<' '<<ans<<' '<<ans_cnt<<'\n';
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    input();
    while(T--){
        solution();
    }
    return 0;
}*/


