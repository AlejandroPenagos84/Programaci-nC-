#include <iostream>
#include <set>
#include <queue>
#include <climits>
using namespace std;
 
// A continuación, las arrays detallan los ocho movimientos posibles
// por un caballero
int row[] = { 2, 2, -2, -2, 1, 1, -1, -1 };
int col[] = { -1, 1, 1, -1, 2, -2, 2, -2 };
 
// Comprueba si (x, y) son coordenadas de tablero de ajedrez válidas.
// Tenga en cuenta que un caballo no puede salir del tablero
bool isValid(int x, int y, int N) {
    return (x >= 0 && x < N) && (y >= 0 && y < N);
}
 
// Un nodo de queue usado en BFS
struct Node
{
    // (x, y) representa las coordenadas del tablero de ajedrez
    // `dist` representa su distancia mínima desde la fuente
    int x, y, dist;
 
    // constructor de nodos
    Node(int x, int y, int dist = 0): x(x), y(y), dist(dist) {}
 
    // Como estamos usando struct como clave en `std::set`,
    // necesitamos sobrecargar el operador `<`.
    // Alternativamente, podemos usar `std::pair<int, int>` como clave
    // para almacenar las coordenadas de la matriz en el conjunto.
 
    bool operator<(const Node& o) const {
        return x < o.x || (x == o.x && y < o.y);
    }
};
 
// Encuentra el número mínimo de pasos dados por el caballero
// desde el origen para llegar al destino usando BFS
int findShortestDistance(int N, Node src, Node dest)
{
    // configurado para verificar si la celda de la matriz se visita antes o no
    set<Node> visited;
 
    // crear una queue y poner en queue el primer nodo
    queue<Node> q;
    q.push(src);
 
    // bucle hasta que la queue esté vacía
    while (!q.empty())
    {
        // sacar de la queue el nodo frontal y procesarlo
        Node node = q.front();
        q.pop();
 
        int x = node.x;
        int y = node.y;
        int dist = node.dist;
 
        // si se alcanza el destino, distancia de regreso
        if (x == dest.x && y == dest.y) {
            return dist;
        }
 
        // omitir si la ubicación se visita antes
        if (!visited.count(node))
        {
            // marca el nodo actual como visitado
            visited.insert(node);
 
            // verifica los ocho movimientos posibles para un caballo
            // y poner en queue cada movimiento válido
            for (int i = 0; i < 8; i++)
            {
                // obtener la posición válida del caballo desde la posición actual en
                // el tablero de ajedrez y ponerlo en queue con +1 de distancia
                int x1 = x + row[i];
                int y1 = y + col[i];
 
                if (isValid(x1, y1, N)) {
                    q.push({x1, y1, dist + 1});
                }
            }
        }
    }
 
    // devuelve infinito si la ruta no es posible
    return INT_MAX;
}
 
int main()
{
    // matriz N x N
    int N = 8;
 
    // coordenadas de origen
    Node src = {0, 7};
 
    // coordenadas de destino
    Node dest = {7, 0};
 
    cout << "The minimum number of steps required is " <<
            findShortestDistance(N, src, dest);
 
    return 0;
}
