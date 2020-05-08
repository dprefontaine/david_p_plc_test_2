///DAVID PREFONTAINE
///4/22/20

///FOR PROBLEM ONE OF TEST TWO

///THIS IS THE SAME PROGRAM WITHOUT ENUMS

//THIS IS WHY ENUMS ARE USED BECAUSE WHO KNOWS WHAT ANY OF THIS MEANS

#include <iostream>

int main(int args, char* argv[]){
    ///EXAMPLE ENUM TYPE ONE
    //example colors
    unsigned int non_photo_blue = 0xA4DDEDFF;
    unsigned int screamin_green = 0x76FF7A00;
    unsigned int golden_rod = 0xDAA520AA;

    std::cout << "The masks of non-photo blue include: " << std::endl;
    std::cout << "red AND - " << std::hex << (non_photo_blue & 0xFF000000) << std::endl;
    std::cout << "green AND - " << (non_photo_blue & 0x00FF0000) << std::endl;
    std::cout << "blue AND - " << (non_photo_blue & 0x0000FF00) << std::endl;
    std::cout << "alpha AND - " << (non_photo_blue & 0x000000FF) << std::endl;
    std::cout << "their total - " << ((non_photo_blue & 0xFF000000) + (non_photo_blue & 0x00FF0000) + (non_photo_blue & 0x0000FF00) + (non_photo_blue & 0x000000FF)) << std::endl;
    std::cout << "blue & green AND - " << ((non_photo_blue & (0x00FF0000 | 0x0000FF00))) << std::endl;
    std::cout << std::endl;

    std::cout << "The or operations used on screamin green: " << std::endl;
    std::cout << "red OR - " << (screamin_green | 0xFF000000) << std::endl;
    std::cout << "blue OR - " << (screamin_green | 0x0000FF00) << std::endl;
    std::cout << "alpha OR - " << (screamin_green | 0x000000FF) << std::endl;
    std::cout << "black OR - " << (screamin_green | 0x00000000) << std::endl;

    std::cout << "Shifting golden_rod left by total color enums: " << (golden_rod << 8) << std::endl;
    std::cout << "Rotating golden_rod right total color enums: " << (golden_rod >> 8) << std::endl;
    std::cout << "Xor of golden rod by red: " << (golden_rod ^ 0xFF000000) << std::endl;
    std::cout << "Xor of golden rod by green: " << (golden_rod ^ 0x00FF0000) << std::endl;
    std::cout << "Inversion of golden rod: " << (~golden_rod) << std::endl;
    std::cout << std::endl;

    ///EXAMPLE ENUM TYPE TWO
    //temperature
    int matter_state, temperature;

    //generate a random number
    std::cout << "A random temperature will be generated to determine a water's matter state: " << std::endl;
    std::cin >> temperature;

    if (temperature < 32){
        matter_state = 0;
    } else if (temperature < 100){
        matter_state = 1;
    } else {
        matter_state = 2;
    }

    std::cout << "At a temperature of " << std::dec << temperature << " degrees Fahrenheit, the matter is a ";

    //Print out the result
    switch (matter_state){
    case 0:
        std::cout << "solid" << std::endl;
        break;
    case 1:
        std::cout << "liquid" << std::endl;
        break;
    case 2:
        std::cout << "gas" << std::endl;
        break;
    }

    //increase the matter state
    matter_state++;

    std::cout << "After that state, the next state at a higher temperature will be a ";

    switch (matter_state){
    case 1:
        std::cout << "liquid at " << (32 - temperature) << " more degrees later" << std::endl;
        break;
    case 2:
        std::cout << "gas at " << (100 - temperature) << " more degrees later" <<  std::endl;
        break;
    case 3:
        std::cout << "plasma some very high temperature later" << std::endl;
        break;
    }

    return 0;
}
