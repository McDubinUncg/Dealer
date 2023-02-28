#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Dealer {
    char *manufacturer;
    char *make;
    char *model;
    float price;
};

int main(int argc, char *argv[]) {
    struct Dealer cars[] = {{"Toyota", "Toyota", "Corolla", 21550},
                            {"Toyota", "Toyota", "Camry", 25945},
                            {"Toyota", "Toyota", "Avalon", 36825},
                            {"Toyota", "Toyota", "Mirai", 49500},
                            {"Toyota", "Toyota", "Sequoia", 58300},
                            {"Toyota", "Toyota", "Tacoma", 27250},
                            {"Toyota", "Toyota", "Tundra", 36965},
                            {"Toyota", "Lexus", "IS", 40585},
                            {"Toyota", "Lexus", "ES", 42490},
                            {"Toyota", "Lexus", "GX", 57575},
                            {"Chevrolet", "Chevy", "Trailblazer", 22100},
                            {"Chevrolet", "Chevy", "Camaro", 26100},
                            {"Chevrolet", "Chevy", "Equinox", 26600},
                            {"Chevrolet", "Chevy", "Traverse", 34520},
                            {"Chevrolet", "Chevy", "Tahoe", 54200},
                            {"Chevrolet", "Chevy", "Suburban", 56900},
                            {"Chevrolet", "Chevy", "Corvette", 64500},
                            {"Chevrolet", "Chevy", "Spark", 13600},
                            {"Chevrolet", "Chevy", "Trax", 21700},
                            {"Chevrolet", "Chevy", "Malibu", 23400},
                            {"Nissan", "Nissan", "Versa", 18990},
                            {"Nissan", "Nissan", "Sentra", 22700},
                            {"Nissan", "Nissan", "Altima", 35385},
                            {"Nissan", "Nissan", "Maxima", 43300},
                            {"Nissan", "Nissan", "Pathfinder", 50660},
                            {"Nissan", "Nissan", "Rogue", 38640},
                            {"Nissan", "Nissan", "Murano", 46910},
                            {"Nissan", "Infiniti", "Q50", 42650},
                            {"Nissan", "Infiniti", "QX55", 49150},
                            {"Nissan", "Infiniti", "QX80", 72700},
                            {"BMW", "BMW", "2 Series Coupe", 38050},
                            {"BMW", "BMW", "3 Series Sedan", 48220},
                            {"BMW", "BMW", "4 Series Convertible", 59320},
                            {"BMW", "BMW", "5 Series Sedan", 55175},
                            {"BMW", "BMW", "7 Series Sedan", 93400},
                            {"BMW", "BMW", "X1", 39700},
                            {"BMW", "BMW", "X3", 46050},
                            {"BMW", "BMW", "X4", 54050},
                            {"BMW", "BMW", "X5", 75400},
                            {"BMW", "BMW", "X7", 77850},
                            {"BMW", "BMW", "X7", 77850},
                            {"Volkswagen", "VW", "Jetta", 18995},
                            {"Volkswagen", "VW", "Passat", 23995},
                            {"Volkswagen", "VW", "Arteon", 36995},
                            {"Volkswagen", "Audi", "Q5", 43500},
                            {"Volkswagen", "Audi", "Q3", 38700},
                            {"Volkswagen", "Audi", "S6", 72700},
                            {"Volkswagen", "Audi", "A6", 55900},
                            {"Volkswagen", "Porsche", "Panamera", 132760},
                            {"Volkswagen", "Porsche", "Macan", 69480},
                            {"Volkswagen", "Porsche", "Cayenne", 92960}};
    int i;
    int n = 1;
    int z = sizeof(cars) / sizeof(cars[0]) / 5;
    int choice;
    int makeChoice;
    float rate = 0;
    float salary = 0;
    float downPayment = 0;
    float payment = 0;
    char makes[][20] = {"Toyota", "Chevrolet", "Nissan", "BMW", "Volkswagen"};
    salary = atof(argv[1]);
    int counter = 1;

    if (argc < 2) {
        printf("Please give a salary as command line argument\n");
        return 1;
    }

    printf("Enter Down Payment:");
    scanf("%f", &downPayment);
    printf("\nAvaliable Manufacturer: \n");
    for (int i = 0; i < 5; i++) {
        printf("%d)%s ", i + 1, makes[i]);
    }

    printf("\nSelect Manufacturer: ");
    scanf("%d", &choice);

    if (salary >= 125000) {
        for (int i = 0; i < sizeof(cars) / sizeof(struct Dealer); i++) {
            if (strcmp(cars[i].manufacturer, makes[choice - 1]) == 0 &&
                cars[i].price < salary) {
                printf("%d)%s %s - $%.0f\n", counter, cars[i].make,
                       cars[i].model, cars[i].price);
                counter++;
            }
        }
        rate = 0.0479;
        printf("\nSelect Make/Model: ");
        scanf("%d", &makeChoice);
    } else if (salary >= 80000 && salary < 125000) {
        for (int i = 0; i < sizeof(cars) / sizeof(struct Dealer); i++) {
            if (strcmp(cars[i].manufacturer, makes[choice - 1]) == 0 &&
                cars[i].price < salary) {
                printf("%d)%s %s - $%.0f\n", counter, cars[i].make,
                       cars[i].model, cars[i].price);
                counter++;
            }
        }
        rate = 0.0655;
        printf("\nSelect Make/Model: ");
        scanf("%d", &makeChoice);
    } else if (salary >= 45000 && salary < 80000) {
        for (int i = 0; i < sizeof(cars) / sizeof(struct Dealer); i++) {
            if (strcmp(cars[i].manufacturer, makes[choice - 1]) == 0 &&
                cars[i].price < salary) {
                printf("%d)%s %s - $%.0f\n", counter, cars[i].make,
                       cars[i].model, cars[i].price);
                counter++;
            }
        }
        rate = 0.0949;
        printf("\nSelect Make/Model: ");
        scanf("%d", &makeChoice);
    } else if (salary < 45000) {
        for (int i = 0; i < sizeof(cars) / sizeof(struct Dealer); i++) {
            if (strcmp(cars[i].manufacturer, makes[choice - 1]) == 0 &&
                cars[i].price < salary) {
                printf("%d)%s %s - $%.0f\n", counter, cars[i].make,
                       cars[i].model, cars[i].price);
                counter++;
            }
        }
        rate = 0.1328;
        printf("\nSelect Make/Model: ");
        scanf("%d", &makeChoice);
    }

    struct Dealer car = cars[(choice - 1) * z + makeChoice - 1];
    payment =
        ((car.price - downPayment) + (car.price - downPayment) * rate * 5) /
        (12 * 5);
    printf("You selected the %s %s. Your monthly payment is $%.2f\n", car.make,
           car.model, payment);
    return 0;
}
