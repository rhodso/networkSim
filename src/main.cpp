#include "main.h"

int clientCount = 10;
std::vector<client*> clients;

int main(){
    debugger::setDebug(true);

    //Check for too many clients if there is then stop
    if(clientCount > 256){
        debugger::p("Too many clients. Stop");
        return 0;
    } else { 
        //If there isn't then create clients
        for(int i = 0; i < clientCount; i++){
            client* c = new client();
            clients.push_back(c);
        }
    }

    //Print ips
    debugger::p("IP list: ");
    for(client* c : clients){
        debugger::p(c->getIpAddr());
    }

    puts("");

    clients.at(0)->assignLobby(clients);
    clients.at(0)->assignServer(clients);
}