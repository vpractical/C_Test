//
// Created by pc on 2020/4/2.
// 头文件 .h 是对外暴露的
//

#ifndef C_TEST_MAIN_H
#define C_TEST_MAIN_H

#endif //C_TEST_MAIN_H

#include <stdint.h>

//相当于java的接口定义
void hello();

void login(int64_t param,void(*loginSuccess)(int64_t,char*),void(*loginFailed)(int64_t));

void loginSuccess(int64_t code,char *res);

void loginFailed(int64_t code);