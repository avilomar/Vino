#include "AVLTree.h"
#include <fstream> 

void readDataWineType(string wineType);
void readDataLocation(string location);
void readDataBudget(string budget);

int main(){

    string wineType;
    string location;
    string budget;

    int option = 0;

    while (option != 5){
        cout << "======================================================================" << endl;
        cout << "      Welcome to VINO! Please select one of the following options:" << endl << endl;
        cout << "                  1. Variety             2. Country " << endl; // tags?? (smoky, soft notes, etc.)
        cout << "                  3. Budget              4. Show me!" << endl;
        cout << "                              5. Exit" << endl; 
        cout << "======================================================================" << endl;

        cout <<"Option: ";
        cin >> option;

        if (option > 5 || option < 1){
            cout << "Come on now. Don't be rude." << endl;
        }
        else{
            if (option == 1){
                cout << "Excellent! What variety shall we go with today?" << endl;
                cin.ignore();
                getline(cin, wineType);
            }

            if (option == 2){
                cout << "Fantastic! What lovely country shall you choose?" << endl;
                cin.ignore();
                getline(cin, location);
            }

            if (option == 3){
                cout << "Magnificent! What's your budget looking like today?" << endl;
                cin.ignore();
                getline(cin, budget);
            }

            if (option == 4){
                if (wineType != "" && location != "" && budget != ""){

                    cout << "\n                        " << wineType << " | " << location << " | $" << budget << endl << endl;

                    cout << "                     What's your priority?" << endl;
                    cout << "                    1. Type       2. Location" << endl;
                    cout << "                          3. Budget" << endl;
                    cout << "======================================================================" << endl;

                    while (option < 1 || option > 3){
                        cout << "Priority: ";
                        cin >> option;
                        cout << endl;
                        if (option > 3 || option < 1)
                            cout << "A number 1-3, please." << endl;
                    }
                    
                    if (option == 1){
                        readDataWineType(wineType);
                    }

                    if (option == 2){
                        readDataLocation(location);
                    }

                    if (option == 3){
                        readDataBudget(budget);
                    }

                }
                else{
                    cout << "Wait! You forgot to enter something!" << endl;
                }
            }

            if (option == 5){
                cout << "Sounds good. Have a great day!" << endl << endl;
                cout << "        |       |" << endl;
                cout << "        \\      / " << endl;
                cout << "         \\    /" << endl;
                cout << "          \\  /" << endl;
                cout << "           ||" << endl;
                cout << "           ||" << endl;
                cout << "           ||" << endl;
                cout << "        --------" << endl;
                return 0;
            }
        }
    }

    return 0;
}

void readDataWineType(string wineType){
    string country, province, region, title, variety, points, price, ppp;
    float pricePerPoint;

    Tree tree = Tree();
    //AdjacencyList list = AdjacencyList(results);

    ifstream loadedFile("winemag-data-130k-v2.csv");
    string fileLine;
    getline(loadedFile, fileLine); 
    getline(loadedFile, fileLine); // getting rid of headers 

    while (getline(loadedFile, fileLine)){
        istringstream streem(fileLine); // turns line into stream 

        getline(streem, country, ','); 
        getline(streem, points, ','); 
        getline(streem, price, ','); 
        getline(streem, province, ','); 
        getline(streem, region, ','); 
        getline(streem, title, ',');
        getline(streem, variety, ','); 
        getline(streem, ppp);

        if (variety == wineType){ // only add values that match the variety 
            tree.addNode(title, variety, country, province, region, stof(ppp), stoi(price));
            // line to add to list here 
        } 
        
    }

    cout << "                           AVL TREE RESULTS"<< endl;
    tree.print();


    cout << "                         ADJACENCY LIST RESULTS"<< endl;
    // PRINT ADJACENCY STUFF BELOW 
}

void readDataLocation(string location){
    string country, province, region, title, variety, points, price, ppp;
    float pricePerPoint;

    Tree tree = Tree();
    //AdjacencyList list = AdjacencyList(results);

    ifstream loadedFile("winemag-data-130k-v2.csv");
    string fileLine;
    getline(loadedFile, fileLine); 
    getline(loadedFile, fileLine); // getting rid of headers 

    while (getline(loadedFile, fileLine)){
        istringstream streem(fileLine); // turns line into stream 

        getline(streem, country, ','); 
        getline(streem, points, ','); 
        getline(streem, price, ','); 
        getline(streem, province, ','); 
        getline(streem, region, ','); 
        getline(streem, title, ',');
        getline(streem, variety, ','); 
        getline(streem, ppp);

        if (country == location){ // only add values that match the country  
            tree.addNode(title, variety, country, province, region, stof(ppp), stoi(price));
            // line to add to list here 
        } 
        
    }

    cout << "                           AVL TREE RESULTS"<< endl;
    tree.print();

    cout << "                         ADJACENCY LIST RESULTS"<< endl;
    // PRINT ADJACENCY STUFF BELOW 
}

void readDataBudget(string budget){
    string country, province, region, title, variety, points, price, ppp;
    float pricePerPoint;

    Tree tree = Tree();
    //AdjacencyList list = AdjacencyList(results);

    ifstream loadedFile("winemag-data-130k-v2.csv");
    string fileLine;
    getline(loadedFile, fileLine); 
    getline(loadedFile, fileLine); // getting rid of headers 

    while (getline(loadedFile, fileLine)){
        istringstream streem(fileLine); // turns line into stream 

        getline(streem, country, ','); 
        getline(streem, points, ','); 
        getline(streem, price, ','); 
        getline(streem, province, ','); 
        getline(streem, region, ','); 
        getline(streem, title, ',');
        getline(streem, variety, ','); 
        getline(streem, ppp);

        if (stoi(price) <= stoi(budget)){ // only add values that are under or equal to budget 
            tree.addNode(title, variety, country, province, region, stof(ppp), stoi(price));
            // line to add to list here 
        } 
        
    }

    cout << "                           AVL TREE RESULTS"<< endl;
    tree.print();


    cout << "                         ADJACENCY LIST RESULTS"<< endl;
    // PRINT ADJACENCY STUFF BELOW 
}