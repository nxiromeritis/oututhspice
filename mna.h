#ifndef _MNA_H_
#define _MNA_H_

#include <gsl/gsl_linalg.h>
#include <gsl/gsl_errno.h>

extern double *mna_array;
extern double *mna_vector;
extern unsigned long mna_dimension_size;

#define LU_SOLVER	0
#define CHOL_SOLVER	1

extern byte solver_type;
extern gsl_matrix_view gsl_mna_array;
extern gsl_vector_view gsl_mna_vector;
extern gsl_permutation *gsl_p;

extern void init_MNA_system();
extern void fill_MNA_system();
extern void free_MNA_system();
extern void print_MNA_system();
extern void execute_commands();

extern void dump_MNA_nodes();

extern void decomp_lu_MNA();
extern void decomp_cholesky_MNA();
extern void solve_lu_MNA();
extern void solve_cholesky_MNA();

#endif
