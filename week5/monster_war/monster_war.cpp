/***
描述
魔兽世界的西面是红魔军的司令部，东面是蓝魔军的司令部。两个司令部之间是依次排列的若干城市。
红司令部，City 1，City 2，……，City n，蓝司令部
两军的司令部都会制造武士。武士一共有 dragon 、ninja、iceman、lion、wolf 五种。每种武士都有编号、生命值这两种属性。
有的武士可以拥有武器。武器有三种，sword, bomb,和arrow，编号分别为0,1,2。
双方的武士编号都是从1开始计算。红方制造出来的第 n 个武士，编号就是n。同样，蓝方制造出来的第 n 个武士，编号也是n。
不同的武士有不同的特点。

dragon 可以拥有一件武器。编号为n的dragon降生时即获得编号为 n%3 的武器。dragon还有“士气”这个属性，是个浮点数，其值为它降生后其司令部剩余生命元的数量除以造dragon所需的生命元数量。

ninjia可以拥有两件武器。编号为n的ninjia降生时即获得编号为 n%3 和 (n+1)%3的武器。

iceman有一件武器。编号为n的iceman降生时即获得编号为 n%3 的武器。

lion 有“忠诚度”这个属性，其值等于它降生后其司令部剩余生命元的数目。

wolf没特点。

请注意，在以后的题目里，武士的士气，生命值，忠诚度在其生存期间都可能发生变化，都有作用，武士手中的武器随着使用攻击力也会发生变化。

武士在刚降生的时候有一个生命值。

在每个整点，双方的司令部中各有一个武士降生。

红方司令部按照 iceman、lion、wolf、ninja、dragon 的顺序循环制造武士。

蓝方司令部按照 lion、dragon、ninja、iceman、wolf 的顺序循环制造武士。

制造武士需要生命元。

制造一个初始生命值为 m 的武士，司令部中的生命元就要减少 m 个。

如果司令部中的生命元不足以制造某个按顺序应该制造的武士，那么司令部就试图制造下一个。如果所有武士都不能制造了，则司令部停止制造武士。

给定一个时间，和双方司令部的初始生命元数目，要求你将从0点0分开始到双方司令部停止制造武士为止的所有事件按顺序输出。

一共有两种事件，其对应的输出样例如下：

1) 武士降生

输出样例： 004 blue lion 5 born with strength 5,2 lion in red headquarter

表示在 4点整，编号为5的蓝魔lion武士降生，它降生时生命值为5,降生后蓝魔司令部里共有2个lion武士。(为简单起见，不考虑单词的复数形式)注意，每制造出一个新的武士，都要输出此时司令部里共有多少个该种武士。

如果造出的是dragon，那么还要输出一行，例：

It has a arrow,and it's morale is 23.34

表示该dragon降生时得到了arrow,其士气是23.34（为简单起见，本题中arrow前面的冠词用a,不用an，士气精确到小数点后面2位，四舍五入）

如果造出的是ninjia，那么还要输出一行，例：

It has a bomb and a arrow

表示该ninjia降生时得到了bomb和arrow。

如果造出的是iceman，那么还要输出一行，例：

It has a sword

表示该iceman降生时得到了sword。

如果造出的是lion，那么还要输出一行，例：

It's loyalty is 24

表示该lion降生时的忠诚度是24。

2) 司令部停止制造武士

输出样例： 010 red headquarter stops making warriors

表示在 10点整，红方司令部停止制造武士

输出事件时：

首先按时间顺序输出；

同一时间发生的事件，先输出红司令部的，再输出蓝司令部的。

输入
第一行是一个整数,代表测试数据组数。

每组测试数据共两行。

第一行，一个整数M。其含义为： 每个司令部一开始都有M个生命元( 1 <= M <= 10000)

第二行：五个整数，依次是 dragon 、ninja、iceman、lion、wolf 的初始生命值。它们都大于0小于等于10000

输出
对每组测试数据，要求输出从0时0分开始，到双方司令部都停止制造武士为止的所有事件。

对每组测试数据，首先输出“Case:n" n是测试数据的编号，从1开始

接下来按恰当的顺序和格式输出所有事件。每个事件都以事件发生的时间开头，时间以小时为单位，有三位。
 ****/
#include "monster_war.hpp"
#include <iostream>
#include <stdio.h>
using namespace std;

//iceman、lion、wolf、ninja、dragon  {"dragon", "ninja", "iceman", "lion", "wolf"};
//lion、dragon、ninja、iceman、wolf
const int RED_HERO_ORDER[HERO_CLASS_NUMBER] = {2, 3, 4, 1, 0};
const int BLUE_HERO_ORDER[HERO_CLASS_NUMBER] = {3, 0, 1, 2, 4};

Command::Command(int hp, string name, const int (&hero_class_order)[HERO_CLASS_NUMBER],
                 const int (&hp_set)[HERO_CLASS_NUMBER], const int (&atk_set)[HERO_CLASS_NUMBER])
    : HP(hp), name(name), id(0), hero_class_count{0}, time(0), state(true), current_hero_order(HERO_CLASS_NUMBER)
{
    for (int i = 0; i < HERO_CLASS_NUMBER; i++)
    {
        HERO_CLASS_ORDER[i] = hero_class_order[i];
        HERO_ATK_SET[i] = atk_set[i];
        HERO_HP_SET[i] = hp_set[i];
    }
}
void Command::generate_warrior()
{
    if (!state)
        return;
    if (has_next_hero())
    {
        auto hero_cls = HERO_CLASS_ORDER[current_hero_order];
        auto hero_hp = HERO_HP_SET[hero_cls];
        auto hero_atk = HERO_ATK_SET[hero_cls];
        HP -= hero_hp;
        Warrior *new_warrior;
        switch (hero_cls)
        {
        case 0:
            new_warrior = new Dragon(id, hero_hp, hero_atk, this);
            break;
        case 1:
            new_warrior = new Ninja(id, hero_hp, hero_atk, this);
            break;
        case 2:
            new_warrior = new Iceman(id, hero_hp, hero_atk, this);
            break;
        case 3:
            new_warrior = new Lion(id, hero_hp, hero_atk, this);
            break;
        case 4:
            new_warrior = new Wolf(id, hero_hp, hero_atk, this);
            break;
        }
        warriors.push_back(new_warrior);
        auto hero_name = new_warrior->get_name();
        auto hero_count = ++hero_class_count[hero_cls];

        //004 blue lion 5 born with strength 5,2 lion in red headquarter
        cout << time << " " << name << " " << hero_name << " " << id << " born with strength ";
        cout << hero_atk << ", " << hero_count << " " << hero_name << " " << name << " headquarter" << endl;
        new_warrior->show();

        // printf("%3d %s %s %d born with strength %d,%d %s in %s headquarter",
        //        time, name.c_str(), hero_name, id, hero_atk, hero_count, hero_name, name);
        id++;
        time++;
    }
    else
    {
        //010 red headquarter stops making warriors
        cout << time << " " << name << " headquarter stops making warriors" << endl;
        state = false;
        // printf("%3d %s headquarter stops making warriors",
        //        time, name);
    }
}
int Command::next_hero_order(int n)
{
    if (n >= HERO_CLASS_NUMBER)
        n = 0;
    else
        n++;
    return n;
}
bool Command::has_next_hero()
{
    int n = next_hero_order(current_hero_order);
    int count = 4;
    while (HP < HERO_HP_SET[HERO_CLASS_ORDER[n]] && count >= 0)
    {
        n = next_hero_order(n);
        count--;
    }

    if (count >= 0)
    {
        current_hero_order = n;
        return true;
    }
    return false;
}

void GameTable::play()
{
    while (red.state || blue.state)
    {
        red.generate_warrior();
        blue.generate_warrior();
    }
}

GameTable::GameTable(int hp0, const int (&hp_set)[HERO_CLASS_NUMBER], const int (&atk_set)[HERO_CLASS_NUMBER])
    : time(0), red(hp0, "red", RED_HERO_ORDER, hp_set, atk_set), blue(hp0, "blue", BLUE_HERO_ORDER, hp_set, atk_set)
{
    for (int i = 0; i < HERO_CLASS_NUMBER; i++)
    {
        this->HERO_HP_SET[i] = hp_set[i];
        this->HERO_ATK_SET[i] = atk_set[i];
    }
}
void resolve_hp_set(int (&hp_set)[HERO_CLASS_NUMBER], string raw)
{
    int start = 0, end;
    auto next_para = [&s = start, &e = end, &str = raw]() -> int {
        e = str.find(",", s);
        string para = str.substr(s, e - s);
        s = e + 1;
        return stoi(para);
    };
    for (int i = 0; i < HERO_CLASS_NUMBER; i++)
    {
        hp_set[i] = next_para();
    }
}
int main()
{
    string in_case, in_hp, in_hp_set;
    int hp;
    int hp_set[HERO_CLASS_NUMBER];
    int atk_set[HERO_CLASS_NUMBER] = {1, 2, 3, 4, 5};
    GameTable *g;
    while (true)
    {
        cout << "please input a case name(input quit to quit game):" << endl;
        getline(cin, in_case);
        cout << "please input total hp(eg, 20):";
        getline(cin, in_hp);
        hp = stoi(in_hp);
        cout << "please input hp set(3,2,4,5,6):";
        getline(cin, in_hp_set);
        resolve_hp_set(hp_set, in_hp_set);
        g = new GameTable(hp, hp_set, atk_set);
        g->play();
        delete g;
    }
    return 0;
}