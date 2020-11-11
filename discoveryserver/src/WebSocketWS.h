using namespace std;

#include "server_ws.hpp"
#include <iostream>
#include <chrono>
#include <thread>
#include <functional>
#include <future>
#include "json.hpp"

using WsServer = SimpleWeb::SocketServer<SimpleWeb::WS>;
using json = nlohmann::json;

class WebSocketWS {
    public:
        WebSocketWS ();
        ~WebSocketWS ();

        static WsServer server;

        void StartServerWS(uint32_t nPort, string sEndURL);
        void SendMessage(shared_ptr<WsServer::Connection> hConnection, string sMessage);
        void timer_start(std::function<void(void)> func, unsigned int interval);
        void Pinging();

        virtual void OnConnected(shared_ptr<WsServer::Connection> hConnection) {};
        virtual void OnMessage(shared_ptr<WsServer::Connection> hConnection, string sMessage) {};
        virtual void OnDisconnected(shared_ptr<WsServer::Connection> hConnection) {};
        virtual void OnError(shared_ptr<WsServer::Connection> hConnection, string sError) {};
        virtual void NetworkDetection() {};
};
