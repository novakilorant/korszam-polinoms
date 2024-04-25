#include <polinom.h>

int main(int argc, char** argv) {
    polinom poli, poli1, poli2;
    if (argc != 1) {
        int i;
		for (i=0;i<argc;i++){
            poli.parameters.push_back(stod(argv[i]));
        }

	}
    else{
        poli.parameters = {1, 2, 3};
    }
    cout << "A polinom kiratasa:" << endl;

    poliprint(poli);

    poli1.parameters = {2, 1, 3};

    cout << "A polinom osszeadasa {2, 1, 3} polinommal:" << endl;

    poli = poli+poli1;

    poliprint(poli);

    cout << "A polinom osszeadasa onmagaval:" << endl;

    poli += poli;

    poliprint(poli);

    cout << "A polinom osszeadasa {2, 1, 3} polinommal:" << endl;

    poli1.parameters = {1, 2, 3};

    cout << "Az eredeti polinom egyutthatoival egy masik polinom:" << endl;

    poliprint(poli1);

    cout << "A eredeti polinomot kivonom a valtoztatottbol:" << endl;

    poli = poli-poli1;

    poliprint(poli);

    cout << "Itt meg egyszer, de a -= operatorral:" << endl;

    poli -= poli1;

    poliprint(poli);

    cout << "A polinom szorzasa 2-vel kulso szorzatkent jobbrol:" << endl;

    poli = poli * 2;

    poliprint(poli);

    cout << "A polinom szorzasa 2-vel kulso szorzatkent balrol:" << endl;

    poli = 2*poli;

    poliprint(poli);

    cout << "A polinom osztasa 2-vel:" << endl;

    poli = poli / 2;

    poliprint(poli);

    cout << "A polinom szorzasa 2-vel a *= operatorral:" << endl;

    poli *= 2;

    poliprint(poli);

    cout << "A polinom osztasa 2-vel a /= operatorral:" << endl;

    poli /= 2;

    poliprint(poli);

    cout << "A polinom derivaltja:" << endl;

    double c = poli.parameters[0]; //eredeti konstans elmentese integralashoz

    poli = derivative(poli);

    poliprint(poli);

    cout << "A polinom határozatlan integralja, az eredeti konstans visszahelyezesevel:" << endl;

    poli = integrate(poli, c);

    poliprint(poli);

    cout << "Van ket polinomunk" << endl;
    poliprint(poli1);
    poli2.parameters = {-1, 8, 0.2};
    poliprint(poli2);
    cout << "Ezek skalarszorzata: " << dot(poli1, poli2) << endl;

    cout << "Ki is tudom iratni a 2.-at ostreammel: " << poli2 << endl;

    return 0;
}


