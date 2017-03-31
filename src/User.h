#pragma once

#include <string>
#include <vector>
#include <iostream>

#include "defs.h"
#include "utils.h"
#include "Accomodation.h"
#include "Date.h"
#include "Reservation.h"


using namespace std;

class User{
private:
	string username;
	string password;
	string name;
	vector<Reservation> reservations;

public:
	/**
	* @brief User constructor
	*
	* @param username
	*
	* @param password
	*
	* @param name
	*
	*/
	User(string username, string password, string name);

	/**
	*
	* @return name of the user
	*
	*/
	string getName() const { return name; }


	/**
	* @brief changes the name of the user
	*
	* @param name 
	*
	*/
	void setName(string name) { this->name = name; }

	/**
	*
	* @return  password of the user
	*
	*/
	string getPassword() const { return password; }

	/**
	* @brief changes user password
	*
	* @param password
	*
	*/
	void setPassword(string password) { this->password = password; }

	/**
	*
	* @return username
	*
	*/
	string getUsername() const { return username; }

	/**
	* @brief changes username
	*
	* @param username
	*
	*/
	void setUsername(string username) { this->username = username; }
	/**
	* @brief shows reservations
	*
	* 
	*/
	void showReservations()const;
	/**
	*
	* @return reservations
	*
	*/
	vector<Reservation> getReservations() const{ return reservations; };
	/**
	* @brief shows reservations
	*
	*
	*/
	void setReservations(vector<Reservation> res) { this->reservations = res; };
	/**
	* @brief deletes reservations
	*
	* @param position
	*/
	void deleteReservation(int position);
	/**
	* @brief equal operator
	*
	* @param user
	*
	* @return if it went well
	*/

	bool operator== (const User & usr) const;
};


class Suplier : public User{
private:
	int nif;
	string adress;
	vector <Accomodation*> accomodations;

public:
	/**
	* @brief creates a new suplier
	*
	* @param user
	*
	* @param password
	*
	* @param name
	*
	* @param nif
	*
	* @adress
	*/
	Suplier(string username, string password, string name, int nif, string adress); 
	/**
	* @brief adds accomodation
	*
	*/
	void addAccomodation();
	/**
	* @brief adds accomodation to file
	*
	* @param accomodation 
	*/
	void addAccomodationFile(Accomodation * acc);
	/**
	* @brief shows accomodations
	*
	*/
	void showAccomodations()const;
	/**
	* @brief gets accomodations
	*
	* @return accomodations
	*/
	vector<Accomodation*> getAccomodations() const { return accomodations; }
	/**
	* @brief sets accomodations
	*
	* @param accomodations
	*/
	void setAccomodations(vector<Accomodation*> accomodations) { this->accomodations = accomodations; }	
	/**
	* @brief gets adress
	*
	* @return 
	*/
	string getAdress() const { return adress; }
	void setAdress(string adress) { this->adress = adress; }
	int getNIF() const { return nif; }
	void save(ofstream & out) const;
	void addReservation(Reservation res);

	void showFees()const;
};


void askForPrice(float & p_night, float & p_week, float & p_month);
void askForAvailability(vector < pair<Date, Date>>&  unavailableDates);

class Client : public User{

	private:
		int points;

	public:
		Client(string username, string password, string name, int points = 0);
		int getPoints() const { return points; };
		void addReservation(Reservation res);

		void save(ofstream & out) const;
		//vector<Reservation*> getReservations() const;
		//void setReservations(vector<Reservation*> reservations);
		//makeReservation		//adicionar um numero de pontos ao utilizador por ter feito uma reserva (no algoritmo da pesquisa de alojamento do programa por a adicionar um numero menor de pontos por estar a pesqiusar no site


};