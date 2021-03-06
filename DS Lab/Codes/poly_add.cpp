#include <iostream>
using namespace std;
struct term{
	float coeff;
	int exp;
	term(){}
	term(float c,int e){
		coeff=c;
		exp=e;
	}
};
struct poly{
	term x[20];
	int size;
};
void read_poly(poly& a){
	cin>>a.size;
	for(int i=0;i<a.size;i++)
		cin>>a.x[i].coeff>>a.x[i].exp;
}
void print_poly(poly a){
	for(int i=0;i<a.size;i++)
		cout<<"+("<<a.x[i].coeff<<")"<<"x^"<<a.x[i].exp;
	cout<<endl;
}
poly poly_add(poly a,poly b){
	int i=0,j=0;
	poly c;
	c.size=0;
	while(i<a.size && j<b.size){
		if(a.x[i].exp == b.x[j].exp){
			float cf=a.x[i].coeff+b.x[j].coeff;
			if(cf!=0)
				c.x[c.size++]=term(cf,a.x[i].exp);
			i++;
			j++;
		}
		else if(a.x[i].exp > b.x[j].exp)
			c.x[c.size++]=a.x[i++];
		else
			c.x[c.size++]=b.x[j++];
	}
	while(i<a.size)
		c.x[c.size++]=a.x[i++];
	while(j<b.size)
		c.x[c.size++]=b.x[j++];
	return c;
}
poly a,b,c;
int main(){
	read_poly(a);
	print_poly(a);
	read_poly(b);
	print_poly(b);
	c=poly_add(a,b);
	print_poly(c);
	return 0;
}