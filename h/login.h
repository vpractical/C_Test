//
// Created by pc on 2020/4/2.
// ͷ�ļ� .h �Ƕ��Ⱪ¶��
//

#ifndef C_TEST_MAIN_H
#define C_TEST_MAIN_H

#endif //C_TEST_MAIN_H

#include <stdint.h>

//�൱��java�Ľӿڶ���
void hello();

void login(int64_t param,void(*loginSuccess)(int64_t,char*),void(*loginFailed)(int64_t));

void loginSuccess(int64_t code,char *res);

void loginFailed(int64_t code);