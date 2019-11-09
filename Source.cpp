#include "rhombus.h"
#include "rectangle.h"
#include "trapezoid.h"
#include "templates.h"
#include "vertex.h"

void menu() {
	std::cout << "_____________________________\n";
    std::cout << "0: Exit\n";
    std::cout << "1: Fake figure\n";
    std::cout << "2: Array figure\n";
    std::cout << "3: Real figure\n";
}

void menuOf3() {
    std::cout << "_____________________________\n";
    std::cout << "0: Exit\n";
    std::cout << "1: Rhombus\n";
    std::cout << "2: Rectangle\n";
    std::cout << "3: Trapezoid\n";
}

int main() {
	
	int cmd;
	
	while (true) {
	    menu();
	    std::cin >> cmd;
	    if (cmd == 0) break;
	    else if (cmd == 1) {
	        std::cout << "Fake rhombus : float\n";
	        std::tuple<vertex<float>, vertex<float>, vertex<float>, vertex<float>> fakeRhombus{{0, 0}, {-1.5, 2}, {1.5, 2}, {0, 4}};
            
            std::cout << "Coordinates: \n";
            print(fakeRhombus);
            std::cout << '\n';
            std::cout << "Center: " << center(fakeRhombus) << '\n';
            std::cout << "Area: " << area(fakeRhombus) << '\n';
	    } else if (cmd == 2) {
	        std::cout << "Array rectangle : double\n";
	        std::array<vertex<double>, 4> arrayRectangle{{{0, 0}, {10, 0}, {0, 8}, {10, 8}}};
	        
	        std::cout << "Coordinates: \n";
            print(arrayRectangle);
            std::cout << '\n';
            std::cout << "Center: " << center(arrayRectangle) << '\n';
            std::cout << "Area: " << area(arrayRectangle) << '\n';
	    } else if (cmd == 3) {
	        menuOf3();
	        int cmdcmd;
	        
	        std::cin >> cmdcmd;
	        
	        if (cmdcmd == 0) break;
	        else if (cmdcmd == 1) {
	            std::cout << "Input 4 coordinates of rhombus" << std::endl;
                rhombus<double> realRhombus(std::cin);
                std::cout << "Coordinates: \n";
                print(realRhombus);
                std::cout << '\n';
                std::cout << "Center: " << center(realRhombus) << '\n';
                std::cout << "Area: " << area(realRhombus) << '\n';
	        } else if (cmdcmd == 2) {
	            std::cout << "Input 4 coordinates of rectangle" << std::endl;
                rectangle<double> realRectangle(std::cin);
                std::cout << "Coordinates: \n";
                print(realRectangle);
                std::cout << '\n';
                std::cout << "Center: " << center(realRectangle) << '\n';
                std::cout << "Area: " << area(realRectangle) << '\n';
	        } else if (cmdcmd == 3) {
	            std::cout << "Input 4 coordinates of trapezoid" << std::endl;
                trapezoid<double> realTrapezoid(std::cin);
                std::cout << "Coordinates: \n";
                print(realTrapezoid);
                std::cout << '\n';
                std::cout << "Center: " << center(realTrapezoid) << '\n';
                std::cout << "Area: " << area(realTrapezoid) << '\n';
	        } else {
	            std::cout << "Not a command\n";
	        }
	        
	    } else {
	        std::cout << "Not a command\n";
	    }
	}

    return 0;
}