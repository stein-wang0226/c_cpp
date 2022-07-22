#include <bits/stdc++.h>
using namespace std;


int n;
struct student{
    double score;
	string name; 
    int age;
}; 
int cmp(const student &s1,const student &s2){//自己定义的排序规则 
    if(s1.score==s2.score){
		if(s1.age==s2.age)
		return s1.name<s2.name;//升序 
        return s1.age<s2.age;}
    return s1.score>s2.score;
} 
int main() {
	cin>>n;
		student s[n];
	for(int i=0;i<n;i++){
		cin>>s[i].name;
		scanf(" %d %lf",&s[i].age,&s[i].score);
	}
	sort(s,s+n,cmp);
	printf("输出：\n"); 
	for(int i=0;i<n;i++){
		cout<<s[i].name;
		printf(" %d %.2lf\n",s[i].age,s[i].score);
	}
	return 0;
}

//最佳 
//struct student2{
//    string name;
//    int age;
//    bool operator < (const student2 & s2) const {//符号重载 
//        if(name==s2.name)
//            return age<s2.age;//升序 
//        return name<s2.name;        
//    }
//}; 
























































































































































































































