#if 1
#pragma warning (disable : 4996)
//#include <cstdio>
#include <iostream>
#include <queue>
#include <algorithm>
#define MAX 10
using namespace std;

int direction_x[] = { -1, 1, 0, 0 };
int direction_y[] = { 0, 0, -1, 1 };

typedef long long ll;
int N, M;
int done_x, done_y;
char map[10][10];
int score[10][10];
bool visited[10][10][10][10];

struct State {
	int rx, ry, bx, by, count;
};

int solve(int r_x, int r_y, int b_x, int b_y) {
	queue<State> q;

	q.push({ r_x, r_y, b_x, b_y, 0 });
	visited[r_x][r_y][b_x][b_y] = true;

	while (!q.empty()) {
		State cur = q.front();
		q.pop();
		if (cur.count >= 10) return -1;
		

		for (int i = 0; i < 4; i++) {
			int nrx = cur.rx; int nry = cur.ry; int r = 0;
			int nbx = cur.bx; int nby = cur.by; int b = 0;
			while (map[nrx + direction_x[i]][nry + direction_y[i]] != '#') {
				if (map[nrx][nry] == 'O') break;
				nrx += direction_x[i];
				nry += direction_y[i];
				r++;
			}
			while (map[nbx + direction_x[i]][nby + direction_y[i]] != '#') {
				if (map[nbx][nby] == 'O') break;
				nbx += direction_x[i];
				nby += direction_y[i];
				b++;
			}
			if (map[nbx][nby] == 'O') {
				continue;
			}
			if (map[nrx][nry] == 'O') {
				return cur.count + 1;
			}
			if (nrx == nbx && nry == nby) {
				if (r > b) {
					nrx -= direction_x[i];
					nry -= direction_y[i];
				}
				else if (r < b) {
					nbx -= direction_x[i];
					nby -= direction_y[i];
				}
			}
			if (visited[nrx][nry][nbx][nby] == false) {
				visited[nrx][nry][nbx][nby] = true;
				q.push({ nrx, nry, nbx, nby, cur.count + 1 });
			}
		}
	}
	return -1;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	int r_x, r_y, b_x, b_y;
	int num = 0;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'R') {
				r_x = i;
				r_y = j;
			}
			else if (map[i][j] == 'B') {
				b_x = i;
				b_y = j;
			}
			else if (map[i][j] == 'O') {
				done_x = i;
				done_y = j;
			}

			score[j][i] = 10000;
			
		}
	}
	cout << solve(r_x, r_y, b_x, b_y);


	
	return 0;
}
#endif