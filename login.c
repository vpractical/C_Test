//
// Created by pc on 2020/4/2.
// �൱��login.hͷ�ļ���ʵ�֣�����java�Ľӿ�ʵ����
//

#include <stdio.h>
//""�����Լ�������ͷ�ļ����·��,����<>��c���û�����ͷ�ļ�
#include "h/login.h"

void hello(){
    printf("please login\n");
}

void login(int64_t param,void(*success)(int64_t,char*),void(*failed)(int64_t)){
    if(param==200){
        success(param,"��¼�ɹ�");
    }else{
        failed(param);
    }
}

void loginSuccess(int64_t code,char *res){
    printf("loginSuccess:%d,%s\n",code,res);
}

void loginFailed(int64_t code){
    printf("loginFailed:%d\n",code);
}