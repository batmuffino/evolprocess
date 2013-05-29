#include "boost/random.hpp"
#include "boost/generator_iterator.hpp"
#include <boost/random/uniform_real_distribution.hpp>
typedef boost::mt19937 RNGType;
RNGType rng;


boost::uniform_int<> codons( 1, 64 );
boost::variate_generator< RNGType, boost::uniform_int<> >
random_codon(rng, codons);


class Exampleindividual: public Individual {
public:
    Exampleindividual() {
        this->genotype = new int(random_codon());
    }
    virtual const void mutate();
};

const void Exampleindividual::mutate() {
    boost::random::uniform_real_distribution<double> dist(0.0,1.0);
    this->fitness = dist(rng);
}
