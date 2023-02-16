#pragma once

#define clear_console() system("cls")

#define out std::cout // outstream

// TODO: use postfix notation like 4s or 10ms (i've seen it somewhere already)

// sleep(4000) means sleep for 4 sec
#define sleep(ms) std::this_thread::sleep_for(std::chrono::milliseconds(ms));

// WARNING: additional behavior - throws 'i' counter variable into the scope
#define for_range(range) for(int i = 0; i < range; ++i)
