#include <iostream>
#include <fstream>
#include <cmath>
#include <string>

using namespace std;


struct NomeDelloStruct{
    double x;
    double y;
};

int count_line(const string& filename);
void load_data(const string& filename, position* vec, int length);
void print_first(position* vec, int length);
void swap(position& x, position& y);
void sort(position* vec, int length);
void print_sorted(position* vec, int length);
double find_min(position* vec, int lentgh);
double find_max(position* vec, int length);
void print_third(position* vec, int lenght);
void print_file(const string& filename, position* vec, int length);
