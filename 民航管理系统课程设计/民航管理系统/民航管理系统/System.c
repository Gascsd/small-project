//
//  System.c
//  民航管理系统
//
//  Created by zht on 2023/5/9.
//

#include "System.h"

void menu()
{
    printf("************民航管理系统*************\n");
    printf("***1. 订票**********2. 退票*********\n");
    printf("***4. 查询航班信息***3. 浏览航班信息***\n");
    printf("***0. 退出系统**********************\n");
    printf("**********************************\n");
}
void BookTicket()
{
    printf("订票\n");
    ViewFlightInfo();
    printf("请选择要定的航班序号：");
    int no = 0;
    scanf("%d", &no);
    
}
void RefundTicket()
{
    printf("退票\n");
}
void ViewFlightInfo()
{
    printf("显示航班信息\n");
    
}
void CheckFlightInfo()
{
    printf("查询航班信息\n");
}
void read_file(Flight* pfight)
{
    //读航班信息文件
    FILE* fp = fopen("FlightInfoFlie.txt", "r");
    if(!fp)//读取失败
    {
        return;
    }
    while(1)
    {
        FlightInfo* newnode = (FlightInfo*)malloc(sizeof(FlightInfo));
        if(!newnode)
        {
            printf("读取文件失败，退出程序...\n");
            exit(-1);
        }
        else
        {
            if (fread(newnode, sizeof(FlightInfo), 1, fp) < 1)
                break;//读取结束
            //头插航班号
            newnode->next = pfight->head.next;
            pfight->head.next = newnode;
            pfight->size++;
        }
    }
    fclose(fp);
    //读乘客信息
    fp = fopen("Book.txt", "r");
    if(!fp)//读取失败
    {
        return;
    }
    while(1)
    {
        Book* newnode = (Book*)malloc(sizeof(Book));
        if(!newnode)
        {
            printf("读取文件失败，退出程序...\n");
            exit(-1);
        }
        else
        {
            if (fread(newnode, sizeof(Book), 1, fp) < 1)
                break;//读取结束
            //头插乘客
            //遍历航班链表，找到newnode的航班号，然后头插
            FlightInfo* cur = pfight->head.next;
            while(cur)
            {
                if(strcmp(newnode->flightNum, cur->flightNo) == 0)
                {
                    //找到对应的航班号了，头插newnode
                    newnode->next = cur->order;
                    cur->order = newnode;
                }
                cur = cur->next;
            }
        }
    }
    fclose(fp);
}
void System()
{
    printf("欢迎使用民航管理系统\n");
    //首先读取文件信息
    Flight flight;
    read_file(&flight);
    //系统开始运行
    int input = 0;
    do
    {
        menu();
        printf("请输入：>");
        scanf("%d", &input);
        switch(input)
        {
            case EXIT:
                printf("退出系统...\n");
                break;
            case BOOK:
                //订票函数
                BookTicket();
                break;
            case REFUND:
                //退票函数
                RefundTicket();
                break;
            case VIEW:
                ViewFlightInfo();
                break;
            case CHECK:
                CheckFlightInfo();
                break;
            default:
                printf("输入错误，请重新输入\n");
        }
    } while (input);
}
