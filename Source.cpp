#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <math.h>

using namespace std;

class edge {
public:
	double probability;
	pair<int, int> Edge;
	edge() {
		Edge.first = 0;
		Edge.second = 0;
		probability = 0.0;
	}
	edge(int a,int b,double c) {
		Edge.first = a;
		Edge.second = b;
		probability = c;
	}
};
bool compare(edge a, edge b) {
	return(a.probability > b.probability);
}
int main() {
	int N;
	cin >> N;
	vector<edge> dataQ;
	int nodeNUM = 0;
	for (int i = 0; i < N; i++) {
		int a, b;
		double c;
		cin >> a >> b >> c;
		edge temp(a,b,c);
		dataQ.push_back(temp);
		if (a > nodeNUM) {
			nodeNUM = a;
		}
		if (b > nodeNUM) {
			nodeNUM = b;
		}
	}
	vector<int> visited(nodeNUM);
	for (int i = 0; i < nodeNUM; i++) {
		visited[i] = i + 1;
	}
	sort(dataQ.begin(), dataQ.end(), compare);
	double weight = 1;
	int f, s;
	/*for (auto x : dataQ)
		cout << x.Edge.first << " " << x.Edge.second << " " << x.probability << endl;*/
	for (int i = 0; i < N; i++) {
		f = dataQ[i].Edge.first;
		s = dataQ[i].Edge.second;
		int temp1 = visited[f - 1];
		int temp2 = visited[s - 1];
		if (temp1 != temp2) {
			visited[f - 1] = f;
			visited[s - 1] = f;
			for (int j = 0; j < N; j++) {
				if (visited[j] == temp1 || visited[j] == temp2) {
					visited[j] = f;
				}
			}
			weight *= dataQ[i].probability;
		}
	}
	if (weight < 0.05) {
		cout << "0" << endl;
	}
	else {
		weight = (double)round(weight / .0001) * 0.0001;
		if ((int)(weight * 10000) % 10 == 0) {
			cout << weight;
		}
		else {
			cout << fixed << setprecision(4) << weight;
		}
	}
}