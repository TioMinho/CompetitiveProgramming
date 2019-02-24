#include <iostream> 
#include <limits.h> 
#include <string.h> 
#include <queue> 
using namespace std; 
  
#define MAXV 2002
#define MAXC 20000 
  
int graph[MAXV][MAXV];
int graph_t[MAXV][MAXV];
int rGraph[MAXV][MAXV];

bool bfs(int s, int t, int parent[]) { 
    bool visited[MAXV]; 
    memset(visited, 0, sizeof(visited)); 
  
    queue <int> q; 
    q.push(s); 
    visited[s] = true; 
    parent[s] = -1; 
  
    while (!q.empty()) { 
        int u = q.front(); q.pop(); 
  
        for (int v=0; v<MAXV; v++) { 
            if (!visited[v] && rGraph[u][v] > 0) { 
                q.push(v); 
                parent[v] = u; 
                visited[v] = true; 
            } 
        } 
    } 
  
    return (visited[t] == true); 
} 
  
int fordFulkerson(int s, int t) { 
    int u, v;
    for (int u = 0; u < MAXV; u++) 
        for (int v = 0; v < MAXV; v++) 
             rGraph[u][v] = graph[u][v]; 
  
    int parent[MAXV];
    int max_flow = 0;
  
    while (bfs(s, t, parent)) { 
        int path_flow = INT_MAX; 
        for (v=t; v!=s; v=parent[v]) { 
            u = parent[v]; 
            path_flow = min(path_flow, rGraph[u][v]); 
        } 
  
        for (v=t; v != s; v=parent[v]) { 
            u = parent[v]; 
            rGraph[u][v] -= path_flow; 
            rGraph[v][u] += path_flow; 
        } 
  
        max_flow += path_flow; 
    } 
  
    return max_flow; 
} 
  
int main() { 
    int P, R, C, totC = 0, aux, aux2, aux3; 
    int minT=1e6, maxT=0;

    cin >> P >> R >> C;
    for (int i = 1; i <= P; i++) {
        cin >> aux;
        graph[0][i] = aux;

        totC += aux;
    }

    for (int i = P+1; i <= P+R; i++) {
        cin >> aux;
        graph[i][P+R+1] = aux;
    }   

    for (int i = 0; i < C; i++) {
        cin >> aux >> aux2 >> aux3;
        minT = min(minT, aux3);
        maxT = max(minT, aux3);

        graph[aux][P+aux2] = 0;
        graph_t[aux][P+aux2] = aux3;
    }

    // for (int i = 0; i <= P+R+1; ++i) {
    //     for (int j = 0; j <= P+R+1; ++j) {
    //         cout << graph[i][j] << " ";
    //     } cout << endl;
    // }

    int t=0, prevT=-1; bool solved = false;
    while(true) {
        if(t == maxT || (t == prevT && solved)) break;
        else if(t == prevT && !solved) t++;
        else
            t = minT + (maxT-minT)/2;

        for (int i = 1; i < P+R+1; ++i) for (int j = 1; j < P+R+1; ++j)
            graph[i][j] = (0 < graph_t[i][j] && graph_t[i][j] <= t) ? 1e6 : 0;

        // for (int i = 0; i <= P+R+1; ++i) {
        //     for (int j = 0; j <= P+R+1; ++j) {
        //         cout << graph[i][j] << " ";
        //     } cout << endl;
        // }
        // cout << "The maximum possible flow is " << fordFulkerson(0, P+R+1) << endl;; 

        if(fordFulkerson(0, P+R+1) == totC) { maxT = t; solved = true; }
        else                                { minT = t; solved = false; }

        prevT = t;
    }

    if(!solved) cout << -1 << endl;
    else        cout << t << endl;
  
    return 0; 
} 
