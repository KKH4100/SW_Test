#if 1
#pragma warning (disable : 4996)
#include <iostream>
#include <vector>
#include <queue>
#define MAX 100

using namespace std;
pair<int, int> map[MAX+1][MAX+1];
queue<pair<int, char>> info;

int direction_x[4] = { 0, 1, 0, -1 };
int direction_y[4] = { 1, 0, -1, 0 };

int N, K, L;
	
int head_x = 1;
int head_y = 1;
int tail_x = 1;
int tail_y = 1;
int body = 1;
int direction = 0;

int main() {
	for (int a = 1; a < MAX + 1; a++) {
		for (int b = 1; b < MAX + 1; b++) {
			map[a][b] = { 0, 0 };
		}
	}
	map[1][1] = { 2, 0 };
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	cin >> N;
	cin >> K;
	for (int i = 0; i < K; i++) {
		int x, y;
		cin >> x >> y;
		map[x][y].first = 1;
	}
	cin >> L;
	for (int i = 0; i < L; i++) {
		int X;
		char C;
		cin >> X;
		cin >> C;
		info.push({ X, C });
	}
	int count = 0;
	while (true) {
		/*for (int x = 1; x <= N; x++) {
			for (int y = 1; y <= N; y++) {
				cout << map[x][y].first << " ";
			}
			cout << endl;
		}
		cout << "--------------------------" << endl;*/
		int next_x = head_x + direction_x[direction];
		int next_y = head_y + direction_y[direction];
		if (map[next_x][next_y].first == 2) break;
		if (next_x <= 0 || next_x > N || next_y <= 0 || next_y > N) break;

		map[head_x][head_y].second = direction;
		if (map[next_x][next_y].first == 1) {
			head_x = next_x;
			head_y = next_y;
			body++;
		}
		else if (map[next_x][next_y].first == 0) {
			head_x = next_x;
			head_y = next_y;
			int last_dir = map[tail_x][tail_y].second;
			map[tail_x][tail_y].first = 0;
			tail_x += direction_x[last_dir];
			tail_y += direction_y[last_dir];

		}
		map[next_x][next_y].first = 2;

		count++;
		if (!info.empty()) {
			pair<int, char> copy = info.front();
			if (copy.first < count) cout << "error" << endl;
			else if (copy.first == count) {
				if (copy.second == 'L') {
					direction = (direction + 3) % 4;
				}
				else if (copy.second == 'D') {
					direction = (direction + 1) % 4;
				}
				info.pop();
			}
		}
	}

	cout << count+1;
	return 0;
}
#endif