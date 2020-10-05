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
	//Konstruktor für die x und y Komponente des Vektors
	Vektoren(const double,const double);
	Vektoren(const int, const int);

	//Get/Set Methoden

	//gibt die x-Komponente des Vektors zurück
	double get_x(void)const;
	//setzt die x-Komponente des Vektors
	void set_x(const double);
	//gibt die y-Komponente des Vektors zurück
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
	
	
	//gibt die Länge des Vektors zurück
	double laenge(void)const;
	//gibt den Winkel zur positiven x-Achse und gegen den Uhrzeigersinn zurück
	double winkel(void)const;
	//Wenn ich den Winkel auf meinen Vektor draufaddiere, dann komme ich zu dem Vektor in den Klammern
	double winkelZwischen2Vektoren(const Vektoren)const;
	//gibt den Vektor mit gleicher Richtung, allerdings mit der Länge 1 zurück
	Vektoren normieren(void)const;
	//gibt den Vektor in der Konsole aus (nur zu Testzwecken)
	void print(void)const;
	//gibt das Skalarprodukt zweier Vektoren zurück 
	double skalarprodukt(Vektoren)const;
};

//Funktionen

//wandelt Bogenmaß in Gradmaß um
double radiantToDegree(const double);
//wandelt Gradmaß in Bogenmaß um
double DegreeToRadiant(const double);
//gibt einen Winkel zwischen 0° und 359° zurück
double winkelNormalisieren(const double w);


#endif // !VEKTOREN_H
