/* stats_tests.cpp
 *
 * Unit tests for the simple statistics library
 * Project UID 5366c7e2b77742d5b2142097e51561a5
 *
 * EECS 280 Project 1
 *
 * Protip #1: Write tests for the functions BEFORE you implement them!  For
 * example, write tests for median() first, and then write median().  It sounds
 * like a pain, but it helps make sure that you are never under the illusion
 * that your code works when it's actually full of bugs.
 *
 * Protip #2: Instead of putting all your tests in main(),  put each test case
 * in a function!
 */


#include "stats.h"
#include <iostream>
#include <cassert>
#include <vector>
#include <cmath>
#include "p1_library.h"


using namespace std;

void test_sum_small_data_set();
void test_sum_large_data_set();
void test_summarize_repeating_inputs();
void test_summarize_unordered_vector();
void test_mean_basic();
void test_mean_decimal();
void test_mean_zero();
void test_mean_extraneous();
void test_count_empty();
void test_count_one();
void test_count_many();
void test_median_even();
void test_median_odd();
void test_mode_normal();
void test_min_zero();
void test_min_same();
void test_min_normal();
void test_max_two();
void test_stdev_normal();
void test_stdev_same();
void test_max_zero();
void test_max_same();
void test_stdev_normal();
void test_stdev_same();
//void test_stdev_round();
void test_percentile_25();
void test_percentile_50();
void test_percentile_75();
void test_percentile_100();
void test_stdev_main();
// Add prototypes for you test functions here.

int main() {
    test_sum_small_data_set();
    test_sum_large_data_set();
    test_summarize_repeating_inputs();
    test_summarize_unordered_vector();
    test_mean_basic();
    test_mean_decimal();
    test_mean_zero();
    test_mean_extraneous();
    test_count_empty();
    test_count_one();
    test_count_many();
    test_median_even();
    test_median_odd();
    test_mode_normal();
    test_min_zero();
    test_min_same();
    test_min_normal();
    test_stdev_same();
    test_max_two();
    test_max_zero();
    test_max_same();
    test_stdev_normal();
    test_stdev_normal();
    test_stdev_same();
   // test_stdev_round();
    test_stdev_main();
    test_percentile_25();
    test_percentile_50();
    test_percentile_75();
    test_percentile_100();
    test_stdev_main();
  return 0;
}

void test_sum_small_data_set() {
  cout << "test_sum_small_data_set" << endl;

  vector<double> data;
  data.push_back(1);
  data.push_back(2);
  data.push_back(3);

  assert(sum(data) == 6);

  cout << "PASS!" << endl;
}

void test_sum_large_data_set(){
    cout << "test_sum_large_data_set" << endl;
    vector<double> data;
    data.push_back(1);
    data.push_back(2);
    data.push_back(3);
    data.push_back(4);
    data.push_back(5);
    data.push_back(6);
    data.push_back(7);
    data.push_back(8);
    data.push_back(9);
    data.push_back(10);
    data.push_back(11);
    data.push_back(12);
    
    assert(sum(data) == 78);
    
    cout << "PASS!" << endl;
}

void test_summarize_repeating_inputs(){
    cout << "test_summarize_repeating_inputs" << endl;
    vector<double> v0 = {1.0, 2.0, 2.0, 3.0, 3.0, 3.0};
    
    sort(v0);
    
    assert((summarize(v0)[0].first) == 1);
    assert((summarize(v0)[0].second) == 1);
    assert((summarize(v0)[1].first) == 2);
    assert((summarize(v0)[2].second) == 2);
    assert((summarize(v0)[2].second) == 3);
    
    cout << "PASS!" << endl;
}

void test_summarize_unordered_vector(){
    
    cout << "test_summarize_unoredered_vector" << endl;
    vector<double> v1 = {2.0, 3234.0, 23.0, 23.0, 432.0, 12.0};
    
    sort(v1);
    assert((summarize(v1)[0].first) == 2);
    assert((summarize(v1)[0].second) == 1);
    assert((summarize(v1)[1].first) == 3234);
    assert((summarize(v1)[1].second) == 1);
    assert((summarize(v1)[2].first) == 23);
    assert((summarize(v1)[2].first) == 2);
    assert((summarize(v1)[3].first) == 432);
    assert((summarize(v1)[3].second) == 1);
    assert((summarize(v1)[4].first) == 12);
    assert((summarize(v1)[4].second) == 1);
    
    cout << "PASS!" << endl;

}

void test_mean_basic() {
    
    cout << "test_mean_basic" << endl;
    std::vector<double> data = {1, 2, 3};
    double expected = 2;
    double actual = mean(data);
    assert(actual == expected);
    
    cout << "PASS!" << endl;
    
}
void test_mean_decimal() {
    cout << "test_mean_decimal" << endl;
    std::vector<double> data1 = {1, 1, 1, 1, 2, 2, 2, 2};
    //const double epsilon = 0.00001;
    
    double expected = 1.5;
    double actual = mean(data1);
    
    assert(actual == expected);
    
    cout << "PASS!" << endl;

}
void test_mean_zero(){
    cout << "test_mean_zero" << endl;
    std::vector<double> data2 = {0,0,0,0,0,0};
    double expected = 0;
    double actual = mean(data2);
    assert(actual == expected);
    
    cout << "PASS!" << endl;
}
void test_mean_extraneous(){
    cout << "test_mean_extraneous" << endl;
    std::vector<double> data3 = {0,0,0,0,0,1};
    const double epsilon = 0.00001;
    
    double expected = .16;
    double actual = mean(data3);
    assert(abs(actual-expected) > epsilon);
    
    cout << "PASS!" << endl;
}

void test_count_empty(){
    cout << "test_count_empty" << endl;
    std::vector<double> data1 = {0};
    double expected = 1;
    double actual = count(data1);
    assert(actual == expected);
    
    cout << "PASS!" << endl;
    
}

void test_count_one(){
    cout << "test_count_one" << endl;
    std::vector<double> data2 = {1};
    double expected = 1;
    double actual = count(data2);
    assert(actual == expected);
    
    cout << "PASS!" << endl;
}

void test_count_many(){
    cout << "test_count_many" << endl;
    std::vector<double> data3 = {1,1,1,2,2,2,1,1,2,2,1,1,2,1,2,1,1,2,1,1,2,1,2,11,2,2,1};
    double expected = 27;
    double actual = count(data3);
    assert(actual == expected);
    
    cout << "PASS!" << endl;
}

void test_median_even(){
    cout << "test_median_even" << endl;
    std::vector<double> data = {1,2,3,4};
    double expected = 2.5;
    double actual = median(data);
    assert(actual == expected);
    
    cout << "PASS!" << endl;
}

void test_median_odd(){
    cout << "test_median_odd" << endl;
    std::vector<double> data1 = {1,1,1};
    double expected = 1;
    double actual = median(data1);
    assert(actual == expected);
    
    cout << "PASS!" << endl;
}

void test_median_zero(){
    cout << "test_median_zero" << endl;
    std::vector<double> data2 = {0};
    double expected = 0;
    double actual = median(data2);
    assert(actual == expected);
    
    cout << "PASS!" << endl;
}

void test_median_nothing(){
    cout << "test_median_nothing" << endl;
    std::vector<double> data3 = {};
    double expected = 0;
    double actual = median(data3);
    assert(actual == expected);
    
    cout << "PASS!" << endl;
}

void test_mode_normal(){
    cout << "test_mode_normal" << endl;
    std::vector<double> data = {2,2,2,2,3};
    double expected = 2;
    double actual = mode(data);
    cout << actual << endl;
    assert(actual == expected);
    
    cout << "PASS!" << endl;
}

void test_min_zero() {
    cout << "test_min_zero" << endl;
    std::vector<double> data = {0};
    double expected = 0;
    double actual = min(data);
    assert(actual == expected);
    cout << "PASS!" << endl;
}

void test_min_same(){
    cout << "test_min_same" << endl;
    std::vector<double> data1 = {1,1,1,1};
    double expected = 1;
    double actual = min(data1);
    assert(actual == expected);
    cout << "PASS!" << endl;
}

void test_min_normal(){
    cout << "test_min_normal" << endl;
    std::vector<double> data2 = {1,2,3,4,5,6,7,7,10,12};
    double expected = 1;
    double actual = min(data2);
    assert(actual == expected);
    cout << "PASS!" << endl;
}

void test_max_two(){
    cout << "test_max_two" << endl;
    std::vector<double> data = {1,12,31,3,31};
    double expected = 31;
    double actual = max(data);
    assert(actual == expected);
    cout << "PASS!" << endl;

}

void test_max_zero(){
    cout << "test_max_zero" << endl;
    std::vector<double> data1 = {0};
    double expected = 0;
    double actual = max(data1);
    assert(actual == expected);
    cout << "PASS!" << endl;
}

void test_max_same(){
    cout << "teset_max_same" << endl;
    std::vector<double> data2 = {1,1,1,1,1};
    double expected = 1;
    double actual = max(data2);
    assert(actual == expected);
    cout << "PASS!" << endl;
}

void test_stdev_normal(){
    cout << "test_stdev_normal" << endl;
    std::vector<double> data = {0,0};
    double expected = 0;
    const double epsilon = 0.00001;
    
    double actual = stdev(data);
    cout << actual;
    assert((abs(actual-expected)) < epsilon);
    cout << "PASS!" << endl;
}

void test_stdev_same(){
    cout << "test_stdev_same" << endl;
    std::vector<double> data1 = {1,1,1,1,1};
    const double epsilon = 0.00001;
    double expected = 0;
    double actual = stdev(data1);
    cout << actual;
    assert(actual == expected);
    assert(abs(actual-expected) < epsilon);
    cout << "PASS!" << endl;
}

//void test_stdev_round(){
//    cout << "test_stdev_same" << endl;
//    std::vector<double> data = {1,24,3254,43,231};
//    double expected = 1274.32658;
//    const double epsilon = 0.00001;
//
//    double actual = stdev(data);
//    assert(abs(actual-expected) < epsilon);
//    cout << "PASS!" << endl;
//
//}

void test_percentile_25(){
    cout << "test_percentile_0.25" << endl;
    std::vector<double> data = {1,2,3,4,5};
    const double epsilon = 0.0001;
    double expected = 2;
    double actual = percentile(data, 0.25);
    //cout << actual;
    assert((actual - expected) < epsilon);
    //assert(actual == expected);
    
    //assert(percentile(data, 0.25) == 2);
    cout << "PASS!" << endl;
    
    
}

void test_percentile_50(){
    cout << "test_percentile_0.50" << endl;
    std::vector<double> data1 = {1,2,3,4,5,};
    const double epsilon = 0.0001;
    double expected = 3;
    double actual = percentile(data1, 0.50);
    cout << actual;
    assert((actual - expected) < epsilon);
    cout << "PASS!" << endl;
    
}
void test_percentile_75(){
    cout << "test_percentile_0.75" << endl;
    std::vector<double> data2 = {1,2,3,4,5};
    const double epsilon = 0.0001;
    double expected = 4;
    double actual = percentile(data2, 0.75);
    assert((actual - expected) < epsilon);
    cout << "PASS!" << endl;
}
void test_percentile_100(){
    cout << "test_percentile_1" << endl;
    std::vector<double> data2 = {1,2,3,4,5};
    const double epsilon = 0.0001;
    double expected = 5;
    double actual = percentile(data2, 1);
    assert((actual - expected) < epsilon);
    cout << "PASS!" << endl;
}

void test_stdev_main(){
    cout << "test_stdev_same" << endl;
    std::vector<double> data = {6,7,8,9,10};
    double expected = 1.58114;
    const double epsilon = 0.00001;
    
    double actual = stdev(data);
    //cout << actual;
    assert(abs(actual-expected) < epsilon);
    cout << "PASS!" << endl;
}
