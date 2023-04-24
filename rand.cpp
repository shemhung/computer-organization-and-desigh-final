#include <bits/stdc++.h>
#include <chrono>
#include<ctime>
#include<fstream>
using namespace std;
using namespace chrono;
int main(){
	ofstream ofs;
	ofs.open("input.txt");
	srand( time(NULL));
	int n,m,k;
	cin>>n>>m>>k;
	ofs<<n<<" "<<m<<" "<<k<<endl;
	float min=-1000;
	float max=1000;
	float x ;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			x=(max-min)*rand()/(RAND_MAX + 1.0) + min;
			ofs<<x<<" ";
		}
		ofs<<endl;
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<k;j++){
			x=(max-min)*rand()/(RAND_MAX + 1.0) + min;
			ofs<<x<<" ";
		}
		ofs<<endl;
	}
}