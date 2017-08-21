//   | 0| 1| 2| 3|
// ---------------
//  0|-1| 1| 2| 4|
// ---------------
//  1|20|-1|-1| 2|
// ---------------
//  2|20|-1|-1| 1|
// ---------------
//  3|10|30|20|-1|
//
#include <iostream>
#include <vector>
#include <stack>

using namespace std;
void dijstra(int st,int end,int n, vector<vector<int> > &value, vector<vector<int> > &map, vector<int> &vs, vector<int> &pre, vector<int> &dist,vector<int> &cost){  
    int i,j,mind,v;  
  
    for(i=0;i<n;++i){  
        dist[i] = map[st][i];  
        cost[i] = value[st][i];  
    }  
  
    vs[st] = 1;  
  
    for(i=1;i<n;++i){  
        mind = INT_MAX;  
        for(j=0;j<n;++j){  
            if(vs[j]==0 && dist[j]<mind){  
                mind = dist[j];  
                v = j;  
            }  
        }  
  
        vs[v] = 1;  
  
        if(v==end)return;  
  
        for(j=0;j<n;++j){  
            if(vs[j]==0 && map[v][j]<INT_MAX){  
                if(dist[j]>dist[v]+map[v][j]){  
                    dist[j] = dist[v] + map[v][j];  
                    cost[j] = cost[v] + value[v][j];  
                    pre[j] = v;  
                }else if(dist[j]==dist[v] + map[v][j]){  
                    if(cost[j]>cost[v] + value[v][j]){  
                        cost[j] = cost[v] + value[v][j];  
                        pre[j] = v;  
                    }  
                }  
            }  
        }  
    }  
}  
int main(int argc, char const *argv[]){
	int N, M, S, E;
	cin >> N >> M >> S >> E;
	vector<vector<int> > value(N, vector<int>(N, INT_MAX));
	vector<vector<int> > map(N, vector<int>(N, INT_MAX));
	vector<int> vs(N, 0);
	vector<int> pre(N, -1);
	vector<int> dist(N);
	vector<int> cost(N);
	stack<int> path;  
	while( M--){
		int i, j, dis, cost;
		cin >> i >> j >> dis >> cost;
		map[i][j] = dis;
		map[j][i] = dis;
		value[j][i] = cost;
		value[i][j] = cost;
	}
	if( S == E) cout << S << " " << E << 0 << " " << 0 << endl;

	dijstra( S, E, N, value, map, vs, pre, dist, cost);
	int p = pre[E];  
    while(p!=-1){  
        path.push(p);  
        p = pre[p];  
    }  
  
    cout << S;
    while(!path.empty()){  
        cout << " " << path.top();  
        path.pop();  
    }  
   	cout << " " << E << " " << dist[E] << " " << cost[E];  

	return 0;
}