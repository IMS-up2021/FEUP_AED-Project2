//
// Created by fuhao on 26/12/2022.
//

#include "airportsGraph.h"
using namespace std;

/*airportsGraph::airportsGraph(CSVReader reader,bool dir){

}*/
airportsGraph::airportsGraph() {
    CSVReader reader;
    reader.populate();
    airports=reader.getAirports();
}
Airport airportsGraph::findAirportByCoord(const double lat, const double longi) const{
    auto it=airports.begin();
    while(it!=airports.end());{
        if(it->getLatitude()==lat&&it->getLongitude()==longi) return *it;
    }
}
unordered_set<Airport,AirportHash> airportsGraph::findAirportsAround(const double lat, const double longi,
                                                                     const double x) const {
    auto it= airports.begin();
    Airport center= findAirportByCoord(lat,longi);
    Airports temp;
    temp.insert(center);
    while(it!=airports.end()){
        if(center.calcDistanceHaversine(*it)<x){
            temp.insert(*it);
        }
    }
}

unordered_set<Airport,AirportHash> airportsGraph::getAirports() {
    return  airports;
}




