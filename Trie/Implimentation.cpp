#include<bits/stdc++.h>
using namespace std;


class node{
public:
	char data;
	bool isTerminal;

	map<char,node*> m;

	node(char d){
		data=d;
		isTerminal=false;
	}
};

class Trie{
	node *root;

public:
	Trie(){
		root= new node('\0');
	}

	void addWord(char *word){

		node *temp=root;
		for(int i=0;word[i]!='\0';i++){
			char ch=word[i];

			if(temp->m.count(ch)){
				temp=temp->m[ch];
			}
			else{
				node *n=new node(ch);
				temp->m[ch]= n;
				temp=n;
			}
		}
		temp->isTerminal=true;

	}

	bool search(char *word){
		node *temp=root;
		for(int i=0;word[i]!='\0';i++){
			char ch= word[i];
			if(temp-> m.count(ch)){
				temp=temp->m[ch];
			}
			else{
				return false;
			}
		}
		return temp->isTerminal;
	}


};

int main(){
	return 0;
}