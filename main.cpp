#include <iostream>
#include "cellular_automaton.h"
using namespace std;

int main(){

      int rules;
      Cell_Automaton arr1;
      
      cout << "セル・オートマトンのルールを指定してください。（0-255）" << endl;
      cin >> rules;

      system("clear");

      arr1.set_arr(127); //配列の長さ、引数を変えることでセルの長さを変えられる。
      arr1.set_cell();
      arr1.show_cell();

      for(int i = 0;i < 63;i++){ //セル・オートマトンを何世代先までループさせるか指定している。
            arr1.calculation_cell();
            arr1.calculation_arr();
            arr1.all_rules(rules);
            arr1.show_cell();

      }

      return 0;

}