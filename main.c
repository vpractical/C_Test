#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>//�����ַ����ĺ���

//����login.h���൱��java�����ýӿ�
#include "h/login.h"

#define LENGTH1 10//����

/*
 * ����1
 */
int add(int a,int b){
    return a + b;
}
/*
 * ����2
 * �����������Ǻ���ָ��
 */
int calculate(int a, int b, int(*i)(int,int)){
    return i(a,b);
}


//���ڽ���2��������ֵ�ĺ���
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
//���������ָ�����a��b��ָ���Ѿ��ʹ���ǰ�Ĳ�ͬ�ˣ�����ֱ�ӽ���a��b��ָ�벻�У���Ҫ����ָ�뱣���ֵ
    int temp = *a;
    *a = *b;
    *b = temp;
    temp = 0;
}


//lsn3
//��������
typedef long long l;
//�ṹ�� ���г�ԱĬ��public��
struct Student{
    char *name;
    int32_t age;
    char sex;
}st = {"���",5,'K'};

//������
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
     * ������Ϊ�з��ţ��޷��ţ�Ĭ�����з��ţ�ȡֵ��Χ��ͬ
     * int	2 �� 4 �ֽ�	-32,768 �� 32,767 �� -2,147,483,648 �� 2,147,483,647
     * unsigned int	2 �� 4 �ֽ�	0 �� 65,535 �� 0 �� 4,294,967,295
     */
    int a = INT_MIN;
    signed int b = INT_MAX;
    printf("\n�з���int��Χ��%d , %d",a,b);

    const int  LENGTH2 = 10;//����

    /*
     * �洢��
     */
    auto int a1; //Ĭ�ϵģ����Բ�дauto,auto ֻ�����ξֲ�����
    register int a2;//register �洢�����ڶ���洢�ڼĴ����ж����� RAM �еľֲ�����.�Ĵ���ֻ������Ҫ���ٷ��ʵı����������������'register' ��ζ�ű������ܴ洢�ڼĴ����У�ȡ����Ӳ����ʵ�ֵ�����
    static int a3;//�������ںͳ����һ�����������������ļ��ڣ����ξֲ�����ֻ��ʼ��һ��
    extern int a4;//���ļ�a�ж���һ��ȫ�ֺ����������������b��ʹ��extern����ͬ���ı�����ʹ����

    /*
     * ָ��
     * һ��������ֵΪ��һ���������ڴ��ַ��ʮ��λ������
     * &+���������Ǳ������ڴ��ַ
     * *+�������ڴ��ַ��������ڴ��ַ��ֵ
     */
    int d = 20;
    int *e;//����ָ�����,���*��ֻ������ָ�������������ָ�����eǰ��*���������ʱ����ʾ��ȡָ��ָ���ڴ汣���ֵ
    e = &d;//������d���ڴ��ַ��ֵ��ָ�����
    printf("\n d��%d,%X,%d,%X",d,&d,*e,e);// d��20,22FE34,20,22FE34

    /*
     * ������һ�������ڴ棬�ַ�����c����һ��һά����
     * �����ַ�ǵ�һ��Ԫ�صĵ�ַ��Ԫ����int���ͣ�ÿ��Ԫ��4���ֽڴ�С�Ļ���Ԫ�ص�ַ�ǵ�һ���ֽڵĵ�ַ��ÿ��Ԫ�ص�ַ�����4
     */
    int f[] = {1,2,3,4,5,6};
    for (int i = 0;i < sizeof(f) / sizeof(int);i++){
        printf("\n ���� %d,%x,%x",f[i],&f[i],f + i);
    }

    /*
     * ����ָ�뼰�ص�����
     */
    int (*h)(int,int) = &add;
    int h1 = 2,h2 = 3,h3 = 7;
    int h4 = calculate(calculate(h1,h2,h),h3,h);
    printf("\n h: %d\n",h4);
    //ģ���¼
    void (*success)(int64_t,char*) = &loginSuccess;
    void (*failed)(int64_t) = &loginFailed;
    login(200,success,failed);
    login(530,success,failed);
    /*
     * ��̬�����ڴ�
     * ��������ʱ����ջ�����ڴ棬�������ڶ���0
     */
    int *g = calloc(10, sizeof(int));//�ڶ�������10��int���͵��ڴ�
//    memset(g,NULL,10* sizeof(int));//��ʼ������ڴ棬��Ϊ�����õ����ڴ�������
    printf("\n ��̬���룺%x",g);
    free(g);//�ͷ��ڴ�
    g = 0;//g��Ұָ���ÿ�


    printf("\nLsn2--------------\n");
    hello();

    int count = 9;//һ�㲻��ô����int�����£���Ҫ����stdint.h
    int32_t count2 = 9;//����32λ��4���ֽڵ�int����
    int8_t count3 = 9;//1���ֽڣ����͵��ȥ�ᷢ����char����

    int *x = &count;//һ��ָ�룬&��ȡ�������ڴ��ַ,xΪָ�������&��ȡ��count���ڴ��ַZ10000Ϊָ�룬ָ������ڴ��ַ
    int ** y = &x;//����ָ�룬ָ�����y�ĵ�ַ22fdd0,������ָ�����x��ָ�뼴�ڴ��ַ
    int*** z = &y;//����ָ��
    printf("�༶ָ�룺x:%x,y:%x,z:%x,**z:%x,***z:%d\n",x,y,z,**z,***z);//x:22fddc,y:22fdd0,z:22fdc8,**z:22fddc,***z:9

    //����2��������ֵ
    char b2 = 'o';
    char b3 = 'k';

    switch1(b2,b3);
    printf("%c,%c\n",b2,b3);
    switch2(&b2,&b3);
    printf("%c,%c\n",b2,b3);
    //switch1�����������ܻ�������Ϊ�������Լ����ڴ�ռ�,switch1���������ĵ�ַ�ʹ����b2��b3�ĵ�ַ��ͬ


    //�ɱ�����ĺ���


    //Ԥ������  ����Ԥ����������Է���#��ͷ #if 0��ע�͵�����
#if 0
    printf("000\n");
#else
    printf("999\n");
#endif
    printf("һ����ִ�е�endif\n");


#define NAME "HONY" //����һ����,����java�еĳ���,Դ����ÿ������������NAME���ԡ�HONY���滻������Ϊ���滻


#ifdef NAME//�Ƿ����˺�
    printf("�����˺�\n");
#endif

#ifndef NAME//�Ƿ�û�ж����
    printf("û�ж����\n");
#endif
    printf("\nLsn3--------------\n");

    //��������
    l number4 = 456456;

    //�ṹ�� ����java�е�bean
    struct Student student;
    student.name = "����";
    student.age = 3;
    student.sex = 'M';
    strcpy(&student.sex,"R");
    printf("ѧ��1��%s,%d,%c\n",student.name,student.age,student.sex);
    //�ṹ���д �ṹ����Բ������֣�ֻҪβ׺��st
    st.name = "С��С��С��С��";
    printf("ѧ��2��%s,%d,%c\n",st.name,st.age,st.sex);
    printf("�ṹ��ռ���ֽ���:%d\n", sizeof(st));//ռ���ֽ���:16,name8,age4,sex4
    //ʹ��ָ����ʽṹ��ĳ�Ա
    struct Student *stdu = &st;
    stdu->name = "��ë";
    printf("ѧ��3��%s,%d,%c\n",stdu->name,stdu->age,stdu->sex);


    //������ ����������ı���������һ���ڴ�,ֵͬ��
    printf("������Data��С:%d\n", sizeof(data));//20 ,�������С����������ռ�ÿռ�����һ�����͵Ĵ�С
    data.i = 1;
    data.i2 = 2;
    data.i3 = 3;
    strcpy(data.str,"st");
    printf("�����壺%d,%d,%d,%s\n",data.i,data.i2,data.i3,data.str);//�����壺29811,29811,29811,st
    //i��ӡ��29811��ֵ�𻵣���Ϊdata.str������ֵռ�����ڴ�ռ�,����ֵʱ��i��ӡ�Ķ���3
    printf("�������б�����ָ��:%x,%x,%x\n",&data.i,&data.i2,&data.str);//�������б�����ָ��:408970,408970,408970
    //ʹ�ó���1����չ���Կ��Ա������µ�ֵ


    //�������� java��import�����ã�c��include�ǰ�������include���ļ�ֱ��ճ������ǰ�ļ�������Ҫ����



    printf("\nLsn4--------------\n");

    return 0;
}

