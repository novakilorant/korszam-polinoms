#include <iostream>
#include <cmath>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib> 
#include <random>

using namespace std;

struct polinom
{std::vector<double> parameters;

polinom& operator+=(polinom& v){
    polinom out;
    int i=0;
    std::vector<double> v1, v2;
    if (v.parameters.size() > parameters.size()){
        v1 = v.parameters;
        v2 = parameters;
    }
    else{
        v1 = parameters;
        v2 = v.parameters;        
    }
    int X = v1.size();
    for (i=0;i<X;i++){
        if (i <  v2.size()){
            out.parameters.push_back(v1[i]+v2[i]);
        }
        else{
            out.parameters.push_back(v1[i]);
        }
    }
    parameters = out.parameters;
    return*this;}
polinom& operator-=(polinom& v){
    polinom out;
    int i=0;
    std::vector<double> v1, v2;
    v1 = parameters;
    v2 = v.parameters;
    if (parameters.size() > v.parameters.size()){
        for (i=0;i<parameters.size()-v.parameters.size();i++){
            v2.push_back(0);
        }
    }
    else{
        for (i=0;i<v.parameters.size()-parameters.size();i++){
            v1.push_back(0);
        }      
    }
    int X = v1.size();
    for (i=0;i<X;i++){
            out.parameters.push_back(v1[i]-v2[i]);
        }
    parameters = out.parameters;
    return*this;}
polinom& operator*=(double const & a){
    polinom out;
    int i=0;
    std::vector<double> v1;
    v1 = parameters;
    int X = v1.size();
    for (i=0;i<X;i++){
            out.parameters.push_back(v1[i]*a);
        }
    parameters = out.parameters;
    return*this;
    }
polinom& operator/=(double const & a){
    polinom out;
    int i=0;
    std::vector<double> v1;
    v1 = parameters;
    int X = v1.size();
    for (i=0;i<X;i++){
            out.parameters.push_back(v1[i]*a);
        }
    parameters = out.parameters;
    return*this;
    }

};

std::ostream& operator<<( std::ostream& o, polinom const& a){
    int i;
    o << "{";
    for (i=0; i < a.parameters.size(); i++){
        if (i != a.parameters.size()-1){
            o << a.parameters[i] << ", ";
        }
        else{
            o << a.parameters[i];
        }
    }
    o << "}" << endl;
    return o;
    }

polinom operator+( polinom const & a, polinom const & b){
    polinom out;
    int i=0;
    std::vector<double> v1, v2;
    if (a.parameters.size() > b.parameters.size()){
        v1 = a.parameters;
        v2 = b.parameters;
    }
    else{
        v1 = b.parameters;
        v2 = a.parameters;        
    }
    int X = v1.size();
    for (i=0;i<X;i++){
        if (i <  v2.size()){
            out.parameters.push_back(v1[i]+v2[i]);
        }
        else{
            out.parameters.push_back(v1[i]);
        }
    }
    return out;
    }

polinom operator-( polinom const & a, polinom const & b){
    polinom out;
    int i=0;
    std::vector<double> v1, v2;
    v1 = a.parameters;
    v2 = b.parameters;
    if (a.parameters.size() > b.parameters.size()){
        for (i=0;i<a.parameters.size()-b.parameters.size();i++){
            v2.push_back(0);
        }
    }
    else{
        for (i=0;i<b.parameters.size()-a.parameters.size();i++){
            v1.push_back(0);
        }      
    }
    int X = v1.size();
    for (i=0;i<X;i++){
            out.parameters.push_back(v1[i]-v2[i]);
        }
    return out;
    }

polinom operator*(double const & a, polinom const & b){
    polinom out;
    int i=0;
    std::vector<double> v1;
    v1 = b.parameters;
    int X = v1.size();
    for (i=0;i<X;i++){
            out.parameters.push_back(v1[i]*a);
        }
    return out;
    }

polinom operator*(polinom const & b, double const & a){
    polinom out;
    int i=0;
    std::vector<double> v1;
    v1 = b.parameters;
    int X = v1.size();
    for (i=0;i<X;i++){
            out.parameters.push_back(v1[i]*a);
        }
    return out;
    }

polinom operator/(polinom const & b, double const & a){
    polinom out;
    int i=0;
    std::vector<double> v1;
    v1 = b.parameters;
    int X = v1.size();
    for (i=0;i<X;i++){
            out.parameters.push_back(v1[i]/a);
        }
    return out;
    }

double dot(polinom const& a, polinom const& b){
    polinom out;
    int i=0;
    std::vector<double> v1, v2;
    v1 = a.parameters;
    v2 = b.parameters;
    if (a.parameters.size() > b.parameters.size()){
        for (i=0;i<a.parameters.size()-b.parameters.size();i++){
            v2.push_back(0);
        }
    }
    else{
        for (i=0;i<b.parameters.size()-a.parameters.size();i++){
            v1.push_back(0);
        }      
    }
    int X = v1.size();
    double sum = 0.0;
    for (i=0;i<X;i++){
            sum += v1[i]*v2[i];
        }
    return sum;
    }

polinom derivative(polinom const& a){
    polinom out;
    int i=0;
    std::vector<double> v1 = a.parameters;
    int X = v1.size();
    double sum = 0.0;
    for (i=1;i<X;i++){
            out.parameters.push_back(v1[i]*i);
        }
    return out;
}

polinom integrate(polinom const& a, double const& c){
    polinom out;
    int i=0;
    std::vector<double> v1 = a.parameters;
    int X = v1.size();
    double sum = 0.0;
    for (i=0;i<X+1;i++){
        if (i==0){
            out.parameters.push_back(c);
        }
        else{
            out.parameters.push_back(v1[i-1]/i);
        }
        }
    return out;
}

void poliprint(polinom const& a){
    int i;
    cout << "{";
    for (i=0; i < a.parameters.size(); i++){
        if (i != a.parameters.size()-1){
            cout << a.parameters[i] << ", ";
        }
        else{
            cout << a.parameters[i];
        }
    }
    cout << "}" << endl;
}