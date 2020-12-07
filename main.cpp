#include "AVLTree.h"
#include <fstream> 

int Tree::numTimesCalled;

void doTree(string name, string extra, float pricePerPoint); 
void doList(string name, string extra, float pricePerPoint);

void readDataWineType(int results, string wineType);
void readDataLocation(int results, string location);
void readDataBudget(int results, string budget);

int main(){

    string wineType = "Variety";
    string location = "Country";
    string budget = "Budget";

    int option = 0;

    while (option != 5){
        cout << "======================================================================" << endl;
        cout << "      Welcome to VINO! Please select one of the following options:" << endl << endl;
        cout << "                  1. " << wineType << "     2. " << location << endl; // tags?? (smoky, soft notes, etc.)
        cout << "                  3. " << budget << "       4. Show me!" << endl;
        cout << "                          5. Exit" << endl; 
        cout << "======================================================================" << endl;

        cout <<"Option: ";
        cin >> option;

        if (option > 5 || option < 1){
            cout << "Come on now. Don't be rude." << endl;
        }
        else{
            if (option == 1){
                cout << "Excellent! What variety shall we go with today?" << endl;
                cin >> wineType;
            }

            if (option == 2){
                cout << "Fantastic! What lovely country shall you choose?" << endl;
                cin >> location;
            }

            if (option == 3){
                cout << "Magnificent! What's your budget looking like today?" << endl;
                cin >> budget;
            }

            if (option == 4){
                if (wineType != "" && location != "" && budget != ""){

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

                    cout << "How many results would you like to show?" << endl;
                    int results;
                    cout << "Number of results: ";
                    cin >> results;
                    cout << endl;

                    
                    if (option == 1){
                        readDataWineType(results, wineType);
                    }

                    if (option == 2){
                        readDataLocation(results, location);
                    }

                    if (option == 3){
                        readDataBudget(results, budget);
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

void readDataWineType(int results, string wineType){
    string designation, country, province, region, variety, points, price;
    float pricePerPoint;

    // before adding intro tree/list, throw out if a value is missing 

    Tree tree = Tree(results);
    //AdjacencyList list = AdjacencyList(results);

    ifstream loadedFile("winemag-data_first150k.csv");
    string fileLine;
    getline(loadedFile, fileLine); // skips first line 
    while (getline(loadedFile, fileLine)){
        istringstream streem(fileLine); // turns line into stream 

        getline(streem, country, ','); 
        getline(streem, designation, ','); 
        getline(streem, points, ','); 
        getline(streem, price, ','); 
        getline(streem, province, ','); 
        getline(streem, region, ','); 
        getline(streem, variety, ','); 
        
        try{
            pricePerPoint = (stof(price)/stof(points))*100.0; 
            if (variety == wineType) // only add values that match the variety 
                tree.addNode(designation, variety, country, province, region, pricePerPoint);
        }
        catch(exception e){
           pricePerPoint = 0; // if missing a value, discard 
        }
        
    }

    cout << "                           AVL Tree:"<< endl;
    tree.print();

    // print adjacency list stuff below 
}

void readDataLocation(int results, string location){
    cout << "temp";
}

void readDataBudget(int results, string budget){
    cout << "temp";
}