#include <iostream>
using namespace std;
const int HERO_CLASS_NUMBER = 5;
const string HERO_CLASS_NAME[5] = {"dragon", "ninja", "iceman", "lion", "wolf"};
class GameTable;
class Command;
// class Warrior
// {
// private:
//     int id;
//     double HP;
//     double ATK;
//     int HeroClass;
//     Warrior(int id, int heroclass) : id(id), HP(GameTable::HERO_HP_SET[heroclass]){};
// };
class Command
{
private:
    int HERO_CLASS_ORDER[HERO_CLASS_NUMBER];
    int HP;
    int hero_class_count[HERO_CLASS_NUMBER];
    int HERO_ATK_SET[HERO_CLASS_NUMBER];
    int HERO_HP_SET[HERO_CLASS_NUMBER];
    int current_hero_order;
    int id;
    string name;
    int time;
    bool state;
    friend class GameTable;
    Command(int hp, string name, const int (&hero_class_order)[HERO_CLASS_NUMBER],
            const int (&hp_set)[HERO_CLASS_NUMBER], const int (&atk_set)[HERO_CLASS_NUMBER]);
    void generate_warrior();
    int next_hero_order(int n);
    bool has_next_hero();
};
class GameTable
{
private:
    Command red;
    Command blue;
    int HERO_HP_SET[HERO_CLASS_NUMBER];
    int HERO_ATK_SET[HERO_CLASS_NUMBER];
    int time;
    friend class Command;

public:
    void play();
    GameTable(int hp0, const int (&hp_set)[HERO_CLASS_NUMBER], const int (&atk_set)[HERO_CLASS_NUMBER]);
};
void resolve_hp_set(int (&hp_set)[], int set_len, string raw)
{
    int start = 0, end;
    auto next_para = [&s = start, &e = end, &str = raw]() -> int {
        e = str.find(",", s);
        string para = str.substr(s, e - s);
        s = e + 1;
        return stoi(para);
    };
    for (int i = 0; i < set_len; i++)
    {
        hp_set[i] = next_para();
    }
}
