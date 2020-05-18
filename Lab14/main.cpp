#include "Domain/Plane.h"
#include "Repository/TemplateRepository.h"
#include <iostream>
using namespace std;

int main() {
    auto *plane_repository = new TemplateRepository<Plane>;
    int planes_number;
    cout << "Numarul de avioane: ";
    cin >> planes_number;
    //cout << int('a') << ' ' << int('b') << endl;
    for (int i = 0; i < planes_number; i++) {
        cout << endl << "Avionul " << i + 1 << ": ";
        char head_line_string;
        cout << "Linia (a-z): ";
        cin >> head_line_string;
        int head_line = int(head_line_string) - 96;
        cout << "Coloana (1-31): ";
        int head_column;
        cin >> head_column;
        Plane plane(head_line, head_column);
        //cout << plane.get_head_line() << ' ' << plane.get_head_column() << endl;
        plane_repository->add(plane);
        cout << "Avion adaugat" << endl;
    }
    return 0;
}
