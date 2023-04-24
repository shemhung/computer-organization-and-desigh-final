#include <bits/stdc++.h>
#include <chrono>
#include<ctime>
#include<fstream>
using namespace std;
using namespace chrono;
int main() {
    int n, k, m;
    fstream ifs;
    ifs.open("input.txt",ios::in);
    ifs >> n >> k >> m;
    vector<vector<float>> A(n, vector<float>(k));
    vector<vector<float>> B(k, vector<float>(m));
    vector<vector<float>> C(n, vector<float>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            ifs >> A[i][j];
        }
    }
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < m; j++) {
            ifs >> B[i][j];
        }
    }
    // mul
    auto start = steady_clock::now();
    float sum;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            sum = 0;
            //printf("calculating C[%d][%d]:",i,j);
            for (int l = 0; l < k; l++) {
            	/*printf("%f x %f ",A[i][l],B[i][l]);
            	if(l<k-1){
            		printf(" + ");
				}*/
                sum += A[i][l] * B[l][j];
            }
            C[i][j] = sum;
            //cout <<"= "<< sum << "\n ";
        }
        //cout << "\n";
    }
    auto end = steady_clock::now();
    auto time = duration_cast<nanoseconds>(end-start);       
    cout<<float(time.count())*nanoseconds::period::num/nanoseconds::period::den<<"s"<<endl;
    /*
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){  
            cout<<C[i][j]<<" "; 
        }
        cout<<endl;
    }*/
    
    
    return 0;
}