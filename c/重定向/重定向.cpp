//������ͬ·���´���һ��in.txt�ı��ĵ�д����������
#include <stdio.h>
#include <stdlib.h>
 
int main()
{
    freopen("in.txt","r",stdin);     //��in.txt �ж�������
    freopen("out.txt","w",stdout);  // ���������д��out.txt��
    int a,b;
    while(scanf("%d%d",&a,&b)!=EOF)     //�����Ǵ�in.txt�������
        printf("%d\n",a+b);             //д��out.txt��
    fclose(stdin);
    fclose(stdout);
    return 0;
}
