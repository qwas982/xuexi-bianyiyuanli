#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
*虚拟机如何工作?比你想象的简单,遵循一个简单模式,
*指令周期,拾取-解码-执行.
*首先获取指令列表或代码中的下一条指令,解码并执行解码后的指令,
*模拟演练于此  github.com/felixangell/mac
*/
typedef enum{
    push,
    add,
    pop,
    hlt
}zlj; //指令集

const int cx [] = {  //程序
    push, 5,
    push, 6,
    add,
    pop,
    hlt
};


bool run = true;
int ip = 0;
int sp = -1;
int zhan[256];

int shiqu(){  //拾取
    return cx[ip];
}

void qz(int zl){  //求值函数  参数 指令
    switch (zl){
        case hlt:{
            run = false;
            printf("fine\n");
            break;
        }
        case push:{
            sp += 1;
            zhan[sp] = cx[ip += 1];
            break;
        }
        case pop:{
            int pop_val = zhan[sp -= 1];
            printf("%d\n",pop_val);
            break;
        }
        case add:{
            int a = zhan[sp -= 1];
            int b = zhan[sp -= 1];
            int jieguo = b + a;
            sp += 1;
            zhan[sp] = jieguo;
            break;
        }
    }
}
int main()
{
    //int zl = cx[ip];
    //return 0;
    while (run){
        qz(shiqu());
        ip += 1;


//        int x = shiqu();
//        if (x == hlt)
//            run = false;
//            ip += 1;

//        int x = shiqu();
//        ip += 1
//        int y = shiqu();
    }
}
