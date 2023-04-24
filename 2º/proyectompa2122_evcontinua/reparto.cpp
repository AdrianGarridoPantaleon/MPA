
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <fstream>
#include <chrono>

using namespace std;

int nclientes = 0, recoFinal = 0, numReco = 0;
bool ocultar = false;
static int reco = 1;

void imprimirV(int *v)
{
    cout << "VECTOR: ";
    for (int i = 0; i <= nclientes; i++)
    {
        if (i == nclientes)
            cout << v[i] << endl;
        else
            cout << v[i] << ", ";
    }
}

void imprimirMat(int **mat)
{
    cout << "\n-------------------MATRIZ-------------------\n"
         << endl;
    for (int i = 0; i <= nclientes; i++)
    {
        for (int j = 0; j <= nclientes; j++)
        {
            cout << "\t" << mat[i][j];
        }
        cout << endl
             << endl;
    }
    cout << endl;
}

bool Ciclos(int *v, int k)
{
    for (int i = 0; i < k; i++)
    {
        for (int j = i + 1; j <= k; j++)
        {
            if (v[i] == v[j])
            {
                return true;
            }
        }
    }
    return false;
}

int calcularCoste(int **mat, int *v, int n)
{
    int valor, ip, jp;
    valor = ip = jp = 0;

    if (ocultar == false)
        cout << "Recorrido " << numReco + 1 << endl;

    for (int i = 0; i < n; i++)
    {
        if (v[i] == 0 && ocultar == false)
            cout << "SUPER" << endl;

        ip = v[i];
        jp = v[i + 1];

        valor += mat[ip][jp];
        if (i != n && ocultar == false)
            cout << v[i + 1] << "\t" << mat[ip][jp] << endl;
    }
    valor += mat[jp][0];
    if (ocultar == false)
    {
        cout << "SUPER\t" << mat[jp][0] << endl
             << endl;
        cout << "COSTE: " << valor << endl
             << endl;
    }
    return valor;
}

void viajante(int **mat, const int &k, int &costeOpt, int *v, int *vOpt)
{
    int costeV;
    v[k] = 0;
    while (v[k] != nclientes)
    {
        v[k] = v[k] + 1;
        if (mat[v[k - 1]][v[k]] != 999 && Ciclos(v, k) == false)
        {
            if (k == nclientes)
            {
                if (mat[v[k]][v[0]] != 999)
                {
                    costeV = calcularCoste(mat, v, k);
                    numReco++;
                    if (costeV < costeOpt)
                    {
                        for (int i = 0; i <= nclientes; i++)
                            vOpt[i] = v[i];
                        recoFinal = numReco;
                        costeOpt = costeV;
                    }
                }
            }
            else
                viajante(mat, k + 1, costeOpt, v, vOpt);
        }
    }
}

void viajanteMejorado(int **mat, int &costeOpt, int *v, int *vOpt)
{
    int k = 1, valor = 0;
    v[k] = 0;
    while (v[k] <= nclientes && k > 0)
    {
    OTRORECORRIDO:
        if ((v[k] + 1) <= nclientes && (v[k] + 1) >= 0)
        {
            v[k] = v[k] + 1;

            if (mat[v[k - 1]][v[k]] != 999 && Ciclos(v, k) == false)
            {
                valor = calcularCoste(mat, v, k);
                if (valor > costeOpt)
                    goto OTRORECORRIDO;
                if (k == nclientes)
                {
                    if (mat[v[k]][v[0]] != 999)
                    {
                        numReco++;
                        if (valor < costeOpt)
                        {
                            for (int i = 0; i <= nclientes; i++)
                                vOpt[i] = v[i];
                            recoFinal = numReco;
                            costeOpt = valor;
                        }
                    }
                }
                else
                    k++;
            }
        }
        else
        {
            v[k] = 0;
            k--;
        }
    }
}

int main()
{
    ifstream fDatos;
    bool cambio = false;
    char linea[200], *tok;
    int eleccion, **mat, ip = 0, jp = 0, *v, *vOpt, costeOpt = 999, k = 1, valorMain = 0;
    string nombreArchivo;

    while (1)
    {
        cout << "1.- Obtener lista de clientes.\n";
        cout << "2.- Ocultar listado de recorridos en opcion 3?\n";
        cout << "3.- Listado de recorridos resaltando el mas corto.\n";
        cout << "4.- Recorrido mas corto(algoritmo mejorado).\n ";
        cout << "5.- Salir." << endl;

        cin >> eleccion;

        if (!cin.good())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        if (eleccion == 1)
        {
            cout << "Introduce el nombre del fichero de texto" << endl;
            cin >> nombreArchivo;
            nombreArchivo += ".txt";

            fDatos.open(nombreArchivo);

            if (!fDatos)
            {
                cout << "ERROR: El archivo no existe, escoja otro nombre. \n";
                continue;
            }

            fDatos.getline(linea, 200);
            tok = strtok(linea, " \t\r\n");
            nclientes = atoi(tok);

            mat = new int *[nclientes + 1];
            v = new int[nclientes + 1];
            vOpt = new int[nclientes + 1];

            for (int i = 0; i <= nclientes; i++)
            {
                v[i] = 0;
                vOpt[i] = -1;
                mat[i] = new int[nclientes + 1];
            }
            for (int i = 0; i <= nclientes; i++)
            {
                for (int j = 0; j <= nclientes; j++)
                {
                    mat[i][j] = 999;
                }
            }

            while (fDatos.good())
            {
                fDatos.getline(linea, 200);
                tok = strtok(linea, " \t\r\n");

                for (int j = 0; j < nclientes; j++)
                {
                    if (j == 0)
                    {
                        ip = atoi(tok);
                    }
                    if (j == 1)
                    {
                        jp = atoi(tok);
                    }
                    if (j == 2)
                    {
                        mat[ip][jp] = atoi(tok);
                    }
                    tok = strtok(NULL, " \t\r\n");
                }
            }
            fDatos.close();

            imprimirMat(mat);

            cout << "Archivo leido correctamente..." << endl;
        }
        else if (eleccion == 2)
        {
            if (ocultar == true)
                ocultar = false;
            else
                ocultar = true;
        }
        else if (eleccion == 3)
        {
            k = 1;
            valorMain = 0;
            costeOpt = 999;
            numReco = 0;
            reco = 1;
            for (int i = 0; i <= nclientes; i++)
                v[i] = 0;

            auto start = chrono::steady_clock::now();
            viajante(mat, k, costeOpt, v, vOpt);
            auto end = chrono::steady_clock::now();

            cout << "---------------------------MEJOR RECORRIDO---------------------------" << endl;
            cout << "Recorrido " << recoFinal << endl;
            for (int i = 0; i < nclientes; i++)
            {
                if (vOpt[i] == 0)
                    cout << "SUPER" << endl;
                ip = vOpt[i];
                jp = vOpt[i + 1];

                valorMain += mat[ip][jp];
                cout << vOpt[i + 1] << "\t" << mat[ip][jp] << endl;
            }
            cout << "SUPER\t" << mat[jp][0] << endl
                 << endl;
            valorMain += mat[jp][0];
            cout << "COSTE: " << valorMain << endl
                 << endl;
        }
        else if (eleccion == 4)
        {
            if (ocultar == false)
            {
                ocultar = true;
                cambio = true;
            }
            valorMain = 0;
            k = 1;
            costeOpt = 999;
            numReco = 0;
            recoFinal = 0;
            for (int i = 0; i <= nclientes; i++)
                v[i] = 0;

            auto start = chrono::steady_clock::now();
            viajanteMejorado(mat, costeOpt, v, vOpt);
            auto end = chrono::steady_clock::now();

            cout << "---------------------------MEJOR RECORRIDO---------------------------" << endl;
            cout << "Recorrido " << recoFinal << endl;
            for (int i = 0; i < nclientes; i++)
            {
                if (vOpt[i] == 0)
                    cout << "SUPER" << endl;
                ip = vOpt[i];
                jp = vOpt[i + 1];

                valorMain += mat[ip][jp];
                cout << vOpt[i + 1] << "\t" << mat[ip][jp] << endl;
            }
            cout << "SUPER\t" << mat[jp][0] << endl
                 << endl;
            valorMain += mat[jp][0];
            cout << "COSTE: " << valorMain << endl
                 << endl;

            cout << "Numero de recorridos hasta llegar a la solucion: " << numReco << endl;

            cout << "\nTiempo que tarda en calcular el mejor recorrido: " << chrono::duration_cast<chrono::seconds>(end - start).count() << " s || " << chrono::duration_cast<chrono::milliseconds>(end - start).count()
                 << " ms || " << chrono::duration_cast<chrono::microseconds>(end - start).count() << " \xE6s || " << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << " ns\n"
                 << endl;
            if (cambio == true)
            {
                ocultar = false;
                cambio = false;
            }
        }
        else if (eleccion == 5)
        {
            exit(1);
        }
        else
        {
            cout << "\nERROR: Se debe elegir entre alguna de estas opciones." << endl;
            continue;
        }
    }
}