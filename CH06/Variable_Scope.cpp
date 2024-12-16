/*
auto 用法  -->  auto variable_name = value;    // 會自動判斷變數型態， 作用範圍限於單一函數，變數值可以修改，型態不可改變

static 用法  -->  static int variable_name = value;    // 不會自動判斷變數型態，全域變數，作用於整個程式，變數值可以修改，型態不可改變
static auto 用法  -->  static auto variable_name = value;    // 會自動判斷變數型態，全域變數，作用於整個程式，變數值可以修改，型態不可改變

const 用法  -->  const int variable_name = value;    // 不會自動判斷變數型態，全域變數，作用於整個程式，變數值不可修改，型態不可改變 
const auto 用法  -->  const auto variable_name = value;    // 會自動判斷變數型態，全域變數，作用於整個程式，變數值不可修改，型態不可改變

define 用法  -->  #define variable_name value    // 不會自動判斷變數型態，全域變數，作用於整個程式，變數值不可修改，型態不可改變

const 與 define 的差異  -->  const 會檢查型態，define 不會檢查型態
*/

#include <iostream>
#include <typeinfo>
using namespace std;
int main() {
    auto i = 16;    
    static auto n = 32;    
    const auto t = 64;   
    #define l 128    

    cout << "Type of i is " << typeid(i).name() << ", i = " << i << endl;
    cout << "Type of n is " << typeid(n).name() << ", n = " << n << endl;
    cout << "Type of t is " << typeid(t).name() << ", t = " << t << endl;
    cout << "Type of l is " << typeid(l).name() << ", l = " << l << endl;

    return 0;
}