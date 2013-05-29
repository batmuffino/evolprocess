#include "boost/random.hpp"
#include "boost/generator_iterator.hpp"
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
};
