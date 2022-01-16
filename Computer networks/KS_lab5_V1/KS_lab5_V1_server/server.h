#pragma once
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <cstring>

using namespace std;

struct Message {
    char message[50] = {};
    char from[100] = {};
    char to[100] = {};
} message;

struct User {
    char login[100] = {};
    char password[50] = {};
} user[3], workUser;