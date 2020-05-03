//
//  main.cpp
//  hi
//
//  Created by Willy Wu on 2020/4/30.
//  Copyright © 2020 Willy Wu. All rights reserved.
//

// mat.cpp
#include <iostream>
#include <string>
#include <random>
#include <vector>
// #include <ctime>

using namespace std;

double to_double(int num) {
    return static_cast<double>(num);
}

double sec(clock_t start, clock_t end) {
    return to_double(end-start)/to_double(CLOCKS_PER_SEC);
}

vector<vector<double>> padding(vector<vector<double>> M, int p) {
    clock_t start = clock()
    for (int i=0; i<M[0].size(); i++) {
        M[i].insert(M[i].begin(), p, 0.0);
        M[i].push_back(M[i].end(), p, 0.0);
    }
    M.insert(M.end(), 2, vector<double>(M[0].size(), 0.0));
    M.insert(M.begin(), 2, vector<double>(M[0].size(), 0.0));
    clock_t over = clock();
    cout << sec(start, over) << endl;
    return M;
}

int main() {

    default_random_engine generator;
    normal_distribution<double> distribution(0.0, 1.0);
    int pad = 1
    int dim = 300;
    vector<vector<double>> M;
    
    for (int i=0; i<dim; i++) {
        vector<double> temp;
        for (int j=0; j<dim; j++)
            temp.push_back(distribution(generator));
        M.push_back(temp);
    }
    
    padding(M, pad);
    cout << sec(start, end) << endl;
}
