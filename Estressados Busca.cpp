#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>
#include <tuple>
#include <functional>
#include <iomanip>
using namespace std;

bool in(vector<int> vet, int x) {
    for (int i = 0; i < vet.size(); i++) {
        if (vet[i] == x)
          return true;
        }
    return false;
}

int index_of(vector<int> vet, int x) {
    for (int i = 0; i < vet.size(); i++) {
        if (vet[i] == x)
          return i;
    }
    return -1;
}

int find_if(vector<int> vet) {
    for (int i = 0; i < vet.size(); i++) {
        if (vet[i] > 0)
          return i;
    }
    return -1;
}

int min_element(vector<int> vet) {
    int min, min_index = -1;
    for (int i = 0; i < vet.size(); i++) {
        if (i == 0) {
            min = vet[0];
            min_index = 0;
        }
        if (vet[i] < min) {
          min_index = i;
          min = vet[i];
        }
    }
    return min_index;
}

int find_min_if(vector<int> vet) {
    vector <int> men = {};
    for (int i = 0; i < vet.size(); i++){
        if (vet[i] > 0)
            men.push_back(vet[i]);
    }
    int min{};
    int min_index = -1;
    for (int i = 0; i < men.size(); i++){
        if (i == 0)
            min = men[0]; 
        if (men[i] < min){
            min = men[i];
            min_index = i;
        }
  }
  return min_index;
}

int count(vector<int> vet, int x) {
    int count = 0;
    for (int i = 0; i < vet.size(); i++) {
        if (vet[i] == x)
          count++;
    }
    return count;
}

double average(vector<int> vet) {
    double average = 0;
    for (int i = 0; i < vet.size(); i++)
        average += abs(vet[i]);
    if (average != 0)
        average = average / vet.size();
    return average;
}

string half_compare(vector<int> vet) {
    int first = 0, second = 0;
    for (int i = 0; i < vet.size()/2; i++)
        first += abs(vet[i]);
    reverse(vet.begin(), vet.end());
    for (int i = 0; i < vet.size()/2; i++)
        second += abs(vet[i]);
    if (first > second)
        return "first";
    else if (first < second)
        return "second";
    return "draw";
}

string more_men(vector<int> vet) {
    int men = 0, women = 0;
    for (int i = 0; i < vet.size(); i++) {
        if (vet[i] > 0)
            men++;
        if (vet[i] < 0)
          women++;
    }
    if (men > women)
        return "men";
    else if (men < women)
        return "women";
    return "draw";
}

string sex_battle(vector<int> vet) {
    double men = 0, women = 0;
    double avg_men = 0, avg_wmen = 0;
    for (int i = 0; i < vet.size(); i++) {
        if (vet[i] > 0) {
            men++;
            avg_men += vet[i];
        }
        if (vet[i] < 0) {
            women++;
            avg_wmen += abs(vet[i]);
        }
    }
    avg_men = avg_men / men;
    avg_wmen = avg_wmen / women;
    if (avg_men > avg_wmen)
        return "men";
    else if (avg_men < avg_wmen)
        return "women";
    return "draw";
}

// Funções auxiliares
template <class T>
T to(std::string data); //int value = to<int>("43");
std::vector<int> to_vet(std::string data); //vector<int> vet = to_vet("[1,2,3]");
std::vector<std::string> split(std::string content, char sep = ' '); //quebra uma linha em um vetor de palavras
std::string fmt(std::vector<int> data); //formata vetor como [2,3,4,5]
std::string fmt(bool value); //retorna bool como "true" ou "false"
std::string fmt(double value); //retorna com duas casas decimais;

template <class T>
void print(T data) {
    std::cout << data << std::endl;
}

//loop principal
int main(){
    while(true) {
        std::string line{};
        std::getline(std::cin, line);
        print("$" + line);
        auto ui = split(line);
        auto cmd = ui[0];
        if (cmd == "end") {
            break;
        } else if (cmd == "in") {
            auto res = in(to_vet(ui[1]), to<int>(ui[2]));
            std::cout << fmt(res) << '\n';
        } else if (cmd == "index_of") {
            auto res = index_of(to_vet(ui[1]), to<int>(ui[2]));
            std::cout << res << '\n';
        } else if (cmd == "find_if") {
            auto res = find_if(to_vet(ui[1]));
            std::cout << res << '\n';
        } else if (cmd == "min_element") {
            std::cout << min_element(to_vet(ui[1])) << '\n';
        } else if (cmd == "find_min_if") {
            std::cout << find_min_if(to_vet(ui[1])) << '\n';
        } else if (cmd == "count") {
            std::cout << count(to_vet(ui[1]), to<int>(ui[2])) << '\n';
        } else if (cmd == "average") {
            std::cout << fmt(average(to_vet(ui[1]))) << '\n';
        } else if (cmd == "more_men") {
            std::cout << more_men(to_vet(ui[1])) << '\n';
        } else if (cmd == "half_compare") {
            std::cout << half_compare(to_vet(ui[1])) << '\n';
        } else if (cmd == "sex_battle") {
            std::cout << sex_battle(to_vet(ui[1])) << '\n';
        } else {
            std::cout << "unknown command: " << cmd << '\n';
        }
    }
    return 0;
}

std::vector<std::string> split(std::string content, char sep) {
    std::stringstream ss(content);
    std::string token;
    std::vector<std::string> vet;
    while(std::getline(ss, token, sep))
        vet.push_back(token);
    return vet;
}

template <class T>
T to(std::string data) {
    T value;
    std::istringstream(data) >> value;
    return value;
}

std::vector<int> to_vet(std::string data) {
    auto vet_str = split(data.substr(1, data.size() - 2), ',');
    int value {};
    std::vector<int> vet;
    for (auto token : vet_str)
        vet.push_back(to<int>(token));
    return vet;
}

std::string fmt(std::vector<int> data) {
    std::ostringstream ss;
    ss << "[";
    for (auto it = data.begin(); it != data.end(); ++it)
        ss << (it != data.begin() ? "," : "") << *it;
    ss << "]";
    return ss.str();
}

std::string fmt(bool value) {
    return value ? "true" : "false";
}

std::string fmt(double value) {
    std::stringstream ss;
    ss << std::fixed << std::setprecision(2) << value;
    return ss.str();
}