//Source file auto-generated using CPP-Getter-Setter-Generator

//Includes
#include "client.h"

//Constructor and Destructor
client::client(){
    //Create vars
    ipAddr = "192.168.123." + std::to_string(count);
    isServer = isLobby = false;
    speedDelay = rand() % 90 + 10;
    lobbyIP = "";
    serverIP = "";
    count++;
}
//client::~client(){}

//Static vars
int client::count = 0;

//Getters and Setters
int client::getCount(){ return count; }
bool client::getIsServer(){ return isServer; }
int client::getSpeedDelay(){ return speedDelay; }
std::string client::getIpAddr(){ return ipAddr; }
bool client::getIsLobby(){ return isLobby; }

void client::setCount( int _count){ count = _count; }
void client::setIsServer( bool _isServer){ isServer = _isServer; }
void client::setSpeedDelay( int _speedDelay){ speedDelay = _speedDelay; }
void client::setIpAddr( std::string _ipAddr){ ipAddr = _ipAddr; }
void client::setIsLobby( bool _isLobby){ isLobby = _isLobby; }

//Other methods
void client::sendMsg(std::string _target, std::string _msg){
    // Get a pointer to the client based on their IP addrm then call
    // target's recvMsg function
    debugger::log(ipAddr + " sending message \"" + _msg + "\" to " + _target);
    client* trg = getclientFromIP(_target);
    trg->recvMsg(ipAddr, _msg);
}
void client::recvMsg(std::string _sender, std::string _msg){
    //Wait for the "internet speed"
    //std::this_thread::sleep_for(std::chrono::microseconds(speedDelay));

    debugger::log(ipAddr + " got message \"" + _msg + "\" from " + _sender);
    //Do stuff based on msg contents
    if(_msg == "Ping me"){
        sendMsg(_sender, "Ping");
    } else if(_msg == "Who else is there?"){
        if (isServer){
            //Access server class for a list of IP addrs

        } else {
            sendMsg(_sender, "I am not server");
        }
    } else if(_msg == "I am server owner"){
        serverIP = _sender;
    } else if(_msg == "I am lobby owner"){
        lobbyIP = _sender;
    }
}
void client::chooseServer(){
    
}
void client::assignServer(std::vector<client*> clients){
    isServer = true;

    //Tell everyone that I am server owner
    for(client* c : clients){
        if(c->getIpAddr() != ipAddr){
            c->sendMsg(ipAddr, "I am lobby owner");
        }
    }
}
void client::assignLobby(std::vector<client*> clients){
    isLobby = true;

    //Tell everyone that I am lobby owner
    for(client* c : clients){
        if(c->getIpAddr() != ipAddr){
            c->sendMsg(ipAddr, "I am lobby owner");
        }
    }
}
std::vector<std::string> client::getIPs(){

}
client* client::getclientFromIP(std::string _ip){
    if(_ip == getIpAddr() ){
        return this; 
    } else {
        return nullptr;
    }
}
std::vector<std::vector<std::string>> client::testSpeeds(){

}
