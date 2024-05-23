#include <bits/stdc++.h>
using namespace std;

struct nodo
{
    char nomb[20];
    nodo *sig;
    nodo *ant;
};

void cread_i(nodo *&, nodo *&);
void cread_f(nodo *&, nodo *&);
void insertard_i(nodo *&, nodo *&);
void insertard_f(nodo *&, nodo *&);
void insertard_ad(nodo *&, char *);
void insertard_dd(nodo *&, char *);
void eliminard_p(nodo *&, nodo *&);
void eliminard_u(nodo *&, nodo *&);
void eliminard_x(nodo *&, nodo *&);
void eliminard_ad(nodo *&, char *);
void eliminard_dd(nodo *&, char *);
void recorre(nodo *);

int main()
{
    char codigo[20];
    nodo *p = NULL;
    nodo *f = NULL;
    int op;
    do
    {
        system("cls");
        cout << "\nLISTAS ENLAZADAS";
        cout << "\n===============";
        cout << "\n1. CREAR POR EL INICIO";
        cout << "\n2. CREAR POR EL FINAL";
        cout << "\n3. INSERTAR AL INICIO";
        cout << "\n4. INSERTAR AL FINAL";
        cout << "\n5. INSERTAR ANTES DE ";
        cout << "\n6. INSERTAR DESPUES DE";
        cout << "\n7. ELIMINAR EL PRIMER NODO";
        cout << "\n8. ELIMINAR EL ULTIMO NODO";
        cout << "\n9. ELIMINAR UN NODO ESPECIFICO";
        cout << "\n10. ELIMINAR EL NODO ANTERIOR A";
        cout << "\n11. ELIMINAR EL NODO POSTERIO A";
        cout << "\n12. M O S T R A R";
        cout << "\n13. S A L I R";
        cout << "\n\n\t\t\t OPCION: ";
        cin >>op;
        switch (op)
        {
        case 1:
            system("cls");
                cread_i(p, f);
            break;
        case 2:
            system("cls");
                cread_f(p, f);
            break;
        case 3:
            system("cls");
            insertard_i(p, f);
            break;
        case 4:
            system("cls");
            insertard_f(p, f);
            break;
        case 5:
            system("cls");
            cout << "Ingrese el codigo: ";
            cin >> codigo;
            insertard_ad(p, codigo);
            break;
        case 6:
            system("cls");
            cout << "Ingrese el codigo: ";
            cin >> codigo;
            insertard_dd(f, codigo);
            break;
        case 7:
            
            system("cls");
            eliminard_p(p, f);
            break;
        case 8:
            system("cls");
            eliminard_u(p, f);
            break;
        case 9:
            system("cls");
            eliminard_x(p, f);
            break;
        case 10:
            system("cls");
            cout << "Ingrese el codigo: ";
            cin >> codigo;
            eliminard_ad(p, codigo);
        case 11:
            system("cls");
            cout << "Ingrese el codigo: ";
            cin >> codigo;
            eliminard_dd(p, codigo);
            break;
        case 12:
            system("cls");
            recorre(p);
            break;
        case 13:
            cout << "SALIENDO DEL PROGRAMA" << endl;
            break;
        }
    } while ((op > 0) && (op < 13));
}





void cread_i(nodo *&p, nodo *&f)
{
    nodo *q;
    p = NULL;
    f = NULL;
    char op;
    do
    {
        system("cls");
        cout << "CREANDO LISTA POR EL INICIO" << endl;
        q = new (nodo);
        cout << "INGRESE EL NOMBRE: ";
        cin >> q->nomb;
        q->ant = NULL;
        q->sig = p;
        if (p == NULL)
        {
            f = q;
        }
        else
        {
            p->ant = q;
        }
        p = q;
        cout << "DESEA AGREGAR MAS NODOS (S/N):";
        cin >> op;
    } while (op == 'S' || op == 's');
}

void cread_f(nodo *&p, nodo *&f)
{
    p = NULL;
    f = NULL;
    char op;
    nodo *q, *r;
    do
    {
        system("cls");
        cout << "CREANDO LISTA POR EL FINAL" << endl;
        q = new (nodo);
        cin >> q->nomb;
        q->sig = NULL;
        q->ant = f;
        if (p == NULL)
        {
            p = q;
        }
        else
        {
            f->sig = q;
        }
        f = q;
        cout << "Desea agregar mas nodos (S/N): ";
        cin >> op;
    } while (op == 'S' || op == 's');
}

void recorre(nodo *p)
{
    nodo *q = p;
    system("cls");
    cout << "LISTAS DE DATOS:" << endl;
    cout << "----------------" << endl;
    while (q != NULL)
    {
        cout << q->nomb << endl;
        q = q->sig;
    }
}

void insertard_i(nodo *&p, nodo *&f)
{
    nodo *q;
    system("cls");
    cout << "INSERTANDO POR EL INICIO" << endl;
    q = new (nodo);
    cout << "INGRESE EL NOMBRE: ";
    cin >> q->nomb;
    q->sig = p;
    q->ant = NULL;
    if (p == NULL)
    {
        f = q;
    }
    else
    {
        p->ant = q;
    }
    p = q;
}

void insertard_f(nodo *&p, nodo *&f)
{
    nodo *q;
    system("cls");
    cout << "INSERTANDO POR EL FINAL" << endl;
    q = new (nodo);
    cin >> q->nomb;
    q->ant = f;
    q->sig = NULL;
    if (p == NULL)
    {
        p = q;
    }
    else
    {
        f->sig = q;
    }
    f = q;
}

void insertard_ad(nodo *&p, char *codigo)
{
    if (p != NULL)
    {
        nodo *q;
        nodo *r;

        int cen;

        q = p;
        cen = 0;
        while ((strcmp(q->nomb, codigo) != 0) && (cen == 0))
        {
            if (q->sig != NULL)
            {
                q = q->sig;
            }
            else
            {
                cen = 1;
            }
        }
        if (cen == 0)
        {
            nodo *x;
            cin >> x->nomb;
            x->sig = q;
            r = q->ant;
            x->ant = r;
            q->ant = x;
            if (p = q)
            {
                p = x;
            }
            else
            {
                r->sig = x;
            }
        }
        else
        {
            cout << "No se encontro el nodo" << endl;
        }
    }
    {
        cout << "Lista vacia" << endl;
    }
}

void insertard_dd(nodo *&f, char *codigo)
{
    if (f != NULL)
    {
        nodo *q;
        nodo *r;

        int cen;

        q = f;
        cen = 0;
        while ((strcmp(q->nomb, codigo) != 0) && (cen == 0))
        {
            if (f->ant != NULL)
            {
                q = q->ant;
            }
            else
            {
                cen = 1;
            }
        }
        if (cen == 0)
        {
            nodo *x;
            x=new(nodo);
            cin >> x->nomb;
            x->ant = q;
            r = q->sig;
            x->sig = r;
            q->sig = x;
            if (f = q)
            {
                f = x;
            }
            else
            {
                r->ant = x;
            }
        }
        else
        {
            cout << "No se encontro el nodo" << endl;
        }
    }
    {
        cout << "Lista vacia" << endl;
    }
}

void eliminard_p(nodo *&p, nodo *&f)
{
    
}

void eliminard_u(nodo *&p, nodo *&f)
{
    
}

void eliminard_x(nodo *&p, nodo *&f)
{
    
}

void eliminard_ad(nodo *&p, char *codigo)
{
    
}

void eliminard_dd(nodo *&p, char *codigo)
{
    
}

