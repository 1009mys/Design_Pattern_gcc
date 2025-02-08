//
// Created by a1009mys on 25. 2. 8.
//

#ifndef BUILDER_LOL_H
#define BUILDER_LOL_H

#include <string>
#include <iostream>

enum Team {Blue, Red};
enum CostType {Mana, Energy, Shield, Heat, None};

class Unit
{
protected:
    std::string name;

    int health;
    int attackPower;
    int abilityPower;
    int defense;
    int magicResistance;

    Team team;
public:
    void set_name(std::string name) { this->name = name; }
    void set_health(int health) { this->health = health; }
    void set_attackPower(int attackPower) { this->attackPower = attackPower; }
    void set_abilityPower(int abilityPower) { this->abilityPower = abilityPower; }
    void set_defense(int defense) { this->defense = defense; }
    void set_magicResistance(int magicResistance) { this->magicResistance = magicResistance; }
    void set_team(Team team) { this->team = team; }

    virtual void printSpec() =0;
};

class Champion : public Unit
{
protected:
    std::string skillQ;
    std::string skillW;
    std::string skillE;
    std::string skillR;

    int maxCost;
    CostType costType;
    std::string passive;
public:
    void set_skillQ(std::string skillQ) { this->skillQ = skillQ; }
    void set_skillW(std::string skillW) { this->skillW = skillW; }
    void set_skillE(std::string skillE) { this->skillE = skillE; }
    void set_skillR(std::string skillR) { this->skillR = skillR; }
    void set_maxCost(int maxCost) { this->maxCost = maxCost; }
    void set_costType(CostType costType) { this->costType = costType; }
    void set_passive(std::string passive) { this->passive = passive; }

    void printSpec() override
    {
        std::cout << "Name: " << name << std::endl;
        std::cout << "Health: " << health << std::endl;
        std::cout << "Attack Power: " << attackPower << std::endl;
        std::cout << "Ability Power: " << abilityPower << std::endl;
        std::cout << "Defense: " << defense << std::endl;
        std::cout << "Magic Resistance: " << magicResistance << std::endl;
        std::cout << "Team: " << (team == Blue ? "Blue" : "Red") << std::endl;
        std::cout << "Skill Q: " << skillQ << std::endl;
        std::cout << "Skill W: " << skillW << std::endl;
        std::cout << "Skill E: " << skillE << std::endl;
        std::cout << "Skill R: " << skillR << std::endl;
        std::cout << "Max Cost: " << maxCost << std::endl;
        std::cout << "Cost Type: " << (costType == Mana ? "Mana" : (costType == Energy ? "Energy" : (costType == Shield ? "Shield" : (costType == Heat ? "Heat" : "None")))) << std::endl;
        std::cout << "Passive: " << passive << std::endl;
    }
};

class Darius : public Champion
{
public:
    Darius() {}



};

class Ari : public Champion
{
public:
    Ari() {}
};

class Aartrox : public Champion
{
public:
    Aartrox() {}
};

class Builder_lol
{
public:
    virtual void set_name(std::string name_) const = 0;

    virtual void set_health(int health) const = 0;
    virtual void set_attackPower(int attackPower) const = 0;
    virtual void set_abilityPower(int abilityPower) const = 0;
    virtual void set_defense(int defense) const = 0;
    virtual void set_magicResistance(int magicResistance) const = 0;
    virtual void set_team(Team team) const = 0;
};

class ChampionBuilder : public Builder_lol
{
protected:
    Champion* champion;
public:
    void set_name(std::string name) const override { champion->set_name(name); }
    void set_health(int health) const override { champion->set_health(health); }
    void set_attackPower(int attackPower) const override { champion->set_attackPower(attackPower); }
    void set_abilityPower(int abilityPower) const override { champion->set_abilityPower(abilityPower); }
    void set_defense(int defense) const override { champion->set_defense(defense); }
    void set_magicResistance(int magicResistance) const override { champion->set_magicResistance(magicResistance); }
    void set_team(Team team) const override { champion->set_team(team); }

    void build_skillQ(std::string skillQ) const { champion->set_skillQ(skillQ); }
    void build_skillW(std::string skillW) const { champion->set_skillW(skillW); }
    void build_skillE(std::string skillE) const { champion->set_skillE(skillE); }
    void build_skillR(std::string skillR) const { champion->set_skillR(skillR); }
    void build_maxCost(int maxCost) const { champion->set_maxCost(maxCost); }
    void build_costType(CostType costType) const { champion->set_costType(costType); }
    void build_passive(std::string passive) const { champion->set_passive(passive); }
};

class DariusBuiler : public ChampionBuilder
{
public:
    DariusBuiler() { champion = new Darius(); }
    ~DariusBuiler() { delete champion; }

    Champion* getChampion() { return champion; }
};

class AriBuilder : public ChampionBuilder
{
public:
    AriBuilder() { champion = new Ari(); }
    ~AriBuilder() { delete champion; }

    Champion* getChampion() { return champion; }
};

class AartroxBuilder : public ChampionBuilder
{
public:
    AartroxBuilder() { champion = new Aartrox(); }
    ~AartroxBuilder() { delete champion; }

    Champion* getChampion() { return champion; }
};

class Director_lol
{
private:
    ChampionBuilder* builder;
public:
    void set_builder(ChampionBuilder* builder){
        this->builder = builder;
    }

    void BuildDarius()
    {
        builder->set_name("Darius");
        builder->set_health(100);
        builder->set_attackPower(100);
        builder->set_abilityPower(0);
        builder->set_defense(100);
        builder->set_magicResistance(50);
        builder->set_team(Blue);

        builder->build_skillQ("Decimate");
        builder->build_skillW("Crippling Strike");
        builder->build_skillE("Apprehend");
        builder->build_skillR("Noxian Guillotine");
        builder->build_maxCost(100);
        builder->build_costType(Mana);
        builder->build_passive("Hemorrhage");
    }
    void BuildAri()
    {
        builder->set_name("Ari");
        builder->set_health(100);
        builder->set_attackPower(0);
        builder->set_abilityPower(100);
        builder->set_defense(50);
        builder->set_magicResistance(100);
        builder->set_team(Red);

        builder->build_skillQ("Orb of Deception");
        builder->build_skillW("Fox-Fire");
        builder->build_skillE("Charm");
        builder->build_skillR("Spirit Rush");
        builder->build_maxCost(100);
        builder->build_costType(Mana);
        builder->build_passive("Vastayan Grace");
    }
    void BuildAartrox()
    {
        builder->set_name("Aartrox");
        builder->set_health(100);
        builder->set_attackPower(100);
        builder->set_abilityPower(0);
        builder->set_defense(100);
        builder->set_magicResistance(50);
        builder->set_team(Blue);

        builder->build_skillQ("The Darkin Blade");
        builder->build_skillW("Infernal Chains");
        builder->build_skillE("Umbral Dash");
        builder->build_skillR("World Ender");
        builder->build_maxCost(0);
        builder->build_costType(None);
        builder->build_passive("Deathbringer Stance");
    }


};

void buildGame()
{
    Director_lol* director = new Director_lol();

    DariusBuiler* darius_builder = new DariusBuiler();
    director->set_builder(darius_builder);
    std::cout << "Build Darius" << std::endl;
    director->BuildDarius();
    Champion* darius = darius_builder->getChampion();

    AriBuilder* ari_builder = new AriBuilder();
    director->set_builder(ari_builder);
    std::cout << "Build Ari" << std::endl;
    director->BuildAri();
    Champion* ari = ari_builder->getChampion();

    AartroxBuilder* aartrox_builder = new AartroxBuilder();
    director->set_builder(aartrox_builder);
    std::cout << "Build Aartrox" << std::endl;
    director->BuildAartrox();
    Champion* aartrox = aartrox_builder->getChampion();

    darius->printSpec();
    std::cout << std::endl;
    ari->printSpec();
    std::cout << std::endl;
    aartrox->printSpec();

    delete director;

    delete darius_builder;
    delete ari_builder;
    delete aartrox_builder;


}



#endif //BUILDER_LOL_H


