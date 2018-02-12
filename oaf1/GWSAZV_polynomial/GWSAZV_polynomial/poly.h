#ifndef POLY_H
#define POLY_H

class Poly {
	private:
		//a dinamikus tomb merete
		int n;
		//a polinom egyutthatoit tarolo dinamikus tomb
		double *v;

	public:
		//polinom fokat megado konstruktor
		Poly(int k);

		//masolo konstruktor
		Poly(const Poly &cPoly);

		//atmeretezo fuggveny
		void Size(int k);

		//destruktor
		~Poly();

		//ertekadas operator
		Poly operator= (const Poly &cPoly);

		//beolvassa a polinom egyutthatoit
		void read();

		//kiirja hagyomanyos formaban a polinomot
		void write();
		
		//megad egy egyutthatot
		double get(int i) const;

		//osszead ket polinomot
		friend Poly add(const Poly& a, const Poly& b);

		//osszeszoroz ket polinomot
		friend Poly mult(const Poly& a, const Poly& b);
};

#endif POLY_H