#ifndef ISLAND_HPP
#define ISLAND_HPP

#include "ga.hpp"

#include <vector>

class Island
{
    private:
        std::vector<GA*> gaList;
        GAParameters gaP;
        uint64_t maxSubIteration;
        double migrationRate;
        void migration(uint16_t ga1, uint16_t ga2);
        void globalMigration();
        Chromosome best;
        std::vector<Chromosome> listOfBests;
        uint32_t seconds;
    public:
        Island(GAParameters gaP, uint64_t maxSubIteration, double migrationRate, std::vector<Task>* taskList, std::vector<Robot> *robotlist, std::vector<std::vector<double>> *distancematrix);
        ~Island();
        void solve();
        void setTimeLimit(uint32_t seconds);
        Chromosome getBest();
        std::vector<Chromosome> getListOfBests();
};



#endif