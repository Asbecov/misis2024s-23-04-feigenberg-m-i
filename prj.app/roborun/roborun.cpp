#include <iostream>
#include <map>
#include <functional>
#include <string>
#include <vector>
#include <stdexcept>

class RoborunFunc {
protected:
    static std::map<std::string, void (RoborunFunc::)(double)> funcs;
    double x{0.0};
    double y{0.0};
public:
    RoborunFunc() {
        funcs["GON"] = GON;
        funcs["GOE"] = GOE;
        funcs["GOS"] = GOS;
        funcs["GOW"] = GOW;
    }
    void GON(double distance) {
        x += distance;
    }
    void GOE(double distance) {
        y += distance;
    }
    void GOS(double distance) {
        x -= distance;
    }
    void GOW(double distance) {
        y -= distance;
    }
};

class Roborun : public RoborunFunc {
private: 
    std::vector<std::pair<std::string, double>> commands;
public: 
    void run() {
        std::string command;
        double value;
        while(!std::cin.eof()) {
            std::cin >> command >> value;
            bool flag{false};
            for (auto idx{funcs.begin()}; idx != funcs.end(); idx++) {
                if (command == idx->first) {
                    flag = true;
                    break;
                }
            }
            if (!flag) {
                throw (std::invalid_argument("Provided command isn't defined!\n"))
            }
            switch(command[command.size()]) {
                case 'R':
                    x = value;
                    for (auto i{commands.begin()}; i != commands.end(); i++) {
                        funcs[i->first](i->second);
                    }
                    commands.clear();
                    std::cout << '{' << x << "; " << y << '}' << std::endl;
                    break;
                case 'V':
                    while(value--) {
                        commands.pop_back();
                    }
                    break;
                default:
                    commands.push_back(std::pair<std::string, double>(command, value));

            }   
        }
    }
};

int main() {
    Roborun Robo;
    Robo.run();
}