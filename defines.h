#pragma once

#define varname(var) (#var)

#define clear_console() system("cls")

#define out std::wcout // outstream
#define screen_buffer out
#define flush std::endl;

// TODO: use postfix notation like 4s or 10ms (i've seen it somewhere already)

// sleep(4000) means sleep for 4 sec
#define sleep(ms) std::this_thread::sleep_for(std::chrono::milliseconds(ms));

// WARNING: additional behavior - throws 'i' counter variable into the scope
#define for_range_var(range, name) for(int name = 0; name < range; ++name)
#define for_range(range) for_range_var(range, i)
#define for_matrix(rows, cols) for_range_var(rows, i) for_range_var(cols, j)
// WARNING: use inside for_matrix loop
#define cur_elem(matrix) matrix.at(i).at(j) // TODO: use [row][col]