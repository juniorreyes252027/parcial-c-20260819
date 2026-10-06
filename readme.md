# Parcial de algoritmos en C++

- Estudiante: Junior Nicolás Reyes Ferreras
- Matrícula: 20260819
- Reto asignado: Reto 21, Taller: cercanía al máximo de rendimiento

## Descripción
El programa recibe `N M L U` y una matriz de `N x M` enteros (piezas terminadas por turno).
Para cada fila busca el máximo `MX` y marca como evento cada valor `x` que cumple
`MX - x <= L && x >= U`. El impacto de un evento es `x - U + 1`.
Imprime, por fila, la cantidad de eventos, el impacto total, la mayor racha de eventos
consecutivos y dónde empieza. También imprime los eventos por columna, la fila prioritaria
y la columna destacada. Si algún dato no cumple las restricciones, imprime solamente `ERROR`.

## Compilación y ejecución
Compilador: g++ (MSYS2 UCRT64) en Windows.

```
g++ -std=c++17 -Wall -Wextra 20260819.cpp -o output/20260819.exe
./output/20260819.exe < pruebas/caso_01.in
```

En PowerShell, en lugar de `<` se usa:

```
Get-Content .\pruebas\caso_01.in | .\output\20260819.exe
```

## Diseño
El análisis, el pseudocódigo y la prueba de escritorio están en `analisis/informe.md`.

## Pruebas
Los casos de entrada y salida esperada del curso están en `pruebas/`.
Las dos pruebas propias, con su justificación, están en `analisis/informe.md` (sección 4)
y sus entradas están en `evidencias/`.

## Estado actual
Implementado: lectura y validación, eventos e impacto, rachas, conteos por fila y columna,
fila prioritaria con todos los desempates y columna destacada.
Probado con el caso 01 del enunciado, casos de error, el caso sin eventos y dos pruebas propias.
Falta comprobar los 17 casos de la carpeta `pruebas/` del curso en mi equipo.
