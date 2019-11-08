#include "rhombus.h"
#include "rectangle.h"
#include "trapezoid.h"
#include "templates.h"

void menu() {
	std::cout << "_____________________________" << std::endl;
    std::cout << "0: Exit" << std::endl;
    std::cout << "1: Fake figure demonstration" << std::endl;
    std::cout << "2: Array figure demonstration" << std::endl;
    std::cout << "3: Real figure demonstration" << std::endl;
}

int main() {

	menu();
	
    int input;

    while (true) {
        std::cin >> input;

        if (input == 0) {
            break;
        }

        if (input > 3) {
            std::cout << "Not a command" << std::endl;
        }

        switch (input) {
            case 1: {
                std::cout << "Fake rhombus (float):" << std::endl;
                std::tuple<vertex<float>, vertex<float>, vertex<float>, vertex<float>>
                        fakeRhombus{{0, 0}, {-1.5, 2}, {1.5, 2}, {0, 4}};
                std::cout << "Coordinates: ";
                print(fakeRhombus);
                std::cout << std::endl;
                std::cout << "center: " << center(fakeRhombus) << std::endl;
                std::cout << "area: " << area(fakeRhombus) << std::endl << std::endl;

                std::cout << "Fake rectangle (int):" << std::endl;
                std::tuple<vertex<int>, vertex<int>, vertex<int>, vertex<int>>
                        fakeRectangle{{0, 0}, {0, 2}, {10, 2}, {10, 0}};
                std::cout << "Coordinates: ";
                print(fakeRectangle);
                std::cout << std::endl;
                std::cout << "center: " << center(fakeRectangle) << std::endl;
                std::cout << "area: " << area(fakeRectangle) << std::endl << std::endl;

                std::cout << "Fake trapezoid (double):" << std::endl;
                std::tuple<vertex<double>, vertex<double>, vertex<double>, vertex<double>>
                        fakeTrapezoid{{0, 0}, {0.5, 2}, {2, 2}, {15.5, 0}};
                std::cout << "Coordinates: ";
                print(fakeTrapezoid);
                std::cout << std::endl;
                std::cout << "center: " << center(fakeTrapezoid) << std::endl;
                std::cout << "area: " << area(fakeTrapezoid) << std::endl << std::endl;
            break;
            }

            case 2: {
                std::cout << "Array rhombus (double):" << std::endl;
                std::array<vertex<double>, 4>
                        arrayRhombus{{{0, 0}, {0, 2}, {2, 2}, {2, 0}}};
                std::cout << "Coordinates: ";
                print(arrayRhombus);
                std::cout << std::endl;
                std::cout << "center: " << center(arrayRhombus) << std::endl;
                std::cout << "area: " << area(arrayRhombus) << std::endl << std::endl;

                std::cout << "Array trapezoid (float):" << std::endl;
                std::array<vertex<float>, 4>
                        arrayTrapezoid{{{0, 0}, {1, 2}, {2, 2}, {3, 0}}};
                std::cout << "Coordinates: ";
                print(arrayTrapezoid);
                std::cout << std::endl;
                std::cout << "center: " << center(arrayTrapezoid) << std::endl;
                std::cout << "area: " << area(arrayTrapezoid) << std::endl << std::endl;
            break;
            }

            case 3: {
                int realID;

                std::cout << "Input real figure id:" << std::endl;
                std::cout << "1: rhombus" << std::endl;
                std::cout << "2: rectangle" << std::endl;
                std::cout << "3: trapezoid" << std::endl;
                
                std::cin >> realID;

                switch (realID) {
                    case 1: {
                        std::cout << "Input 4 coordinates" << std::endl;
                        rhombus<double> realRhombus(std::cin);
                        std::cout << "Coordinates: ";
                        print(realRhombus);
                        std::cout << std::endl;
                        std::cout << "center: " << center(realRhombus) << std::endl;
                        std::cout << "area: " << area(realRhombus) << std::endl << std::endl;
                    break;
                    }

                    case 2: {
                        std::cout << "Input 4 coordinates" << std::endl;
                        rectangle<double> realRectangle(std::cin);
                        std::cout << "Coordinates: ";
                        print(realRectangle);
                        std::cout << std::endl;
                        std::cout << "center: " << center(realRectangle) << std::endl;
                        std::cout << "area: " << area(realRectangle) << std::endl << std::endl;
                    break;
                    }

                    case 3: {
                        std::cout << "Input 4 coordinates" << std::endl;
                        trapezoid<double> realTrapezoid(std::cin);
                        std::cout << "Coordinates: ";
                        print(realTrapezoid);
                        std::cout << std::endl;
                        std::cout << "center: " << center(realTrapezoid) << std::endl;
                        std::cout << "area: " << area(realTrapezoid) << std::endl << std::endl;
                    break;
                    }
                }
            break;
            }
        }
    }
    return 0;
}