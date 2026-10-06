/*
 * ITLA | Algoritmos | Reto 21: Taller, cercania al maximo de rendimiento (version C++)
 * Autor: Junior Nicolas Reyes Ferreras | Matricula: 20260819
 *
 * Regla particular: una posicion es EVENTO si MX - x <= L && x >= U
 * Impacto de un evento: x - U + 1 (las demas posiciones aportan 0).
 * Las rachas se recorren siempre horizontalmente (por fila).
 */
#include <iostream>

using namespace std;

const int MAXN = 30;
const int MAXM = 30;

int main()
{
    int N, M, L, U;
    int mat[MAXN][MAXM];          // matriz original, no se modifica
    int eventos[MAXN];            // cantidad de eventos por fila
    long impacto[MAXN];           // suma de impactos por fila
    int racha[MAXN];              // mayor racha de eventos consecutivos
    int inicio[MAXN];             // inicio (base 1) de esa racha
    int colEv[MAXM];              // eventos por columna

    // ---------- Lectura y validacion de la primera linea ----------
    if (!(cin >> N >> M >> L >> U)) {
        cout << "ERROR\n";
        return 0;
    }
    // N y M se validan antes de leer la matriz
    if (N < 1 || N > MAXN || M < 1 || M > MAXM ||
        L < 0 || U > 1000 || L > U) {
        cout << "ERROR\n";
        return 0;
    }

    // ---------- Lectura y validacion de la matriz ----------
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (!(cin >> mat[i][j]) || mat[i][j] < 0 || mat[i][j] > 1000) {
                cout << "ERROR\n";
                return 0;
            }
        }
    }

    for (int j = 0; j < M; j++)
        colEv[j] = 0;

    // ---------- Analisis fila por fila ----------
    for (int i = 0; i < N; i++) {
        int mx = mat[i][0];
        int rachaAct = 0;         // longitud de la racha en curso
        int inicioAct = 0;        // inicio de la racha en curso

        eventos[i] = 0;
        impacto[i] = 0;
        racha[i] = 0;
        inicio[i] = 0;

        // maximo de la fila
        for (int j = 1; j < M; j++)
            if (mat[i][j] > mx)
                mx = mat[i][j];

        for (int j = 0; j < M; j++) {
            int x = mat[i][j];
            if (mx - x <= L && x >= U) {         // condicion exacta
                eventos[i]++;
                impacto[i] += x - U + 1;         // impacto del evento
                colEv[j]++;
                if (rachaAct == 0)
                    inicioAct = j + 1;           // nueva racha
                rachaAct++;
                // '>' estricto: ante empate se conserva la que empieza antes
                if (rachaAct > racha[i]) {
                    racha[i] = rachaAct;
                    inicio[i] = inicioAct;
                }
            } else {
                rachaAct = 0;                    // un no evento corta la racha
            }
        }
    }

    // ---------- Fila prioritaria ----------
    int prio = 0;                 // indice 0-based de la mejor fila
    bool hayEventos = false;
    for (int i = 0; i < N; i++)
        if (eventos[i] > 0)
            hayEventos = true;

    if (hayEventos) {
        for (int i = 1; i < N; i++) {
            // comparaciones estrictas: el empate total conserva la menor fila
            if (racha[i] > racha[prio] ||
                (racha[i] == racha[prio] && impacto[i] > impacto[prio]) ||
                (racha[i] == racha[prio] && impacto[i] == impacto[prio] &&
                 eventos[i] > eventos[prio]))
                prio = i;
        }
    }

    // ---------- Columna destacada ----------
    int col = 0;                  // indice 0-based de la mejor columna
    for (int j = 1; j < M; j++)
        if (colEv[j] > colEv[col])
            col = j;

    // ---------- Salida ----------
    for (int i = 0; i < N; i++)
        cout << "FILA " << i + 1
             << " EVENTOS " << eventos[i]
             << " IMPACTO " << impacto[i]
             << " RACHA " << racha[i]
             << " INICIO " << inicio[i] << "\n";

    cout << "COLUMNAS";
    for (int j = 0; j < M; j++)
        cout << " " << colEv[j];
    cout << "\n";

    if (hayEventos) {
        cout << "PRIORIDAD " << prio + 1 << "\n";
        cout << "COLUMNA " << col + 1 << "\n";
    } else {
        cout << "PRIORIDAD 0\n";
        cout << "COLUMNA 0\n";
    }
    return 0;
}
