//
// Created by yang zhengtao on 2021/5/23.
//
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
struct Point
{
    double x;
    double y;
    Point(double _x, double _y){
        x = _x;
        y = _y;
    }
};
double get_dist(const Point& point1, const Point& point2){
    return sqrt(pow((point1.x - point2.x), 2) + pow((point1.y - point2.y), 2));
}
double get_area(std::vector<Point> polygon){
    // add your code here
    if(polygon.size() < 3) return 0;
    int n = polygon.size();

    double sum_area = 0;
    for(int i = 1; i < n - 1; ++i){
        double half_len = (get_dist(polygon[0], polygon[i]) + get_dist(polygon[i], polygon[i + 1]) + get_dist(polygon[i + 1], polygon[0])) / 2.0;

        double temp_area = sqrt(half_len * (half_len - get_dist(polygon[0], polygon[i])) * (half_len - get_dist(polygon[i], polygon[i + 1])) * (half_len - get_dist(polygon[i + 1], polygon[0])));
        cout<<temp_area<<endl;
        sum_area += temp_area;
    }
    return sum_area;
}


int main(){
    vector<Point> vec;
    vec.push_back(Point(0.0, 0.0));
    vec.push_back(Point(5.0, 0.0));
    vec.push_back(Point(5.0, 5.0));
    vec.push_back(Point(0.0, 5.0));
    cout<<get_area(vec);

    return 0;

}
