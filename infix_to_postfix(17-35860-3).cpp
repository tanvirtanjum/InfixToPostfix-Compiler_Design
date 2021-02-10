///SHOURAV, TANVIR TANJUM
///17-35860-3
///COMPILER DESIGN [A]


#include<iostream>
using namespace std;

char input[]="";
char *la=input;

void expr();
void exprP();
void term();
void termP();
void factor();
void match(char optr);

void expr()
{
    term();
    exprP();
}

void term()
{
    factor();
    termP();
}

void factor()
{
    if(isdigit(*la))
    {
        cout<<*la;
        la++;
    }

    else if(*la=='(')
    {
        match('(');
        expr();
        match(')');
    }

    else
    {
        cout<<"Invalid Expression."<<endl;
    }
}

void match(char optr)
{
    if(*la==optr)
    {
        la++;
    }
}

void exprP()
{
    if(*la=='+')
    {
        match('+');
        term();
        cout<<"+";
        exprP();
    }

    else if(*la=='-')
    {
        match('-');
        term();
        cout<<"-";
        exprP();
    }

    else{}
}

void termP()
{
    if(*la=='*')
    {
        match('*');
        factor();
        cout<<"*";
        termP();
    }

    else if(*la=='/')
    {
        match('/');
        factor();
        cout<<"/";
        termP();
    }

    else{}
}

void start()
{
    cout<<"Type an infix notation containing single digits(0-9) and operators '+','-','*' and '/' :";
    cin>>input;
    cout<<endl;
    cout<<"..................................................................................."<<endl;
    cout<<"Infix Form: "<<input<<endl;
    cout<<"Postfix Form: ";
    expr();
    cout<<endl<<"..................................................................................."<<endl;
    cout<<endl<<endl;
}

int main()
{
    char cont[1];
    cout<<"Infix to Postfix Converter"<<endl;

    while(true)
    {
        cout<<"Press 'C' to continue or press any character to exit."<<endl;
        cin>>cont;

        if(cont[0] == 'C' || cont[0] == 'c')
        {
            start();
        }

        else
        {
            break;
        }
    }
    return 0;
}


///SHOURAV, TANVIR TANJUM
///17-35860-3
///COMPILER DESIGN [A]


