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

vector<vector<double>> expand(vector<vector<double>> M) {
    for (int i=0; i<M[0].size(); i++) {
        M[i].insert(M[i].begin(), 1, 0.0);
        M[i].push_back(0.0);
    }
    M.push_back(vector<double>(M[0].size(), 0.0));
    M.insert(M.begin(), 1, vector<double>(M[0].size()));
    
    return M;
}

int main() {

    default_random_engine generator;
    normal_distribution<double> distribution(0.0, 1.0);
    int dim = 300;
    vector<vector<double>> M;
    
    for (int i=0; i<dim; i++) {
        vector<double> temp;
        for (int j=0; j<dim; j++)
            temp.push_back(distribution(generator));
        M.push_back(temp);
    }
    
    clock_t start = clock();
    expand(M);
    clock_t end = clock();
    cout << sec(start, end) << endl;
}
