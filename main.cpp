#include "header.h" 
#include <cstdlib>

int main(){

    int dim = count_line("elettroni.dat");
    position* data = new position[dim];

    load_data("elettroni.dat", data, dim);
    print_first(data, dim);

    sort(data, dim);
    print_sorted(data, dim);

    print_third(data, dim);
    print_file("risultati.dat", data, dim);

    return 0;
}
