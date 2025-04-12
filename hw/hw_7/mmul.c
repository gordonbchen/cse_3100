#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "matrix.h"

// Search TODO to find the locations where code needs to be completed

#define     NUM_THREADS     2

typedef struct {
    unsigned int id;
    TMatrix *m, *n, *t;
} thread_arg_t;

static void * thread_main(void * p_arg)
{
    // TODO
    thread_arg_t* arg = (thread_arg_t*) p_arg;
    TMatrix* t = arg->t;
    TMatrix* m = arg->m;
    TMatrix* n = arg->n;

    for (unsigned int row = arg->id; row < t->nrows; row += NUM_THREADS) {
        for (unsigned int col = 0; col < t->ncols; ++col) {
            TElement dot_product = 0;
            for (unsigned int i = 0; i < m->ncols; ++i) {
                dot_product += m->data[row][i] * n->data[i][col];
            }
            t->data[row][col] = dot_product;
        }
    }
    return NULL;
}

/* Return the sum of two matrices.
 *
 * If any pthread function fails, report error and exit. 
 * Return NULL if anything else is wrong.
 *
 * Similar to mulMatrix, but with multi-threading.
 */
TMatrix * mulMatrix_thread(TMatrix *m, TMatrix *n)
{
    if (    m == NULL || n == NULL
         || m->ncols != n->nrows )
        return NULL;

    TMatrix * t = newMatrix(m->nrows, n->ncols);
    if (t == NULL)
        return t;

    // TODO
    pthread_t threads[NUM_THREADS];
    thread_arg_t thread_args[NUM_THREADS];
    for (int i = 0; i < NUM_THREADS; ++i) {
        thread_args[i].id = i;
        thread_args[i].m = m;
        thread_args[i].n = n;
        thread_args[i].t = t;
        pthread_create(threads+i, NULL, thread_main, thread_args+i);
    }

    for (int i = 0; i < NUM_THREADS; ++i) {
        pthread_join(threads[i], NULL);
    }
    return t;
}
