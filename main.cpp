// main.cpp
// Project UID 5366c7e2b77742d5b2142097e51561a5
#include <iostream>
#include <vector>
#include <cstdio>
#include "stats.h"
#include <cassert>
#include <cmath>
#include "p1_library.h"

using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    string filename, column;
    vector <double> csv_file;
    vector<vector<double>> summarized;
    cout << "enter a filename" << endl;
    cin >> filename;
    cout << "enter a column name" << endl;
    cin >> column;
    cout << "reading column " << column << " from " << filename << endl;
    //data = extract_column(filename, column);
    //sort(extract_column(filename, column));
    //summarized = summarize(data);
    vector<pair<double, int>> vp = summarize(extract_column(filename, column));
    
    cout << "Summary (value: frequency)" << endl;
    for (size_t i = 0; i < vp.size(); i++){
        cout << vp[i].first << ": ";
        cout << vp[i].second << endl;
        }
    cout << "\n";
    
    cout << "count = " << count(extract_column(filename, column)) << endl;
    cout << "sum = " << sum(extract_column(filename, column)) << endl;
    cout << "mean = " << mean(extract_column(filename, column)) << endl;
    cout << "stdev = " << stdev(extract_column(filename, column)) << endl;
    cout << "median = " << median(extract_column(filename, column)) << endl;
    cout << "mode = " << mode(extract_column(filename, column)) << endl;
    cout << "min = " << min(extract_column(filename, column)) << endl;
    cout << "max = " << max(extract_column(filename, column)) << endl;
    cout << "  0th percentile = " << percentile(extract_column(filename, column),0.0) << endl;
    cout << " 25th percentile = " << percentile(extract_column(filename, column),0.25) << endl;
    cout << " 50th percentile = " << percentile(extract_column(filename, column),0.50) << endl;
    cout << " 75th percentile = " << percentile(extract_column(filename, column),0.75) << endl;
    cout << "100th percentile = " << percentile(extract_column(filename, column),1) << endl;
    
    
//    #ifdef __APPLE__
//    freopen("main_test.in", "r", stdin);
//    #endif
//
//    std::cout << "Hello, World!\n";

    //return 0;
}
