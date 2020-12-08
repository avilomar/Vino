#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <map>
#include <queue>
#include <unordered_map>
using namespace std;
/*
struct Node{
    private:
    string country;
    string region;
    string points;
    string price;
    string province;
    string pricePerPoint;
    string variety;
    string title;
    public:
    Node(string country, string title, string points, string price, string province, string region, string variety, string pricePerPoint);
};

Node::Node(string country, string title, string points, string price, string province, string region, string variety, string pricePerPoint){

}
*/
class Lista{
private:
    map<float, map<string, string> > vinos;
    map<int, map<string, string> > vinos2;
   //priority_queue<int, map<string,string> > vinos3;
public:
    int addVino(string country, string title, string points, string price, string province, string region, string variety, string pricePerPoint);
    void losVinos();
};
int Lista::addVino(string country, string title, string points, string price, string province, string region, string variety, string pricePerPoint){
    float ppp = stof(pricePerPoint);

    
    
    map<string, string> props;
    props.emplace("country", country);
    props.emplace("points", points);
    props.emplace("price", price);
    props.emplace("province", province);
    props.emplace("region", region);
    props.emplace("variety", variety);
    props.emplace("pricePerPoint", pricePerPoint);
    props.emplace("title", title);
    
    int proice = stoi(price);
    vinos.emplace(ppp, props);
    vinos2.emplace(proice, props);
   //vinos3.push(make_pair(proice, props));
    return 1;
    
    }

void Lista::losVinos(){
    int count = 1;
    for (auto i = vinos.begin(); count < 51; i++){
        if (i!=vinos.end()){
            string location = i->second["country"] + ", " + i->second["region"] + ", " + i->second["province"];
        cout << count << ". " << i->second["title"] << " | " << i->second["variety"] << " | " << location << " | $" << i->second["price"] << endl;
        count++;
        }
        else
        {
            break;
        }
        
    }
}