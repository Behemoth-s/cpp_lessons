#include <iostream>
#include <vector>
#include <assert.h>
#include <math.h>
using namespace std;
const int HERO_CLASS_NUMBER = 5;
const int WEAPON_CLASS_NUMBER = 3;
const string HERO_CLASS_NAME[HERO_CLASS_NUMBER] = {"dragon", "ninja", "iceman", "lion", "wolf"};
const string WEAPON_NAME[WEAPON_CLASS_NUMBER] = {"sword", "bomb", "arrow"};
class GameTable;
class Command;
class Weapon;
class Warrior;
class Command
{
private:
    int HERO_CLASS_ORDER[HERO_CLASS_NUMBER];
    int HP;
    int hero_class_count[HERO_CLASS_NUMBER];
    int HERO_ATK_SET[HERO_CLASS_NUMBER];
    int HERO_HP_SET[HERO_CLASS_NUMBER];
    int current_hero_order;
    vector<Warrior *> warriors;
    int id;
    string name;
    int time;
    bool state;
    friend class GameTable;
    friend class Warrior;
    Command(int hp, string name, const int (&hero_class_order)[HERO_CLASS_NUMBER],
            const int (&hp_set)[HERO_CLASS_NUMBER], const int (&atk_set)[HERO_CLASS_NUMBER]);
    void generate_warrior();
    int next_hero_order(int n);
    bool has_next_hero();

public:
    int get_HP()
    {
        return HP;
    }
};
class Weapon
{
private:
    int id;

public:
    Weapon(int id) : id(id)
    {
        assert(id < WEAPON_CLASS_NUMBER);
    }
    string get_name()
    {
        return WEAPON_NAME[id];
    }
};
class Warrior
{
protected:
    int id;
    int hp;
    int atk;
    Command *cmd;

public:
    Warrior(int id, int hp, int atk, Command *cmd) : id(id), hp(hp), atk(atk), cmd(cmd)
    {
    }
    virtual string get_name() { return "Warrior"; }
    virtual void show() {}
};

class Dragon : public Warrior
{
    /***
    dragon 可以拥有一件武器。编号为n的dragon降生时即获得编号为 n%3 的武器。
    dragon还有“士气”这个属性，是个浮点数，其值为它降生后其司令部剩余生命元的数量
    除以造dragon所需的生命元数量。
    如果造出的是dragon，那么还要输出一行，例：
        It has a arrow,and it's morale is 23.34
        表示该dragon降生时得到了arrow,其士气是23.34（为简单起见，本题中arrow前面的冠词用a,不用an，士气精确到小数点后面2位，四舍五入）
    ***/
private:
    Weapon main_weapon;
    double morale;
    string name = "dragon";

public:
    Dragon(int id, int hp, int atk, Command *cmd) : Warrior(id, hp, atk, cmd), main_weapon(id % 3)
    {

        morale = round((*cmd).get_HP() * 100) / 100;
    }
    void show()
    {
        cout << "It has a " << this->main_weapon.get_name() << ",and it's morale is " << morale << endl;
    }
    string get_name()
    {
        return name;
    }
};
class Ninja : public Warrior
{
    /**
    ninjia可以拥有两件武器。
    编号为n的ninjia降生时即获得编号为 n%3 和 (n+1)%3的武器。
    如果造出的是ninjia，那么还要输出一行，例：
    It has a bomb and a arrow
    表示该ninjia降生时得到了bomb和arrow。
    **/
private:
    Weapon main_weapon;
    Weapon secondary_weapon;
    string name = "Ninja";

public:
    Ninja(int id, int hp, int atk, Command *cmd) : Warrior(id, hp, atk, cmd), main_weapon(id % 3), secondary_weapon((id + 1) % 3) {}
    void show()
    {
        cout << "It has a " << this->main_weapon.get_name() << " and a " << this->secondary_weapon.get_name() << endl;
    }
    string get_name()
    {
        return name;
    }
};
class Iceman : public Warrior
{
    /**
    iceman有一件武器。编号为n的iceman降生时即获得编号为 n%3 的武器。
    如果造出的是iceman，那么还要输出一行，例：
    It has a sword
    表示该iceman降生时得到了sword。
    **/
private:
    Weapon main_weapon;
    string name = "iceman";

public:
    Iceman(int id, int hp, int atk, Command *cmd) : Warrior(id, hp, atk, cmd), main_weapon(id % 3)
    {
    }
    void show()
    {
        cout << "It has a " << this->main_weapon.get_name() << endl;
    }
    string get_name()
    {
        return name;
    }
};
class Lion : public Warrior
{
    /**
     * lion 有“忠诚度”这个属性，其值等于它降生后其司令部剩余生命元的数目。
     * 如果造出的是lion，那么还要输出一行，例：
     * It's loyalty is 24
     **/
private:
    int loyalty;
    string name = "lion";

public:
    Lion(int id, int hp, int atk, Command *cmd) : Warrior(id, hp, atk, cmd)
    {
        loyalty = (*cmd).get_HP();
    }
    void show()
    {
        cout << "It's loyalty is " << loyalty << endl;
    }
    string get_name()
    {
        return name;
    }
};
class Wolf : public Warrior
{
    string name = "wolf";

public:
    Wolf(int id, int hp, int atk, Command *cmd) : Warrior(id, hp, atk, cmd) {}
    string get_name()
    {
        return name;
    }
    void show() {}
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
