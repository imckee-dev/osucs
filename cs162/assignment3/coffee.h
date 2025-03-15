#ifndef COFFEE_H
#define COFFEE_H

#include <string>
#include <fstream>

using namespace std;

class Coffee {
  private:
    string name;
    float small_cost;
    float medium_cost;
    float large_cost;
    
  public:
    //need to include accessor functions and mutator functions for private member when appropriate
    //need to include constructors and destructors where appropriate
    //need to use 'const' when appropriate

    Coffee();     //coffee constructor from lab5

    // //setters/mutators
    // void set_name(const string);
    // void set_small_cost(const float);
    // void set_medium_cost(const float);
    // void set_large_cost(const float);

    // //getters/accessors
    string get_name() const;    
    float get_small_cost () const;
    float get_medium_cost () const;
    float get_large_cost () const;

    void print_coffee() const; //print the coffee object

    //other functions:
    void coffee_load_data(ifstream &);

    void append_new_coffee(ofstream &) const; //ofstream coffee object to menu.txt file when adding new

    void get_new_drink();

    string check_name(string);

    void print_coffee_searchprice(float) const;
    
};
#endif