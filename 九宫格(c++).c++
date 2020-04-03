//我们把第一个图的局面记为：12345678. 
//把第二个图的局面记为：123.46758 
//显然是按从上到下，从左到右的顺序记录数字，空格记为句点。 
//本题目的任务是已知九宫的初态和终态，求最少经过多少步的移动可以到达。如果无论多少步都无法到达，则输出-1。
//输入
//输入第一行包含九宫的初态，第二行包含九宫的终态。 
//输出
//输出最少的步数，如果不存在方案，则输出-1。
//样例输入
//12345678. 
//123.46758 
//样例输出
//3

#include<iostream>
#include<algorithm>
#include<queue>
#include<map>
#include<string>
using namespace std;
map<string,int>m1,m2;
struct node {
	string s;
	int we,step;
};
queue<node>q,p;
int dir[4]= {1,-1,3,-3};
int main() {
	node t1,t2;
	cin>>t1.s>>t2.s;
	for(int i=0; i<9; i++) {
		if(t1.s[i]=='.')
			t1.we=i;
		if(t2.s[i]=='.')
			t2.we=i;
	}
	if(t1.s==t2.s) {
		cout<<t1.step;
		return 0;
	}
	node l1,l2,h1,h2;
	t1.step=0;
	t2.step=0;
	l1.s=t1.s;
	l1.we=t1.we;
	l1.step=t1.step;
	l2.step=t2.step;
	l2.s=t2.s;
	l2.we=t2.we;
	m1[l1.s]=1;
	m2[l2.s]=1;
	q.push(l1);
	p.push(l2);
	while(!q.empty()) {
		h1=q.front();
		h2=p.front();
		q.pop();
		p.pop();
		for(int i=0; i<4; i++) {
			if((i==0&&h1.we%3==2)||(i==1&&h1.we%3==0)||(i==2&&h1.we>5)||(i==3&&h1.we<3))
				continue;
			l1.we=h1.we+dir[i];
			l1.step=h1.step+1;
			l1.s=h1.s;
			if(l1.we>=0&&l1.we<=8) {
				swap(l1.s[l1.we],l1.s[h1.we]);
				if(m2[l1.s]) {
					cout<<l1.step+m2[l1.s]-1;
					return 0;
				}
				if(!m1[l1.s]) {
					m1[l1.s]=l1.step+1;
					q.push(l1);
				}
			}
		}
		for(int i=0; i<4; i++) {
			if((i==0&&h2.we%3==2)||(i==1&&h2.we%3==0)||(i==2&&h2.we>5)||(i==3&&h2.we<3))
				continue;
			l2.we=h2.we+dir[i];
			l2.step=h2.step+1;
			l2.s=h2.s;
			if(l2.we>=0&&l2.we<=8) {
				swap(l2.s[l2.we],l2.s[h2.we]);
				if(m1[l2.s]) {
					cout<<l2.step+m1[l2.s]-1;
					return 0;
				}
				if(!m2[l2.s]) {
					m2[l2.s]=l2.step+1;
					p.push(l2);
				}
			}
		}
	}
	cout<<-1;
	return 0;
}
