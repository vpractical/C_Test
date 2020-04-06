#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>//操作字符串的函数

//引入login.h，相当于java的引用接口
#include "h/login.h"

#define LENGTH1 10//常量

/*
 * 函数1
 */
int add(int a,int b){
    return a + b;
}
/*
 * 函数2
 * 第三个参数是函数指针
 */
int calculate(int a, int b, int(*i)(int,int)){
    return i(a,b);
}


//用于交互2个变量的值的函数
void switch1(char a,char b){
    char temp = a;
    a = b;
    b = temp;
    temp = 0;
}

void switch2(char *a,char *b){
//    int temp = a;
//    a = b;
//    b = temp;
//这个函数中指针变量a，b的指针已经和传入前的不同了，所以直接交换a，b的指针不行，需要交换指针保存的值
    int temp = *a;
    *a = *b;
    *b = temp;
    temp = 0;
}


//lsn3
//别名定义
typedef long long l;
//结构体 所有成员默认public的
struct Student{
    char *name;
    int32_t age;
    char sex;
}st = {"里二",5,'K'};

//共用体
union Data
{
    int i;
    int i2;
    int i3;
    float f;
    char  str[20];
} data;



int main() {

    printf("Lsn1-----------------\n");

    /*
     * 变量分为有符号，无符号，默认是有符号，取值范围不同
     * int	2 或 4 字节	-32,768 到 32,767 或 -2,147,483,648 到 2,147,483,647
     * unsigned int	2 或 4 字节	0 到 65,535 或 0 到 4,294,967,295
     */
    int a = INT_MIN;
    signed int b = INT_MAX;
    printf("\n有符号int范围：%d , %d",a,b);

    const int  LENGTH2 = 10;//常量

    /*
     * 存储类
     */
    auto int a1; //默认的，可以不写auto,auto 只能修饰局部变量
    register int a2;//register 存储类用于定义存储在寄存器中而不是 RAM 中的局部变量.寄存器只用于需要快速访问的变量，比如计数器。'register' 意味着变量可能存储在寄存器中，取决于硬件和实现的限制
    static int a3;//生命周期和程序的一样，但作用域限于文件内，修饰局部变量只初始化一次
    extern int a4;//在文件a中定义一个全局函数或变量，可以在b中使用extern修饰同样的变量名使用它

    /*
     * 指针
     * 一个变量，值为另一个变量的内存地址，十六位进制数
     * &+变量名就是变量的内存地址
     * *+变量的内存地址就是这个内存地址的值
     */
    int d = 20;
    int *e;//定义指针变量,这个*号只是声明指针变量，像下面指针变量e前加*号用于输出时，表示获取指针指向内存保存的值
    e = &d;//将变量d的内存地址赋值给指针变量
    printf("\n d：%d,%X,%d,%X",d,&d,*e,e);// d：20,22FE34,20,22FE34

    /*
     * 数组是一段连续内存，字符串在c中是一个一维数组
     * 数组地址是第一个元素的地址，元素是int类型，每个元素4个字节大小的话，元素地址是第一个字节的地址，每个元素地址跨度是4
     */
    int f[] = {1,2,3,4,5,6};
    for (int i = 0;i < sizeof(f) / sizeof(int);i++){
        printf("\n 数组 %d,%x,%x",f[i],&f[i],f + i);
    }

    /*
     * 函数指针及回调函数
     */
    int (*h)(int,int) = &add;
    int h1 = 2,h2 = 3,h3 = 7;
    int h4 = calculate(calculate(h1,h2,h),h3,h);
    printf("\n h: %d\n",h4);
    //模拟登录
    void (*success)(int64_t,char*) = &loginSuccess;
    void (*failed)(int64_t) = &loginFailed;
    login(200,success,failed);
    login(530,success,failed);
    /*
     * 动态申请内存
     * 声明变量时的是栈区的内存，这里是在堆区0
     */
    int *g = calloc(10, sizeof(int));//在堆中申请10个int类型的内存
//    memset(g,NULL,10* sizeof(int));//初始化这块内存，因为可能拿到的内存有内容
    printf("\n 动态申请：%x",g);
    free(g);//释放内存
    g = 0;//g是野指针置空


    printf("\nLsn2--------------\n");
    hello();

    int count = 9;//一般不这么定义int，如下，需要引入stdint.h
    int32_t count2 = 9;//定义32位即4个字节的int类型
    int8_t count3 = 9;//1个字节，类型点进去会发现是char类型

    int *x = &count;//一级指针，&获取变量的内存地址,x为指针变量，&获取的count的内存地址Z10000为指针，指针就是内存地址
    int ** y = &x;//二级指针，指针变量y的地址22fdd0,保存了指针变量x的指针即内存地址
    int*** z = &y;//三级指针
    printf("多级指针：x:%x,y:%x,z:%x,**z:%x,***z:%d\n",x,y,z,**z,***z);//x:22fddc,y:22fdd0,z:22fdc8,**z:22fddc,***z:9

    //互换2个变量的值
    char b2 = 'o';
    char b3 = 'k';

    switch1(b2,b3);
    printf("%c,%c\n",b2,b3);
    switch2(&b2,&b3);
    printf("%c,%c\n",b2,b3);
    //switch1传变量本身不能互换，因为函数有自己的内存空间,switch1函数参数的地址和传入的b2，b3的地址不同


    //可变参数的函数


    //预处理器  所有预处理命令均以符号#开头 #if 0有注释的作用
#if 0
    printf("000\n");
#else
    printf("999\n");
#endif
    printf("一定会执行的endif\n");


#define NAME "HONY" //定义一个宏,类似java中的常量,源程序每次遇到宏名称NAME，以“HONY”替换他，称为宏替换


#ifdef NAME//是否定义了宏
    printf("定义了宏\n");
#endif

#ifndef NAME//是否没有定义宏
    printf("没有定义宏\n");
#endif
    printf("\nLsn3--------------\n");

    //别名定义
    l number4 = 456456;

    //结构体 类似java中的bean
    struct Student student;
    student.name = "三儿";
    student.age = 3;
    student.sex = 'M';
    strcpy(&student.sex,"R");
    printf("学生1：%s,%d,%c\n",student.name,student.age,student.sex);
    //结构体简写 结构体可以不用名字，只要尾缀的st
    st.name = "小四小四小四小四";
    printf("学生2：%s,%d,%c\n",st.name,st.age,st.sex);
    printf("结构体占用字节数:%d\n", sizeof(st));//占用字节数:16,name8,age4,sex4
    //使用指针访问结构体的成员
    struct Student *stdu = &st;
    stdu->name = "五毛";
    printf("学生3：%s,%d,%c\n",stdu->name,stdu->age,stdu->sex);


    //共用体 共用体包含的变量，共用一块内存,值同步
    printf("共用体Data大小:%d\n", sizeof(data));//20 ,共用体大小是它包含的占用空间最大的一个类型的大小
    data.i = 1;
    data.i2 = 2;
    data.i3 = 3;
    strcpy(data.str,"st");
    printf("共用体：%d,%d,%d,%s\n",data.i,data.i2,data.i3,data.str);//共用体：29811,29811,29811,st
    //i打印了29811，值损坏，因为data.str赋给的值占用了内存空间,不赋值时，i打印的都是3
    printf("共用体中变量的指针:%x,%x,%x\n",&data.i,&data.i2,&data.str);//共用体中变量的指针:408970,408970,408970
    //使用场景1，扩展属性可以保持最新的值


    //导入引用 java中import是引用，c中include是包含，将include的文件直接粘贴到当前文件，所以要少用



    printf("\nLsn4--------------\n");

    return 0;
}

