//
//  stats.cpp
//  p1-stats
//
//  Created by Ronald Luke Jamieson on 5/2/23.

// Project UID 5366c7e2b77742d5b2142097e51561a5
#include "stats.h"
#include "p1_library.h"
#include <cassert>
#include <vector>
#include <cmath>

using namespace std;

vector<pair<double, int> > summarize(vector<double> v) {
    //psuedocode:
    // give us a vector to sort and return summary of dataset as pairs
    // return vector of pairs?
    //{value, frequency}
    // sort by value
    // use sort function to sort vector;
    // create a counter to keep track of iterations throught the vector of doubles
    // create a variable for the current number in the vector
    
    // sort
    sort(v);
    // counter
    int count = 0;
    // create a vector of pairs
    vector<pair<double, int>> data;
    // variable that notes value
    double current_number = v[0];
    //iterate through input gvector until size
    for (size_t i = 0; i < v.size(); i++) {
        // if the current number is equal to number at position
        if (current_number == v[i]) {
            // increment count
            count++;
        }
        else {
            data.push_back({current_number, count});
            current_number = v[i];
            count = 1;
        }
    }
    data.push_back({current_number, count});
    return(data);
}

int count(vector<double> v) {
    // iterate through the vector for every value
    // increase the count variable by 1
    int count = 0;
    for (size_t i = 0; i < v.size(); i++){
        count++;
    }
    return(count);
  //assert(false);
}

double sum(vector<double> v) {
    double sum_of_elements = 0;
    for (double i(v.size()); i > 0; --i){
        sum_of_elements += v[i-1];
    }
       
    return(sum_of_elements);
}

double mean(vector<double> v) {
    // use the sum function and divide by the size of the vector
    return sum(v)/v.size();
}

double median(vector<double> v) {
    // if the count of the vector is divisible by 2, then the vector has even number of values
    // divide count by 2 and access the beginning plus count/2 position
    // return the value
    // if the count of vector isn't divisible by 2 then vector is odd
    // return
    int vector_size = count(v);
    sort(v);
    if (vector_size % 2 == 0) {
        return (v[vector_size/2] + v[vector_size/2 - 1]) /2;
    }
    else{
        return(v[vector_size/2]);
    }
}

double mode(vector<double> v) {
    assert(!v.empty());
    sort(v);
    // iterate through the vector
    //vector<pair<double, int>> vp;
    vector<pair<double, int>> v1 = summarize(v);
    //summarize(v1);
    
    //double value = 0;
    //int count = 0;
    int tempMode = v1[0].first;
    int tempFreq = v1[0].second;
 
    for (size_t i = 0 ; i < v1.size(); i++){
            if (v1[i].second > tempFreq){
                tempMode = v1[i].first;
                tempFreq = v1[i].second;
                //v1[i] == tempfreq;
                }
            }
    return tempMode;
}


double min(vector<double> v) {
    sort(v);
    assert(!v.empty());
    int min = fmin(v[0], v[v.size() -1]);
    return(min);
}

double max(vector<double> v) {
    sort(v);
    assert(!v.empty());
    int max = fmax(v[0], v[v.size() -1]);
    //fmin(v[0],v.end())
//    int max = v[0];
//    for (size_t i = 0; i < v.size(); i++){
//        if(v[i] > max){
//            max = v[i];
//        }
//    }
    return max;}

double stdev(vector<double> v) {
    //variance is the standard deviation squared
    // use a for loop to iterate through items and find variance of total data set
    // return sqrt of variance to give population standard deviation
    // create a variable representing the number of element in v
    
    int elements_v = count(v);
    //double variance = 0.0;
    double average = mean(v);
    double standard_deviation = 0;
    
    for (size_t i = 0; i < v.size(); i++){
        standard_deviation += pow((v[i] - average), 2);
    }
    return sqrt(standard_deviation/(elements_v-1));

}

double percentile(vector<double> v, double p) {
    assert(!v.empty());
    sort(v);
    // iterating from 0 instead of 1
    double rank = p * (v.size() -1) + 1;
    double fractpartD = 0;
    double intpartK = 0;
    
    fractpartD = modf(rank, &intpartK);
    if(rank == v.size()){
        return v[v.size() - 1];
    }
    double percentileV = v[intpartK-1] + (fractpartD * ((v[intpartK ] - v[intpartK-1])));
    
    return percentileV;
}


