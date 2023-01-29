#include <iostream>
#include <unistd.h>
#include "cellular_automaton.h"
using namespace std;

int main(){

      Cell_Automaton arr1;

      system("clear");

      arr1.set_arr(127);

      for(int i = 0;i < 256;i++){
            arr1.set_cell();
            arr1.show_cell();

            for(int j = 0;j < 63;j++){ //セル・オートマトンを何世代先までループさせるか指定している。
                  arr1.calculation_cell();
                  arr1.calculation_arr();
                  arr1.all_rules(i);
                  arr1.show_cell();
            }

            cout << "Cell Automaton Rules:" << i << endl;
            usleep(0.5 * 1000000);
            system("clear");
      }

      return 0;

}
