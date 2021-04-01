//Header file auto-generated using CPP-Getter-Setter-Generator
#ifndef CLIENT_H
#define CLIENT_H

//Includes
#include <string>
#include <vector>
#include <chrono>
#include <thread>
#include "debugger.h"

class client {
	public:
		//Constructor and Destructor
		client();
		//~client();

		//Getters and Setters
		int getCount();
		bool getIsServer();
		int getSpeedDelay();
		std::string getIpAddr();
		bool getIsLobby();

		void setCount( int _count );
		void setIsServer( bool _isServer );
		void setSpeedDelay( int _speedDelay );
		void setIpAddr( std::string _ipAddr );
		void setIsLobby( bool _isLobby );

		//Other methods
		void sendMsg(std::string _target, std::string _msg);
		void recvMsg(std::string _sender, std::string _msg);
		void chooseServer();
		void assignServer(std::vector<client*> clients);
		void assignLobby(std::vector<client*> clients);
		std::vector<std::string> getIPs();
		client* getclientFromIP(std::string _ip);
		std::vector<std::vector<std::string>> testSpeeds();

	private:
		//Variables
		static int count;
		bool isServer;
		bool isLobby;
		int speedDelay;
		std::string ipAddr;
		std::string lobbyIP;
		std::string serverIP;
		
};
#endif