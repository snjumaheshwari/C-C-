#include<bits/stdc++.h>
using namespace std;

struct point{
	int x,y,id;

	point(int id,int x,int y){
		this->x=x;
		this->id=id;
		this->y=y;
	}

	int dist(){
		return x*x + y*y;
	}

	void print(){
		cout<<id<<" ("<<x<<" , "<<y<<" )"<<endl;
	}

};

class Comp{
public:
	bool operator()(point a,point b){
		return a.dist() > b.dist();
	}

	/*
	void operator()(){
		printf("Hello ! Functor is here");
	}
	*/

};
int main(){

	/*
	Comp c;
	c();
	*/
	int x,y;
	int n; cin>>n;


	priority_queue<point, vector<point>,Comp> pq;
	for(int i=1;i<=n;i++){
		cin>>x>>y;
		point p(i,x,y);
		pq.push(p);

	}

	while(!pq.empty()){
		point p= pq.top();
		pq.pop();
		p.print();
	}


	return 0;
}