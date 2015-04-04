// Compile with the following command:
// g++ problem039.cpp -lgsl -lgslcblas

#include <gsl/gsl_blas.h>

#include <iostream>
#include <vector>

const double m1[] = { -1,  2,  2,
                      -2,  1,  2,
                      -2,  2,  3 };

const double m2[] = {  1,  2,  2,
                       2,  1,  2,
                       2,  2,  3 };

const double m3[] = {  1, -2,  2,
                       2, -1,  2, 
                       2, -2,  3 };

gsl_matrix_const_view a[] = { gsl_matrix_const_view_array(m1, 3, 3),
                              gsl_matrix_const_view_array(m2, 3, 3),
                              gsl_matrix_const_view_array(m3, 3, 3) };

struct Triple
{
    int a, b, c;

    Triple(int a, int b, int c)
    : a(a), b(b), c(c)
    {
    }
};

int sum(const Triple& t)
{
    return t.a + t.b + t.c;
}

void pythagoreanTriples(const Triple& root, int maxPerimeter, std::vector<Triple>& results)
{
    if (sum(root) > maxPerimeter) {
        return;
    }
    results.push_back(root);
    double r[] = { root.a, root.b, root.c };
    double c[3];
    gsl_vector_view x = gsl_vector_view_array(r, 3);
    gsl_vector_view y = gsl_vector_view_array(c, 3);
    for (int i = 0; i < 3; ++i) {
        gsl_blas_dgemv(CblasNoTrans, 1.0, &a[i].matrix, &x.vector, 0.0, &y.vector);
        pythagoreanTriples(Triple(c[0], c[1], c[2]), maxPerimeter, results);
    }
}

std::vector<Triple> pythagoreanTriples(int maxPerimeter)
{
    std::vector<Triple> results;
    pythagoreanTriples(Triple(3, 4, 5), maxPerimeter, results);
    return results;
}

int rightestTrianglePerimeter(int maxPerimeter)
{
    int result = -1;
    std::vector<Triple> triples = pythagoreanTriples(maxPerimeter);
    std::vector<int> vec(maxPerimeter / 2 + 1);
    for (int i = 0; i < triples.size(); ++i) {
        int p = sum(triples[i]);
        int m = p;
        do {
            ++vec[m / 2];
            m += p;
        } while (m <= maxPerimeter);
    }
    int maxTriples = 0;
    for (int i = 6; i < vec.size(); ++i) {
        if (vec[i] > maxTriples) {
            maxTriples = vec[i];
            result = 2 * i;
        }
    }
    return result;
}

int main()
{
    std::cout << "Answer: " << rightestTrianglePerimeter(1000) << '\n';
    return 0;
}
