#include <iostream>
#include <sstream>
using namespace std;

struct Node {
    int coeff;
    int exp;
    Node* next;
};

class Polynomial {
private:
    Node* head;
public:
    Polynomial() {
        head = NULL;
    }
//insert
    void insertTerm(int coeff, int exp) {
        Node* newNode = new Node;
        newNode->coeff = coeff;
        newNode->exp = exp;
        newNode->next = head;
        head = newNode;
    }
//display
    void display() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->coeff << "x^" << temp->exp << " ";
            temp = temp->next;
            if (temp != NULL) {
                cout << "+ ";
            }
        }
        cout << endl;
    }
//sum
    Polynomial sum(Polynomial p) {
        Polynomial result;
        Node* p1 = head;
        Node* p2 = p.head;

        while (p1 != NULL && p2 != NULL) {
            if (p1->exp > p2->exp) {
                result.insertTerm(p1->coeff, p1->exp);
                p1 = p1->next;
            } else if (p1->exp < p2->exp) {
                result.insertTerm(p2->coeff, p2->exp);
                p2 = p2->next;
            } else {
                result.insertTerm(p1->coeff + p2->coeff, p1->exp);
                p1 = p1->next;
                p2 = p2->next;
            }
        }

        while (p1 != NULL) {
            result.insertTerm(p1->coeff, p1->exp);
            p1 = p1->next;
        }

        while (p2 != NULL) {
            result.insertTerm(p2->coeff, p2->exp);
            p2 = p2->next;
        }

        return result;
    }
//sub
    Polynomial subtract(Polynomial p) {
        Polynomial result;
        Node* p1 = head;
        Node* p2 = p.head;

        while (p1 != NULL && p2 != NULL) {
            if (p1->exp > p2->exp) {
                result.insertTerm(p1->coeff, p1->exp);
                p1 = p1->next;
            } else if (p1->exp < p2->exp) {
                result.insertTerm(-p2->coeff, p2->exp);
                p2 = p2->next;
            } else {
                result.insertTerm(p1->coeff - p2->coeff, p1->exp);
                p1 = p1->next;
                p2 = p2->next;
            }
        }

        while (p1 != NULL) {
            result.insertTerm(p1->coeff, p1->exp);
            p1 = p1->next;
        }

        while (p2 != NULL) {
            result.insertTerm(-p2->coeff, p2->exp);
            p2 = p2->next;
        }

        return result;
    }
//multiply
    Polynomial multiply(Polynomial p) {
        Polynomial result;
        Node* p1 = head;

        while (p1 != NULL) {
            Node* p2 = p.head;
            while (p2 != NULL) {
                int newCoeff = p1->coeff * p2->coeff;
                int newExp = p1->exp + p2->exp;
                result.insertTerm(newCoeff, newExp);
                p2 = p2->next;
            }
            p1 = p1->next;
        }

        return result;
    }



    Polynomial divideByScalar(int scalar) {
        Polynomial result;
        Node* temp = head;

        while (temp != NULL) {
            result.insertTerm(temp->coeff / scalar, temp->exp);
            temp = temp->next;
        }

        return result;
    }

    string toString() {
        stringstream ss;
        Node* temp = head;

        while (temp != NULL) {
            ss << temp->coeff << "x^" << temp->exp << " ";
            temp = temp->next;
            if (temp != NULL) {
                ss << "+ ";
            }
        }

        return ss.str();
    }

};

int main() {
    Polynomial poly1, poly2, result;
    poly1.insertTerm(3, 3);
    poly1.insertTerm(4, 2);
    poly1.insertTerm(5, 0);

    poly2.insertTerm(5, 4);
    poly2.insertTerm(3, 3);
    poly2.insertTerm(2, 1);

    cout << "Polynomial 1=> " << poly1.toString() << endl;

    cout << "Polynomial 2=> " << poly2.toString() << endl;

    result = poly1.sum(poly2);
    cout << "Sum=> " << result.toString() << endl;

    result = poly1.subtract(poly2);
    cout << "Subtract=> " << result.toString() << endl;

    result = poly1.multiply(poly2);
    cout << "Multiply=> " << result.toString() << endl;


    Polynomial divisionResult = poly1.divideByScalar(5);
    cout << "Polynomial 1 divided by 5=> " << divisionResult.toString() << endl;


    return 0;
}