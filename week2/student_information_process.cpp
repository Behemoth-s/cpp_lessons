#include <iostream>
using namespace std;

class MyStudent
{
private:
    string name;
    int age;
    string id;
    int score1;
    int score2;
    int score3;
    int score4;
    int avg_score;
    string delim = ",";
    void set_paras(string argv);

public:
    MyStudent(string argv);
    void print();
};
MyStudent ::MyStudent(string argv)
{
    set_paras(argv);
}

void MyStudent::set_paras(string argv)
{

    auto start = 0U;
    int end;
    auto next_para = [&s = start, &e = end, &str = argv](string delim) -> string {
        e = str.find(delim, s);
        string para = str.substr(s, e - s);
        s = e + 1;
        return para;
    };
    name = next_para(delim);
    age = stoi(next_para(delim));
    id = next_para(delim);
    score1 = stoi(next_para(delim));
    score2 = stoi(next_para(delim));
    score3 = stoi(next_para(delim));
    score4 = stoi(next_para(delim));
    avg_score = (score1 + score2 + score3 + score4) / 4;
    // while (end != std::string::npos)
    // {
    //     std::cout << s.substr(start, end - start) << std::endl;
    //     start = end + delim.length();
    //     end = s.find(delim, start);
    // }
}
void MyStudent::print()
{
    cout << name << "," << age << "," << id << "," << avg_score << endl;
}
int main(int argc, char *argv[])
{
    for (int i = 1; i < argc; i++)
    {
        MyStudent s(argv[i]);
        s.print();
        // cout << argv[i] << endl;
    }
    return 0;
}