#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#include <unordered_map>
#include <cctype>

//Hashcodes
class HashCode {
public:
    //polynomial hash code
    int operator() (const std::string& s, const int a = 37) {
        unsigned int h = 0;
        int k = s.size();

        for(int i = 0; i < k; i++) {
            int power = (k - 1) - i;
            h += (unsigned int) s[i] * std::pow(a, power);
        }

        return h;
    }

};

std::string lowerCase(std::string& s) {
    for(char& c : s){
        c = std::tolower(c);
    }
    return s;
}


int main(int argc, char const *argv[])
{
    std::cout << "Author: Jesus Rodriguez-Luna" << std::endl;
    std::unordered_map<int, int> collisions;
    std::unordered_map<int, std::string> wordList;
    std::ifstream US_DoI_File("C:/Users/jesus/Documents/GitHub/Hash-Map/usdeclarPC.txt");
    HashCode h;
    int hasher = 0;
    std::string word = "";
    int sumOfCollisions = 0;

    //not open?
    if(!US_DoI_File.is_open()) std::cout << "Not Open!" << std::endl;

    while (US_DoI_File >> word) {
        word = lowerCase(word);
        hasher = std::abs(h(word));
        auto p = wordList.find(hasher);
        if (p == wordList.end()) {
            wordList[hasher] = word;
            collisions[hasher] = 1;
        } else {
            if (word != wordList[hasher]) {  // Collision only if different words have the same hash
                collisions[hasher]++;
            }
        }
    }


    auto q = collisions.begin();
    while(q != collisions.end()) {
        if(q->second > 1) sumOfCollisions += q->second;
        ++q;
    }

    std::cout << "Polynomial Shift Hashcode - Number of collisions: " << sumOfCollisions << std::endl;
    
    return 0;
}
