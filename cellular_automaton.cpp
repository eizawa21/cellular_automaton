#include <iostream>
#include "cellular_automaton.h"
using namespace std;

Cell_Automaton::Cell_Automaton(){
      arr = new int(); //動的にメモリを確保している。
      calc_cell = new int();
}

Cell_Automaton::~Cell_Automaton(){
      delete[] arr; //デストラクタを利用してメモリを開放する。
      delete[] calc_cell;
      cout << "Cell_Automaton END!" << endl;
}

void Cell_Automaton::set_arr(int num){ //arrとcalc_arrという２つの配列のメモリを動的に確保している。引数の大きさで配列の長さが決まる。
      arr = new int[num];
      arr_len = num;
      calc_cell_len = num+2;
      calc_cell = new int[calc_cell_len];

      for(int i = 0;i < num;i++){
            arr[i] = 0;
            calc_cell[i+1];
      }
}

void Cell_Automaton::calculation_cell(){ //arrからcalc_arrに要素を渡すだけの関数。

      for(int i = 1; i < arr_len+1; i++)
      {   
          calc_cell[i] = arr[i-1];
      }

}

void Cell_Automaton::calculation_arr(){ //セルの原点nとして、n-1,n+1の３ビットを読み込み合計値を計算している。
      int sum_x =0;

      for(int i = 1;i < arr_len+1;i++){
            if(calc_cell[i-1] == 1){
                  sum_x += 4;
            }
            if (calc_cell[i] == 1){
                  sum_x += 2;
            }
            if (calc_cell[i+1] == 1){
                  sum_x += 1;
            }

            arr[i-1] = sum_x;
            sum_x = 0;
      }

}

void Cell_Automaton::all_rules(int rule_num){ //calculation_arr関数で習得した整数値(0-7)の配列の各要素ごとに要素の数値分だけ左ビットシフト演算を行う。
      int bit_num;

      for(int i = 0;i < arr_len;i++){
            bit_num = 1 << arr[i]; //先頭の1ビットだけ立てて、配列の要素分だけ左ビットシフトしている。
            
            if((bit_num & rule_num) == 0){ //ビットシフトして得られた数値と、セルオートマトンのルールの数値をAND演算する。解が0なら0、それ以外なら1が配列に代入される。
                  arr[i] = 0;
            }
            else{
                  arr[i] = 1;
            }
      }

}

void Cell_Automaton::set_cell(){ //配列の中央にセルを配置するだけの関数。
      int center;

      for(int i = 0;i < arr_len;i++){
            arr[i] = 0;
      }
      center = arr_len / 2;
      arr[center] = 1;
}

void Cell_Automaton::show_cell(){ //0と1の数値を、セルの記号として、1の場合は"■" 、0の場合は"□"に変換して出力する。
      for(int i = 0;i < arr_len;i++){
            if(arr[i] == 1){
                  cout << "■ ";
            }
            else{
                  cout << "□ ";
            }
      }

      cout << endl;
}