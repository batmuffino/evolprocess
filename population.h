#include <vector>
#include <iostream>
#include "mutationmatrix.h"
#include "individual.h"
#include "exampleindividual.h"
#include <boost/random/mersenne_twister.hpp>
#include <boost/random/discrete_distribution.hpp>
#include <boost/random/uniform_real_distribution.hpp>
#include <boost/random/binomial_distribution.hpp>

boost::mt19937 gen;


class Population {
public:
    std::vector<Individual*> individuals;
    Mutationmatrix mutationmatrix;

    double (*fitnessfunction)(Individual*);

    long age;
    long guid;
    int population_size;

    void step();
    void (*mutate)(std::vector<Individual*> &individuals);
    void (*select)(std::vector<Individual*> &individuals);
    void (*kill)(std::vector<Individual*> &individuals);
    void init_pupulation();
    void setup();
    void setup_example();
    void run();

    Population() {
        age=0;
        guid = 0;
        population_size = 0;
    }
};


void example_mutate(std::vector<Individual*> &individuals) {
    double mutationrate = 0.0001;
    boost::binomial_distribution<> binomial(individuals.size(),mutationrate);
    int num_candidates = binomial(rng);
    std::random_shuffle(individuals.begin(),individuals.end());
    for (int i = 0; i < num_candidates; i++) {
        individuals[i]->mutate();
        //std::cout << individuals[i]->fitness;
    }
}

void example_select(std::vector<Individual*> &individuals) {
    std::vector<double> probabilities(individuals.size(),0.);

    for (int i = 0; i < individuals.size(); i++) {
        probabilities[i] = individuals[i]->fitness;
    }

    boost::random::discrete_distribution<> dist(probabilities);

    int candidate = dist(gen);
    //std::cout << candidate << std::endl;

    boost::random::uniform_int_distribution<> kill(0,individuals.size());

    int to_kill = kill(gen);

    delete individuals[to_kill];
    //delete old_individual;
    //std::memcpy(individuals[to_kill],individuals[candidate],sizeof individuals[to_kill]);
    //individuals[to_kill] = individuals[candidate];
    Exampleindividual *new_individual = new(Exampleindividual);
    new_individual->fitness = individuals[candidate]->fitness;
    new_individual->id = individuals[candidate]->id;
    new_individual->mutationmatrix = individuals[candidate]->mutationmatrix;
    individuals[to_kill] = new_individual;
}

void example_kill(std::vector<Individual*> &individuals) {
    ;
}

void Population::run() {
    for (int i = 0; i < 100000; i++) {
        this->step();
    }
}

void Population::step() {
    age++;
    if (age%10==0) {
        std::cout << age << '\t';
        double avg_fit = 0.0;
        for (int i = 0; i < individuals.size(); i++) {
            avg_fit += individuals[i]->fitness;
        }
        std::cout << avg_fit/individuals.size() << std::endl;
    }

    this->mutate(this->individuals);
    this->select(this->individuals);
    this->kill(this->individuals);
}

void Population::setup() {}

void Population::setup_example() {
    this->population_size=8000;
    for (int i = 0; i < population_size; i++) {
        Exampleindividual *new_individual = new(Exampleindividual);
        new_individual->id = guid;
        boost::random::uniform_real_distribution<double> dist(0.0,1.0);
        new_individual->fitness = dist(gen);
        new_individual->mutationmatrix = &this->mutationmatrix;
        guid++;
        //std::cout << new_individual->id << std::endl;
        this->individuals.push_back(new_individual);
    }
    this->mutate = &example_mutate;
    this->select = &example_select;
    this->kill = &example_kill;
}
