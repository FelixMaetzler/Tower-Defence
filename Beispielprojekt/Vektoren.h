#pragma once
#ifndef VEKTOREN_H
#define VEKTOREN_H




class Vektoren {
private:
	double x;//x-Komponente des Vektors
	double y;//y-Komponente des Vektors
public:
	//Konstruktoren

	//Standartkonstruktor
	Vektoren(void);
	//Konstruktor f�r die x und y Komponente des Vektors
	Vektoren(const double,const double);
	Vektoren(const int, const int);

	//Get/Set Methoden

	//gibt die x-Komponente des Vektors zur�ck
	double get_x(void)const;
	//setzt die x-Komponente des Vektors
	void set_x(const double);
	//gibt die y-Komponente des Vektors zur�ck
	double get_y(void)const;
	//setzt die y-Komponente des Vektors
	void set_y(const double);

	//andere Methoden

	//addiert die Vektoren
	Vektoren operator+(const Vektoren)const;
	//addiert die Vektoren
	Vektoren operator+=(const Vektoren)const;
	//subtrahiert die Vektoren
	Vektoren operator-(const Vektoren)const;
	//subtrahiert die Vektoren
	Vektoren operator-=(const Vektoren)const;
	//bildet das Skalarprodukt
	double operator*(const Vektoren) const;
	//multipliziert den Vektor mit der Zahl
	Vektoren operator*(const double)const;
	//multipliziert den Vektor mit der Zahl
	Vektoren operator*=(const double)const;
	//dividiert den Vektor mit der Zahl
	Vektoren operator/(const double)const;
	//dividiert den Vektor mit der Zahl
	Vektoren operator/=(const double)const;
	
	
	//gibt die L�nge des Vektors zur�ck
	double laenge(void)const;
	//gibt den Winkel zur positiven x-Achse und gegen den Uhrzeigersinn zur�ck
	double winkel(void)const;
	//Wenn ich den Winkel auf meinen Vektor draufaddiere, dann komme ich zu dem Vektor in den Klammern
	double winkelZwischen2Vektoren(const Vektoren)const;
	//normiert den Vektoren
	void normieren(void);
	//gibt den Vektor in der Konsole aus (nur zu Testzwecken)
	void print(void)const;
	//gibt das Skalarprodukt zweier Vektoren zur�ck 
	double skalarprodukt(Vektoren)const;
};

//Funktionen

//wandelt Bogenma� in Gradma� um
double radiantToDegree(const double);
//wandelt Gradma� in Bogenma� um
double DegreeToRadiant(const double);
//gibt einen Winkel zwischen 0� und 359� zur�ck
double winkelNormalisieren(const double);
double winkelingosuwinkel(const double);


#endif // !VEKTOREN_H
