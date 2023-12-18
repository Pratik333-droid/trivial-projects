#include <iostream>
using namespace std;

//adding two equations in desecding order of power
class Node 
{
    int coeff, power;
    Node *next;
    friend class Equation;
};

class Equation 
{
    Node *head, *last;
    public:
    Equation()
    {
        head = NULL;
    }
    void addTerm(int, int); //coeff, power
    void performAddition(Equation, Equation);
    void displayEquation ();


};

void Equation :: addTerm (int coef, int pow)
{
    
    if (head == NULL)
    {
        Node *node = new Node;
        node->coeff = coef;
        node->power = pow;
        node->next = NULL;
        head = node;
        last = node;
    }
    
    else
    {
        Node *node = new Node;
        node->coeff = coef;
        node->power = pow;
        last->next = node; 
        last = node;
        last->next = NULL;
    }


}

void Equation :: performAddition (Equation e1, Equation e2)
{
    Node *iter1, *iter2;
    iter1 = e1.head;
    iter2 = e2.head;
    // Equation sum;
    while ((iter1!= NULL) && (iter2!= NULL))
    {
        if ((iter1!= NULL) && (iter2!= NULL))
        {
            if ((iter1->power) > (iter2->power))
            {
                addTerm(iter1->coeff, iter1->power);
                iter1 = iter1->next;
            }
            else if ((iter2->power)> (iter1->power))
            {
                addTerm(iter2->coeff, iter2->power);
                iter2 = iter2->next;

            }
            else
            {
                addTerm(iter1->coeff + iter2->coeff, iter1->power);
                iter1 = iter1->next;
                iter2 = iter2->next;
            }
        }

        else if (iter1 == NULL)
        {
            addTerm(iter2->coeff, iter2->power);
            iter2 = iter2->next;
        }

        else if (iter2 == NULL)
        {
            addTerm(iter1->coeff, iter1->power);
            iter1 = iter1->next;
        }
        else
        {
            cout <<"If this block is executed, something is wrong."<<endl;
        }
    }

}

void Equation :: displayEquation ()
{
    Node *iter = head;
    while (iter!= NULL)
    {
        cout <<iter->coeff<<"x^"<<iter->power<<" ";
        iter = iter->next;
        if (iter!= NULL && iter->coeff > 0)
        cout <<"+ ";
        // if (iter == NULL)
        // cout <<"iter = nULL"<<endl;
    }
}
int main ()
{
    Equation eq1, eq2, sum;
    eq1.addTerm(1,3);
    eq1.addTerm(-4, 2);
    eq1.addTerm(3, 1);
    eq1.addTerm (-7,0);

    cout <<"(";
    eq1.displayEquation ();
    cout <<") + (";

    eq2.addTerm (-12, 9);
    eq2.addTerm (-1, 7);
    eq2.addTerm (10, 5);
    eq2.addTerm (2, 3);
    eq2.addTerm (22, 2);
    eq2.addTerm (-4, 0);
    // eq1.displayEquation();


    eq2.displayEquation ();

    cout <<") = (";

    sum.performAddition(eq1, eq2);

    sum.displayEquation();
    cout <<")";
    

    return 0;
}