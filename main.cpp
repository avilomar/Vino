#include "AVLTree.h"
#include "adjacencyList.h"
#include <fstream> 

void doTree(string name, string extra, float pricePerPoint); 
/*
1. wine type (alphabetical) enter as: name, wineType, priceperpoint 
2. location (alphabetical) enter as: name, location, ppp 
3. by number 
*/
void doList(string name, string extra, float pricePerPoint);
/*
1. From wine type -> price per point 
2. US->California, US->Oregon, etc. (country->region)
3. from price->point 
*/

void readDataWineType(int results, string wineType);
void readDataLocation(int results, string location);
void readDataBudget(int results, string budget);

void showChoices(string wineType, string location, string budget){
    cout << "======================================================================";
    cout << endl << "                        Your choice(s):" << endl << endl;
    if (wineType != "")
        cout << "                         " << wineType << endl;
    if (location != "")
        cout << "                         " << location << endl;
    if (budget != "")
        cout << "                         " << budget << endl;
}

int main(){

    string wineType;
    string location;
    string budget;

    int option = 0;

    while (option != 5){
        cout << "======================================================================" << endl;
        cout << "      Welcome to VINO! Please select one of the following options:" << endl << endl;
        cout << "                  1. Wine type        2. Location" << endl; // tags?? (smoky, soft notes, etc.)
        cout << "                  3. Budget           4. Show me!" << endl;
        cout << "                             5. Exit" << endl; 
        cout << "======================================================================" << endl;

        cout <<"Option: ";
        cin >> option;

        if (option > 5 || option < 1){
            cout << "Come on now. Don't be rude." << endl;
        }
        else{
            if (option == 1){
                cout << "Excellent! What wine shall we go with today?" << endl;
                cin >> wineType;
                showChoices(wineType, location, budget);
            }

            if (option == 2){
                cout << "Fantastic! What lovely country shall you choose?" << endl;
                cin >> location;
                showChoices(wineType, location, budget);
            }

            if (option == 3){
                cout << "Magnificent! What's your budget looking like today?" << endl;
                cin >> budget;
                showChoices(wineType, location, budget);
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
                cout << "Sounds good. Have a great day!" << endl;
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
    string designation, country, province, region, variety;
    int points, price;
    float pricePerPoint;
    // before adding intro tree/list, throw out if a value is missing 

    Tree tree = Tree(results);
    AdjacencyList list = AdjacencyList(results);

    ifstream theFile("winemag-data_first150k.csv");
    while (getline())






    cout << "AVL Tree:"<< endl;
    tree.print();
    cout << "Adjacency List:" << endl;
    list.print();
}

void readDataLocation(int results, string location){

}

void readDataBudget(int results, string budget){

}