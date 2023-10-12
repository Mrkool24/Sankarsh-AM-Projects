//Project Name: C++ Stack Implementation Console Application
//File type: .c
//Executed by: Sankarsh A M

#include<iostream>
#include<cstdlib>
using namespace std;
#define max_size 5
template<class type>
class stack
{
	static int TOP;
	type stk[5];
	public:
	stack(){
			TOP=-1;
		}
	void push()
	{
		if(TOP>=5)
		{
			cout<<"stack overflow"<<endl;
			return;
		}
		TOP++;
		cout<<"enter element in stack"<<endl;
		cin>>stk[TOP];
	}
	
	void pop()
	{
		if(TOP<=-1)
		{
			cout<<"stack underflow"<<endl;
			return;
		}
		cout<<"delete element from stack"<<endl;
		TOP--;
	}

	void display()
	{
		if(TOP<=-1)
		{
			cout<<"stack is empty"<<endl;
			return;
		}
		int i=0;
		for(i=0;i<=TOP;i++)
			cout<<stk[i]<<" ";
			cout<<endl;
	}

};
template<class type>
int stack<type>::TOP=-1;
int main()
{
	stack<int>oi;
	stack<char>oc;
	stack<double>od;
	stack<float>of;
	stack<string>os;

	int op,op1;
	cout<<"enter the choice"<<endl;
	cout<<"1)int 2)char 3)flaot 4)double 5)string 6)exit"<<endl;
	cin>>op;
	switch(op)
	{
		case 1:{cout<<"int stack application ready to use"<<endl;
		       while(1){
			       cout<<"1)push 2)pop 3)display 4)main_menu"<<endl;
			       cin>>op1;
			       if(op1==1)
				       oi.push();
			       else if(op1==2)
				       oi.pop();
			       else if(op1==3)
				       oi.display();
				}
			       break;}
			       case 2:{cout<<"char stack application ready to use"<<endl;
				      while(1)
				      {
					      cout<<"1)push 2)pop 3)display 4)main_menu"<<endl;
					      cin>>op1;
					      if(op1==1)
						      oc.push();
					      else if(op1==2)
						      oc.pop();
					      else if(op1==3)
						      oc.display();
				      }
				      break;}
			       case 3:{cout<<"float stack application ready to use"<<endl;
				      while(1)
				      {
					      cout<<"1)push 2)pop 3)display 4)main_menu"<<endl;
					      cin>>op1;
					      if(op1==1)
						      of.push();
					      else if(op1==2)
						      of.pop();
					      else if(op1==3)
						      of.display();
				      }
				      break;}
			       case 4:{cout<<"double stack application ready to use"<<endl;
				      while(1)
				      {
					      cout<<"1)push 2)pop 3)display 4)main_menu"<<endl;
					      cin>>op1;
					      if(op1==1)
						      od.push();
					      else if(op1==2)
						      od.pop();
					      else if(op1==3)
						      od.display();
				      }
				      break;}
			       case 5:{cout<<"string stack application ready to use"<<endl;
				      while(1)
				      {
					      cout<<"1)push 2)pop 3)display 4)main_menu"<<endl;
					      cin>>op1;
					      if(op1==1)
						      os.push();
					      else if(op1==2)
						      os.pop();
					      else if(op1==3)
						      os.display();
				      }
				      break;}
				case 6:exit(0);
		       }
}
