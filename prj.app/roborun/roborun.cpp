#include <iostream>
#include <map>
#include <functional>
#include <string>
#include <vector>
#include <stdexcept>

class RoborunFunc {
protected:
    std::map<std::string, void (RoborunFunc::*)(double)> funcs;
    double x{0.0};
    double y{0.0};
public:

    RoborunFunc() {
        funcs["GON"] = &RoborunFunc::GON;
        funcs["GOE"] = &RoborunFunc::GOE;
        funcs["GOS"] = &RoborunFunc::GOS;
        funcs["GOW"] = &RoborunFunc::GOW;
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
        while(std::cin >> command >> value) {
            if (funcs.find(command) == funcs.end() && (command != "GOR" && command != "REV")) {
                throw std::invalid_argument("Provided command isn't defined!\n");
            }
            if (command != "GOR" && command != "REV") {
                commands.push_back(std::make_pair(command, value));
            }
            switch(command[command.size() - 1]) {
                case 'R':
                    x = value;
                    for (auto cmd : commands) {
                        (this->*funcs[cmd.first])(cmd.second);
                        //std::cout << "Past the first potential breakpoint " << cmd.first << " " << cmd.second << "\n";
                    }
                    std::cout << '{' << x << "; " << y << '}' << std::endl;
                    commands.clear();
                    break;
                case 'V':
                    commands.resize(commands.size() - static_cast<size_t>(value));
                    //std::cout << "Past the second potential breakpoint, " << value << ' ' << commands.size() << "\n";
                    break;
                default:
                    break;
            }
        }
    }
};

int main() {
    Roborun Robo;
    Robo.run();
}
