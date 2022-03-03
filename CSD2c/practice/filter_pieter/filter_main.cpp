#include <iostream>
#include "filter.h"

int main(){
    Filter filter;
    
    for(int i = 0; i < 1000; i++){
        filter.filter(i);
    }    
    filter.filter_out();
    filter.plot_waveshaper();
}   