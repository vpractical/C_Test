//
// Created by pc on 2020/4/2.
// 相当于login.h头文件的实现，类似java的接口实现类
//

#include <stdio.h>
//""查找自己创建的头文件相对路径,上面<>是c配置环境的头文件
#include "h/login.h"

void hello(){
    printf("please login\n");
}

void login(int64_t param,void(*success)(int64_t,char*),void(*failed)(int64_t)){
    if(param==200){
        success(param,"登录成功");
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