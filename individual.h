
class Individual {
public:
    void *genotype;
    Mutationmatrix *mutationmatrix;
    double fitness;
    long age;
    long id;
    virtual const void mutate() { ;}
};
