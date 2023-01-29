class Cell_Automaton{ //Cell_Automatonというクラスを作成する。
      private: //メンバ関数で整数型のポインターを指定している。
         int *arr;
         int *calc_cell;
         int arr_len; //配列の長さを入れる変数。
         int calc_cell_len; //計算に使う配列の長さを入れる関数。
      public:
         Cell_Automaton(); //コンストラクタ、動的にメモリを確保する時に、配列の初期化を行う。
         ~Cell_Automaton(); //デストラクタ、終了時に動的に確保した配列のメモリを開放する。
         void set_arr(int num); //配列を入力値に応じた長さで作成する。
         void calculation_cell(); //arr配列の中身をcalc_arrに移し替える。
         void calculation_arr(); //配列内の３ビットの計算し、結果をarr配列の各要素に代入していく。
         void all_rules(int rule_num); //引数にセルオートマトンのルールの番号を与えると、そのルール通りのビット列を返す関数。
         void set_cell();
         void show_cell();
};