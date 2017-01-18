#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <stdint.h>
#include <climits>

using namespace std;

long int retmin(vector<long int>& p, vector< vector<long int> >c, long int iday) {
	long int i, j, k, l;
	long int N = p.size();
	long int M = c[0].size();
	long int min = LONG_MAX;
	long int index = M+1;
	for(i=0;i<iday;i++) {
		if(p[i]>=M) continue;
		else if(c[i][p[i]]<min) {
			min = c[i][p[i]];
			index = i;
		}
	}
	p[index] = p[index] + 1;
	return min;
}

int main() {
	long int T, N, M;
	fstream fin("in1", ios::in);
	fstream fout("out1",ios::out);
	fin>>T;
	long int i, j, k, l, t;
	for(t=0;t<T;t++) {
		fin>>N>>M;
		vector< vector<long int> > c(N);
		vector<long int> p(N);
		for(i=0;i<N;i++) p[i] = 0;
		for(i = 0;i<N;i++) c[i].resize(M);
		for(i=0;i<N;i++) {
			for(j=0;j<M;j++) {
				fin>>c[i][j];
			}
		}
		for(i=0;i<N;i++) {
			sort(c[i].begin(), c[i].end());
		}
		for(i=0;i<N;i++) {
			for(j=0;j<M;j++) {
				c[i][j] = c[i][j] + (2*j+1);
			}
		}
		long int cost = 0;
		for(i=0;i<N;i++) {
			cost = cost + retmin(p, c, i+1);
		}
		fout<<"Case #"<<t+1<<": "<<cost<<endl;
		//fin.seekg(0, ios::beg); fin>>T;
	}
}