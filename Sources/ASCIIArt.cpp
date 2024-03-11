/**
 * 
 * @author Thiago Barbosa Ribeiro
 * @copyright All rights reserved to the author.
*/

#include "ASCIIArt.h"
#include <iostream>

void cASCIIArt::ShowAsciiArt(){
  std::cout << R"(
  _____                _ _               _    _ _     _                   
 |  __ \              | (_)             | |  | (_)   | |                  
 | |__) |___  __ _  __| |_ _ __   __ _  | |__| |_ ___| |_ ___  _ __ _   _ 
 |  _  // _ \/ _` |/ _` | | '_ \ / _` | |  __  | / __| __/ _ \| '__| | | |
 | | \ \  __/ (_| | (_| | | | | | (_| | | |  | | \__ \ || (_) | |  | |_| |
 |_|  \_\___|\__,_|\__,_|_|_| |_|\__, | |_|  |_|_|___/\__\___/|_|   \__, |
                                  __/ |                              __/ |
                                 |___/                              |___/                                                                                                                                                                              
  )" << std::endl;
}