//首先在同路径下创建一个in.txt文本文档写入若干数字
#include <stdio.h>
#include <stdlib.h>
 
int main()
{
    freopen("in.txt","r",stdin);     //从in.txt 中读入数据
    freopen("out.txt","w",stdout);  // 将最后数据写入out.txt中
    int a,b;
    while(scanf("%d%d",&a,&b)!=EOF)     //数据是从in.txt中输入的
        printf("%d\n",a+b);             //写入out.txt中
    fclose(stdin);
    fclose(stdout);
    return 0;
}
