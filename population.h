#include <vector>
#include <iostream>
#include "individual.h"
#include "exampleindividual.h"
#include "mutationmatrix.h"


class Population {
    public:
    std::vector<Individual*> individuals;
    Mutationmatrix mutationmatrix;

    double (*fitnessfunction)(Individual*);

    long age;
    long guid;

    void step();
    void (*mutate)(std::vector<Individual*> &individuals);
    void (*select)(std::vector<Individual*> &individuals);
    void (*kill)(std::vector<Individual*> &individuals);
    void init_pupulation();
    void setup();
    void setup_example();
    void run();

    Population() { age=0; guid = 0; }
};

void example_mutate(std::vector<Individual*> &individuals) {
    ;
}

void example_select(std::vector<Individual*> &individuals) {
;
}

void example_kill(std::vector<Individual*> &individuals) {
;
}

void Population::run() {
    for (int i = 0; i < 1000; i++) {
        this->step();
    }
}

void Population::step() {
    age++;
    if (age%100==0) {
        std::cout << age << std::endl;
    }

    this->mutate(this->individuals);
    this->select(this->individuals);
    this->kill(this->individuals);
}

void Population::setup() {}

void Population::setup_example() {
    for (int i = 0; i < 80; i++) {
        Exampleindividual *new_individual = new(Exampleindividual);
        new_individual->id = guid;
        guid++;
        //std::cout << new_individual->id << std::endl;
        this->individuals.push_back(new_individual);
    }
    this->mutate = &example_mutate;
    this->select = &example_select;
    this->kill = &example_kill;
}
