// Copyright (c) 2014
// Akira Takahashi, Fumiki Fukuda.
// Released under the CC0 1.0 Universal license.

class single_thread_model { /*……*/ }; // シングルスレッド
class multi_thread_model  { /*……*/ }; // マルチスレッド

class reference_count { /*……*/ }; // 参照カウント方式
class deep_copy       { /*……*/ }; // ディープコピー方式
class copy_on_write   { /*……*/ }; // 書き込み時コピー方式

// スマートポインタ<所有権管理方式, スレッドモデル>
template <class Ownership, class ThreadModel>
class smart_ptr { /*……*/ };

int main()
{
  // シングルスレッドの参照カウント方式のスマートポインタ
  smart_ptr<reference_count, single_thread_model> ptr1;
  
  // マルチスレッドのディープコピー方式のスマートポインタ
  smart_ptr<deep_copy, multi_thread_model> ptr2;
  
  // マルチスレッドの書き込み時コピー方式のスマートポインタ
  smart_ptr<copy_on_write, multi_thread_model> ptr3;
}
