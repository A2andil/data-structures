//in the name of God

#include <iostream>

#define N 4
#define ll long long

using namespace std;

struct Query {
        int x1, y1;
        int x2, y2;
};

void updateBIT(int BIT[][N + 1], int x, int y, int val) {
        while (x <= N) {
                int tmp = y;
                while (tmp <= N) {
                        BIT[x][tmp] += val;
                        tmp += tmp & -tmp;
                }
                x += x & -x;
        }
        return;
}

int getSum(int BIT[][N + 1], int x, int y) {
        ll rs = 0;
        while (x > 0) {
                int tmp = y;
                while (tmp > 0) {
                        rs += BIT[x][tmp];
                        tmp -= tmp & -tmp;
                }
                x -= x & -x;
        }
        return rs;
}

void constructAux(int mat[][N], int aux[][N + 1]) {
        for (int i = 0; i <= N; i++) {
                for (int j = 0; j <= N; j++)
                        aux[i][j] = 0;
        }

        for (int j = 1; j <= N; j++) {
                for (int i = 1; i <= N; i++)
                        aux[i][j] = mat[N - j][i - 1];
        }

        return;
}

void construct2DBIT(int mat[][N], int BIT[][N + 1]) {
        int aux[N + 1][N + 1];
        constructAux(mat, aux);

        for (int i = 1; i <= N; i++) {
                for (int j = 1; j <= N; j++)
                        BIT[i][j] = 0;
        }

        for (int j = 1; j <= N; j++) {
                for (int i = 1; i <= N; i++) {
                        updateBIT(BIT, i, j, aux[i][j]);
                }
        }

        return;
}

void answerQueries(Query q[], int m, int BIT[][N + 1]) {
        for (int i = 0; i < m; i++) {
                int x1 = q[i].x1 + 1;
                int y1 = q[i].y1 + 1;
                int x2 = q[i].x2 + 1;
                int y2 = q[i].y2 + 1;

                int ans = getSum(BIT, x2, y2) - getSum(BIT, x2, y1 - 1) -
                        getSum(BIT, x1 - 1, y2) + getSum(BIT, x1 - 1, y1 - 1);

                printf("Query(%d, %d, %d, %d) = %d\n",
                        q[i].x1, q[i].y1, q[i].x2, q[i].y2, ans);
        }
        return;
}

int main() {
        int mat[N][N] = {
                { 1, 2, 3, 4 },
                { 5, 3, 8, 1 },
                { 4, 6, 7, 5 },
                { 2, 4, 8, 9 },
        };

        int BIT[N + 1][N + 1];
        construct2DBIT(mat, BIT);

        Query q[] = {
                { 1, 1, 3, 2 },
                { 2, 3, 3, 3 },
                { 1, 1, 1, 1 },
        };
        int m = sizeof(q) / sizeof(q[0]);
        answerQueries(q, m, BIT);

        return(0);
}
