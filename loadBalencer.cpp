#include <bits/stdc++.h>
using namespace std;
class Server {
public:
    string serverName;
    int weight;
    int handledCount;
    Server(string name, int w) {
        serverName = name;
        weight = w;
        handledCount = 0;
    }
    void handleRequest(string request) {
        handledCount++;
        cout << "Server " << serverName << " is handling request: " << request << "\n";
    }
};

class LoadBalancer {
private:
    vector<Server> backendList;     
    vector<int> weightedOrder;      
    int pos;                       
public:
    LoadBalancer() {
        pos = 0;
    }
    void addBackend(Server backend) {
        backendList.push_back(backend);
        int index = backendList.size() - 1;
        for (int i = 0; i < backend.weight; i++) {
            weightedOrder.push_back(index);
        }
    }
    void routeRequest(string request) {
        if (weightedOrder.size() == 0) {
            cout << "No backends available to handle request!\n";
            return;
        }
        int backendIndex = weightedOrder[pos];
        backendList[backendIndex].handleRequest(request);

        pos = (pos + 1) % weightedOrder.size();
    }
    void showStats() {
        for (int i = 0; i < backendList.size(); i++) {
            cout << "Server " << backendList[i].serverName
                 << " handled " << backendList[i].handledCount << " requests\n";
        }
    }
};

int main() {
    LoadBalancer lb;
    lb.addBackend(Server("A", 3)); 
    lb.addBackend(Server("B", 2));
    lb.addBackend(Server("C", 1));  
    string requests[] = {"Req1","Req2","Req3","Req4","Req5","Req6","Req7","Req8","Req9","Req10"};
    int n = 10;
    for (int i = 0; i < n; i++) {
        lb.routeRequest(requests[i]);
    }

    cout << endl;
    lb.showStats();
    return 0;
}
