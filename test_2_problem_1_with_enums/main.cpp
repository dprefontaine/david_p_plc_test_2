///DAVID PREFONTAINE
///4/22/20

///FOR PROBLEM ONE OF TEST TWO

///THIS IS THE PROGRAM WITH ENUMS

#include <iostream>

//enum example for masking color
enum COLORS_AND_ALPHA {
    BLACK = 0x00000000,
    RED = 0xFF000000,
    GREEN = 0x00FF0000,
    BLUE = 0x0000FF00,
    WHITE = 0xFFFFFF00,
    ALPHA = 0x000000FF,
    ALL = 0xFFFFFFFF,
    COLORS_TOTAL = 8
};

enum MATTER_STATES {
    SOLID,
    LIQUID,
    GAS,
    PLASMA,
    MATTER_TOTAL
};

int main(int args, char* argv[]){
    ///EXAMPLE ENUM TYPE ONE
    //example colors
    unsigned int non_photo_blue = 0xA4DDEDFF;
    unsigned int screamin_green = 0x76FF7A00;
    unsigned int golden_rod = 0xDAA520AA;

    std::cout << "The masks of non-photo blue include: " << std::endl;
    std::cout << "red AND - " << std::hex << (non_photo_blue & RED) << std::endl;
    std::cout << "green AND - " << (non_photo_blue & GREEN) << std::endl;
    std::cout << "blue AND - " << (non_photo_blue & BLUE) << std::endl;
    std::cout << "alpha AND - " << (non_photo_blue & ALPHA) << std::endl;
    std::cout << "their total - " << ((non_photo_blue & RED) + (non_photo_blue & GREEN) + (non_photo_blue & BLUE) + (non_photo_blue & ALPHA)) << std::endl;
    std::cout << "blue & green AND - " << ((non_photo_blue & (GREEN | BLUE))) << std::endl;
    std::cout << std::endl;

    std::cout << "The or operations used on screamin green: " << std::endl;
    std::cout << "red OR - " << (screamin_green | RED) << std::endl;
    std::cout << "blue OR - " << (screamin_green | BLUE) << std::endl;
    std::cout << "alpha OR - " << (screamin_green | ALPHA) << std::endl;
    std::cout << "black OR - " << (screamin_green | BLACK) << std::endl;
    std::cout << std::endl;

    std::cout << "Extra operations on golden rod: " << std::endl;
    std::cout << "Shifting golden rod left by total color enums: " << (golden_rod << COLORS_TOTAL) << std::endl;
    std::cout << "Rotating golden rod right total color enums: " << (golden_rod >> COLORS_TOTAL) << std::endl;
    std::cout << "Xor of golden rod by red: " << (golden_rod ^ RED) << std::endl;
    std::cout << "Xor of golden rod by green: " << (golden_rod ^ GREEN) << std::endl;
    std::cout << "Inversion of golden rod: " << (~golden_rod) << std::endl;
    std::cout << std::endl;

    ///EXAMPLE ENUM TYPE TWO
    //temperature
    int matter_state, temperature;

    //generate a random number
    std::cout << "Input a temperature will be generated to determine a water's matter state: " << std::endl;
    std::cin >> temperature;

    if (temperature < 32){
        matter_state = SOLID;
    } else if (temperature < 100){
        matter_state = LIQUID;
    } else {
        matter_state = GAS;
    }

    std::cout << "At a temperature of " << std::dec << temperature << " degrees Fahrenheit, the matter is a ";

    //Print out the result
    switch (matter_state){
    case SOLID:
        std::cout << "solid" << std::endl;
        break;
    case LIQUID:
        std::cout << "liquid" << std::endl;
        break;
    case GAS:
        std::cout << "gas" << std::endl;
        break;
    }

    //increase the matter state
    matter_state++;

    std::cout << "After that state, the next state at a higher temperature will be a ";

    switch (matter_state){
    case LIQUID:
        std::cout << "liquid at " << (32 - temperature) << " more degrees later" << std::endl;
        break;
    case GAS:
        std::cout << "gas at " << (100 - temperature) << " more degrees later" <<  std::endl;
        break;
    case PLASMA:
        std::cout << "plasma some very high temperature later" << std::endl;
        break;
    }

    return 0;
}
