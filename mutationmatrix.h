#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/io.hpp>
using namespace boost::numeric::ublas;


class Mutationmatrix {
    matrix<double> m;

public:
    Mutationmatrix() : m(64,64) {
        //testdata
        for (int i = 0; i < 64; i++) {
            for (int j = 0; j < 64; j++) {
                if (i==j) {
                    m(i,j) = 1.;
                } else {
                    m(i,j) = 0.;
                }
            }
        }
    }

};
