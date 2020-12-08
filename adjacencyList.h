#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <map>
#include <unordered_map>
using namespace std;
class Lista{
private:
    map<string, map<string, string> > vinos;
public:
    int addVino(string country, string title, string points, string price, string province, string region, string variety, string pricePerPoint);
};
int Lista::addVino(string country, string title, string points, string price, string province, string region, string variety, string pricePerPoint){
    map<string, string> props;
    props.insert(make_pair("country", country));
    props.insert(make_pair("points", points));
    props.insert(make_pair("price", price));
    props.insert(make_pair("province", province));
    props.insert(make_pair("region", region));
    props.insert(make_pair("variety", variety));
    props.insert(make_pair("pricePerPoint", pricePerPoint));
    vinos.insert(make_pair(title, props));
    return 1;
}
