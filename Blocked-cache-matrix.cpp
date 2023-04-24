#include<iostream>
#include <bits/stdc++.h>
#include<cmath>
#include<iomanip>
#include <chrono>
#include<fstream>
using namespace std;
using namespace chrono;
#define BlockSize 32
int main(){
	int n,m,k;
	fstream ifs;
    ifs.open("input.txt",ios::in);
	ifs >> n >> m >> k;
	vector<vector<float>> A(n, vector<float>(m));
    vector<vector<float>> B(m, vector<float>(k));
    vector<vector<float>> result(n, vector<float>(k));
    vector<vector<float>> BT(n, vector<float>(k));

	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			ifs >> A[i][j];
		}
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<k;j++){
			ifs >> B[i][j];
		}
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<k;j++){
			BT[j][i]=B[i][j];	
		}
	}

	for(int i=0;i<n;i++){
		for(int j=0;j<k;j++){
			result[i][j] = 0;
		}
	}//memset(result, 0, sizeof(result));
	auto start = steady_clock::now();
	//mul
	for(int x=0;x<n;x+=BlockSize){
		for(int y=0;y<k;y+=BlockSize){
			for(int z=0;z<m;z+=BlockSize){
				for(int i=x;i<x+BlockSize;i++){
					for(int j=y;j<y+BlockSize;j++){
						//printf("calculating C[%d][%d]=",i,j);
						for(int t=z;t<z+BlockSize;t++){
							result[i][j] += (A[i][t]*BT[j][t]); 
							//printf("A[%d][%d]*BT[%d][%d]+",i,t,j,t);
						}
						//cout<<"= "<<result[i][j];
						//printf("\n");
					}
				}
			}
		}
	}
	auto end = steady_clock::now();
    auto time = duration_cast<nanoseconds>(end-start);       // float
    cout<<float(time.count())*nanoseconds::period::num/nanoseconds::period::den<<"s"<<endl;
    /*
	for(int i=0;i<n;i++){
		for(int j=0;j<k;j++){
			cout << fixed << setprecision(4) << result[i][j] << " ";
		}
		cout << endl;
	}*/
}
